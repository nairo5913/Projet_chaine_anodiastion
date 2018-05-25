#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent)
    :
    FramePrincipal(parent)
{
    m_connecte = false;

    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = 185;
    widths[1] = -1;
    m_statusBar->SetStatusWidths(2, widths);
    m_statusBar->SetStatusText(wxT("Serveur déconnecté"), 0);

    sbSizerGestion->Hide(true);
    sbSizerGestion->Layout();
    Layout();
}

void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
    if(m_connecte)
    {
        m_serveur->Close();
        delete m_serveur;
    }

    Destroy();
}

void EvtFramePrincipal::OnButtonDemarrerServeurToggle(wxCommandEvent& event)
{
    if(!m_connecte)
    {
        long port = 30000;

        m_serveur = new Serveur(this, port, 2);
        m_connecte = m_serveur->IsOK();

        if(m_connecte)
        {
// on connecte les événements venant du serveur
            Connect(ID_SERVEUR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::MAJnombreClients), NULL, this);
            Connect(ID_SERVEUR + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessageServeur), NULL, this);

            m_statusBar->SetStatusText(wxT("Serveur connecté"), 0);
            m_buttonViderAffichage->Show();
            
            m_textCtrlAffichage->Clear();
            
            sbSizerGestion->Show(true);
            sbSizerGestion->Layout();
            Layout();
        }
        else
        {
            wxString message("");
            message.Printf("ERREUR ! : Le serveur n'a pas pu démarrer sur le port %ld\n", port);

            m_textCtrlAffichage->AppendText(message);
            delete m_serveur;
        }
    }
}

void EvtFramePrincipal::OnButtonClickViderAffichage(wxCommandEvent& event)
{
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::OnToggleButtonDisponibiliteClick(wxCommandEvent& event)
{
    if(m_toggleBtnDisponibilite->GetValue())
    {
        m_textCtrlAffichage->AppendText(wxT("Bras disponible\n"));
        m_serveur->SetBrasDispo(true);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Bras non disponible\n"));
        m_serveur->SetBrasDispo(false);
        
        m_toggleBtnDisponibilite->SetValue(false);
        m_toggleBtnDisponibilite->SetLabel(wxT("Changer la disponibilité du bras\nen non disponible"));
    }
}


void EvtFramePrincipal::AfficheMessageServeur(wxCommandEvent& event)
{
    // affiche dans le log sur événement du serveur
    m_textCtrlAffichage->AppendText(event.GetString());
}

void EvtFramePrincipal::MAJnombreClients(wxCommandEvent& event)
{
    // affiche dans la statusbar sur événement du serveur
    m_statusBar->SetStatusText(event.GetString(), 1);
}
