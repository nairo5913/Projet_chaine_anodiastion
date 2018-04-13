#ifndef CLIENT_H
#define CLIENT_H
#include <wx/socket.h>
#include <EvtFramePrincipal.h>
#define SOCKET_ID ???
#include <string>
using std::string;

class Client
{
public:
    Client(wxString ip, long port, EvtFramePrincipal *frame );
    ~Client();
    bool IsOK(){return m_client_connecte;};
    wxString EcritMessage(wxString message);
    void Close();

    protected:
    private:
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
