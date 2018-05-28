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
    m_identifie = false;
    m_fabrication = false;
    m_bdd_anodisation = new DataAnodisation(DSN);
    m_donnees_IHM = new DonneesIHM(m_bdd_anodisation);

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
//
////////////////////////////////////////////////////////////////////////////////
//  Méthode lié à l'IHM
////////////////////////////////////////////////////////////////////////////////
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
        if(m_client_connecte)
        {
            DeconnexionClient(wxT("Déconnexion depuis le poste responsable de production."));
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
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxGREEN));
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

void EvtFramePrincipal::OnListBoxAffichageSelection(wxCommandEvent& event)
{
    // m_textCtrlAffichage->AppendText(wxT("Selection liste affichage processus\n"));
    wxString selection = m_listBoxAffichageProcessus->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = GardeIdSelection(selection);
    
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
        wxString heure = DecouperTexteDebut(duree, 2);
        m_textCtrlDureeTotalHeureAfficher->AppendText(heure);
        
        wxString temp = DecouperTexteDebut(duree, 5);
        wxString minute = DecouperTexteFin(temp, 3);
        m_textCtrlDureeTotalMinuteAfficher->AppendText(minute);
        
        wxString seconde = DecouperTexteFin(duree, 6);
        m_textCtrlDureeTotalSecondeAfficher->AppendText(seconde);
        
        m_textCtrlAffichage->AppendText(duree + wxT("\n"));
        
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n")
                << wxT("Raison : ") << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }
    
    // Liste des trajectoires du processus
    /*if(m_donnees_IHM->RecupereListeTrajectoiresProcessus(ConversionEnString(id_selection)))
    {
        
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n")
                << wxT("Raison : ") << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }*/
    
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
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n")
                << wxT("Raison : ") << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }
    
    // Nombre de bain du processus
    /*if(m_donnees_IHM->RecupereNombreBain(ConversionEnString(id_selection)))
    {
        
        
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n")
                << wxT("Raison : ") << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }*/
    
    // Ordre des trajectoires
    /*if(m_donnees_IHM->RecupereOrdreTrajectoires(ConversionEnString(id_selection)))
    {
        
        
    }
    else
    {
        wxString message;
        message << wxT("\t Erreur lors de la requête à la base de données.\n") << wxT("\n")
                << wxT("Raison : ") << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");
        m_textCtrlAffichage->AppendText(message);
    }*/
}

void EvtFramePrincipal::OnListBoxModifierSelection(wxCommandEvent& event)
{
    // Récupération de la saisie
    wxString selection;
    selection << m_listBoxModifierProcessus->GetStringSelection() << wxT("\n");

    // Garder de l'id du processus
    wxString id_selection = GardeIdSelection(selection);
    wxLogDebug(wxT("Selection modifier processus : ") + id_selection);
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
    //
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
        if(m_client_connecte)
        {
            DeconnexionClient(wxT("Déconnexion depuis le poste responsable de production."));
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
//
////////////////////////////////////////////////////////////////////////////////
//  Méthode du programme
////////////////////////////////////////////////////////////////////////////////
//
bool EvtFramePrincipal::LancerFabrication(wxString id_processus)
{
    bool retour = false;

    //

    return retour;
}

void EvtFramePrincipal::VideListBox()
{
    m_listBoxAffichageProcessus->Clear();
    m_listBoxDetruireProcessus->Clear();
    m_listBoxLancerProcessus->Clear();
    m_listBoxModifierProcessus->Clear();
    m_listBoxTesterProcessus->Clear();
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

void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    DeconnexionClient(event.GetString());
}

//
// IHM
//
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
    wxString identifiant = wxT("Responsable");
    wxString motpasse = wxT("responsable");
    bool retour = false;

    if(identifiant == login && motpasse == pass)
    {
        retour = true;
    }

    return retour;
}

void EvtFramePrincipal::RempliListBox()
{
    if(m_donnees_IHM->RecupereListeProcessus())
    {
        vector<string> liste_processus = m_donnees_IHM->GetListeProcessus();

        // cout << "taille : " << liste_processus.size() << endl;
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
        m_textCtrlAffichage->AppendText(m_bdd_anodisation->GetLastError());
    }
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

wxString EvtFramePrincipal::DecouperTexteFin(wxString texte, int position)
{
    wxString fin(texte.substr(position));

    return fin;
}