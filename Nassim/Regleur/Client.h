#ifndef CLIENT_H
#define CLIENT_H
#include <vector>
#include <wx/socket.h>
#include "EvtFramePrincipal.h"
class EvtFramePrincipal;
#define SOCKET_ID 110
#include <string>
using std::string;
using std::vector;
#include "Protocole.h"

using std::string;

class Client : public wxEvtHandler
{
public:
    Client(wxString ip, long port, EvtFramePrincipal *frame );
    ~Client();
    bool IsOK(){return m_client_connecte;};
    string EcritMessage(wxString message);
    void Close();
    bool DemandeDisponibiliteBras();
    vector<string> DemandeTacheEnCours();
    void TestMouvement(wxString num_id); 
    void TestTrajectoire(wxString num_id);
    void StopTestMouvement(wxString num_id);
    void StopTestTrajectoire(wxString num_id);
    
    protected:
    
    private:
        bool Identification(wxString utilisateur);
        wxString m_hote;
        int m_port;
        EvtFramePrincipal *m_frame;
        bool m_client_connecte;
        wxSocketClient *m_client;
        void OnSocketEvent(wxSocketEvent& event);
        int m_etat_actuel;
    
    string LitReponse();
    void Deconnexion(wxString message);
};

#endif // CLIENT_H
