/*******************************************************************************
 *  Fichier:  Serveur.h
 *  Projet:   Chaîne d'anodisation - Test du client pour le PC responsable 
              de production avec un serveur
 *  Crée le:  14/04/2018
 *  Utilité:  Gestion de la partie serveur réseau
 *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef SERVEUR_H
#define SERVEUR_H

#include "EvtFramePrincipal.h"
class EvtFramePrincipal;
#include "DonneesClient.h"
#include "Protocoles.h"

#include <wx/socket.h>
#include <wx/log.h>
#include <map>
using namespace std;

enum
{
  // id pour les sockets
  SERVER_ID = 201,
  SOCKET_ID
};

class Serveur : public wxEvtHandler
{
    public:
        Serveur(EvtFramePrincipal *frame, long port, int maxclients=0);
        ~Serveur();
        bool IsOK(){return m_serveur_running;};
        void SetBrasDispo(bool etat){m_bras_dispo = etat;};
        bool GetBrasDispo(){return m_bras_dispo;};
        void SetTache(wxString tache){m_tache = tache;};
        void SetIdTache(wxString id_tache){m_id_tache = id_tache;};
        void Close();
    protected:
    private:
        EvtFramePrincipal *m_frame;
        wxSocketServer *m_serveur;
        bool m_serveur_running;
        bool m_bras_dispo;
        int m_nombreClients;
        int m_nombreMaxClients;
        long m_port;
        typedef map <int,DonneesClient*> DONNEES_CLIENT_MAP;
        DONNEES_CLIENT_MAP m_donnees_client_map;
        wxString m_tache;
        wxString m_id_tache;
        
        int RetireClient(wxSocketBase *sock);
        int TrouveNumeroClientLibre();
        void OnServerEvent(wxSocketEvent& event);
        void OnSocketEvent(wxSocketEvent& event);
        void DecodeMessage (wxString message, wxSocketBase *sock, DonneesClient *donnes);
        void EcritReponse(wxSocketBase *sock, string reponse);
        void AfficheNombreClients();
        void AfficheMessage(wxString message);
        void AfficheReponse(wxString reponse);
        wxString LitMessage(wxSocketBase *sock);
};

#endif // SERVEUR_H
