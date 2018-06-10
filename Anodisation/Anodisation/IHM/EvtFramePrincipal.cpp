#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent )
:
FramePrincipal( parent )
{

}

void EvtFramePrincipal::OnCharEntered( wxKeyEvent& event )
{
    // TODO: Implement OnCharEntered
}

void EvtFramePrincipal::OnFrameClose( wxCloseEvent& event )
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

void EvtFramePrincipal::OnButtonConnexionToggle( wxCommandEvent& event )
{
    // TODO: Implement OnButtonConnexionToggle
}

void EvtFramePrincipal::OnTextMaxLength( wxCommandEvent& event )
{
    // TODO: Implement OnTextMaxLength
}

void EvtFramePrincipal::OnButtonChoixTrajectoiresClicks( wxCommandEvent& event )
{
    // TODO: Implement OnButtonChoixTrajectoiresClicks
}

void EvtFramePrincipal::OnButtonChoixMouvementsClicks( wxCommandEvent& event )
{
    // TODO: Implement OnButtonChoixMouvementsClicks
}

void EvtFramePrincipal::OnListBoxAffichageSelectionProcessus( wxCommandEvent& event )
{
// TODO: Implement OnListBoxAffichageSelectionProcessus
}

void EvtFramePrincipal::OnCharEnteredNum( wxKeyEvent& event )
{
    // TODO: Implement OnCharEnteredNum
}

void EvtFramePrincipal::OnListBoxModifierSelectionProcessus( wxCommandEvent& event )
{
// TODO: Implement OnListBoxModifierSelectionProcessus
}

void EvtFramePrincipal::OnApplyButtonModifierClick( wxCommandEvent& event )
{
    // TODO: Implement OnApplyButtonModifierClick
}

void EvtFramePrincipal::OnCharEnteredOrdre( wxKeyEvent& event )
{
    // TODO: Implement OnCharEnteredOrdre
}

void EvtFramePrincipal::OnSpinCtrlModifierBain( wxSpinEvent& event )
{
    // TODO: Implement OnSpinCtrlModifierBain
}

void EvtFramePrincipal::OnCancelButtonModiffierClick( wxCommandEvent& event )
{
    // TODO: Implement OnCancelButtonModiffierClick
}

void EvtFramePrincipal::OnSaveButtonCreerClick( wxCommandEvent& event )
{
    // TODO: Implement OnSaveButtonCreerClick
}

void EvtFramePrincipal::OnSpinCtrlCreerBain( wxSpinEvent& event )
{
    // TODO: Implement OnSpinCtrlCreerBain
}

void EvtFramePrincipal::OnCancelButtonCreerClick( wxCommandEvent& event )
{
    // TODO: Implement OnCancelButtonCreerClick
}

void EvtFramePrincipal::OnListBoxDetruireSelectionProcessus( wxCommandEvent& event )
{
// TODO: Implement OnListBoxDetruireSelectionProcessus
}

void EvtFramePrincipal::OnApplyButtonDetruireClick( wxCommandEvent& event )
{
    // TODO: Implement OnApplyButtonDetruireClick
}

void EvtFramePrincipal::OnListBoxLancerSelectionProcessus( wxCommandEvent& event )
{
// TODO: Implement OnListBoxLancerSelectionProcessus
}

void EvtFramePrincipal::OnOkButtonLancerClick( wxCommandEvent& event )
{
    // TODO: Implement OnOkButtonLancerClick
}

void EvtFramePrincipal::OnListBoxTesterSelectionProcessus( wxCommandEvent& event )
{
// TODO: Implement OnListBoxTesterSelectionProcessus
}

void EvtFramePrincipal::OnStopButtonTesterClick( wxCommandEvent& event )
{
    // TODO: Implement OnStopButtonTesterClick
}

void EvtFramePrincipal::OnOkButtonTesterClick( wxCommandEvent& event )
{
    // TODO: Implement OnOkButtonTesterClick
}

void EvtFramePrincipal::OnButtonDisponibiliteBrasClick( wxCommandEvent& event )
{
    // TODO: Implement OnButtonDisponibiliteBrasClick
}

void EvtFramePrincipal::OnButtonTacheEnCoursClick( wxCommandEvent& event )
{
    // TODO: Implement OnButtonTacheEnCoursClick
}

void EvtFramePrincipal::OnListBoxAffichageSelectionMouvements( wxCommandEvent& event )
{
    // TODO: Implement OnListBoxAffichageSelectionMouvements
}

void EvtFramePrincipal::OnListBoxModifierSelectionMouvements( wxCommandEvent& event )
{
// TODO: Implement OnListBoxModifierSelectionMouvements
}

void EvtFramePrincipal::OnApplyButtonModifierMouvementClick( wxCommandEvent& event )
{
    // TODO: Implement OnApplyButtonModifierMouvementClick
}

void EvtFramePrincipal::OnCancelButtonModifierMouvementClick( wxCommandEvent& event )
{
    // TODO: Implement OnCancelButtonModifierMouvementClick
}

void EvtFramePrincipal::OnSaveButtonCreerMouvementClick( wxCommandEvent& event )
{
    // TODO: Implement OnSaveButtonCreerMouvementClick
}

void EvtFramePrincipal::OnYesButtonDetruireMouvementClick( wxCommandEvent& event )
{
// TODO: Implement OnYesButtonDetruireMouvementClick
}

void EvtFramePrincipal::OnCancelButtonTestMouvementClick( wxCommandEvent& event )
{
// TODO: Implement OnCancelButtonTestMouvementClick
}

void EvtFramePrincipal::OnInfoBrasTestMouvementClick( wxCommandEvent& event )
{
// TODO: Implement OnInfoBrasTestMouvementClick
}

void EvtFramePrincipal::OnYesButtonTesterMouvementClick( wxCommandEvent& event )
{
// TODO: Implement OnYesButtonTesterMouvementClick
}

void EvtFramePrincipal::OnButtonViderAffichageClick( wxCommandEvent& event )
{
    // TODO: Implement OnButtonViderAffichageClick
}

void EvtFramePrincipal::OnMenuQuitterSelection( wxCommandEvent& event )
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

void EvtFramePrincipal::OnMenuViderAffichageSelection( wxCommandEvent& event )
{
    // TODO: Implement OnMenuViderAffichageSelection
}

void EvtFramePrincipal::OnMenuAideSelection( wxCommandEvent& event )
{
    // TODO: Implement OnMenuAideSelection
}

void EvtFramePrincipal::OnMenuAproposSelection( wxCommandEvent& event )
{
    // TODO: Implement OnMenuAproposSelection
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

void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    DeconnexionClient(event.GetString());
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

wxString EvtFramePrincipal::DecouperTexteDebut(wxString texte, int position)
{
    wxString fin(texte.substr(position));

    wxString debut = "";
    texte.EndsWith(fin, &debut);

    return debut;
}

wxString EvtFramePrincipal::GardeIdSelection(wxString texte)
{
    int separateur = texte.find(" - ");
    wxString id_selection = DecouperTexteDebut(texte, separateur);

    return id_selection;
}

wxString EvtFramePrincipal::ConversionEnWxString(string texte)
{
    wxString temp_wxstring(texte.c_str(), wxConvUTF8);

    return temp_wxstring;
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

wxString EvtFramePrincipal::DecouperTexteFin(wxString texte, int position)
{
    wxString fin(texte.substr(position));

    return fin;
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
//
// IHM
//
void EvtFramePrincipal::AfficheStatus(wxString texte, int position)
{
    m_statusBar->SetStatusText(texte, position);
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

void EvtFramePrincipal::AfficheInfoClient(wxCommandEvent& event)
{
    // Affiche dans la barre de statusbar l'événement
    AfficheStatus(event.GetString(), 0);
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

//
// Partie client de communication
//
void EvtFramePrincipal::AfficheMessageClient(wxCommandEvent& event)
{
    // Affiche dans le log l'événement
    m_textCtrlAffichage->AppendText(event.GetString());
}