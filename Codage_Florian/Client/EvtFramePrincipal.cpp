#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent )
:
FramePrincipal( parent )
{
    m_connecte=false;
    m_statusBar->SetStatusText(wxT("Déconnecté"),0);
    m_panelParametresConnexion->Hide();

    // Connexion des événements pouvant venir du client
    Connect( ID_CLIENT, wxEVT_COMMAND_BUTTON_CLICKED ,
            wxCommandEventHandler( EvtFramePrincipal::AfficheInfoClient ), NULL, this );
    Connect( ID_CLIENT+1, wxEVT_COMMAND_BUTTON_CLICKED ,
            wxCommandEventHandler( EvtFramePrincipal::AfficheMessageClient ), NULL, this );
    Connect( ID_CLIENT+2, wxEVT_COMMAND_BUTTON_CLICKED ,
            wxCommandEventHandler( EvtFramePrincipal::AgitServeurPerdu ), NULL, this );
}

void EvtFramePrincipal::OnFrameClose( wxCloseEvent& event )
{
    // Gestion de la fermeture de la fenetre
    // penser à bloquer la fermeture pour la suite du projet surtout si fabrication
    if (m_connecte)
    {
        m_client->Close();
        delete m_client;
    }
    
    Destroy();
}

void EvtFramePrincipal::OnButtonConnexionToggle( wxCommandEvent& event )
{
    // TODO: Implement OnButtonConnexionToggle
}

void EvtFramePrincipal::OnClickButtonEnvoyer( wxCommandEvent& event )
{
    // TODO: Implement OnClickButtonEnvoyer
    m_textCtrlAffichage->AppendText(wxT("Bouton envoyer \n"));
}

void EvtFramePrincipal::OnTextEnterSaisie( wxCommandEvent& event )
{
    // TODO: Implement OnTextEnterSaisie
}


void EvtFramePrincipal::AfficheMessageClient(wxCommandEvent& event)
{
    // Affiche dans le log l'événement
    m_textCtrlAffichage->AppendText(event.GetString());
}

void EvtFramePrincipal::Deconnexion(wxString message)
{
    
}

void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    
}

void EvtFramePrincipal::GereReponse(wxString reponse, wxString reponse_attendue)
{
    
}

void EvtFramePrincipal::AfficheInfoClient(wxCommandEvent& event)
{
    // Affiche dans la barre de statusbar l'événement
    m_statusBar->SetStatusText(event.GetString(),0);
}

void EvtFramePrincipal::OnToggleButton( wxCommandEvent& event )
{
    m_textCtrlAffichage->AppendText(wxT("Toggle Button"));
    
    if(!m_connecte)
    {
        long port = 30000;
        // Test en local
        wxString ip = wxT("localhost");
        // Adresse de la Raspberry
        //wxString ip = wxT("192.168.1.249");
        
        //m_client = new Client(m_textCtrlSaisieHote->GetValue(), port, this);
        m_client = new Client(ip, port, this);
        m_connecte = m_client->IsOK();
        
        if(m_connecte)
        {
            m_panelSaisie->Show();
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
            //m_panelParametresConnexion->Hide();
            Layout();
        }
        else
        {
            m_textCtrlAffichage->AppendText(wxT("Connexion impossible, vérifiez que le serveur est bien lancé...\n"));
            m_toggleBtnConnexion->SetValue(false);
            
        }
    }
    else
    {
        Deconnexion(wxT("Déconnexion depuis le client"));
    }
}