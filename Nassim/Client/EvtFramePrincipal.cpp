#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent )
:
FramePrincipal( parent )
{
    m_connecte=false;
    m_statusBar->SetStatusText(wxT("Déconnecté..."),0);

    Connect( ID_CLIENT,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal::ConnexionServeur), NULL,this );
    Connect( ID_CLIENT+1,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal::EnvoiReception), NULL,this );
    Connect( ID_CLIENT+2,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal::Execution), NULL,this );
    Connect( ID_CLIENT+3,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal::Erreur), NULL,this );
    Connect( ID_CLIENT+4,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal::Information), NULL,this );
    Connect( ID_CLIENT+5,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal::Deconnexion), NULL,this );
    /*a ajouté en fonction des evenement possiblement realisable*/
}

void EvtFramePrincipal::OnButtonConnexionToggle( wxCommandEvent& event )
{
if (!m_connecte)
/*si on est pas ocnnecté on verifie les info de connexion avant dessaye de se co*/
{
long port=30000;
wxString ip=wxT("localhost");
m_client=new Client(ip,port,this);
m_connecte=m_client->IsOK();
}
else
{
Deconnexion((wxT("Déconnexion depuis le client")));
}
}

void EvtFramePrincipal::OnClickButtonSaisie( wxCommandEvent& event )
{
// TODO: Implement OnClickButtonSaisie
}


void EvtFramePrincipal::ConnexionServeur(wxCommandEvent& event)
{
    wxString requete(wxT("100"));
    
}

void EvtFramePrincipal::EnvoiReception(wxCommandEvent& event)
{
    wxString requete(wxT("200-"));
}

void EvtFramePrincipal::Information(wxCommandEvent& event)
{
    wxString requete(wxT("500-"));
    
}

void EvtFramePrincipal::Deconnexion(wxCommandEvent& event)
{
    wxString requete(wxT("600-"));
    
}

void EvtFramePrincipal::GereReponse(wxString reponse, wxString reponse_attendue)
{
    wxString reste(wxT(""));
    if (reponse.StartsWith(reponse_attendue,&reste))
    // réponse correcte
    {
        wxString message(wxT("Le serveur a retourné: "));
        message<<reste<<wxT("\n");
        m_textCtrlLog->AppendText(message);
    }
    else if (reponse.IsSameAs(wxT("404")))
    // commande inconnue
    {
        // on ne devrait normalement pas arriver ici...
        wxLogWarning(wxT("Le serveur a retourné: Commande inconnue..."));
    }
    else if (reponse.IsSameAs(wxT("102-")))
    // erreur réseau
    {
        Deconnexion(wxT("PROBLÈME d'entrée/sortie réseau: Déconnexion"));
    }
    else
    {
        // on ne devrait jamais arriver ici...
        wxLogWarning(wxT("Le serveur a retourné une valeur non prévue dans le protocole!!!"));
    }
}

void EvtFramePrincipal::OnFrameClose( wxCloseEvent& event )
{
    if (m_connecte)
    {
        m_client->Close();
        delete m_client;
    }
    Destroy();
}

void EvtFramePrincipal::Erreur(wxCommandEvent& event)
{
    wxString requete(wxT("400"));
}