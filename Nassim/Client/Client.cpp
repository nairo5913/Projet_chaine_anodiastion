/***************************************************************
 * Nom:     Client.cpp
 * Projet:  wxClient
 * Auteur:  Nassim Boubziz (boubziznassim14@gmail.com)
 **************************************************************/
#include "Client.h"


Client::Client(wxString ip, long port,EvtFramePrincipal *frame)
{
    m_hote = ip;
    m_port=port;
    m_frame=frame;
    
    wxIPV4address socket;
    socket.Hostname(m_hote);
    socket.Service(m_port);
    m_client=new wxSocketClient();
    /*on se connecte sur le socket*/
    m_client->Connect(socket,false);
    /*on attend au maximum 10 secondes que la connexion s'établisse*/
    m_client->WaitOnConnect(10);
    /*on verifie le succée de la connection*/
    if(m_client->IsConnected())
    {
        m_client_connecte=true;
        string reponse=LitReponse();
        
        if (reponse==CONNEXION_OK)
        {
            wxString message(wxT(""));
            message << wxT("Connecté sur") <<m_hote
                    << wxT(",Port") << m_port;
        /*on demande a l'ihm d'afficher le message*/
        wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED,ID_CLIENT);
        MyEvent.SetString(message);
        wxPostEvent(m_frame, MyEvent);
        /*on connecte le gestionnaire d'événement a l'évenement socket*/
        //Connect(SOCKET_ID, wxEVT_SOCKET , wxSocketEventHandler(Client::OnSocketEvent ));
        
        /*on indique quel gestionnaire d'évenement utiliser*/
        m_client->SetEventHandler(*this, SOCKET_ID);
        /*sur un evenement socket perdu*/
        m_client->SetNotify(wxSOCKET_LOST_FLAG);
        /*on active les evenements sur ce socket*/
        m_client->Notify(true);
        }
        else if (reponse==NOMBRE_MAX_UTILISATEURS)
            {
                wxString message(wxT("PROBLEME d'entrée/sortie réseau: déconnexion"));
                message << m_hote <<wxT("\n");
                Deconnexion(message);
            }
        else if (reponse==CONNEXION_PAS_OK)
            {
                wxString message(wxT("PROBLÉME d'entrée/sortie réseau: Décinnexion"));
            }
        else
        {
            wxString message(wxT("PROBLÈME d'entrée/sortie réseau: Déconnexion"));
            Deconnexion(message);
        }
            //remplir avec les "else" qui serons necessaire
    }
}

Client::~Client()
{
    Close();
}

wxString Client::EcritMessage(wxString message)
{
    char *cstring;
    cstring=new char(message.Len()+3);
    strcpy(cstring, (const char*)message.mb_str(wxConvUTF8));
    //a remplir avec ce qui sera necessaire et en se concertant tout d'abord avec les autres
    m_client->Write(cstring, strlen(cstring));
    delete cstring;
    
    wxString reponse(LitReponse().c_str(), wxConvUTF8);
    return reponse;
}

//gestionnaire d'évenement pour le socket
void Client::OnSocketEvent(wxSocketEvent& event)
{
    //on peut récupérer le socket:
    //wxSocketBase *sock=event.GetSocket();
    switch (event.GetSocketEvent())
    {
        case wxSOCKET_LOST:
        {
            wxString message(wxT(""));
            message <<  wxT("Déconnexion du serveur situé sur ") <<  m_hote <<wxT(": il a disparu\n");
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

string Client::LitReponse()
{
    string reponse="";
    
    if (!m_client->Error())
    {
        unsigned char c=0;
        do
        {
            m_client->Read(&c, 1);
            reponse.push_back(c);
        } while (c != 0x0A); // jusqu'à le 'LF'
        // on retire le 'LF' et le 'CR'
        reponse.resize(reponse.length()-2);
    }
    else
    {
        reponse = CONNEXION_PAS_OK;
    }
    return reponse;
}

void Client::Deconnexion(wxString message)
{
    m_client_connecte=false;
    m_client->Destroy();
    
    wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED,ID_CLIENT/* voir ce quil y aura a mettre */);
    MyEvent.SetString(message);
    wxPostEvent(m_frame, MyEvent);
}

void Client::Close()
{
    if(m_client_connecte)
    {
        m_client->Close();
        m_client_connecte=false;
    }
}

void EvtFramePrincipal::EnvoiTrajectoire(wxCommandEvent& event)
{
    wxString requete(wxT(DEMANDE_TEST_TRAJECTOIRE));
    
}

void EvtFramePrincipal::EnvoiMouvements(wxCommandEvent& event)
{
    wxString requete(wxT(DEMANDE_TEST_MOUVEMENT));
    
    
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