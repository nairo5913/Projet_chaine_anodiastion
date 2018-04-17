/*******************************************************************************
  *  Fichier:  Client.cpp
  *  Projet:   Chaîne d'anodisation - Gestion du client pour le PC responsable 
               de production
  *  Crée le:  11/04/2018
  *  Utilité:  Gestion du client
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "Client.h"

Client::Client(wxString ip, long port, EvtFramePrincipal *frame)
{
    m_hote = ip;
    m_port = port;
    m_frame = frame;
    
    // Création du socket
    wxIPV4address socket;
    socket.Hostname(m_hote);
    socket.Service(m_port);
    m_client = new wxSocketClient();
    
    // on se connecte en non bloquant sur le socket
    m_client->Connect(socket, false);
    
    // on attend au maximum 10s que la connexion s'établisse
    m_client->WaitOnConnect(10);
    
    // Vérification du succès de la connexion
    if(m_client->IsConnected())
    {
        m_client_connecte = true;
        string reponse = LitReponse();
        
        if(reponse == CONNEXION_OK) // 101
        {
            wxString message(wxT(""));
            
            // Affichage des détail de la connexion
            /*message <<  wxT("Connecté sur ") << m_hote
                    <<  wxT(", Port ") <<  m_port;*/
            
            // on demande à l'IHM d'afficher le message
            wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT);
            MyEvent.SetString(message);
            wxPostEvent(m_frame, MyEvent);
            
            // On connecte le gestionnaire d'événement à l'événement socket
            Connect( SOCKET_ID, wxEVT_SOCKET , wxSocketEventHandler( Client::OnSocketEvent ));
            
            // On indique quel gestionnaire d'événement utiliser
            m_client->SetEventHandler(*this, SOCKET_ID);
            
            // sur un événement socket perdu
            m_client->SetNotify(//wxSOCKET_CONNECTION_FLAG |
                                //wxSOCKET_INPUT_FLAG |
                                wxSOCKET_LOST_FLAG);
            
            // on active les événements sur ce socket
            m_client->Notify(true);
            
            wxCommandEvent MyEventMsg(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
            
            wxString utilisateur = wxT("Responsable");
            
            if(Identification(utilisateur))
            {
                message.clear();
                message << wxT("Identification OK \n");
                MyEventMsg.SetString(message);
                wxPostEvent(m_frame, MyEventMsg);
            }
            else
            {
                message.clear();
                message << wxT("Échec de l'identification \n");
                MyEventMsg.SetString(message);
                wxPostEvent(m_frame, MyEventMsg);
                Deconnexion(message);
            }
            
            
        }
        else if(reponse == NOMBRE_MAX_UTILISATEURS)
        {
            wxString message(wxT("Désolé, nombre maximum d'utilisateurs atteints \n"));
            Deconnexion(message);
        }
        else if(reponse == CONNEXION_PAS_OK)
        {
            wxString message(wxT("Erreur lors de la connexion \n"));
            Deconnexion(message);
        }
        else if(reponse == ERREUR_RESEAUX)
        {
            wxString message(wxT("Erreur réseau \n"));
            Deconnexion(message);
        }
        else
        {
            wxString message(wxT("Raison: le serveur n'est pas le serveur d'anodisation \n"));
            Deconnexion(message);
        }
    }
    else
    {
        m_client_connecte = false;
        delete m_client;
    }
}

Client::~Client()
{
    if(m_client_connecte)
    {
        m_client->Close();
    }
}

string Client::EcritMessage(wxString message)
{
    char *cstring;
    cstring = new char(message.Len()+3);
    strcpy(cstring, (const char*)message.mb_str(wxConvUTF8));

    // le protocole indique que le message doit se terminer par CR LF
    cstring[strlen(cstring)+2]=0x00;
    cstring[strlen(cstring)+1]=0x0A;
    cstring[strlen(cstring)]=0x0D;
    
    // on envoie le message
    m_client->Write(cstring, strlen(cstring));
    delete cstring;

    //wxString reponse(LitReponse().c_str(), wxConvUTF8);
    string reponse = LitReponse();
    
    return reponse;
}

void Client::Close()
{
    if (m_client_connecte)
    {
        m_client->Close();
        m_client_connecte=false;
    }
}

void Client::EnvoiProcessus(int num_id/*, wxString utilisateur*/)
{
    
}

bool Client::Identification(wxString utilisateur)
{
    bool retour = false;
    
    wxString requete(wxT(DEMANDE_IDENTIFICATION));
    requete << utilisateur;
    
    wxString reponse = EcritMessage(requete);
    
    if(reponse == IDENTIFICATION_OK)
    {
        retour = true;
    }
    else if(reponse == IDENTIFICATION_PAS_OK)
    {
        retour = false;
    }
    else
    {
        retour = false;
    }
    
    return retour;
}

string Client::LitReponse()
{
    string reponse="";
    
    //on teste s'il y a eu une erreur d'E/S réseau
    if (!m_client->Error())
    {
        unsigned char c = 0;
        
        do
        {
            m_client->Read(&c, 1);
            reponse.push_back(c);
            
        }while (c != 0x0A); // jusqu'à "LF"
        
        // on retire le 'LF' et le 'CR'
        reponse.resize(reponse.length()-2);
    }
    else
    {
        reponse="999";
    }
    return reponse;
}

void Client::Deconnexion(wxString raison)
{
    wxString message(wxT(DEMANDE_DECONNEXION));
    string reponse = EcritMessage(message);
    
    m_client_connecte=false;
    m_client->Destroy();
    
    // on demande à l'IHM d'afficher le message
    wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED,ID_CLIENT+2);
    MyEvent.SetString(raison);
    wxPostEvent(m_frame, MyEvent);
    
    wxCommandEvent MyEvent1(wxEVT_COMMAND_BUTTON_CLICKED,ID_CLIENT+1);
    MyEvent.SetString(reponse);
    wxPostEvent(m_frame, MyEvent1);
}

void Client::OnSocketEvent(wxSocketEvent& event)
{
    //on peut récupérer le socket:
    //wxSocketBase *sock=event.GetSocket();
    
    switch (event.GetSocketEvent())
    {
        case wxSOCKET_LOST:
        {
            wxString message(wxT(""));
            message <<  wxT("Déconnexion du serveur situé sur ") <<  m_hote << wxT(": il a disparu\n");
            Deconnexion(message);
            break;
        }
        case wxSOCKET_INPUT:
            break;
        case wxSOCKET_OUTPUT:
            break;
        case wxSOCKET_CONNECTION:
            break;
    }
}