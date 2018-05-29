#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_client_connecte = false;
    m_bdd_connecte = false;
    m_identifie = false;
    m_bdd_anodisation = new DataAnodisation("Anodisation");
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
    Destroy();
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
            // PREVOIR AFFICHAGE DES DEUX BOUTTON POUR LE NOTEBOOK
            // Changement du label du toggle button
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
            m_panelChoix->Show();
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
                message << wxT("\t Erreur lors de la connection à la base de données.\n") << wxT("\n")
                        << wxT("Raison : ") << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");

                erreur = true;
            }

            m_client = new Client("192.168.1.16", 30000, this);
            // m_client_connecte = m_client->IsOK();

            // Tester la connection du client de communication
            if(m_client->IsOK())
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
            VideListBoxMouvements();
            VideListBoxTrajectoires();
            RempliListBoxMouvements();
            RempliListBoxTrajectoires();
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
            DeconnexionClient(wxT("Déconnexion du régleur"));
        }
        // Gérer déconnection du client
        // verifier que l'on a pas lancé de fabrication

        m_identifie = false;

        // Activation des textCtrl de connexion
        m_textCtrlLogin->Enable();
        m_textCtrlPass->Enable();

        // Vider les listBox pour éviter les problème si on se reconnecte sans fermer l'application
        void VideListBoxMouvements();
        void VideListBoxTrajectoires();

        // Masquage des onglets de gestion des processus
        m_notebookMouvements->Hide();
        m_notebookTrajectoires->Hide();

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
    m_notebookTrajectoires->Show();
    m_notebookMouvements->Hide();
    Layout();
}

void EvtFramePrincipal::OnButtonChoixMouvementsClicks(wxCommandEvent& event)
{
    m_notebookTrajectoires->Hide();
    m_notebookMouvements->Show();
    Layout();
}

void EvtFramePrincipal::OnListBoxAffichageSelectionMouvements(wxCommandEvent& event)
{
    wxString selection = m_listBoxAffichageMouvements->GetStringSelection();

    // Récupération de l'id du mouvement
    wxString id_selection = GardeIdSelection(selection);

    m_textCtrlAffichage->AppendText(selection + wxT("\nid selection :") + id_selection + wxT("\n"));

    m_textCtrlDureeHeureAfficherMouvements->Clear();
    m_textCtrlDureeMinuteAfficherMouvements->Clear();
    m_textCtrlDureeSecondeAfficherMouvements->Clear();
    m_textCtrlNomAfficherMouvements->Clear();
    m_textCtrlxAfficherMouvements->Clear();
    m_textCtrlyAfficherMouvements->Clear();
    m_textCtrlzAfficherMouvements->Clear();

    if(m_bdd_anodisation->RecupereNomMouvement(ConversionEnString(id_selection)))
    {
        wxString nom = ConversionEnWxString(m_bdd_anodisation->GetNomMouvement());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = DecouperTexteDebut(nom, separateur);
        m_textCtrlNomAfficherMouvements->AppendText(nomdecoupe);
    }

    if(m_bdd_anodisation->RecupereDureeTotalMouvement(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_bdd_anodisation->GetDureeTotalMouvement());
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureAfficherMouvements->AppendText(heure);

        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinuteAfficherMouvements->AppendText(minute);

        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeAfficherMouvements->AppendText(seconde);

        m_textCtrlAffichage->AppendText(duree + wxT("\n"));
    }

    if(m_bdd_anodisation->RecupereAxeXMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeXMouvement());
        m_textCtrlxAfficherMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAxeYMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeYMouvement());
        m_textCtrlyAfficherMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAxeZMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeZMouvement());
        m_textCtrlzAfficherMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }
}

void EvtFramePrincipal::OnListBoxModifierSelectionMouvements(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierMouvements->GetStringSelection();

    // Récupération de l'id du mouvement
    wxString id_selection = GardeIdSelection(selection);

    m_textCtrlAffichage->AppendText(selection + wxT("\nid selection :") + id_selection + wxT("\n"));

    m_textCtrlDureeHeureModifierMouvements->Clear();
    m_textCtrlDureeMinutesModifierMouvements->Clear();
    m_textCtrlDureeSecondeModifierMouvements->Clear();
    m_textCtrlNomModifierMouvements->Clear();
    m_textCtrlxModifierMouvements->Clear();
    m_textCtrlyModifierMouvements->Clear();
    m_textCtrlzModifierMouvements->Clear();

    if(m_bdd_anodisation->RecupereNomMouvement(ConversionEnString(id_selection)))
    {
        wxString nom = ConversionEnWxString(m_bdd_anodisation->GetNomMouvement());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = DecouperTexteDebut(nom, separateur);
        m_textCtrlNomModifierMouvements->AppendText(nomdecoupe);
    }

    if(m_bdd_anodisation->RecupereDureeTotalMouvement(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_bdd_anodisation->GetDureeTotalMouvement());
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierMouvements->AppendText(heure);

        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierMouvements->AppendText(minute);

        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierMouvements->AppendText(seconde);

        m_textCtrlAffichage->AppendText(duree + wxT("\n"));
    }

    if(m_bdd_anodisation->RecupereAxeXMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeXMouvement());
        m_textCtrlxModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAxeYMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeYMouvement());
        m_textCtrlyModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAxeZMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeZMouvement());
        m_textCtrlzModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }
}

void EvtFramePrincipal::OnApplyButtonModifierMouvementClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonModifierMouvementClick
}

void EvtFramePrincipal::OnCancelButtonModifierMouvementClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierMouvements->GetStringSelection();

    // Récupération de l'id du mouvement
    wxString id_selection = GardeIdSelection(selection);

    m_textCtrlAffichage->AppendText(selection + wxT("\nid selection :") + id_selection + wxT("\n"));

    m_textCtrlDureeHeureModifierMouvements->Clear();
    m_textCtrlDureeMinutesModifierMouvements->Clear();
    m_textCtrlDureeSecondeModifierMouvements->Clear();
    m_textCtrlNomModifierMouvements->Clear();
    m_textCtrlxModifierMouvements->Clear();
    m_textCtrlyModifierMouvements->Clear();
    m_textCtrlzModifierMouvements->Clear();

    if(m_bdd_anodisation->RecupereNomMouvement(ConversionEnString(id_selection)))
    {
        wxString nom = ConversionEnWxString(m_bdd_anodisation->GetNomMouvement());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = DecouperTexteDebut(nom, separateur);
        m_textCtrlNomModifierMouvements->AppendText(nomdecoupe);
    }

    if(m_bdd_anodisation->RecupereDureeTotalMouvement(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_bdd_anodisation->GetDureeTotalMouvement());
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierMouvements->AppendText(heure);

        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierMouvements->AppendText(minute);

        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierMouvements->AppendText(seconde);

        m_textCtrlAffichage->AppendText(duree + wxT("\n"));
    }

    if(m_bdd_anodisation->RecupereAxeXMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeXMouvement());
        m_textCtrlxModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAxeYMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeYMouvement());
        m_textCtrlyModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAxeZMouvement(ConversionEnString(id_selection)))
    {
        wxString coordonnee = ConversionEnWxString(m_bdd_anodisation->GetAxeZMouvement());
        m_textCtrlzModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }
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
    wxString selection = m_listBoxAffichageTrajectoires->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);

    // m_textCtrlAffichage->AppendText(selection + wxT("\nid selection :") + id_selection + wxT("\n"));

    // Vider les text control
    // du coté droit

    m_textCtrlDureeHeureAfficherTrajectoires->Clear();
    m_textCtrlDureeMinutesAfficherTrajectoires->Clear();
    m_textCtrlDureeSecondesAfficherTrajectoires->Clear();
    m_listBoxCompositionTrajectoire->Clear();
    m_textCtrlNomAfficherTrajectoires->Clear();
    m_textCtrlBaindedepartAfficher->Clear();
    m_textCtrlBainDarriveeAfficher->Clear();

    // Remplisage

    if(m_bdd_anodisation->RecupereNomTrajectoire(ConversionEnString(id_selection)))
    {
        wxString nom = ConversionEnWxString(m_bdd_anodisation->GetNomTrajectoire());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = DecouperTexteDebut(nom, separateur);

        m_textCtrlNomAfficherTrajectoires->AppendText(nomdecoupe);
    }

    if(m_bdd_anodisation->RecupereDureeTotalTrajectoire(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_bdd_anodisation->GetDureeTotalTrajectoire());
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureAfficherTrajectoires->AppendText(heure);

        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesAfficherTrajectoires->AppendText(minute);

        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondesAfficherTrajectoires->AppendText(seconde);

        // m_textCtrlAffichage->AppendText(duree + wxT("\n"));
    }

    if(m_bdd_anodisation->RecupereDepartTrajectoire(ConversionEnString(id_selection)))
    {
        wxString depart = ConversionEnWxString(m_bdd_anodisation->GetDepartTrajectoire());
        m_textCtrlBaindedepartAfficher->AppendText(depart);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAriveeTrajectoire(ConversionEnString(id_selection)))
    {
        wxString arivee = ConversionEnWxString(m_bdd_anodisation->GetArriveeTrajectoire());
        m_textCtrlBainDarriveeAfficher->AppendText(arivee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }
}

void EvtFramePrincipal::OnListBoxModifierSelectionTrajectoires(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierTrajectoires->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);

    // m_textCtrlAffichage->AppendText(selection + wxT("\nid selection :") + id_selection + wxT("\n"));

    // Vider les text control
    // du coté droit

    m_textCtrlDureeHeureModifierTrajectoires->Clear();
    m_textCtrlDureeMinutesModifierTrajectoires->Clear();
    m_textCtrlDureeSecondeModifierTrajectoires->Clear();
    m_listBoxCompositionTrajectoire->Clear();
    m_textCtrlOrdreMouvements->Clear();
    m_textCtrlNomModifierTrajectoires->Clear();
    m_textCtrlBainDeDepartModifier->Clear();
    m_textCtrlBainDarriveeModifier->Clear();

    // Remplisage

    if(m_bdd_anodisation->RecupereNomTrajectoire(ConversionEnString(id_selection)))
    {
        wxString nom = ConversionEnWxString(m_bdd_anodisation->GetNomTrajectoire());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = DecouperTexteDebut(nom, separateur);

        m_textCtrlNomModifierTrajectoires->AppendText(nomdecoupe);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("erreur\n"));
    }

    if(m_bdd_anodisation->RecupereDureeTotalTrajectoire(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_bdd_anodisation->GetDureeTotalTrajectoire());
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierTrajectoires->AppendText(heure);

        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierTrajectoires->AppendText(minute);

        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierTrajectoires->AppendText(seconde);

        m_textCtrlAffichage->AppendText(duree + wxT("\n"));
    }

    if(m_bdd_anodisation->RecupereDepartTrajectoire(ConversionEnString(id_selection)))
    {
        wxString depart = ConversionEnWxString(m_bdd_anodisation->GetDepartTrajectoire());
        m_textCtrlBainDeDepartModifier->AppendText(depart);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAriveeTrajectoire(ConversionEnString(id_selection)))
    {
        wxString arivee = ConversionEnWxString(m_bdd_anodisation->GetArriveeTrajectoire());
        m_textCtrlBainDarriveeModifier->AppendText(arivee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereOrdreMouvements(ConversionEnString(id_selection)))
    {
        wxString ordre = ConversionEnWxString(m_bdd_anodisation->GetOrdreMouvements());
        m_textCtrlOrdreMouvements->AppendText(ordre);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }
}

void EvtFramePrincipal::OnApplyButtonModifierTrajectoiresClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonModifierTrajectoiresClick
}

void EvtFramePrincipal::OnCancelButtonModifierTrajectoiresClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierTrajectoires->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);

    // m_textCtrlAffichage->AppendText(selection + wxT("\nid selection :") + id_selection + wxT("\n"));

    // Vider les text control
    // du coté droit

    m_textCtrlDureeHeureModifierTrajectoires->Clear();
    m_textCtrlDureeMinutesModifierTrajectoires->Clear();
    m_textCtrlDureeSecondeModifierTrajectoires->Clear();
    m_listBoxCompositionTrajectoire->Clear();
    m_textCtrlNomModifierTrajectoires->Clear();
    m_textCtrlBainDeDepartModifier->Clear();
    m_textCtrlBainDarriveeModifier->Clear();

    // Remplisage

    if(m_bdd_anodisation->RecupereNomTrajectoire(ConversionEnString(id_selection)))
    {
        wxString nom = ConversionEnWxString(m_bdd_anodisation->GetNomTrajectoire());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = DecouperTexteDebut(nom, separateur);

        m_textCtrlNomModifierTrajectoires->AppendText(nomdecoupe);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("erreur\n"));
    }

    if(m_bdd_anodisation->RecupereDureeTotalTrajectoire(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_bdd_anodisation->GetDureeTotalTrajectoire());
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierTrajectoires->AppendText(heure);

        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierTrajectoires->AppendText(minute);

        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierTrajectoires->AppendText(seconde);

        m_textCtrlAffichage->AppendText(duree + wxT("\n"));
    }

    if(m_bdd_anodisation->RecupereDepartTrajectoire(ConversionEnString(id_selection)))
    {
        wxString depart = ConversionEnWxString(m_bdd_anodisation->GetDepartTrajectoire());
        m_textCtrlBainDeDepartModifier->AppendText(depart);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }

    if(m_bdd_anodisation->RecupereAriveeTrajectoire(ConversionEnString(id_selection)))
    {
        wxString arivee = ConversionEnWxString(m_bdd_anodisation->GetArriveeTrajectoire());
        m_textCtrlBainDarriveeModifier->AppendText(arivee);
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Erreur \n"));
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }
}

void EvtFramePrincipal::OnListBoxSelectionMouvementsCreationTrajectoire(wxCommandEvent& event)
{

    
    /*if(m_bdd_anodisation->RecupereListeToutMouvements())
    {
        for()
        /*wxString nom = ConversionEnWxString(m_bdd_anodisation->GetListeToutMouvements());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = DecouperTexteDebut(nom, separateur);

        m_listBoxCreerTrajectoires->Append(wxT("bla"));
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("erreur\n"));
    }*/
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
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::VideListBoxMouvements()
{
    m_listBoxAffichageMouvements->Clear();
    m_listBoxDetruireMouvements->Clear();
    m_listBoxTesterMouvements->Clear();
    m_listBoxModifierMouvements->Clear();
}

void EvtFramePrincipal::AfficheMessageClient(wxCommandEvent& event)
{
    // Affiche dans le log l'événement
    m_textCtrlAffichage->AppendText(event.GetString());
}

void EvtFramePrincipal::RempliListBoxTrajectoires()
{
    if(m_bdd_anodisation->RecupereListeTouteTrajectoires())
    {
        vector<string> liste_trajectoires = m_bdd_anodisation->GetListeTouteTrajectoires();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_trajectoires.size(); taille++)
        {
            if(taille % 2 == 0)
            {
                rempli.clear();
                rempli << liste_trajectoires[taille] << wxT("-");
            }
            else
            {
                nom.clear();
                nom << liste_trajectoires[taille];

                int separateur = nom.find("   ");
                rempli << DecouperTexteDebut(nom, separateur);

                m_listBoxAffichageTrajectoires->Append(rempli);
                m_listBoxDetruireTrajectoires->Append(rempli);
                m_listBoxTesterTrajectoires->Append(rempli);
                m_listBoxModifierTrajectoires->Append(rempli);
            }
        }
    }
}

void EvtFramePrincipal::RempliListBoxMouvements()
{
    if(m_bdd_anodisation->RecupereListeToutMouvements())
    {
        vector<string> liste_mouvement = m_bdd_anodisation->GetListeToutMouvements();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_mouvement.size(); taille++)
        {
            if(taille % 2 == 0)
            {
                rempli.clear();
                rempli << liste_mouvement[taille] << wxT("-");
            }
            else
            {
                nom.clear();
                nom << liste_mouvement[taille];

                int separateur = nom.find("   ");
                rempli << DecouperTexteDebut(nom, separateur);

                m_listBoxAffichageMouvements->Append(rempli);
                m_listBoxDetruireMouvements->Append(rempli);
                m_listBoxTesterMouvements->Append(rempli);
                m_listBoxModifierMouvements->Append(rempli);
            }
        }
    }
}

void EvtFramePrincipal::AfficheInfoClient(wxCommandEvent& event)
{
    // Affiche dans la barre de statusbar l'événement
    AfficheStatus(event.GetString(), 0);
}

void EvtFramePrincipal::DeconnexionClient(wxString message)
{
    m_client->Close();
    m_client_connecte = false;

    if(message.EndsWith(wxT(": il a disparu\n")))
    {
        wxLogError(wxT("Le serveur de communication de la raspberry c'est déconnecté!"));
    }

    delete m_client;
    // Affichage du message
    message << wxT("\n");

    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
    m_textCtrlAffichage->AppendText(message);
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

    AfficheStatus(wxT("Client déconnecté"), 0);

    if(m_bdd_anodisation)
    {
        AfficheStatus(wxT("Connecté à la bdd"), 1);
    }
    else
    {
        AfficheStatus(wxT("Non connecté"), 1);
    }
}

wxString EvtFramePrincipal::ConversionEnWxString(string texte)
{
    wxString temp_wxstring(texte.c_str(), wxConvUTF8);

    return temp_wxstring;
}

wxString EvtFramePrincipal::GardeIdSelection(wxString texte)
{
    int separateur = texte.find("-");
    wxString id_selection = DecouperTexteDebut(texte, separateur);

    return id_selection;
}

wxString EvtFramePrincipal::DecouperTexteFin(wxString texte, int position)
{
    wxString fin(texte.substr(position));

    return fin;
}


void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    DeconnexionClient(event.GetString());
}

void EvtFramePrincipal::AfficheStatus(wxString texte, int position)
{
    m_statusBar->SetStatusText(texte, position);
}

wxString EvtFramePrincipal::DecouperTexteDebut(wxString texte, int position)
{
    wxString fin(texte.substr(position));

    wxString debut = "";
    texte.EndsWith(fin, &debut);

    return debut;
}

bool EvtFramePrincipal::VerificationLogin(wxString login, wxString pass)
{
    wxString identifiant = wxT("Régleur");
    wxString motpasse = wxT("regleur");
    bool retour = false;

    if(identifiant == login && motpasse == pass)
    {
        retour = true;
    }

    return retour;
}

string EvtFramePrincipal::ConversionEnString(wxString texte)
{
    string temp_string = texte.ToStdString();

    return temp_string;
}

void EvtFramePrincipal::VideListBoxTrajectoires()
{
    m_listBoxAffichageTrajectoires->Clear();
    m_listBoxDetruireTrajectoires->Clear();
    m_listBoxTesterTrajectoires->Clear();
    m_listBoxModifierTrajectoires->Clear();
}