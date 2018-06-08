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
    Connect(ID_CLIENT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheInfoClient), NULL, this);
    Connect(ID_CLIENT + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessageClient), NULL, this);
    Connect(ID_CLIENT + 2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AgitServeurPerdu), NULL, this);

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

            // Désactivation des textCtrl et des staticText de connexion
            m_textCtrlLogin->Disable();
            m_textCtrlPass->Disable();
            m_staticTextLogin->Disable();
            m_staticTextPass->Disable();

            // Désactiver le logo Ozanam
            // m_bitmapLogoOzanam->Disable();

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
                message << wxT(
                    "Erreur lors de la connection du client de communication au serveur de la Raspberry Pi.\n");

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

            // Cacher les réglages des bains 2 et 3 pour la création
            m_staticCreerDureeTotalBain2->Hide();
            m_textCtrlCreerHeureBain2->Hide();
            m_staticTextCreerDureeBain2->Hide();
            m_textCtrlCreerMinuteBain2->Hide();
            m_staticTextCreerDureeFinBain2->Hide();
            m_textCtrlCreerSecondeBain2->Hide();
            bSizerCreerDureeBain2->Hide(this);

            m_staticCreerDureeTotalBain3->Hide();
            m_textCtrlCreerHeureBain3->Hide();
            m_staticTextCreerDureeBain3->Hide();
            m_textCtrlCreerMinuteBain3->Hide();
            m_staticTextCreerDureeFinBain3->Hide();
            m_textCtrlCreerSecondeBain3->Hide();
            bSizerCreerDureeBain3->Hide(this);

            bSizerCreerDureeBain2->Layout();
            bSizerCreerDureeBain3->Layout();
            bSizerBainCreerDuree->Layout();
            bSizerCreerDureeBain1->Layout();
            bSizerCreerBain->Layout();

            sbSizerGestionBainCreer->Layout();

            // Cacher les réglages des bains 2 et 3 pour l'affichage
            m_staticAfficherDureeTotalBain2->Hide();
            m_textCtrlAfficherHeureBain2->Hide();
            m_staticTextAfficherDureeBain2->Hide();
            m_textCtrlAfficherMinuteBain2->Hide();
            m_staticTextAfficherDureeFinBain2->Hide();
            m_textCtrlAfficherSecondeBain2->Hide();
            bSizerAfficherDureeBain2->Hide(this);

            m_staticAfficherDureeTotalBain3->Hide();
            m_textCtrlAfficherHeureBain3->Hide();
            m_staticTextAfficherDureeBain3->Hide();
            m_textCtrlAfficherMinuteBain3->Hide();
            m_staticTextAfficherDureeFinBain3->Hide();
            m_textCtrlAfficherSecondeBain3->Hide();
            bSizerAfficherDureeBain3->Hide(this);

            bSizerAfficherDureeBain2->Layout();
            bSizerAfficherDureeBain3->Layout();
            bSizerBainAfficherDuree->Layout();
            bSizerAfficherDureeBain1->Layout();
            bSizerAfficherBain->Layout();

            sbSizerGestionBainAfficher->Layout();
            Layout();
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
        // Vidange de l'affichage
        m_textCtrlAffichage->Clear();
        
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
        m_staticTextLogin->Enable();
        m_staticTextPass->Enable();

        // Résactiver le logo Ozanam
        // m_bitmapLogoOzanam->Enable();

        // Vider les listBox pour éviter les problème si on se reconnecte sans fermer l'application
        VideListBox();

        // Masquage des onglets de gestion des processus
        m_notebookProcessus->Hide();

        // Changement du label du toggle button
        m_toggleBtnConnexion->SetValue(false);
        m_toggleBtnConnexion->SetLabel(wxT("Connexion"));

        // Mise à jour de la statue bar
        AfficheStatus(wxT("Déconnecté"), 1);

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
    
    m_textCtrlAfficherHeureBain1->Clear();
    m_textCtrlAfficherMinuteBain1->Clear();
    m_textCtrlAfficherSecondeBain1->Clear();
    
    m_textCtrlAfficherHeureBain2->Clear();
    m_textCtrlAfficherMinuteBain2->Clear();
    m_textCtrlAfficherSecondeBain2->Clear();
    
    m_textCtrlAfficherHeureBain3->Clear();
    m_textCtrlAfficherMinuteBain3->Clear();
    m_textCtrlAfficherSecondeBain3->Clear();

    // Du coté gauche
    m_textCtrlNomAfficher->Clear();
    m_textCtrlNombreBainAfficher->Clear();
    m_textCtrlOrdreTrajectoiresAfficher->Clear();
    
    // Masquage
    m_staticAfficherDureeTotalBain2->Hide();
    m_textCtrlAfficherHeureBain2->Hide();
    m_staticTextAfficherDureeBain2->Hide();
    m_textCtrlAfficherMinuteBain2->Hide();
    m_staticTextAfficherDureeFinBain2->Hide();
    m_textCtrlAfficherSecondeBain2->Hide();
    m_staticTextAfficherNumBain2->Hide();
    bSizerAfficherDureeBain2->Hide(this);
    
    m_staticAfficherDureeTotalBain3->Hide();
    m_textCtrlAfficherHeureBain3->Hide();
    m_staticTextAfficherDureeBain3->Hide();
    m_textCtrlAfficherMinuteBain3->Hide();
    m_staticTextAfficherDureeFinBain3->Hide();
    m_textCtrlAfficherSecondeBain3->Hide();
    m_staticTextAfficherNumBain3->Hide();
    bSizerAfficherDureeBain3->Hide(this);
    
    bSizerAfficherDureeBain3->Layout();
    bSizerAfficherDureeBain2->Layout();
    bSizerBainAfficherDuree->Layout();
    bSizerAfficherDureeBain1->Layout();
    bSizerAfficherBain->Layout();

    sbSizerGestionBainAfficher->Layout();
    Layout();

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
        string requete;
        requete = "SELECT numero_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                + ConversionEnString(id_selection);
        vector<string> numero_bain;
        
        if(m_bdd_anodisation->ExecuteSelect(requete))
        {
            numero_bain = m_bdd_anodisation->GetLastResult();
        }
        else
        {
            AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
        
        
        
        if(m_donnees_IHM->GetNombreBain() == "1")
        {
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                m_staticTextAfficherNumBain1->SetLabel(ConversionEnWxString(numero_bain[1]) + wxT(" :"));
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlAfficherHeureBain1->AppendText(DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlAfficherMinuteBain1->AppendText(DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain1->AppendText(DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    m_textCtrlAffichage->AppendText(wxT("Il n'y a pas de durée pour le bain 1 de ce processus.\n"));
                }
            }
            else
            {
                AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
        }
        else if(m_donnees_IHM->GetNombreBain() == "2")
        {
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_staticTextAfficherNumBain1->SetLabel(ConversionEnWxString(numero_bain[1]) + wxT(" :"));
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlAfficherHeureBain1->AppendText(DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlAfficherMinuteBain1->AppendText(DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain1->AppendText(DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    m_textCtrlAffichage->AppendText(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 2
            m_staticAfficherDureeTotalBain2->Show();
            m_textCtrlAfficherHeureBain2->Show();
            m_staticTextAfficherDureeBain2->Show();
            m_textCtrlAfficherMinuteBain2->Show();
            m_staticTextAfficherDureeFinBain2->Show();
            m_textCtrlAfficherSecondeBain2->Show();
            m_staticTextAfficherNumBain2->Show();
            bSizerAfficherDureeBain2->Show(this);
            
            bSizerAfficherDureeBain2->Layout();
            bSizerBainAfficherDuree->Layout();
            bSizerAfficherDureeBain1->Layout();
            bSizerAfficherBain->Layout();

            sbSizerGestionBainAfficher->Layout();
            Layout();
            
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[2];
                    
            m_staticTextAfficherNumBain2->SetLabel(ConversionEnWxString(numero_bain[2]) + wxT(" :"));
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain2 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain2.empty())
                {
                    m_textCtrlAfficherHeureBain2->AppendText(DecouperTexteDebut(duree_bain2[0], 2));
                    
                    wxString temp = DecouperTexteDebut(duree_bain2[0], 5);
                    m_textCtrlAfficherMinuteBain2->AppendText(DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain2->AppendText(DecouperTexteFin(duree_bain2[0], 6));
                }
                else
                {
                    m_textCtrlAffichage->AppendText(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
        }
        else if(m_donnees_IHM->GetNombreBain() == "3")
        {
            
        }
        else
        {
            m_textCtrlAffichage->AppendText(wxT("Pas de nombre de bain pour le remplissage.\n"));
        }
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
void EvtFramePrincipal::OnTextMaxLength(wxCommandEvent& event)
{
    m_textCtrlAffichage->AppendText(wxT("Nombre maximun de caractères entré dans ce champ.\n"));
}

void EvtFramePrincipal::OnCharEntered(wxKeyEvent& event)
{
    // TODO: Implement OnCharEntered
    event.Skip();
    /*switch(event.GetKeyCode())
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
    }*/
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
        wxString nombre_bain = m_donnees_IHM->GetNombreBain();

        double temp;
        nombre_bain.ToDouble(&temp);
        int nb_bain = temp;

        m_spinCtrlNombreBainModifier->SetValue(nb_bain);

        switch(nb_bain)
        {
            case 1:

            m_staticModifierDureeTotalBain2->Hide();
            m_choiceModifierBain2->Hide();
            m_staticModifierBain2->Hide();
            m_staticModifierDureeTotalBain2->Hide();
            m_textCtrlModifierHeureBain2->Hide();
            m_staticTextModifierDureeBain2->Hide();
            m_textCtrlModifierMinuteBain2->Hide();
            m_staticTextModifierDureeFinBain2->Hide();
            m_textCtrlModifierSecondeBain2->Hide();
            bSizerModifierDureeBain2->Hide(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        case 2:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        case 3:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Show();
            m_choiceModifierBain3->Show();
            m_staticModifierBain3->Show();
            m_staticModifierDureeTotalBain3->Show();
            m_textCtrlModifierHeureBain3->Show();
            m_staticTextModifierDureeBain3->Show();
            m_textCtrlModifierMinuteBain3->Show();
            m_staticTextModifierDureeFinBain3->Show();
            m_textCtrlModifierSecondeBain3->Show();
            bSizerModifierDureeBain3->Show(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

            default:

                break;
        }
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

void EvtFramePrincipal::OnSpinCtrlModifierBain(wxSpinEvent& event)
{
    int nombre_bain = m_spinCtrlNombreBainModifier->GetValue();
    // cout << "Nombre de bain : " << nombre_bain << endl;

    switch(nombre_bain)
    {
        case 1:

            m_staticModifierDureeTotalBain2->Hide();
            m_choiceModifierBain2->Hide();
            m_staticModifierBain2->Hide();
            m_staticModifierDureeTotalBain2->Hide();
            m_textCtrlModifierHeureBain2->Hide();
            m_staticTextModifierDureeBain2->Hide();
            m_textCtrlModifierMinuteBain2->Hide();
            m_staticTextModifierDureeFinBain2->Hide();
            m_textCtrlModifierSecondeBain2->Hide();
            bSizerModifierDureeBain2->Hide(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        case 2:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        case 3:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Show();
            m_choiceModifierBain3->Show();
            m_staticModifierBain3->Show();
            m_staticModifierDureeTotalBain3->Show();
            m_textCtrlModifierHeureBain3->Show();
            m_staticTextModifierDureeBain3->Show();
            m_textCtrlModifierMinuteBain3->Show();
            m_staticTextModifierDureeFinBain3->Show();
            m_textCtrlModifierSecondeBain3->Show();
            bSizerModifierDureeBain3->Show(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        default:

            break;
    }
}

void EvtFramePrincipal::OnApplyButtonModifierClick(wxCommandEvent& event)
{
    bool erreur = false;
    char* car = ";";
    string nom_processus;
    string duree_total;
    string ordre;
    string duree_bain1, duree_bain2 = "", duree_bain3 = "";
    string num_bain1, num_bain2, num_bain3;
    unsigned int nombre_bain = m_spinCtrlNombreBainModifier->GetValue();
    vector<string> ordre_separe;
    wxString id_selection = GardeIdSelection(m_listBoxModifierProcessus->GetStringSelection());
    wxString message;
    wxUniChar caractere(*car);
    
    // Vérification du champ nom du processus s'il il est rempli
    if(!m_textCtrlNomModifier->IsEmpty())
    {
        nom_processus = ConversionEnString(m_textCtrlNomModifier->GetValue());
    }
    else
    {
        erreur = true;
        message << wxT("Le champ nom du processus est vide.\n");
    }

    // Vérification du champ ordre des trajectoires s'il il est rempli
    if(!m_textCtrlDureeTotalHeureModifier->IsEmpty() && !m_textCtrlDureeTotalMinuteModifier->IsEmpty() && !m_textCtrlDureeTotalSecondeModifier->IsEmpty())
    {
        duree_total = ConversionEnString(m_textCtrlDureeTotalHeureModifier->GetValue()) + ":"
                    + ConversionEnString(m_textCtrlDureeTotalMinuteModifier->GetValue()) + ":"
                    + ConversionEnString(m_textCtrlDureeTotalSecondeModifier->GetValue());
    }
    else
    {
        erreur = true;
        message << wxT("L'un ou des champs de la durée total est/sont vide.\n");
    }

    // Vérification du champ ordre trajectoire s'il il est rempli
    if(!m_textCtrlOrdreTrajectoiresModifier->IsEmpty())
    {
        wxString ordrewx = m_textCtrlOrdreTrajectoiresModifier->GetValue();
        
        if(ordrewx.length() == 1)
        {
            ordrewx << wxT(";") << ordrewx;
            wxLogDebug(ordrewx);
        }
        else if(ordrewx.length() == 2)
        {
            ordrewx << ordrewx;
            wxLogDebug(ordrewx);
        }
        
        if(ordrewx.EndsWith(wxT(";")))
        {
            ordrewx.RemoveLast();
        }
        
        ordre = ConversionEnString(ordrewx);
        
        unsigned int nb_point_virgule = ordrewx.Freq(caractere);
        unsigned int position;
        wxString temp;
        
        for(unsigned int i = 0; i < nb_point_virgule+1; i++)
        {
            if(i == 0)
            {
                position = ordrewx.find(";");
                ordre_separe.push_back(ConversionEnString(DecouperTexteDebut(ordrewx, position)));
            }
            else
            {
                if(i == nb_point_virgule)
                {
                    position = ordrewx.find(";");
                    ordre_separe.push_back(ConversionEnString(DecouperTexteFin(ordrewx, position+1)));
                }
                else
                {
                    position = ordrewx.find(";");
                    temp.clear();
                    temp = DecouperTexteFin(ordrewx, position+1);
                    position = temp.find(";");
                    ordre_separe.push_back(ConversionEnString(DecouperTexteDebut(temp, position)));
                    ordrewx.clear();
                    ordrewx = (DecouperTexteFin(temp, position));
                }
                
            }
        }
    }
    else
    {
        message << wxT("Le champ de la trajectoire est vide.\n");
    }

    // Vérification en fonction du nombre de bain
    switch(nombre_bain)
    {
        case 1:
            // Vérification des champs du bain 1 qu'il ont bien été rempli
            if(!m_textCtrlModifierHeureBain1->IsEmpty() && !m_textCtrlModifierMinuteBain1->IsEmpty()
               && !m_textCtrlModifierSecondeBain1->IsEmpty())
            {
                duree_bain1 = ConversionEnString(m_textCtrlModifierHeureBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierMinuteBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierSecondeBain1->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }

            break;

        case 2:
            num_bain1 = m_choiceCreerBain1->GetStringSelection();
            num_bain2 = m_choiceCreerBain2->GetStringSelection();
            
            if(num_bain1 == num_bain2)
            {
                erreur = true;
                message << wxT("Les deux numéros de bain sont identique.\n");
            }
            
            // Vérification des champs du bain 1 qu'ils ont bien été rempli
            if(!m_textCtrlModifierHeureBain1->IsEmpty() && !m_textCtrlModifierMinuteBain1->IsEmpty()
               && !m_textCtrlModifierSecondeBain1->IsEmpty())
            {
                duree_bain1 = ConversionEnString(m_textCtrlModifierHeureBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierMinuteBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierSecondeBain1->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }

            // Vérification des champs du bain 2 qu'ils ont bien été rempli
            if(!m_textCtrlModifierHeureBain2->IsEmpty() && !m_textCtrlModifierMinuteBain2->IsEmpty()
               && !m_textCtrlModifierSecondeBain2->IsEmpty())
            {
                duree_bain2 = ConversionEnString(m_textCtrlModifierHeureBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierMinuteBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierSecondeBain2->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
            }

            break;

        case 3:
            num_bain1 = m_choiceCreerBain1->GetStringSelection();
            num_bain2 = m_choiceCreerBain2->GetStringSelection();
            num_bain3 = m_choiceCreerBain2->GetStringSelection();
            
            if(num_bain1 == num_bain2 && num_bain1 == num_bain3 && num_bain2 == num_bain3)
            {
                erreur = true;
                message << wxT("Des numéros de bain sont identique.\n");
            }
            
            // Vérification des champs du bain 1 qu'ils ont bien été rempli
            if(!m_textCtrlModifierHeureBain1->IsEmpty() && !m_textCtrlModifierMinuteBain1->IsEmpty()
               && !m_textCtrlModifierSecondeBain1->IsEmpty())
            {
                duree_bain1 = ConversionEnString(m_textCtrlModifierHeureBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierMinuteBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierSecondeBain1->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }

            // Vérification des champs du bain 2 qu'ils ont bien été rempli
            if(!m_textCtrlModifierHeureBain2->IsEmpty() && !m_textCtrlModifierMinuteBain2->IsEmpty()
               && !m_textCtrlModifierSecondeBain2->IsEmpty())
            {
                duree_bain2 = ConversionEnString(m_textCtrlModifierHeureBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierMinuteBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierSecondeBain2->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
            }

            // Vérification des champs du bain 3 qu'ils ont bien été rempli
            if(!m_textCtrlModifierHeureBain3->IsEmpty() && !m_textCtrlModifierMinuteBain3->IsEmpty()
               && !m_textCtrlModifierSecondeBain3->IsEmpty())
            {
                duree_bain3 = ConversionEnString(m_textCtrlModifierHeureBain3->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierMinuteBain3->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlModifierSecondeBain3->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 3 est/sont vide.\n");
            }

            break;

        default:

            break;
    }
    
    if(erreur)
    {
        string id_p = m_bdd_anodisation->DernierIdProcessus();
        cout << "id_p : " << id_p << endl;
        wxMessageBox(message, "Responsable de production - Champs vide !",
                     wxOK_DEFAULT | wxICON_EXCLAMATION | wxCENTRE | wxSTAY_ON_TOP, this);
    }
    else
    {
        string requete = "UPDATE processus SET nom_processus='" + nom_processus
                       + "', duree_processus='" + duree_total
                       + "', nombre_bain=" +  IntEnString(nombre_bain)
                       + "WHERE id_processus=" + ConversionEnString(id_selection);
        
        if(m_bdd_anodisation->ExecuteUpdate(requete))
        {
            switch(nombre_bain)
            {
                case 1:
                    for(unsigned int i =0; i < ordre_separe.size(); i++)
                    {
                        requete = "UPDATE intermediaire_processus_trajectoires SET id_p=" + ConversionEnString(id_selection)
                                + ", id_t=" + ordre_separe[i]
                                + ", ordre_trajectoires='" + ordre
                                + "', numero_bain=" + num_bain1
                                + ", duree_bain='" + duree_bain1
                                + "' WHERE id_p=" + ConversionEnString(id_selection);
                                
                        cout << requete << endl;
                        if(!m_bdd_anodisation->ExecuteInsert(requete))
                        {
                            AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                        }
                        
                        VideListBox();
                        RempliListBox();
                    }
                    break;
                
                case 2:
                    
                    break;
                
                case 3:
                    
                    break;
                
                default:
                    
                    break;
                
            }
        }
        else
        {
            AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
    }
    VideListBox();
    RempliListBox();
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
        wxString nombre_bain = m_donnees_IHM->GetNombreBain();

        double temp;
        nombre_bain.ToDouble(&temp);
        int nb_bain = temp;

        m_spinCtrlNombreBainModifier->SetValue(nb_bain);

        switch(nb_bain)
        {
            case 1:

                m_staticModifierDureeTotalBain2->Hide();
                m_textCtrlModifierHeureBain2->Hide();
                m_staticTextModifierDureeBain2->Hide();
                m_textCtrlModifierMinuteBain2->Hide();
                m_staticTextModifierDureeFinBain2->Hide();
                m_textCtrlModifierSecondeBain2->Hide();
                bSizerModifierDureeBain2->Hide(this);

                m_staticModifierDureeTotalBain3->Hide();
                m_textCtrlModifierHeureBain3->Hide();
                m_staticTextModifierDureeBain3->Hide();
                m_textCtrlModifierMinuteBain3->Hide();
                m_staticTextModifierDureeFinBain3->Hide();
                m_textCtrlModifierSecondeBain3->Hide();
                bSizerModifierDureeBain3->Hide(this);

                bSizerModifierDureeBain2->Layout();
                bSizerModifierDureeBain3->Layout();
                bSizerBainModifierDuree->Layout();
                bSizerModifierDureeBain1->Layout();
                bSizerModifierBain->Layout();

                sbSizerGestionBainModifier->Layout();
                Layout();

                break;

            case 2:

                m_staticModifierDureeTotalBain2->Show();
                m_textCtrlModifierHeureBain2->Show();
                m_staticTextModifierDureeBain2->Show();
                m_textCtrlModifierMinuteBain2->Show();
                m_staticTextModifierDureeFinBain2->Show();
                m_textCtrlModifierSecondeBain2->Show();
                bSizerModifierDureeBain2->Show(this);

                m_staticModifierDureeTotalBain3->Hide();
                m_textCtrlModifierHeureBain3->Hide();
                m_staticTextModifierDureeBain3->Hide();
                m_textCtrlModifierMinuteBain3->Hide();
                m_staticTextModifierDureeFinBain3->Hide();
                m_textCtrlModifierSecondeBain3->Hide();
                bSizerModifierDureeBain3->Hide(this);

                bSizerModifierDureeBain2->Layout();
                bSizerModifierDureeBain3->Layout();
                bSizerBainModifierDuree->Layout();
                bSizerModifierDureeBain1->Layout();
                bSizerModifierBain->Layout();

                sbSizerGestionBainModifier->Layout();
                Layout();

                break;

            case 3:

                m_staticModifierDureeTotalBain2->Show();
                m_textCtrlModifierHeureBain2->Show();
                m_staticTextModifierDureeBain2->Show();
                m_textCtrlModifierMinuteBain2->Show();
                m_staticTextModifierDureeFinBain2->Show();
                m_textCtrlModifierSecondeBain2->Show();
                bSizerModifierDureeBain2->Show(this);

                m_staticModifierDureeTotalBain3->Show();
                m_textCtrlModifierHeureBain3->Show();
                m_staticTextModifierDureeBain3->Show();
                m_textCtrlModifierMinuteBain3->Show();
                m_staticTextModifierDureeFinBain3->Show();
                m_textCtrlModifierSecondeBain3->Show();
                bSizerModifierDureeBain3->Show(this);

                bSizerModifierDureeBain2->Layout();
                bSizerModifierDureeBain3->Layout();
                bSizerBainModifierDuree->Layout();
                bSizerModifierDureeBain1->Layout();
                bSizerModifierBain->Layout();

                sbSizerGestionBainModifier->Layout();
                Layout();

                break;

            default:

                break;
        }
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
    // Vider les champs
    m_textCtrlDureeTotalHeureCreer->Clear();
    m_textCtrlDureeTotalMinuteCreer->Clear();
    m_textCtrlDureeTotalSecondeCreer->Clear();
    m_textCtrlNomCreer->Clear();
    m_textCtrlOrdreTrajectoiresCreer->Clear();
    m_spinCtrlNombreBainCreer->SetValue(1);
    m_textCtrlCreerHeureBain1->Clear();
    m_textCtrlCreerMinuteBain1->Clear();
    m_textCtrlCreerSecondeBain1->Clear();
    m_textCtrlCreerHeureBain2->Clear();
    m_textCtrlCreerMinuteBain2->Clear();
    m_textCtrlCreerSecondeBain2->Clear();
    m_textCtrlCreerHeureBain3->Clear();
    m_textCtrlCreerMinuteBain3->Clear();
    m_textCtrlCreerSecondeBain3->Clear();
    
    m_choiceCreerBain1->SetSelection(0);
    
    // Cacher les réglage des bain 2 et 3
    m_staticCreerDureeTotalBain2->Hide();
    m_choiceCreerBain2->Hide();
    m_choiceCreerBain2->SetSelection(1);
    m_staticCreerBain2->Hide();
    m_textCtrlCreerHeureBain2->Hide();
    m_staticTextCreerDureeBain2->Hide();
    m_textCtrlCreerMinuteBain2->Hide();
    m_staticTextCreerDureeFinBain2->Hide();
    m_textCtrlCreerSecondeBain2->Hide();
    bSizerCreerDureeBain2->Hide(this);

    m_staticCreerDureeTotalBain3->Hide();
    m_choiceCreerBain3->Hide();
    m_choiceCreerBain3->SetSelection(2);
    m_staticCreerBain3->Hide();
    m_textCtrlCreerHeureBain3->Hide();
    m_staticTextCreerDureeBain3->Hide();
    m_textCtrlCreerMinuteBain3->Hide();
    m_staticTextCreerDureeFinBain3->Hide();
    m_textCtrlCreerSecondeBain3->Hide();
    bSizerCreerDureeBain3->Hide(this);

    bSizerCreerDureeBain2->Layout();
    bSizerCreerDureeBain3->Layout();
    bSizerBainCreerDuree->Layout();
    bSizerCreerDureeBain1->Layout();
    bSizerCreerBain->Layout();

    sbSizerGestionBainCreer->Layout();
    Layout();
}

void EvtFramePrincipal::OnSaveButtonCreerClick(wxCommandEvent& event)
{
    bool erreur = false;
    char* car = ";";
    string nom_processus;
    string duree_total;
    string ordre;
    string duree_bain1, duree_bain2 = "", duree_bain3 = "";
    string num_bain1, num_bain2, num_bain3;
    unsigned int nombre_bain = m_spinCtrlNombreBainCreer->GetValue();
    vector<string> ordre_separe;
    wxString message;
    wxUniChar caractere(*car);
    
    // Vérification du champ nom du processus s'il il est rempli
    if(!m_textCtrlNomCreer->IsEmpty())
    {
        nom_processus = ConversionEnString(m_textCtrlNomCreer->GetValue());
    }
    else
    {
        erreur = true;
        message << wxT("Le champ nom du processus est vide.\n");
    }

    // Vérification du champ ordre des trajectoires s'il il est rempli
    if(!m_textCtrlDureeTotalHeureCreer->IsEmpty() && !m_textCtrlDureeTotalMinuteCreer->IsEmpty() && !m_textCtrlDureeTotalSecondeCreer->IsEmpty())
    {
        duree_total = ConversionEnString(m_textCtrlDureeTotalHeureCreer->GetValue()) + ":"
                    + ConversionEnString(m_textCtrlDureeTotalMinuteCreer->GetValue()) + ":"
                    + ConversionEnString(m_textCtrlDureeTotalSecondeCreer->GetValue());
    }
    else
    {
        erreur = true;
        message << wxT("L'un ou des champs de la durée total est/sont vide.\n");
    }

    // Vérification du champ ordre trajectoire s'il il est rempli
    if(!m_textCtrlOrdreTrajectoiresCreer->IsEmpty())
    {
        wxString ordrewx = m_textCtrlOrdreTrajectoiresCreer->GetValue();
        
        if(ordrewx.length() == 1)
        {
            ordrewx << wxT(";") << ordrewx;
            wxLogDebug(ordrewx);
        }
        else if(ordrewx.length() == 2)
        {
            ordrewx << ordrewx;
            wxLogDebug(ordrewx);
        }
        
        if(ordrewx.EndsWith(wxT(";")))
        {
            ordrewx.RemoveLast();
        }
        
        ordre = ConversionEnString(ordrewx);
        
        unsigned int nb_point_virgule = ordrewx.Freq(caractere);
        unsigned int position;
        wxString temp;
        
        for(unsigned int i = 0; i < nb_point_virgule+1; i++)
        {
            if(i == 0)
            {
                position = ordrewx.find(";");
                ordre_separe.push_back(ConversionEnString(DecouperTexteDebut(ordrewx, position)));
            }
            else
            {
                if(i == nb_point_virgule)
                {
                    position = ordrewx.find(";");
                    ordre_separe.push_back(ConversionEnString(DecouperTexteFin(ordrewx, position+1)));
                }
                else
                {
                    position = ordrewx.find(";");
                    temp.clear();
                    temp = DecouperTexteFin(ordrewx, position+1);
                    position = temp.find(";");
                    ordre_separe.push_back(ConversionEnString(DecouperTexteDebut(temp, position)));
                    ordrewx.clear();
                    ordrewx = (DecouperTexteFin(temp, position));
                }
                
            }
        }
    }
    else
    {
        erreur = true;
        message << wxT("Le champ de la trajectoire est vide.\n");
    }

    // Vérification en fonction du nombre de bain
    switch(nombre_bain)
    {
        case 1:
            // Vérification des champs du bain 1 qu'il ont bien été rempli
            if(!m_textCtrlCreerHeureBain1->IsEmpty() && !m_textCtrlCreerMinuteBain1->IsEmpty()
               && !m_textCtrlCreerSecondeBain1->IsEmpty())
            {
                duree_bain1 = ConversionEnString(m_textCtrlCreerHeureBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerMinuteBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerSecondeBain1->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }

            break;

        case 2:
            num_bain1 = m_choiceCreerBain1->GetStringSelection();
            num_bain2 = m_choiceCreerBain2->GetStringSelection();
            
            if(num_bain1 == num_bain2)
            {
                erreur = true;
                message << wxT("Les deux numéros de bain sont identique.\n");
            }
            
            // Vérification des champs du bain 1 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain1->IsEmpty() && !m_textCtrlCreerMinuteBain1->IsEmpty()
               && !m_textCtrlCreerSecondeBain1->IsEmpty())
            {
                duree_bain1 = ConversionEnString(m_textCtrlCreerHeureBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerMinuteBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerSecondeBain1->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }
            
            // Vérification des champs du bain 2 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain2->IsEmpty() && !m_textCtrlCreerMinuteBain2->IsEmpty()
               && !m_textCtrlCreerSecondeBain2->IsEmpty())
            {
                duree_bain2 = ConversionEnString(m_textCtrlCreerHeureBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerMinuteBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerSecondeBain2->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
            }

            break;

        case 3:
            num_bain1 = m_choiceCreerBain1->GetStringSelection();
            num_bain2 = m_choiceCreerBain2->GetStringSelection();
            num_bain3 = m_choiceCreerBain2->GetStringSelection();
            
            if(num_bain1 == num_bain2 && num_bain1 == num_bain3 && num_bain2 == num_bain3)
            {
                erreur = true;
                message << wxT("Des numéros de bain sont identique.\n");
            }
            
            // Vérification des champs du bain 1 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain1->IsEmpty() && !m_textCtrlCreerMinuteBain1->IsEmpty()
               && !m_textCtrlCreerSecondeBain1->IsEmpty())
            {
                duree_bain1 = ConversionEnString(m_textCtrlCreerHeureBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerMinuteBain1->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerSecondeBain1->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }

            // Vérification des champs du bain 2 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain2->IsEmpty() && !m_textCtrlCreerMinuteBain2->IsEmpty()
               && !m_textCtrlCreerSecondeBain2->IsEmpty())
            {
                duree_bain2 = ConversionEnString(m_textCtrlCreerHeureBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerMinuteBain2->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerSecondeBain2->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
            }

            // Vérification des champs du bain 3 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain3->IsEmpty() && !m_textCtrlCreerMinuteBain3->IsEmpty()
               && !m_textCtrlCreerSecondeBain3->IsEmpty())
            {
                duree_bain3 = ConversionEnString(m_textCtrlCreerHeureBain3->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerMinuteBain3->GetValue()) + ":"
                            + ConversionEnString(m_textCtrlCreerSecondeBain3->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 3 est/sont vide.\n");
            }

            break;

        default:

            break;
    }
    
    if(erreur)
    {
        //string id_p = m_bdd_anodisation->DernierIdProcessus();
        //cout << "id_p : " << id_p << endl;
        wxMessageBox(message, "Responsable de production - Champs vide !", wxOK_DEFAULT | wxICON_EXCLAMATION | wxCENTRE | wxSTAY_ON_TOP, this);
    }
    else
    {
        string requete = "INSERT INTO processus (nom_processus, duree_processus, nombre_bain) VALUES('" 
                        + nom_processus + "', '"
                        + duree_total + "', "
                        + IntEnString(nombre_bain) + ")";
        
        if(m_bdd_anodisation->ExecuteInsert(requete))
        {
            
            string id_p = m_bdd_anodisation->DernierIdProcessus();
            
            switch(nombre_bain)
            {
                case 1:
                    for(unsigned int i =0; i < ordre_separe.size(); i++)
                    {
                        requete = "INSERT INTO intermediaire_processus_trajectoires (id_p, id_t, ordre_trajectoires, numero_bain, duree_bain) VALUES ("
                                + id_p + ", "
                                + ordre_separe[i] + ", '"
                                + ordre + "', "
                                + num_bain1 + ", '"
                                + duree_bain1 + "')";
                                
                        cout << requete << endl;
                        if(!m_bdd_anodisation->ExecuteInsert(requete))
                        {
                            AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                        }
                    }
                    break;
                
                case 2:
                    
                    break;
                
                case 3:
                    
                    break;
                
                default:
                    
                    break;
                
            }
        }
        else
        {
            AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
    }
    
    VideListBox();
    RempliListBox();
}

void EvtFramePrincipal::OnSpinCtrlCreerBain(wxSpinEvent& event)
{
    int nombre_bain = m_spinCtrlNombreBainCreer->GetValue();
    // cout << "Nombre de bain : " << nombre_bain << endl;

    switch(nombre_bain)
    {
        case 1:

            m_staticCreerDureeTotalBain2->Hide();
            m_choiceCreerBain2->Hide();
            m_staticCreerBain2->Hide();
            m_textCtrlCreerHeureBain2->Hide();
            m_staticTextCreerDureeBain2->Hide();
            m_textCtrlCreerMinuteBain2->Hide();
            m_staticTextCreerDureeFinBain2->Hide();
            m_textCtrlCreerSecondeBain2->Hide();
            bSizerCreerDureeBain2->Hide(this);

            m_staticCreerDureeTotalBain3->Hide();
            m_choiceCreerBain3->Hide();
            m_staticCreerBain3->Hide();
            m_textCtrlCreerHeureBain3->Hide();
            m_staticTextCreerDureeBain3->Hide();
            m_textCtrlCreerMinuteBain3->Hide();
            m_staticTextCreerDureeFinBain3->Hide();
            m_textCtrlCreerSecondeBain3->Hide();
            bSizerCreerDureeBain3->Hide(this);

            bSizerCreerDureeBain2->Layout();
            bSizerCreerDureeBain3->Layout();
            bSizerBainCreerDuree->Layout();
            bSizerCreerDureeBain1->Layout();
            bSizerCreerBain->Layout();

            sbSizerGestionBainCreer->Layout();
            Layout();

            break;

        case 2:

            m_staticCreerDureeTotalBain2->Show();
            m_choiceCreerBain2->Show();
            m_staticCreerBain2->Show();
            m_textCtrlCreerHeureBain2->Show();
            m_staticTextCreerDureeBain2->Show();
            m_textCtrlCreerMinuteBain2->Show();
            m_staticTextCreerDureeFinBain2->Show();
            m_textCtrlCreerSecondeBain2->Show();
            bSizerCreerDureeBain2->Show(this);

            m_staticCreerDureeTotalBain3->Hide();
            m_choiceCreerBain3->Hide();
            m_staticCreerBain3->Hide();
            m_textCtrlCreerHeureBain3->Hide();
            m_staticTextCreerDureeBain3->Hide();
            m_textCtrlCreerMinuteBain3->Hide();
            m_staticTextCreerDureeFinBain3->Hide();
            m_textCtrlCreerSecondeBain3->Hide();
            bSizerCreerDureeBain3->Hide(this);

            bSizerCreerDureeBain2->Layout();
            bSizerCreerDureeBain3->Layout();
            bSizerBainCreerDuree->Layout();
            bSizerCreerDureeBain1->Layout();
            bSizerCreerBain->Layout();

            sbSizerGestionBainCreer->Layout();
            Layout();

            break;

        case 3:

            m_staticCreerDureeTotalBain2->Show();
            m_choiceCreerBain2->Show();
            m_staticCreerBain2->Show();
            m_textCtrlCreerHeureBain2->Show();
            m_staticTextCreerDureeBain2->Show();
            m_textCtrlCreerMinuteBain2->Show();
            m_staticTextCreerDureeFinBain2->Show();
            m_textCtrlCreerSecondeBain2->Show();
            bSizerCreerDureeBain2->Show(this);

            m_staticCreerDureeTotalBain3->Show();
            m_choiceCreerBain3->Show();
            m_staticCreerBain3->Show();
            m_textCtrlCreerHeureBain3->Show();
            m_staticTextCreerDureeBain3->Show();
            m_textCtrlCreerMinuteBain3->Show();
            m_staticTextCreerDureeFinBain3->Show();
            m_textCtrlCreerSecondeBain3->Show();
            bSizerCreerDureeBain3->Show(this);

            bSizerCreerDureeBain2->Layout();
            bSizerCreerDureeBain3->Layout();
            bSizerBainCreerDuree->Layout();
            bSizerCreerDureeBain1->Layout();
            bSizerCreerBain->Layout();

            sbSizerGestionBainCreer->Layout();
            Layout();

            break;

        default:

            break;
    }
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
            message << wxT("Supression du processus : ") << DecouperTexteFin(selection, separateur + 3)
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
    if(m_client_connecte)
    {
        m_client->ExecutionProcessus(GardeIdSelection(m_listBoxLancerProcessus->GetStringSelection()));
    }
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
    if(m_client_connecte)
    {
        m_client->StopProcessus();
    }
}

void EvtFramePrincipal::OnOkButtonTesterClick(wxCommandEvent& event)
{
    if(m_client_connecte)
    {
        m_client->TestProcessus(GardeIdSelection(m_listBoxTesterProcessus->GetStringSelection()));
    }
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
            // Cacher les StaticText et TextCtrl
            m_staticTextTypeTache->Hide();
            m_textCtrlTypeTache->Hide();
            m_staticTextNomTache->SetLabel(wxT("Il n’y a pas de tâche en cours."));
            m_textCtrlNomTache->Hide();
            m_staticDureeRestant->Hide();
            m_textCtrlDureeRestantHeure->Hide();
            m_staticTextDureeRestantMinute->Hide();
            m_textCtrlDureeRestantMinute->Hide();
            m_staticTextDureeRestantSeconde->Hide();
            m_textCtrlDureeRestantSeconde->Hide();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras est disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpVert);

            // Désactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Disable();
        }
        else
        {
            // Montrer les StaticText et TextCtrl
            m_staticTextTypeTache->Show();
            m_textCtrlTypeTache->Show();
            m_staticTextNomTache->SetLabel(wxT("Nom de la tâche : "));
            m_textCtrlNomTache->Show();
            m_staticDureeRestant->Show();
            m_textCtrlDureeRestantHeure->Show();
            m_staticTextDureeRestantMinute->Show();
            m_textCtrlDureeRestantMinute->Show();
            m_staticTextDureeRestantSeconde->Show();
            m_textCtrlDureeRestantSeconde->Show();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras n'est pas disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpRouge);

            // Réactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Enable();
        }

        // Réorganiser l'intérieur des sbSizer
        sbSizerTache->Layout();
        sbSizerDisponibiliteBras->Layout();
        Layout();
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
            // Cacher les StaticText et TextCtrl
            m_staticTextTypeTache->Hide();
            m_textCtrlTypeTache->Hide();
            m_staticTextNomTache->SetLabel(wxT("Il n’y a pas de tâche en cours."));
            m_textCtrlNomTache->Hide();
            m_staticDureeRestant->Hide();
            m_textCtrlDureeRestantHeure->Hide();
            m_staticTextDureeRestantMinute->Hide();
            m_textCtrlDureeRestantMinute->Hide();
            m_staticTextDureeRestantSeconde->Hide();
            m_textCtrlDureeRestantSeconde->Hide();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras est disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpVert);

            // Désactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Disable();
        }
        else
        {
            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras n'est pas disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpRouge);

            // Réactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Enable();

            // Montrer les StaticText et TextCtrl
            m_staticTextTypeTache->Show();
            m_textCtrlTypeTache->Show();
            m_staticTextNomTache->SetLabel(wxT("Nom de la tâche : "));
            m_textCtrlNomTache->Show();
            m_staticDureeRestant->Show();
            m_textCtrlDureeRestantHeure->Show();
            m_staticTextDureeRestantMinute->Show();
            m_textCtrlDureeRestantMinute->Show();
            m_staticTextDureeRestantSeconde->Show();
            m_textCtrlDureeRestantSeconde->Show();

            // Vider les TextCtrl
            m_textCtrlTypeTache->Clear();
            m_textCtrlNomTache->Clear();
            m_textCtrlDureeRestantHeure->Clear();
            m_textCtrlDureeRestantMinute->Clear();
            m_textCtrlDureeRestantSeconde->Clear();

            // Récupération des valeurs
            wxString type = tache[0];
            wxString id_tache = tache[1];

            wxString message;
            string requete;

            if(type == "Processus")
            {
                m_textCtrlTypeTache->AppendText(wxT("Processus"));

                // Nom du processus
                requete = "SELECT nom_processus FROM processus WHERE id_processus=" + id_tache;

                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> nom = m_bdd_anodisation->GetLastResult();
                    wxString temp = ConversionEnWxString(nom[0]);

                    int separateur = temp.find("   ");
                    wxString nomwx = DecouperTexteDebut(temp, separateur);
                    m_textCtrlNomTache->AppendText(nomwx);
                }
                else
                {
                    AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
            else if(type == "Trajectoire")
            {
                m_textCtrlTypeTache->AppendText(wxT("Trajectoire"));

                // Nom de la trajectoire
                requete = "SELECT nom_trajectoire FROM trajectoires WHERE id_trajectoire=" + id_tache;

                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> nom = m_bdd_anodisation->GetLastResult();
                    wxString temp = ConversionEnWxString(nom[0]);

                    int separateur = temp.find("   ");
                    wxString nomwx = DecouperTexteDebut(temp, separateur);
                    m_textCtrlNomTache->AppendText(nomwx);
                }
                else
                {
                    AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
            else if(type == "Mouvement")
            {
                m_textCtrlTypeTache->AppendText(wxT("Mouvement"));

                // Nom du mouvement
                requete = "SELECT nom_mouvement FROM mouvements WHERE id_mouvement=" + id_tache;

                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> nom = m_bdd_anodisation->GetLastResult();
                    wxString temp = ConversionEnWxString(nom[0]);

                    int separateur = temp.find("   ");
                    wxString nomwx = DecouperTexteDebut(temp, separateur);
                    m_textCtrlNomTache->AppendText(nomwx);
                }
                else
                {
                    AfficheErreurRemplisage(ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
            else  // Ne devrais pas arriver
            {
                wxString message = wxT("Une erreur est survenue.\t\t");
                wxLogError(message);
            }
        }

        // Réorganiser l'intérieur des sbSizer
        sbSizerTache->Layout();
        sbSizerDisponibiliteBras->Layout();
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

    if(message.EndsWith(wxT(": il a disparu.\n")))
    {
        wxLogError(wxT("Le serveur de communication de la Raspberry pi c'est déconnecté!"));
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

string EvtFramePrincipal::IntEnString(int nombre)
{
    ostringstream temp;
    temp << nombre;

    return temp.str();
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
