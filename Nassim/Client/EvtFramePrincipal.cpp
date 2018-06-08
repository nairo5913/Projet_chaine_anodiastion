#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_connecte = false;
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

void EvtFramePrincipal::OnButtonConnexionToggle(wxCommandEvent& event)
{
    if(!m_connecte)
    {
        long port = 30000;
        // Test en local
        // wxString ip = wxT("localhost");
        // Adresse de la Raspberry
        wxString ip = wxT("192.168.1.16");

        // m_client = new Client(m_textCtrlSaisieHote->GetValue(), port, this);
        m_client = new Client(ip, port, this);
        m_connecte = m_client->IsOK();

        if(m_connecte)
        {
            m_panelSaisie->Show();
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
            m_panelSaisie->Show();
            // m_panelParametresConnexion->Hide();
            Layout();
        }
        else
        {
            m_textCtrlAffichage->AppendText(wxT("Connexion impossible, vérifiez que le serveur est bien lancé...\n"));
            m_toggleBtnConnexion->SetValue(false);
        }
    }
    else
    {
        Deconnexion(wxT("Déconnexion depuis le client"));
    }
}

void EvtFramePrincipal::OnClickButtonSaisie(wxCommandEvent& event)
{
    // m_textCtrlAffichage->AppendText(wxT("Bouton envoyer \n"));

    // Récupération de la saisie et affichage
    wxString saisie = m_textCtrlSaisie->GetValue();
    m_textCtrlAffichage->AppendText(saisie + wxT("\n"));
    m_textCtrlSaisie->Clear();
    wxString texte = "";

    if(saisie.StartsWith(DEMANDE_TEST_MOUVEMENT, &texte))
    {
        // Affichage pour tester
        wxString message = wxT("Commence par 202- et le contenu est : ") + texte + wxT("\n");
        m_textCtrlAffichage->AppendText(message);

        if(texte != wxT(""))
        {
            // Pour la suite du projet récuperer l'id du processus directement
            int id_mouvement = 1;
            m_client->TestMouvement(id_mouvement);
        }
    }
    else if(saisie.StartsWith(DEMANDE_TEST_TRAJECTOIRE, &texte))
    {
        // Affichage pour tester
        wxString message = wxT("Commence par 201- et le contenu est : ") + texte + wxT("\n");
        m_textCtrlAffichage->AppendText(message);

        if(texte != wxT(""))
        {
            // Pour la suite du projet récuperer l'id du processus directement
            int id_trajectoire = 1;
            m_client->TestTrajectoire(id_trajectoire);
        }
        else
        {
            wxLogError(wxT("Il faut rentrer un id du mouvement à envoyer."));
        }
    }
    else if(saisie.IsSameAs(DISPONIBILITE_BRAS))
    {
        wxString message = wxT("Demande état bras (300-)\n");
        m_textCtrlAffichage->AppendText(message);

        m_client->DemandeDisponibiliteBras();
    }
    else if(saisie.IsSameAs(DEMANDE_TACHE_EN_COURS))
    {
        wxString message = wxT("Demande état bras (303-)\n");
        m_textCtrlAffichage->AppendText(message);

        vector<string> tache = m_client->DemandeTacheEnCours();
    }
    else
    {
    }
}

void EvtFramePrincipal::AfficheMessageClient(wxCommandEvent& event)
{
    // Affiche dans le log l'événement
    m_textCtrlAffichage->AppendText(event.GetString());
}

void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    Deconnexion(event.GetString());
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

void EvtFramePrincipal::AfficheInfoClient(wxCommandEvent& event)
{
    // Affiche dans la barre de statusbar l'événement
    m_statusBar->SetStatusText(event.GetString(), 0);
}
