#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = -1; widths[1] = 130;
    m_statusBar->SetStatusWidths(2, widths);
    
    AfficheStatus(wxT("Déconnecté"), 1);
    
    m_bdd_anodisation = NULL;
}

void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
    // TODO: Implement OnFrameClose
    Destroy();
}

void EvtFramePrincipal::OnToggleButtonConnexion(wxCommandEvent& event)
{
    // TODO: Implement OnToggleButtonConnexion
    // On éfface le log
    m_textCtrlAffichage->Clear();
    
    if(m_toggleBtnConnexion->GetValue() == true)
    {
        string strconnexion(m_textCtrlDSN->GetValue().mb_str());
        
        m_bdd_anodisation = new DataAnodisation(strconnexion);
        
        // vérifier l'état de la connection
        if (m_bdd_anodisation->IsConnexionOK())
        {
            AfficheStatus(wxT("Connecté !"), 1);
            
            // Modifier le label du bouton de connexion
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
            
            // Désactivation de la zone de saisie du DSN
            m_textCtrlDSN->Disable();
            
            // Affichage du panel
            m_scrolledWindowRequete->Show();
            
            Layout();
        }
        else
        {
            AfficheStatus(wxT("Erreur de connexion"), 0);
            
            wxString erreur(m_bdd_anodisation->GetLastError().c_str(), wxConvUTF8);
            AfficheResultat(erreur);
            
            // Relâcher le bouton de connexion
            m_toggleBtnConnexion->SetValue(false);
            
        }
    }
    else
    {
        delete m_bdd_anodisation;
        m_bdd_anodisation = NULL;
        
        // Mise à jour de l'affichage
        AfficheStatus(wxT("Déconnecté"), 1);
        AfficheStatus(wxT(""),0);
        m_toggleBtnConnexion->SetLabel(wxT("Connexion"));
        
        m_textCtrlDSN->Enable();
        m_scrolledWindowRequete->Hide();
        
        Layout();
    }
    
}

void EvtFramePrincipal::OnButtonClickSelection(wxCommandEvent& event)
{
    // TODO: Implement OnButtonClickSelection
}

void EvtFramePrincipal::OnButtonClickInsertion(wxCommandEvent& event)
{
    // TODO: Implement OnButtonClickInsertion
}

void EvtFramePrincipal::OnButtonClickMAJ(wxCommandEvent& event)
{
    // TODO: Implement OnButtonClickMAJ
}

void EvtFramePrincipal::OnButtonClickSuppression(wxCommandEvent& event)
{
    // TODO: Implement OnButtonClickSuppression
}

void EvtFramePrincipal::OnMenuQuitterSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuQuitterSelection
    Destroy();
}

void EvtFramePrincipal::OnMenuAideSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuAideSelection
    EvtMyDialogAide* dialog_aide = new EvtMyDialogAide(0);
    dialog_aide->Show();
}

void EvtFramePrincipal::AfficheStatus(wxString texte, int position)
{
    m_statusBar->SetStatusText(texte, position);
}

void EvtFramePrincipal::AfficheResultat(wxString texte)
{
    m_textCtrlAffichage->AppendText(texte);
}