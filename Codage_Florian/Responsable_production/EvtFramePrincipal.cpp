/*******************************************************************************
  *  Fichier:  EvtFramePrincipal.h
  *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
  *  Crée le:  29/04/2018
  *  Utilité:  Gestion des événements du frame principal
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_connecte = false;
    m_identifie = false;
    m_fabrication = false;

    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = -1;
    widths[1] = 130;
    m_statusBar->SetStatusWidths(2, widths);
    m_statusBar->SetStatusText(wxT("Déconnecté"), 1);

    // Connexion des événements du client
    Connect(ID_CLIENT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheInfoClient), NULL,
            this);
    Connect(ID_CLIENT + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessageClient),
            NULL, this);
    Connect(ID_CLIENT + 2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AgitServeurPerdu),
            NULL, this);
}

void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
    // TODO: Implement OnFrameClose
    // Bloquer la fermeture de la fenêtre
    if(m_fabrication)
    {
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
        m_textCtrlAffichage->AppendText(wxT("\nVeulliez attendre la fin de la fabrication en cours!\n"));
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
    }
    else
    {
        if(m_connecte)
        {
            DeconnexionClient(wxT("Déconnexion depuis le client"));
        }

        Destroy();
    }
}

void EvtFramePrincipal::OnButtonConnexionToggle(wxCommandEvent& event)
{
    // TODO: Implement OnButtonConnexionTogglewxString message;
    /*wxString message;
    message << wxT("Identifiant : ") << m_textCtrlLogin->GetValue() << wxT("\nMot de passe : ")
    << m_textCtrlPass->GetValue() << wxT("\n");

    m_textCtrlAffichage->AppendText(message);*/

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
    // m_textCtrlAffichage->AppendText(wxT("Selection liste affichage processus\n"));
    wxString selection = wxT("Votre séléction : ");
    selection << m_listBoxAffichageProcessus->GetStringSelection() << wxT("\n");
    m_textCtrlAffichage->AppendText(selection);
}

void EvtFramePrincipal::OnListBoxModifierSelection(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxModifierSelection
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
    message << m_listBoxDetruireProcessus->GetStringSelection() << wxT("\n");
    m_staticTextDetuireTitre->SetLabel(message);

    Layout();
}

void EvtFramePrincipal::OnApplyButtonDetruireClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonDetruireClick
}

void EvtFramePrincipal::OnListBoxLancerSelection(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxLancerSelection
    m_textCtrlAffichage->AppendText(wxT("Selection liste détruire processus\n"));
    wxString selection = wxT("Votre séléction : ");
    selection << m_listBoxLancerProcessus->GetStringSelection() << wxT("\n");
    m_textCtrlAffichage->AppendText(selection);

    wxString message;
    message << m_listBoxLancerProcessus->GetStringSelection() << wxT("\n");
    m_staticTextLancerTitre->SetLabel(message);

    Layout();
}

void EvtFramePrincipal::OnOkButtonLancerClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonLancerClick
}

void EvtFramePrincipal::OnListBoxTesterSelection(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxTesterSelection
}

void EvtFramePrincipal::OnStopButtonTesterClick(wxCommandEvent& event)
{
    // TODO: Implement OnStopButtonTesterClick
}

void EvtFramePrincipal::OnOkButtonTesterClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonTesterClick
}

void EvtFramePrincipal::OnButtonDisponibiliteBrasClick(wxCommandEvent& event)
{
    // TODO: Implement OnButtonDisponibiliteBrasClick
    //
    // if else avec la requete au client
    //
    // m_panelBrasDisponible->Hide();
    m_panelBrasIndisponible->Show();

    Layout();
}

void EvtFramePrincipal::OnButtonTacheEnCoursClick(wxCommandEvent& event)
{
    // TODO: Implement OnButtonTacheEnCoursClick
    //
    // if else avec la requete au client
    //
    // m_panelPasTache->Hide();
    m_panelTacheEnCours->Show();

    Layout();
}

void EvtFramePrincipal::OnButtonViderAffichageClick(wxCommandEvent& event)
{
    // TODO: Implement OnButtonViderAffichageClick
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::OnMenuQuitterSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuQuitterSelection
    if(m_fabrication)
    {
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
        m_textCtrlAffichage->AppendText(wxT("\nVeulliez attendre la fin de la fabrication en cours!\n"));
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
    }
    else
    {
        if(m_connecte)
        {
            DeconnexionClient(wxT("Déconnexion depuis le client"));
        }

        Destroy();
    }
}

void EvtFramePrincipal::OnMenuViderAffichageSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuViderAffichageSelection
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::OnMenuAideSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuAideSelection
    EvtFrameAide* frame_aide = new EvtFrameAide(this);
    frame_aide->Show();
}

void EvtFramePrincipal::OnMenuAproposSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuAproposSelection
    EvtFrameApropos* frame_apropos = new EvtFrameApropos(this);
    frame_apropos->Show();
}
//
////////////////////////////////////////////////////////////////////////////////
//  Méthode du programme
////////////////////////////////////////////////////////////////////////////////
//
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
//
// Partie client de communication
//
void EvtFramePrincipal::AfficheMessageClient(wxCommandEvent& event)
{
    // Affiche dans le log l'événement
    m_textCtrlAffichage->AppendText(event.GetString());
}

void EvtFramePrincipal::AfficheInfoClient(wxCommandEvent& event)
{
    // Affiche dans la barre de statusbar l'événement
    m_statusBar->SetStatusText(event.GetString(), 0);
}

void EvtFramePrincipal::DeconnexionClient(wxString message)
{
    m_client->Close();
    m_connecte = false;
    delete m_client;

    // Affichage du message
    message << wxT("\n");

    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
    m_textCtrlAffichage->AppendText(message);
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

    // Mise à jour de l'IHM
    // m_statusBar->SetStatusText(wxT("Déconnecté"), 0);
}

void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    DeconnexionClient(event.GetString());
}
