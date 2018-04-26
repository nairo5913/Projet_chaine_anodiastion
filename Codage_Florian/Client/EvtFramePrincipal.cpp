#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_connecte = false;
    m_statusBar->SetStatusText(wxT("Déconnecté"), 0);
    m_panelParametresConnexion->Hide();

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
    // Gestion de la fermeture de la fenêtre
    // penser à bloquer la fermeture pour la suite du projet surtout si fabrication
    if(m_connecte)
    {
        m_client->Close();
        delete m_client;
    }
    
    wxBitmap bitmap;
    if (bitmap.LoadFile("../Images/Good-Bye-Image-5.jpg", wxBITMAP_TYPE_PNG))
    {
        wxSplashScreen* splash = new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT, 2000, NULL, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxSTAY_ON_TOP);
    }

    Destroy();
}

void EvtFramePrincipal::OnButtonConnexionToggle(wxCommandEvent& event)
{
    if(!m_connecte)
    {
        long port = 30000;
        // Test en local
        wxString ip = wxT("localhost");
        // Adresse de la Raspberry
        // wxString ip = wxT("192.168.1.249");

        // m_client = new Client(m_textCtrlSaisieHote->GetValue(), port, this);
        m_client = new Client(ip, port, this);
        m_connecte = m_client->IsOK();

        if(m_connecte)
        {
            m_panelSaisie->Show();
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
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

void EvtFramePrincipal::OnClickButtonEnvoyer(wxCommandEvent& event)
{
    // m_textCtrlAffichage->AppendText(wxT("Bouton envoyer \n"));

    // Récupération de la saisie et affichage
    wxString saisie = m_textCtrlSaisie->GetValue();
    m_textCtrlSaisie->Clear();
    m_textCtrlAffichage->AppendText(saisie + wxT("\n"));

    wxString texte = "";

    if(saisie.StartsWith(DEMANDE_EXECUTION_PROCESSUS, &texte))
    {
        // Affichage pour tester
        wxString message = wxT("Commence par 200- et le contenu est : ") + texte + wxT("\n");
        m_textCtrlAffichage->AppendText(message);

        if(texte != wxT(""))
        {
            // Pour la suite du projet récuperer l'id du processus directement
            int id_processus = 1;
            m_client->ExecutionProcessus(id_processus);
        }
        else
        {
            wxLogError(wxT("Il faut rentrer un id du processus à envoyer."));
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
        
        if(tache[0] == "0")
        {
            message.clear();
            message << "Il n'y a pas de taches en cours.\n";
            
            // Affichage
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxGREEN));
            m_textCtrlAffichage->AppendText(message);
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
        }
        else
        {
            // Récupération des valeurs
            wxString type = tache[0];
            wxString id_tache = tache[1];
            wxString message;
            
            if(type == "Processus")
            {
                // Requete pour avoir les détails grace à l'id
                message  << wxT("La tache est un processus d'id : ") <<  id_tache << wxT("\n");
                
                m_textCtrlAffichage->AppendText(message);
            }
            else if(type == "Trajectoire")
            {
                // Requete pour avoir les détails grace à l'id
                message  << wxT("La tache est une trajectoire d'id : ") <<  id_tache << wxT("\n");
                
                m_textCtrlAffichage->AppendText(message);
            }
            else
            {
                // Requete pour avoir les détails grace à l'id
                message  << wxT("La tache est un mouvement d'id : ") <<  id_tache << wxT("\n");
                
                m_textCtrlAffichage->AppendText(message);
            }
            
        }
        
    }
    else
    {
        wxString message = wxT("Saisie non reconnue\n");
        
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
        m_textCtrlAffichage->AppendText(message);
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
    }
}

void EvtFramePrincipal::AfficheMessageClient(wxCommandEvent& event)
{
    // Affiche dans le log l'événement
    m_textCtrlAffichage->AppendText(event.GetString());
}

void EvtFramePrincipal::Deconnexion(wxString message)
{
    m_client->Close();
    m_connecte = false;
    delete m_client;

    // Affichage du message
    message << wxT("\n");
    
    m_textCtrlAffichage->Clear();
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
    m_textCtrlAffichage->AppendText(message);
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

    // Mise à jour de l'IHM
    m_toggleBtnConnexion->SetValue(false);
    m_panelSaisie->Hide();
    m_toggleBtnConnexion->SetLabel(wxT("Connexion"));
    m_statusBar->SetStatusText(wxT("Déconnecté"), 0);
    
    Layout();
}

void EvtFramePrincipal::AgitServeurPerdu(wxCommandEvent& event)
{
    Deconnexion(event.GetString());
}

void EvtFramePrincipal::AfficheInfoClient(wxCommandEvent& event)
{
    // Affiche dans la barre de statusbar l'événement
    m_statusBar->SetStatusText(event.GetString(), 0);
}