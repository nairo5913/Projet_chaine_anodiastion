/*******************************************************************************
 *  Fichier:  Client.h
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  29/04/2018
 *  Utilité:  Gestion du client
 *  Auteur:   Florian Provost
              Nassim Boubziz
*******************************************************************************/
#ifndef CLIENT_H
#define CLIENT_H

#define SOCKET_ID 110

class EvtFramePrincipal;
#include <wx/socket.h>
#include <string>
using std::string;
#include <vector>
using std::vector;

class Client : public wxEvtHandler
{
    public:
        Client(wxString ip, long port, EvtFramePrincipal *frame, wxString utilisateur);
        ~Client();
        bool IsOK(){return m_client_connecte;};
        
        bool DemandeDisponibiliteBras();
        vector<string> DemandeTacheEnCours();
        string EcritMessage(wxString message);
        //void AnalyseReponseServeur(string reponse);
        void Close();
        void ExecutionProcessus(wxString num_id);
        void StopTestMouvement(wxString num_id);
        void StopProcessus();
        void StopTestTrajectoire(wxString num_id);
        void TestMouvement(wxString num_id);
        void TestProcessus(wxString num_id);
        void TestTrajectoire(wxString num_id);
        
    
    protected:
    private:
        EvtFramePrincipal *m_frame;
        wxSocketClient *m_client;
        bool m_client_connecte;
        int m_etat_actuel;
        int m_port;
        wxString m_hote;
        
        bool Identification(wxString utilisateur);
        string LitReponse();
        void AfficheMessage(wxString message);
        void Deconnexion(wxString message);
        void OnSocketEvent(wxSocketEvent& event);
};

#endif // CLIENT_H
