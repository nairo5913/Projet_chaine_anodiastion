/***************************************************************
 * Nom:     Client.cpp
 * Projet:  wxClient
 * Auteur:  Nassim Boubziz (boubziznassim14@gmail.com)
 **************************************************************/
#include "Client.h"


Client::Client(wxString ip, long port,EvtFramePrincipal *frame)
{
    m_hote_ip;
    m_port=port;
    m_frame=frame;
    wxIPV4address socket;
    socket.Hostname(m_hote);
    socket.Service(m_port);
    m_cliant=new wxSocketClient();
    m_client->Connect(socket,false);
    m_client->WaitOnConnect(???);
    if(m_client->IsConnected())
        {
            m_client_connecte=true;
            string reponse=LitReponse();
            if (reponse=="???")
            {
                wxString message(wxT(""));
                message << wxT("Connecté sur") <<m_hote
                        << wxT(",Port") << m_port;
                        
            wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED,ID_CLIENT);
            MyEvent.SetString(message);
            wxPostEvent(m_frame, MyEvent);
            
            Connect( SOCKET_ID, wxEVT_SOCKET , wxSocketEventHandler(Client::OnSocketEvent ));
            
            m_client->SetEventHandler((*this, SOCKET_ID));
            
            m_client->SetNotify(wxSOCKET_LOST_FLAG);
            
            m_client->Notify(true);
            }
            else if (reponse=="???")
                {
                    wxString message(wxT("PROBLEME d'entrée/sortie réseau: déconnexion"));
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
    
    wxString reponse(Litreponse().c_str(), wxConvUTF8);
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
        unsigned char c;
        do
        {
            m_client->Read(/*&c, 1*/);
            reponse.push_back(c);
        } while ()
            reponse.resize(reponse./*a voir */());
            
    }
    else
        reponse = "???";
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
        m_client->Close()
        m_client_connecte=false;
    }
}


