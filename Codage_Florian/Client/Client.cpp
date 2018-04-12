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
    
    // Vérification du succès de la connection
    if(m_client->IsConnected())
    {
        
    }
    else
    {
        m_client_connecte = false;
        delete m_client;
    }
}

Client::~Client()
{
    // Destructeur
}

