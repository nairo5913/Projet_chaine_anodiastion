/*******************************************************************************
 *  Fichier:  EvtFramePrincipal.cpp
 *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
 *  Crée le:  29/04/2018
 *  Utilité:  Gestion des événements du frame principal
 *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_client_connecte = false;
    m_bdd_connecte = false;
    m_bdd_anodisation = NULL;
    m_identifie = false;
    m_fabrication = false;
    point_virgule_saisie_creer = true;
    point_virgule_saisie_modifier = true;

    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = -1;
    widths[1] = 140;
    m_statusBar->SetStatusWidths(2, widths);
    AfficheStatus(wxT("Déconnecté"), 1);

    // Connexion des événements du client
    Connect(ID_CLIENT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheInfoClient), NULL,
            this);
    Connect(ID_CLIENT + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessageClient),
            NULL, this);
    Connect(ID_CLIENT + 2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AgitServeurPerdu),
            NULL, this);

    // Charger les bitmap pour la disponibilité du bras
    BmpRouge.LoadFile(wxT("../Images/RougeAllume.bmp"), wxBITMAP_TYPE_BMP);
    BmpVert.LoadFile(wxT("../Images/VertAllume.bmp"), wxBITMAP_TYPE_BMP);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                     Méthode générées par wxFormBuilder                     //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
    // Bloquer la fermeture de la fenêtre
    if(m_fabrication)
    {
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
        m_textCtrlAffichage->AppendText(wxT("\nVeulliez attendre la fin de la fabrication en cours !\n"));
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

        // Boite de dialogue
        wxMessageBox("\nUne fabrication est en cours.\nVeulliez attendre la fin de la fabrication en cours !\n",
                     "Fabrication en cours !", wxOK_DEFAULT | wxICON_EXCLAMATION | wxCENTRE | wxSTAY_ON_TOP, this);
    }
    else
    {
        if(m_identifie)
        {
            delete m_bdd_anodisation;
            m_bdd_anodisation = NULL;

            delete m_donnees_IHM;

            if(m_client_connecte)
            {
                DeconnexionClient(wxT("Déconnexion depuis le poste responsable de production."));
            }
        }

        Destroy();
    }
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
            m_textCtrlAffichage->Clear();
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxColour("FOREST GREEN")));
            m_textCtrlAffichage->AppendText(wxT("\n\tIdentification OK\n\n"));
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

            m_identifie = true;

            // Désactivation des textCtrl de connexion
            m_textCtrlLogin->Disable();
            m_textCtrlPass->Disable();
            // Affichage des onglets de gestion des processus
            m_notebookProcessus->Show();
            // Changement du label du toggle button
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));

            Layout();

            wxString message;
            bool erreur = false;

            m_bdd_anodisation = new DataAnodisation(DSN);
            m_donnees_IHM = new DonneesIHM(m_bdd_anodisation);

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

            m_client = new Client(IP, PORT, this);
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
            // m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxColour("ORANGE RED")));
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

        delete m_bdd_anodisation;
        m_bdd_anodisation = NULL;

        delete m_donnees_IHM;

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

void EvtFramePrincipal::OnListBoxAffichageSelection(wxCommandEvent& event)
{
    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(m_listBoxAffichageProcessus->GetStringSelection());

    // Vider les text control
    // du coté droit
    m_textCtrlIdAfficher->Clear();
    m_textCtrlDureeTotalHeureAfficher->Clear();
    m_textCtrlDureeTotalMinuteAfficher->Clear();
    m_textCtrlDureeTotalSecondeAfficher->Clear();
    m_listBoxListeTrajectoiresAfficher->Clear();

    // Du coté gauche
    m_textCtrlNomAfficher->Clear();
    m_textCtrlNombreBainAfficher->Clear();
    m_textCtrlOrdreTrajectoiresAfficher->Clear();

    // Remplisage
    m_textCtrlIdAfficher->AppendText(id_selection);

    // Durée total du processus
    if(m_donnees_IHM->RecupereDureeTotal(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_textCtrlDureeTotalHeureAfficher->AppendText(DecouperTexteDebut(duree, 2));

        wxString temp = DecouperTexteDebut(duree, 5);
        m_textCtrlDureeTotalMinuteAfficher->AppendText(DecouperTexteFin(temp, 3));
        
        m_textCtrlDureeTotalSecondeAfficher->AppendText(DecouperTexteFin(duree, 6));
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Liste des trajectoires du processus
    if(m_donnees_IHM->RecupereListeTrajectoiresProcessus(ConversionEnString(id_selection)))
    {
        vector<string> resultat = m_donnees_IHM->GetListeTrajectoiresProcessus();
        m_listBoxListeTrajectoiresAfficher->Clear();

        for(unsigned int taille = 0; taille < resultat.size(); taille++)
        {
            // m_textCtrlAffichage->AppendText(ConversionEnWxString(resultat[taille]));
            // m_textCtrlAffichage->AppendText(wxT("\n"));

            wxString rempli;

            if(taille % 4 == 0 && taille != 0)
            {
                // m_textCtrlAffichage->AppendText(wxT("Modulo " + rempli + wxT("\n")));
                rempli << resultat[taille];
                m_listBoxListeTrajectoiresAfficher->Append(rempli);
                rempli.clear();
                // rempli << resultat[taille] << wxT(" - ");
            }
            else
            {
                // m_textCtrlAffichage->AppendText(wxT("Hors modulo " + rempli + wxT("\n")));
                rempli << resultat[taille] << wxT(" - ");
                // m_textCtrlAffichage->AppendText(liste_processus[taille] + wxT("\n"));
            }
        }
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nom du processus
    if(m_donnees_IHM->RecupereNomProcessus(ConversionEnString(id_selection)))
    {
        wxString temp = ConversionEnWxString(m_donnees_IHM->GetNomProcessus());

        int separateur = temp.find("   ");
        wxString nom = DecouperTexteDebut(temp, separateur);

        m_textCtrlNomAfficher->AppendText(nom);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(ConversionEnString(id_selection)))
    {
        m_textCtrlNombreBainAfficher->AppendText(ConversionEnWxString(m_donnees_IHM->GetNombreBain()));
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(ConversionEnString(id_selection)))
    {
        m_textCtrlOrdreTrajectoiresAfficher->AppendText(ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires()));
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}
//
// Saisie au clavier
//
void EvtFramePrincipal::OnCharEntered(wxKeyEvent& event)
{
    // TODO: Implement OnCharEntered
    switch(event.GetKeyCode())
    {
        case WXK_F1:
            // m_textCtrlAffichage->AppendText(wxT("Touche F1.\n"));

            event.Skip();
            break;

        case WXK_F2:
            // m_textCtrlAffichage->AppendText(wxT("Touche F2.\n"));

            event.Skip();
            break;

        case WXK_F3:
            // m_textCtrlAffichage->AppendText(wxT("Touche F3.\n"));

            event.Skip();
            break;

        default:

            event.Skip();
            break;
    }
}

void EvtFramePrincipal::OnCharEnteredNum(wxKeyEvent& event)
{
    switch(event.GetKeyCode())
    {
        case '0':

            event.Skip();
            break;

        case '1':

            event.Skip();
            break;

        case '2':

            event.Skip();
            break;

        case '3':

            event.Skip();
            break;

        case '4':
            event.Skip();
            break;

        case '5':

            event.Skip();
            break;

        case '6':

            event.Skip();
            break;

        case '7':

            event.Skip();
            break;

        case '8':

            event.Skip();
            break;

        case '9':

            event.Skip();
            break;

        case WXK_BACK:

            event.Skip();
            break;

        case WXK_DELETE:

            event.Skip();
            break;

        case WXK_TAB:

            event.Skip();
            break;

        case WXK_LEFT:

            event.Skip();
            break;

        case WXK_UP:

            event.Skip();
            break;

        case WXK_RIGHT:

            event.Skip();
            break;

        case WXK_DOWN:

            event.Skip();
            break;

        default:

            // On ne fait rien
            break;
    }
}

void EvtFramePrincipal::OnSpinCtrlModifierBain(wxSpinEvent& event)
{
    // TODO: Implement OnSpinCtrlModifierBain
    m_textCtrlAffichage->AppendText(wxT("Test modif\n"));
}

void EvtFramePrincipal::OnCharEnteredOrdre(wxKeyEvent& event)
{
    switch(event.GetKeyCode())
    {
        case '0':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '1':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '2':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '3':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '4':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '5':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '6':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '7':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '8':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '9':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case ';':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(!point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = true;
                    event.Skip();
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(!point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = true;
                    event.Skip();
                }
            }
            break;

        case WXK_BACK:  // Retour arrière
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                wxString temp = m_textCtrlOrdreTrajectoiresModifier->GetValue();

                if(!temp.IsEmpty())
                {
                    if(temp.Last() == wxT(';'))
                    {
                        point_virgule_saisie_modifier = false;
                    }

                    if(temp.length() == 1)
                    {
                        point_virgule_saisie_modifier = true;
                    }
                }
                else
                {
                    point_virgule_saisie_modifier = true;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                wxString temp = m_textCtrlOrdreTrajectoiresCreer->GetValue();

                if(!temp.IsEmpty())
                {
                    if(temp.Last() == wxT(';'))
                    {
                        point_virgule_saisie_creer = false;
                    }

                    if(temp.length() == 1)
                    {
                        point_virgule_saisie_creer = true;
                    }
                }
                else
                {
                    point_virgule_saisie_creer = true;
                }
            }
            event.Skip();
            break;

        /*case WXK_DELETE: // Touche supprimer

            event.Skip();
            break;*/

        case WXK_TAB:  // Touche Tab

            event.Skip();
            break;

        case WXK_LEFT:  // Touche fleche gauche

            event.Skip();
            break;

        case WXK_UP:  // Touche fleche haut

            event.Skip();
            break;

        case WXK_RIGHT:  // Touche fleche droite

            event.Skip();
            break;

        case WXK_DOWN:  // Touche fleche bas

            event.Skip();
            break;

        default:

            // On ne fait rien
            break;
    }
}
//
// Modifier un processus
//
void EvtFramePrincipal::OnListBoxModifierSelection(wxCommandEvent& event)
{
    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(m_listBoxModifierProcessus->GetStringSelection());

    // Vider les text control
    // du coté droit
    m_textCtrlIdModifier->Clear();
    m_textCtrlDureeTotalHeureModifier->Clear();
    m_textCtrlDureeTotalMinuteModifier->Clear();
    m_textCtrlDureeTotalSecondeModifier->Clear();

    // Du coté gauche
    m_textCtrlNomModifier->Clear();
    m_textCtrlOrdreTrajectoiresModifier->Clear();

    // Remplisage
    m_textCtrlIdModifier->AppendText(id_selection);

    // Durée total du processus
    if(m_donnees_IHM->RecupereDureeTotal(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_textCtrlDureeTotalHeureModifier->AppendText(DecouperTexteDebut(duree, 2));

        wxString temp = DecouperTexteDebut(duree, 5);
        m_textCtrlDureeTotalMinuteModifier->AppendText(DecouperTexteFin(temp, 3));

        m_textCtrlDureeTotalSecondeModifier->AppendText(DecouperTexteFin(duree, 6));
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nom du processus
    if(m_donnees_IHM->RecupereNomProcessus(ConversionEnString(id_selection)))
    {
        wxString temp = ConversionEnWxString(m_donnees_IHM->GetNomProcessus());

        int separateur = temp.find("   ");
        wxString nom = DecouperTexteDebut(temp, separateur);

        m_textCtrlNomModifier->AppendText(nom);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(ConversionEnString(id_selection)))
    {
        m_spinCtrlNombreBainModifier->SetValue(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(ConversionEnString(id_selection)))
    {
        m_textCtrlOrdreTrajectoiresModifier->AppendText(ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires()));
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}

void EvtFramePrincipal::OnApplyButtonModifierClick(wxCommandEvent& event)
{
    // TODO: Implement OnApplyButtonModifierClick
}

void EvtFramePrincipal::OnCancelButtonModiffierClick(wxCommandEvent& event)
{
    // TODO: Implement OnCancelButtonModiffierClick
    // Récupération de la saisie
    wxString selection = m_listBoxModifierProcessus->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);

    // Vider les text control
    // du coté droit
    m_textCtrlIdModifier->Clear();
    m_textCtrlDureeTotalHeureModifier->Clear();
    m_textCtrlDureeTotalMinuteModifier->Clear();
    m_textCtrlDureeTotalSecondeModifier->Clear();

    // Du coté gauche
    m_textCtrlNomModifier->Clear();
    m_textCtrlOrdreTrajectoiresModifier->Clear();

    // Remplisage
    m_textCtrlIdModifier->AppendText(id_selection);

    // Durée total du processus
    if(m_donnees_IHM->RecupereDureeTotal(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeTotalHeureModifier->AppendText(heure);

        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeTotalMinuteModifier->AppendText(minute);

        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeTotalSecondeModifier->AppendText(seconde);
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n") << wxT("Raison : ")
                << ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }

    // Nom du processus
    if(m_donnees_IHM->RecupereNomProcessus(ConversionEnString(id_selection)))
    {
        wxString temp = ConversionEnWxString(m_donnees_IHM->GetNomProcessus());

        int separateur = temp.find("   ");
        wxString nom = DecouperTexteDebut(temp, separateur);

        m_textCtrlNomModifier->AppendText(nom);
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n") << wxT("Raison : ")
                << ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(ConversionEnString(id_selection)))
    {
        m_spinCtrlNombreBainModifier->SetValue(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(ConversionEnString(id_selection)))
    {
        wxString ordre = ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());

        m_textCtrlOrdreTrajectoiresModifier->AppendText(ordre);
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n") << wxT("Raison : ")
                << ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()) << wxT("\n");

        m_textCtrlAffichage->AppendText(message);
    }
}
//
// Créer un processus
//
void EvtFramePrincipal::OnCancelButtonCreerClick(wxCommandEvent& event)
{
    m_textCtrlDureeTotalHeureCreer->Clear();
    m_textCtrlDureeTotalMinuteCreer->Clear();
    m_textCtrlDureeTotalSecondeCreer->Clear();
    m_textCtrlNomCreer->Clear();
    m_textCtrlOrdreTrajectoiresCreer->Clear();
    m_spinCtrlNombreBainCreer->SetValue(1);
}

void EvtFramePrincipal::OnSaveButtonCreerClick(wxCommandEvent& event)
{
    vector<string> donnees;
    donnees.push_back("Test Processus");
    donnees.push_back("00:01:02");

    if(m_bdd_anodisation->ExecuteInsert(donnees))
    {
        m_textCtrlAffichage->AppendText(wxT("OK\n"));
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
    }
}

void EvtFramePrincipal::OnSpinCtrlCreerBain(wxSpinEvent& event)
{
    // TODO: Implement OnSpinCtrlCreerBain
    m_textCtrlAffichage->AppendText(wxT("Test"));
}
//
// Détruire un processus
//
void EvtFramePrincipal::OnListBoxDetruireSelection(wxCommandEvent& event)
{
    wxString selection = m_listBoxDetruireProcessus->GetStringSelection();

    wxString message;
    int separateur = selection.find(" - ");
    message << DecouperTexteFin(selection, separateur + 3) << wxT("\n");
    m_staticTextDetuireTitre->SetLabel(message);

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);

    // Durée total
    if(m_donnees_IHM->RecupereDureeTotal(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_staticTextDureeTotalValeurDetruire->SetLabel(duree);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(ConversionEnString(id_selection)))
    {
        m_staticTextNombreBainValeurDetruire->SetLabel(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(ConversionEnString(id_selection)))
    {
        wxString ordre = ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());

        m_staticTextOrdreTrajectoiresDetruireValeur->SetLabel(ordre);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    Layout();
}

void EvtFramePrincipal::OnApplyButtonDetruireClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxDetruireProcessus->GetStringSelection();
    string id_selection = ConversionEnString(GardeIdSelection(selection));

    string requete = "DELETE FROM intermediaire_processus_trajectoires WHERE id_p=" + id_selection;

    if(m_bdd_anodisation->ExecuteDelete(requete))
    {
        requete = "DELETE FROM processus WHERE id_processus=" + id_selection;
        
        if(m_bdd_anodisation->ExecuteDelete(requete))
        {
            int separateur = selection.find(" - ");
            wxString message;
            message << wxT("Supression du processus : ")
                    << DecouperTexteFin(selection, separateur + 3)
                    << wxT(" réussi !\n");
            
            m_textCtrlAffichage->AppendText(message);
            wxLogMessage(message);
            
            VideListBox();
            RempliListBox();
        }
        else
        {
            AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
    }
}
//
// Lancer un processus
//
void EvtFramePrincipal::OnListBoxLancerSelection(wxCommandEvent& event)
{
    wxString selection = m_listBoxLancerProcessus->GetStringSelection();

    wxString message;
    int separateur = selection.find(" - ");
    message << DecouperTexteFin(selection, separateur + 3) << wxT("\n");
    m_staticTextLancerTitre->SetLabel(message);

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);

    // Durée total
    if(m_donnees_IHM->RecupereDureeTotal(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_staticTextDureeTotalValeurLancer->SetLabel(duree);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(ConversionEnString(id_selection)))
    {
        m_staticTextNombreBainValeurLancer->SetLabel(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(ConversionEnString(id_selection)))
    {
        wxString ordre = ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());

        m_staticTextOrdreTrajectoiresValeurLancer->SetLabel(ordre);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    bSizerLancerDroit->Layout();
    bSizerLancerGauche->Layout();
    bSizerDetailLancer->Layout();
    Layout();
}

void EvtFramePrincipal::OnOkButtonLancerClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonLancerClick
}
//
// Tester un processus
//
void EvtFramePrincipal::OnListBoxTesterSelection(wxCommandEvent& event)
{
    wxString selection = m_listBoxTesterProcessus->GetStringSelection();

    wxString message;
    int separateur = selection.find(" - ");
    message << DecouperTexteFin(selection, separateur + 3) << wxT("\n");
    m_staticTextTesterTitre->SetLabel(message);

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);

    // Vider les données
    m_staticTextDureeTotalValeurTester->SetLabel(wxT(""));
    m_staticTextOrdreTrajectoiresValeurTester->SetLabel(wxT(""));

    // Durée total
    if(m_donnees_IHM->RecupereDureeTotal(ConversionEnString(id_selection)))
    {
        wxString duree = ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_staticTextDureeTotalValeurTester->SetLabel(duree);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(ConversionEnString(id_selection)))
    {
        m_staticTextNombreBainValeurTester->SetLabel(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(ConversionEnString(id_selection)))
    {
        wxString ordre = ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());

        m_staticTextOrdreTrajectoiresValeurTester->SetLabel(ordre);
    }
    else
    {
        AfficheErreurRemplisage(ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    bSizerTesterDroit->Layout();
    bSizerTesterGauche->Layout();
    bSizerDetailTester->Layout();
    Layout();
}

void EvtFramePrincipal::OnStopButtonTesterClick(wxCommandEvent& event)
{
    // TODO: Implement OnStopButtonTesterClick
}

void EvtFramePrincipal::OnOkButtonTesterClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonTesterClick
}
//
// Disponibilité bras et détail de la tache en cours
//
void EvtFramePrincipal::OnButtonDisponibiliteBrasClick(wxCommandEvent& event)
{
    if(m_client_connecte)
    {
        if(m_client->DemandeDisponibiliteBras())
        {
            m_panelPasTache->Show();
            m_panelTacheEnCours->Hide();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras est disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpVert);

            // Désactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Disable();

            // Réorganiser l'intérieur des sbSizer
            sbSizerTacheEnCours->Layout();
            sbSizerDisponibiliteBras->Layout();
        }
        else
        {
            m_panelPasTache->Hide();
            m_panelTacheEnCours->Show();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras n'est pas disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpRouge);

            // Réactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Enable();
        }
    }
    else
    {
        wxLogError(wxT("Le client n'est pas connecté au serveur de la Raspberry pi."));
    }
}

void EvtFramePrincipal::OnButtonTacheEnCoursClick(wxCommandEvent& event)
{
    if(m_client_connecte)
    {
        vector<string> tache = m_client->DemandeTacheEnCours();

        if(tache[0] == "0")
        {
            m_panelPasTache->Show();
            m_panelTacheEnCours->Hide();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras est disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpVert);

            // Désactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Disable();

            // Réorganiser l'intérieur des sbSizer
            sbSizerTacheEnCours->Layout();
            sbSizerDisponibiliteBras->Layout();
        }
        else
        {
            m_panelPasTache->Hide();
            m_panelTacheEnCours->Show();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras n'est pas disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpRouge);
            bSizerTacheEnCoursPrincipal->Layout();

            // Réactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Enable();

            // Récupération des valeurs
            wxString type = tache[0];
            wxString id_tache = tache[1];
            wxString message;

            if(type == "Processus")
            {
                // Requete pour avoir les détails grace à l'id
                message << wxT("La tache est un processus d'id : ") << id_tache << wxT("\n");

                m_textCtrlAffichage->AppendText(message);
            }
            else if(type == "Trajectoire")
            {
                // Requete pour avoir les détails grace à l'id
                message << wxT("La tache est une trajectoire d'id : ") << id_tache << wxT("\n");

                m_textCtrlAffichage->AppendText(message);
            }
            else
            {
                // Requete pour avoir les détails grace à l'id
                message << wxT("La tache est un mouvement d'id : ") << id_tache << wxT("\n");

                m_textCtrlAffichage->AppendText(message);
            }
        }
        Layout();
    }
    else
    {
        wxLogError(wxT("Le client n'est pas connecté au serveur de la Raspberry pi."));
    }
}

void EvtFramePrincipal::OnButtonViderAffichageClick(wxCommandEvent& event)
{
    m_textCtrlAffichage->Clear();
}
//
// Barre de menu
//
void EvtFramePrincipal::OnMenuQuitterSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuQuitterSelection
    if(m_fabrication)
    {
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
        m_textCtrlAffichage->AppendText(wxT("\nVeulliez attendre la fin de la fabrication en cours!\n"));
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

        // Boite de dialogue
        wxMessageBox("\nUne fabrication est en cours.\nVeulliez attendre la fin de la fabrication en cours !\n",
                     "Fabrication en cours !", wxOK_DEFAULT | wxICON_EXCLAMATION | wxCENTRE | wxSTAY_ON_TOP, this);
    }
    else
    {
        if(m_identifie)
        {
            delete m_bdd_anodisation;
            m_bdd_anodisation = NULL;

            delete m_donnees_IHM;

            if(m_client_connecte)
            {
                DeconnexionClient(wxT("Déconnexion depuis le poste responsable de production."));
            }
        }

        Destroy();
    }
}

void EvtFramePrincipal::OnMenuViderAffichageSelection(wxCommandEvent& event)
{
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::OnMenuAideSelection(wxCommandEvent& event)
{
    EvtFrameAide* frame_aide = new EvtFrameAide(this);
    frame_aide->Show();
}

void EvtFramePrincipal::OnMenuAproposSelection(wxCommandEvent& event)
{
    EvtFrameApropos* frame_apropos = new EvtFrameApropos(this);
    frame_apropos->Show();
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                            Méthode du programme                            //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool EvtFramePrincipal::LancerFabrication(wxString id_processus)
{
    bool retour = false;

    //

    return retour;
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
    AfficheStatus(event.GetString(), 0);
}

void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    DeconnexionClient(event.GetString());
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
//
// IHM
//
void EvtFramePrincipal::AfficheStatus(wxString texte, int position)
{
    m_statusBar->SetStatusText(texte, position);
}

void EvtFramePrincipal::AfficheErreurRemplisage(wxString erreur)
{
    wxString message;
    message << wxT("\n") << wxT("Erreur lors de la requête à la base de données.\n") << wxT("\n");

    wxTextAttr centre;
    centre.SetAlignment(wxTEXT_ALIGNMENT_CENTRE);
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxColour("SALMON")));
    m_textCtrlAffichage->SetDefaultStyle(centre);
    m_textCtrlAffichage->AppendText(message);
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

    message.clear();
    message << wxT("Raison : ") << erreur << wxT("\n");

    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxColour("SLATE BLUE")));
    m_textCtrlAffichage->AppendText(message);
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
}

void EvtFramePrincipal::RempliListBox()
{
    if(m_donnees_IHM->RecupereListeProcessus())
    {
        vector<string> liste_processus = m_donnees_IHM->GetListeProcessus();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_processus.size(); taille++)
        {
            if(taille % 2 == 0)
            {
                // m_textCtrlAffichage->AppendText(liste_processus[taille]);
                rempli.clear();
                rempli << liste_processus[taille] << wxT(" - ");
            }
            else
            {
                // m_textCtrlAffichage->AppendText(liste_processus[taille] + wxT("\n"));
                nom.clear();
                nom << liste_processus[taille];

                int separateur = nom.find("   ");
                rempli << DecouperTexteDebut(nom, separateur);

                // Remplissage des listBox depuis la BdD
                m_listBoxAffichageProcessus->Append(rempli);
                m_listBoxDetruireProcessus->Append(rempli);
                m_listBoxLancerProcessus->Append(rempli);
                m_listBoxModifierProcessus->Append(rempli);
                m_listBoxTesterProcessus->Append(rempli);
            }
        }
    }
    else
    {
        m_textCtrlAffichage->AppendText(m_donnees_IHM->GetDerniereErreur());
    }

    if(m_donnees_IHM->RecupereListeTouteTrajectoires())
    {
        vector<string> liste_trajectoire = m_donnees_IHM->GetListeTouteTrajectoires();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_trajectoire.size(); taille++)
        {
            // m_textCtrlAffichage->AppendText(liste_trajectoire[taille] + wxT("\n"));
            taille = taille + 1;

            if(taille % 4 == 0 && taille != 0)
            {
                rempli << wxT("Durée : ") << liste_trajectoire[taille - 1];
                m_listBoxListeTrajectoiresCreer->Append(rempli);
                m_listBoxListeTrajectoiresModifier->Append(rempli);
                rempli.clear();
            }
            else if(taille % 4 != 0 && taille % 2 == 0)
            {
                nom.clear();
                nom << liste_trajectoire[taille - 1];

                int separateur = nom.find("   ");
                rempli << DecouperTexteDebut(nom, separateur) << wxT(" - ");
            }
            else
            {
                // m_textCtrlAffichage->AppendText(liste_trajectoire[taille-1] + wxT("\n"));
                rempli << liste_trajectoire[taille - 1] << wxT(" - ");
            }

            taille = taille - 1;
        }
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n") << wxT("Raison : ")
                << ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }
}

void EvtFramePrincipal::VideListBox()
{
    m_listBoxAffichageProcessus->Clear();
    m_listBoxDetruireProcessus->Clear();
    m_listBoxLancerProcessus->Clear();
    m_listBoxModifierProcessus->Clear();
    m_listBoxTesterProcessus->Clear();
    m_listBoxListeTrajectoiresAfficher->Clear();
    m_listBoxListeTrajectoiresCreer->Clear();
    m_listBoxListeTrajectoiresModifier->Clear();
}
//
// Partie manipulation texte
//
string EvtFramePrincipal::ConversionEnString(wxString texte)
{
    string temp_string = texte.ToStdString();

    return temp_string;
}

wxString EvtFramePrincipal::ConversionEnWxString(string texte)
{
    wxString temp_wxstring(texte.c_str(), wxConvUTF8);

    return temp_wxstring;
}

wxString EvtFramePrincipal::GardeIdSelection(wxString texte)
{
    int separateur = texte.find(" - ");
    wxString id_selection = DecouperTexteDebut(texte, separateur);

    return id_selection;
}

wxString EvtFramePrincipal::DecouperTexteDebut(wxString texte, int position)
{
    wxString fin(texte.substr(position));

    wxString debut = "";
    texte.EndsWith(fin, &debut);

    return debut;
}

wxString EvtFramePrincipal::DecouperTexteFin(wxString texte, int position)
{
    wxString fin(texte.substr(position));

    return fin;
}
