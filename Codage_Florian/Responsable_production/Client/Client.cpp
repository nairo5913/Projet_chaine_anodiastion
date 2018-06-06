/*******************************************************************************
 *  Fichier:  Client.cpp
 *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
 *  Crée le:  29/04/2018
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

bool Client::DemandeDisponibiliteBras()
{
    wxString requete(wxT(DISPONIBILITE_BRAS));
    
    wxString reponse = EcritMessage(requete);
    bool retour = false;
    
    if(reponse == BRAS_DISPONIBLE)
    {
        wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
        MyEvent.SetString(wxT("Le bras est disponible.\n"));
        wxPostEvent(m_frame, MyEvent);
        
        retour = true;
    }
    else if(reponse == BRAS_INDISPONIBLE)
    {
        wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
        MyEvent.SetString(wxT("Le bras n'est pas disponible.\n"));
        wxPostEvent(m_frame, MyEvent);
    }
    else
    {
        wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
        MyEvent.SetString(wxT("Une erreur est survenue.\n"));
        wxPostEvent(m_frame, MyEvent);
    }
    
    return retour;
}

vector<string> Client::DemandeTacheEnCours()
{
    vector<string> tache;
    
    if(DemandeDisponibiliteBras() == false)
    {
        wxString requete(wxT(DEMANDE_TACHE_EN_COURS));
        wxString reponse = EcritMessage(requete);
        wxString texte="";
        
        if(reponse.StartsWith(TACHE_EN_COURS, &texte))
        {
            int separateur = texte.find("-");
            
            string type = m_frame->ConversionEnString(m_frame->DecouperTexteDebut(texte, separateur));
            string id_tache = m_frame->ConversionEnString(m_frame->DecouperTexteFin(texte, separateur+1));
            
            // Première cellule "type", deuxième cellule "id"
            tache.push_back(type);
            tache.push_back(id_tache);
        }
        else if(reponse.IsSameAs(PAS_TACHE_EN_COURS))
        {
            tache.push_back("0");
        }
        else
        {
            tache.push_back("0");
        }
    }
    else
    {
        tache.push_back("0");
    }
    
    return  tache;
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

/*void Client::AnalyseReponseServeur(string reponse) // À coder
{
    
}*/

void Client::Close()
{
    if (m_client_connecte)
    {
        m_client->Close();
        m_client_connecte=false;
    }
}

void Client::ExecutionProcessus(wxString num_id)
{
    if(DemandeDisponibiliteBras())
    {
        wxString requete;
        requete << wxT(DEMANDE_EXECUTION_PROCESSUS) << num_id;
        
        wxString reponse = EcritMessage(requete);
        
        if(reponse == EXECUTION_IMPOSSIBLE)
        {
            wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
            MyEvent.SetString(wxT("Erreur d'éxecution"));
            wxPostEvent(m_frame, MyEvent);
        }
        else
        {
            wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
            MyEvent.SetString(wxT("Éxecution réussie."));
            wxPostEvent(m_frame, MyEvent);
        }
    }
    else
    {
        wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
        MyEvent.SetString(wxT("Imposible de lancer l'éxecution du processus car le bras n'est pas disponible.\n"));
        wxPostEvent(m_frame, MyEvent);
    }
}

void Client::StopProcessus()
{
    wxString requete;
    requete << wxT(STOP_TEST_PROCESSUS);
    
    wxString reponse = EcritMessage(requete);
    
    wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
    MyEvent.SetString(wxT("Processus stopper."));
    wxPostEvent(m_frame, MyEvent);
}

void Client::TestProcessus(wxString num_id)
{
    if(DemandeDisponibiliteBras())
    {
        wxString requete;
        requete << wxT(DEMANDE_TEST_PROCESSUS) << num_id;
        
        wxString reponse = EcritMessage(requete);
        
        if(reponse == EXECUTION_IMPOSSIBLE)
        {
            wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
            MyEvent.SetString(wxT("Erreur de lancement du test"));
            wxPostEvent(m_frame, MyEvent);
        }
        else
        {
            wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
            MyEvent.SetString(wxT("Lancement du test réussi."));
            wxPostEvent(m_frame, MyEvent);
        }
    }
    else
    {
        wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
        MyEvent.SetString(wxT("Imposible de lancer le test du processus car le bras n'est pas disponible.\n"));
        wxPostEvent(m_frame, MyEvent);
    }
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
        reponse = ERREUR_RESEAUX;
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
    wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+2);
    MyEvent.SetString(raison);
    wxPostEvent(m_frame, MyEvent);
    
    wxCommandEvent MyEvent1(wxEVT_COMMAND_BUTTON_CLICKED, ID_CLIENT+1);
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