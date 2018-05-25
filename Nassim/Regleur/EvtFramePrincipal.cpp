#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_client_connecte = false;
    m_statusBar->SetStatusText(wxT("Déconnecté"), 0);
    // m_panelParametresConnexion->Hide();

    // Connexion des événements pouvant venir du client
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
}

void EvtFramePrincipal::OnButtonConnexionToggle(wxCommandEvent& event)
{
    /*wxString message;
    
    message << wxT("Identifiant : ") << m_textCtrlLogin->GetValue() << wxT("\nMot de passe : ")
    << m_textCtrlPass->GetValue() << wxT("\n");
    
    wxLogDebug(message);*/

    if(!m_identifie)
    {
        if(VerificationLogin(m_textCtrlLogin->GetValue(), m_textCtrlPass->GetValue()))
        {
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxGREEN));
            m_textCtrlAffichage->AppendText(wxT("\n\tIdentification OK\n\n"));
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

            m_identifie = true;
            
            // Désactivation des textCtrl de connexion
            m_textCtrlLogin->Disable();
            m_textCtrlPass->Disable();
            // Affichage des onglets de gestion des processus
            //PREVOIR AFFICHAGE DES DEUX BOUTTON POUR LE NOTEBOOK
            // Changement du label du toggle button
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));

            Layout();
            
            wxString message;
            bool erreur = false;
            
            // Tester connexion à la BdD
            if(m_bdd_anodisation->IsConnexionOK())
            {
                m_bdd_connecte = true;
                m_textCtrlAffichage->AppendText(wxT("Connecté à la BdD.\n"));
            }
            else
            {
                message.clear();
                message << wxT("\t Erreur lors de la connection à la base de données.\n")
                        << wxT("\n") << wxT("Raison : ")
                        << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");
                
                erreur = true;
            }
            
            m_client = new Client("localhost", 30000, this);
            m_client_connecte = m_client->IsOK();
            
            // Tester la connection du client de communication
            if(m_client_connecte)
            {
                m_client_connecte = true;
                m_textCtrlAffichage->AppendText(wxT("Connecté au client de communication.\n"));
            }
            else
            {
                message << wxT("\t Erreur lors de la connection au client de communication.\n");
                
                erreur = true;
            }
            
            // Mise à jour de la barre de statu en fonction de la connexion
            if(m_bdd_connecte && !m_client_connecte)
            {
                AfficheStatus(wxT("Connecté à la bdd"), 1);
            }
            else if(!m_bdd_connecte && m_client_connecte)
            {
                AfficheStatus(wxT("Connecté au client"), 1);
            }
            else if(m_bdd_connecte && m_client_connecte)
            {
                
                AfficheStatus(wxT(""), 0);
                AfficheStatus(wxT("Connecté"), 1);
            }
            else 
            {
                AfficheStatus(wxT("Non connecté"), 1);
            }
            
            // Si il y a une erreur de connection l'afficher
            if(erreur)
            {
                m_textCtrlAffichage->AppendText(message);
                wxLogError(message);
            }
            
            // Remplir la liste des processus
            RempliListBox();
            
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
        if(m_client_connecte)
        {
            DeconnexionClient(wxT("Déconnexion du responsable"));
        }
        // Gérer déconnection du client
        // verifier que l'on a pas lancé de fabrication

        m_identifie = false;

        // Activation des textCtrl de connexion
        m_textCtrlLogin->Enable();
        m_textCtrlPass->Enable();
        
        // Vider les listBox pour éviter les problème si on se reconnecte sans fermer l'application
        VideListBox();
        
        // Masquage des onglets de gestion des processus
        m_notebookProcessus->Hide();
        
        // Changement du label du toggle button
        m_toggleBtnConnexion->SetValue(false);
        m_toggleBtnConnexion->SetLabel(wxT("Connexion"));
        
        // Mise à jour de la statue bar
        AfficheStatus(wxT("Déconnecté"), 1);
        
        // Vidange de l'affichage
        m_textCtrlAffichage->Clear();

        Layout();
    }
}

void EvtFramePrincipal::OnButtonChoixTrajectoiresClicks(wxCommandEvent& event)
{
    // TODO: Implement OnButtonChoixTrajectoiresClicks
}

void EvtFramePrincipal::OnButtonChoixMouvementsClicks(wxCommandEvent& event)
{
    // TODO: Implement OnButtonChoixMouvementsClicks
}

void EvtFramePrincipal::OnListBoxAffichageSelectionMouvements(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxAffichageSelectionMouvements
}

void EvtFramePrincipal::OnListBoxModifierSelectionMouvements(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxModifierSelectionMouvements
}

void EvtFramePrincipal::OnApplyButtonModifierMouvementClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonModifierMouvementClick
}

void EvtFramePrincipal::OnCancelButtonModifierMouvementClick(wxCommandEvent& event)
{
    // TODO: Implement OnCancelButtonModifierMouvementClick
}

void EvtFramePrincipal::OnSaveButtonCreerMouvementClick(wxCommandEvent& event)
{
    // TODO: Implement OnSaveButtonCreerMouvementClick
}

void EvtFramePrincipal::OnListBoxDetruireSelectionMouvements(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxDetruireSelectionMouvements
}

void EvtFramePrincipal::OnYesButtonDetruireMouvementClick(wxCommandEvent& event)
{
    // TODO: Implement OnYesButtonDetruireMouvementClick
}

void EvtFramePrincipal::OnListBoxTesterSelectionMouvements(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxTesterSelectionMouvements
}

void EvtFramePrincipal::OnYesButtonTesterMouvementClick(wxCommandEvent& event)
{
    // TODO: Implement OnYesButtonTesterMouvementClick
}

void EvtFramePrincipal::OnListBoxAffichageSelectionTrajectoires(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxAffichageSelectionTrajectoires
}

void EvtFramePrincipal::OnListBoxModifierSelectionTrajectoires(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxModifierSelectionTrajectoires
}

void EvtFramePrincipal::OnApplyButtonModifierTrajectoiresClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonModifierTrajectoiresClick
}

void EvtFramePrincipal::OnCancelButtonModifierTrajectoiresClick(wxCommandEvent& event)
{
    // TODO: Implement OnCancelButtonModifierTrajectoiresClick
}

void EvtFramePrincipal::OnSaveButtonCreerTrajectoiresClick(wxCommandEvent& event)
{
    // TODO: Implement OnSaveButtonCreerTrajectoiresClick
}

void EvtFramePrincipal::OnListBoxDetruireSelectionTrajectoires(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxDetruireSelectionTrajectoires
}

void EvtFramePrincipal::OnYesButtonDetruireTrajectoiresClick(wxCommandEvent& event)
{
    // TODO: Implement OnYesButtonDetruireTrajectoiresClick
}

void EvtFramePrincipal::OnListBoxTesterSelectionTrajectoires(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxTesterSelectionTrajectoires
}

void EvtFramePrincipal::OnYesButtonTesterTrajectoiresClick(wxCommandEvent& event)
{
    // TODO: Implement OnYesButtonTesterTrajectoiresClick
}

void EvtFramePrincipal::OnButtonViderAffichageClick(wxCommandEvent& event)
{
    // TODO: Implement OnButtonViderAffichageClick
}
void EvtFramePrincipal::Deconnexion(wxString reponse)
{
    m_client->Close();
    m_connecte = false;
    delete m_client;

    reponse << wxT("\n");
    m_textCtrlAffichage->Clear();
    m_textCtrlAffichage->AppendText(reponse);

    // Mise à jour de l'IHM
    m_toggleBtnConnexion->SetValue(false);
    m_panelSaisie->Hide();
    m_toggleBtnConnexion->SetLabel(wxT("Connexion"));
    m_statusBar->SetStatusText(wxT("Déconnecté"), 0);
    Layout();
}

dit