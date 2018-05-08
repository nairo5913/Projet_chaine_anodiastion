#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_connecte = false;
    m_identifie = false;

    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = -1;
    widths[1] = 130;
    m_statusBar->SetStatusWidths(2, widths);
    m_statusBar->SetStatusText(wxT("Déconnecté"), 1);
}

void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
    // TODO: Implement OnFrameClose
    // Bloquer la fermeture de la fenêtre
    if(m_identifie)
    {
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
        m_textCtrlAffichage->AppendText(wxT("\nVeulliez vous déconnecter pour fermer la fentre !\n"));
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
    }
    else
    {
        Destroy();
    }
}

void EvtFramePrincipal::OnButtonConnexionToggle(wxCommandEvent& event)
{
    // TODO: Implement OnButtonConnexionTogglewxString message;
    wxString message;
    message << wxT("Identifiant : ") << m_textCtrlLogin->GetValue() << wxT("\nMot de passe : ")
            << m_textCtrlPass->GetValue() << wxT("\n");

    m_textCtrlAffichage->AppendText(message);

    if(!m_identifie)
    {
        if(VerificationLogin(m_textCtrlLogin->GetValue(), m_textCtrlPass->GetValue()))
        {
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxGREEN));
            m_textCtrlAffichage->AppendText(wxT("\n\tConnexion OK\n\n"));
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

            m_identifie = true;

            // S'occuper du client + test BdD

            // Désactivation des textCtrl de connexion
            m_textCtrlLogin->Disable();
            m_textCtrlPass->Disable();
            // Affichage des onglets de gestion des processus
            m_notebookProcessus->Show();
            // Changement du label du toggle button
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
            // Mise à jour de la statue bar
            m_statusBar->SetStatusText(wxT("Connecté"), 1);

            Layout();
        }
        else
        {
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
            m_textCtrlAffichage->AppendText(wxT("\n\tMauvais identifiant ou mot de passe !\n\n"));
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

            m_identifie = false;
        }
    }
    else
    {
        // Vérifier conection client (m_connecte)
        // Gérer déconnection du client
        // verifier que l'on a pas lancé de fabrication

        m_identifie = false;

        // Activation des textCtrl de connexion
        m_textCtrlLogin->Enable();
        m_textCtrlPass->Enable();
        // Masquage des onglets de gestion des processus
        m_notebookProcessus->Hide();
        // Changement du label du toggle button
        m_toggleBtnConnexion->SetValue(false);
        m_toggleBtnConnexion->SetLabel(wxT("Connexion"));
        // Mise à jour de la statue bar
        m_statusBar->SetStatusText(wxT("Déconnecté"), 1);
        // Vidange de l'affichage
        m_textCtrlAffichage->Clear();

        Layout();
    }
}

void EvtFramePrincipal::OnListBoxAffichageSelection(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxAffichageSelection
    m_textCtrlAffichage->AppendText(wxT("Selection liste affichage processus\n"));
    wxString selection = wxT("Votre séléction : ");
    selection << m_listBoxAffichageProcessus->GetStringSelection() << wxT("\n");
    m_textCtrlAffichage->AppendText(selection);
}

void EvtFramePrincipal::OnListBoxModifierSelection(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxModifierSelection
}

void EvtFramePrincipal::OnButtonModifierClick(wxCommandEvent& event)
{
    // TODO: Implement OnButtonModifierClick
}

void EvtFramePrincipal::OnApplyButtonModifierClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonModifierClick
}

void EvtFramePrincipal::OnCancelButtonModiffierClick(wxCommandEvent& event)
{
    // TODO: Implement OnCancelButtonModiffierClick
}

void EvtFramePrincipal::OnCancelButtonCreerClick(wxCommandEvent& event)
{
    // TODO: Implement OnCancelButtonCreerClick
}

void EvtFramePrincipal::OnSaveButtonCreerClick(wxCommandEvent& event)
{
    // TODO: Implement OnSaveButtonCreerClick
}

void EvtFramePrincipal::OnListBoxDetruireSelection(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxDetruireSelection
    m_textCtrlAffichage->AppendText(wxT("Selection liste détruire processus\n"));
    wxString selection = wxT("Votre séléction : ");
    selection << m_listBoxDetruireProcessus->GetStringSelection() << wxT("\n");
    m_textCtrlAffichage->AppendText(selection);

    wxString message;
    message << wxT("Vous allez détruire le ") << m_listBoxDetruireProcessus->GetStringSelection() << wxT(" !\n");
    m_staticTextDetruire->SetLabel(message);

    Layout();
}

void EvtFramePrincipal::OnApplyButtonDetruireClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonDetruireClick
}

void EvtFramePrincipal::OnListBoxLancerSelection(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxLancerSelection
}

void EvtFramePrincipal::OnOkButtonLancerClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonLancerClick
}

void EvtFramePrincipal::OnButtonViderAffichageClick(wxCommandEvent& event)
{
    // TODO: Implement OnButtonViderAffichageClick
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::OnMenuQuitterSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuQuitterSelection
    Destroy();
}

void EvtFramePrincipal::OnMenuAideSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuAideSelection
}

void EvtFramePrincipal::OnMenuAproposSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuAproposSelection
}

bool EvtFramePrincipal::VerificationLogin(wxString login, wxString pass)
{
    wxString identifiant = wxT("Responsable");
    wxString motpasse = wxT("responsable");
    bool retour = false;

    if(identifiant == login && motpasse == pass)
    {
        retour = true;
    }

    return retour;
}
