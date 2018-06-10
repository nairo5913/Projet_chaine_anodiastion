/*******************************************************************************
 *  Fichier:  EvtFramePrincipal.cpp
 *  Projet:   Chaîne d'anodisation
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
    
    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = -1;
    widths[1] = 140;
    m_statusBar->SetStatusWidths(2, widths);
    AfficheStatus(wxT("Déconnecté"), 1);
    m_evt_panel_responsable->SetFrame(this);
    m_evt_panel_regleur->SetFrame(this);
    
    // Connexion des événements du client
    Connect(ID_CLIENT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheInfoClient), NULL, this);
    Connect(ID_CLIENT + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessageClient), NULL, this);
    Connect(ID_CLIENT + 2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AgitServeurPerdu), NULL, this);
    
    Connect(ID_RESPONSABLE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessagePanel), NULL, this);
    Connect(ID_RESPONSABLE + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheErreurRemplisage), NULL, this);
    
    Connect(ID_REGLEUR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessagePanel), NULL, this);
    Connect(ID_REGLEUR + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheErreurRemplisage), NULL, this);
}
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Méthode générées par wxFormBuilder                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
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
            
            delete m_donnees_IHM_regleur;
            delete m_donnees_IHM_responsable;
            
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
            
            wxString message;
            bool erreur = false;
            
            // Changement du label du toggle button
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
            
            m_bdd_anodisation = new DataAnodisation(DSN);
            m_donnees_IHM_responsable = new DonneesIHMresponsable(m_bdd_anodisation);
            m_donnees_IHM_regleur = new DonneesIHMregleur(m_bdd_anodisation);

            // Tester connexion à la BdD
            if(m_bdd_anodisation->IsConnexionOK())
            {
                m_bdd_connecte = true;
                m_textCtrlAffichage->AppendText(wxT("Connecté à la BdD.\n"));
            }
            else
            {
                message << wxT("\t Erreur lors de la connection à la base de données.\n") << wxT("\n")
                        << wxT("Raison : ") << ConversionEnWxString(m_bdd_anodisation->GetLastError()) << wxT("\n");

                erreur = true;
            }

            m_client = new Client(IP, PORT, this, m_login);
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
            
            if(m_login == "Responsable")
            {
                m_evt_panel_responsable->Show();
                m_evt_panel_responsable->SetBdD(m_bdd_anodisation);
                m_evt_panel_responsable->SetDonneesIHM(m_donnees_IHM_responsable);
                m_evt_panel_responsable->SetClient(m_client);
                m_evt_panel_responsable->SetClientConnecte(m_client_connecte);
                m_evt_panel_responsable->RempliListBox();
            }
            else if(m_login == "Regleur")
            {
                m_panelChoix->Show();
                m_evt_panel_regleur->SetBdD(m_bdd_anodisation);
                m_evt_panel_regleur->SetDonneesIHM(m_donnees_IHM_regleur);
                m_evt_panel_regleur->SetClient(m_client);
                m_evt_panel_regleur->SetClientConnecte(m_client_connecte);
                m_evt_panel_regleur->RempliListBoxMouvements();
                m_evt_panel_regleur->RempliListBoxTrajectoires();
            }
            else
            {
                message.clear();
                message << wxT("Erreur avec le login. Il est donc impossible d'afficher les panels.\n");
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
        
        delete m_donnees_IHM_responsable;
        delete m_donnees_IHM_regleur;
        
        // Activation des textCtrl de connexion
        m_textCtrlLogin->Enable();
        m_textCtrlPass->Enable();
        m_staticTextLogin->Enable();
        m_staticTextPass->Enable();

        // Résactiver le logo Ozanam
        // m_bitmapLogoOzanam->Enable();

        // Masquage des onglets de gestion des processus
        if(m_login == "Responsable")
        {
            m_evt_panel_responsable->Hide();
            m_evt_panel_responsable->SetBdD(m_bdd_anodisation);
            m_evt_panel_responsable->SetClient(m_client);
            m_evt_panel_responsable->SetClientConnecte(m_client_connecte);
            m_evt_panel_responsable->SetFrame(this);
            m_evt_panel_responsable->VideListBox();
        }
        else if(m_login == "Regleur")
        {
            m_panelChoix->Hide();
            m_evt_panel_regleur->Hide();
            m_evt_panel_regleur->CacheNoteBookMouvement();
            m_evt_panel_regleur->CacheNoteBookTrajectoire();
            m_evt_panel_regleur->SetBdD(m_bdd_anodisation);
            m_evt_panel_regleur->SetClient(m_client);
            m_evt_panel_regleur->SetClientConnecte(m_client_connecte);
            m_evt_panel_regleur->VideListBoxMouvements();
            m_evt_panel_regleur->VideListBoxTrajectoires();
        }

        // Changement du label du toggle button
        m_toggleBtnConnexion->SetValue(false);
        m_toggleBtnConnexion->SetLabel(wxT("Connexion"));

        // Mise à jour de la statue bar
        AfficheStatus(wxT("Déconnecté"), 1);

        Layout();
    }
}
//
// Saisie au clavier
//
void EvtFramePrincipal::OnCharEntered(wxKeyEvent& event)
{
    event.Skip();
}

void EvtFramePrincipal::OnTextMaxLength(wxCommandEvent& event)
{
    m_textCtrlAffichage->AppendText(wxT("Nombre maximun de caractères entré dans ce champ.\n"));
}
//
// Boutons
//
void EvtFramePrincipal::OnButtonViderAffichageClick(wxCommandEvent& event)
{
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::OnButtonChoixTrajectoiresClicks(wxCommandEvent& event) 
{
    m_evt_panel_regleur->Show();
    m_evt_panel_regleur->MontreNoteBookTrajectoire();
    m_evt_panel_regleur->CacheNoteBookMouvement();
    Layout();
}

void EvtFramePrincipal::OnButtonChoixMouvementsClicks(wxCommandEvent& event)
{
    
    m_evt_panel_regleur->Show();
    m_evt_panel_regleur->MontreNoteBookMouvement();
    m_evt_panel_regleur->CacheNoteBookTrajectoire();
    Layout();
}
//
// Barre de menu
//
void EvtFramePrincipal::OnMenuQuitterSelection(wxCommandEvent& event)
{
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
            
            delete m_donnees_IHM_regleur;
            delete m_donnees_IHM_responsable;

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
//                                                                            //
//                            Méthode du programme                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
bool EvtFramePrincipal::VerificationLogin(wxString login, wxString pass)
{
    bool retour = false;
    
    if(login == "Responsable" && pass == "responsable")
    {
        m_login = wxT("Responsable");
        retour = true;
    }
    else if(login == "Régleur" && pass == "regleur")
    {
        m_login = wxT("Regleur");
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
    m_evt_panel_responsable->SetClientConnecte(m_client_connecte);
    m_evt_panel_regleur->SetClientConnecte(m_client_connecte);

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

void EvtFramePrincipal::AfficheErreurRemplisage(wxCommandEvent& event)
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
    message << wxT("Raison : ") << event.GetString() << wxT("\n");

    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxColour("SLATE BLUE")));
    m_textCtrlAffichage->AppendText(message);
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
}

void EvtFramePrincipal::AfficheMessagePanel(wxCommandEvent& event)
{
    m_textCtrlAffichage->AppendText(event.GetString());
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
