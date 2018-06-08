/*******************************************************************************
 *  Fichier:  EvtFramePrincipal.h
 *  Projet:   Chaîne d'anodisation - Test du client pour le PC responsable
              de production avec un serveur
 *  Crée le:  11/04/2018
 *  Utilité:  Gestion des événements du frame principal
 *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    m_connecte = false;

    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = -1;
    widths[1] = 185;
    m_statusBar->SetStatusWidths(2, widths);
    m_statusBar->SetStatusText(wxT("Serveur déconnecté"), 1);

    Layout();
}

void EvtFramePrincipal::OnCharEntered(wxKeyEvent& event)
{
    // TODO: Implement OnCharEntered
}

void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
    if(m_connecte)
    {
        m_serveur->Close();
        delete m_serveur;
    }
    
    Destroy();
}

void EvtFramePrincipal::OnButtonDemarrerServeurToggle(wxCommandEvent& event)
{
    if(!m_connecte)
    {
        long port = 30000;

        m_serveur = new Serveur(this, port, 2);
        m_connecte = m_serveur->IsOK();

        if(m_connecte)
        {
            // on connecte les événements venant du serveur
            Connect(ID_SERVEUR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::MAJnombreClients), NULL, this);
            Connect(ID_SERVEUR + 1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheMessageServeur), NULL, this);
            Connect(ID_SERVEUR + 2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::AfficheReponseServeur), NULL, this);
            Connect(ID_SERVEUR + 3, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EvtFramePrincipal::MAJetatBras), NULL, this);

            m_statusBar->SetStatusText(wxT("Serveur connecté"), 1);
            m_toggleBtnDisponibilite->Show();
            m_toggleBtnConnexion->Disable();

            m_textCtrlAffichage->Clear();

            Layout();
        }
        else
        {
            wxString message("");
            message.Printf("ERREUR ! : Le serveur n'a pas pu démarrer sur le port %ld\n", port);

            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxRED));
            m_textCtrlAffichage->AppendText(message);
            m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));

            delete m_serveur;
        }
    }
}

void EvtFramePrincipal::OnToggleButtonDisponibiliteClick(wxCommandEvent& event)
{
    if(m_toggleBtnDisponibilite->GetValue())
    {
        m_textCtrlAffichage->AppendText(wxT("Bras non disponible\n"));
        m_serveur->SetBrasDispo(false);

        m_toggleBtnDisponibilite->SetLabel(wxT("Bras non disponible"));

        m_staticTextTacheEnCours->Show();
        m_choiceTacheEnCours->Show();
        Layout();

        wxString selection = m_choiceTacheEnCours->GetStringSelection();
        m_textCtrlAffichage->AppendText(wxT("Type de tache selectionné : ") + selection + wxT(" d'id 1\n"));

        m_serveur->SetTache(selection);
        m_serveur->SetIdTache(wxT("1"));
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Bras disponible\n"));
        m_serveur->SetBrasDispo(true);

        m_toggleBtnDisponibilite->SetValue(false);
        m_toggleBtnDisponibilite->SetLabel(wxT("Bras disponible"));

        m_staticTextTacheEnCours->Hide();
        m_choiceTacheEnCours->Hide();
        Layout();
    }
}

void EvtFramePrincipal::OnChoiceTache(wxCommandEvent& event)
{
    wxString selection = m_choiceTacheEnCours->GetStringSelection();
    m_textCtrlAffichage->AppendText(wxT("Type de tache selectionné : ") + selection + wxT(" d'id 1\n"));

    m_serveur->SetTache(selection);
}

void EvtFramePrincipal::OnButtonClickViderAffichage(wxCommandEvent& event)
{
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::OnMenuSelectionQuitter(wxCommandEvent& event)
{
    if(m_connecte)
    {
        m_serveur->Close();
        delete m_serveur;
    }

    Destroy();
}

void EvtFramePrincipal::OnMenuSelectionChangerDisponibiliteBras(wxCommandEvent& event)
{
    if(m_connecte)
    {
        if(!m_serveur->GetBrasDispo())
        {
            m_textCtrlAffichage->AppendText(wxT("Bras disponible\n"));
            m_serveur->SetBrasDispo(true);
    
            m_toggleBtnDisponibilite->SetValue(false);
            m_toggleBtnDisponibilite->SetLabel(wxT("Bras disponible"));
    
            m_staticTextTacheEnCours->Hide();
            m_choiceTacheEnCours->Hide();
            
            Layout();
        
        }
        else
        {
            m_textCtrlAffichage->AppendText(wxT("Bras non disponible\n"));
            m_serveur->SetBrasDispo(false);
    
            m_toggleBtnDisponibilite->SetLabel(wxT("Bras non disponible"));
            m_toggleBtnDisponibilite->SetValue(true);
            
            m_staticTextTacheEnCours->Show();
            m_choiceTacheEnCours->Show();
            
            m_choiceTacheEnCours->SetSelection(0);
            
            wxString selection = m_choiceTacheEnCours->GetStringSelection();
            m_textCtrlAffichage->AppendText(wxT("Type de tache selectionné : ") + selection + wxT(" d'id 1.\n"));
            m_serveur->SetTache(selection);
            
            Layout();
        }
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Il faut d'abord lancer le serveur pour pouvoir changer les valeurs.\n"));
    }
}

void EvtFramePrincipal::OnMenuSelectionMouvement(wxCommandEvent& event)
{
    if(m_connecte)
    {
        m_choiceTacheEnCours->SetSelection(0);

        wxString selection = m_choiceTacheEnCours->GetStringSelection();
        m_textCtrlAffichage->AppendText(wxT("Type de tache selectionné : ") + selection + wxT(" d'id 1.\n"));
        m_serveur->SetTache(selection);
        
        m_textCtrlAffichage->AppendText(wxT("Bras non disponible\n"));
        m_serveur->SetBrasDispo(false);

        m_toggleBtnDisponibilite->SetLabel(wxT("Bras non disponible"));

        m_staticTextTacheEnCours->Show();
        m_choiceTacheEnCours->Show();
        
        Layout();
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Il faut d'abord lancer le serveur pour pouvoir changer les valeurs.\n"));
    }
}

void EvtFramePrincipal::OnMenuSelectionProcessus(wxCommandEvent& event)
{
    // TODO: Implement OnMenuSelectionProcessus
    if(m_connecte)
    {
        m_choiceTacheEnCours->SetSelection(1);

        wxString selection = m_choiceTacheEnCours->GetStringSelection();
        m_textCtrlAffichage->AppendText(wxT("Type de tache selectionné : ") + selection + wxT(" d'id 1.\n"));

        m_serveur->SetTache(selection);
        
        m_textCtrlAffichage->AppendText(wxT("Bras non disponible\n"));
        m_serveur->SetBrasDispo(false);

        m_toggleBtnDisponibilite->SetLabel(wxT("Bras non disponible"));

        m_staticTextTacheEnCours->Show();
        m_choiceTacheEnCours->Show();
        
        Layout();
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Il faut d'abord lancer le serveur pour pouvoir changer les valeurs.\n"));
    }
}

void EvtFramePrincipal::OnMenuSelectionTrajectoire(wxCommandEvent& event)
{
    if(m_connecte)
    {
        m_choiceTacheEnCours->SetSelection(2);

        wxString selection = m_choiceTacheEnCours->GetStringSelection();
        m_textCtrlAffichage->AppendText(wxT("Type de tache selectionné : ") + selection + wxT(" d'id 1\n"));

        m_serveur->SetTache(selection);
        
        m_textCtrlAffichage->AppendText(wxT("Bras non disponible\n"));
        m_serveur->SetBrasDispo(false);

        m_toggleBtnDisponibilite->SetLabel(wxT("Bras non disponible"));

        m_staticTextTacheEnCours->Show();
        m_choiceTacheEnCours->Show();
        
        Layout();
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Il faut d'abord lancer le serveur pour pouvoir changer les valeurs.\n"));
    }
}

void EvtFramePrincipal::OnMenuSelectionViderAffichage(wxCommandEvent& event)
{
    m_textCtrlAffichage->Clear();
}

void EvtFramePrincipal::AfficheMessageServeur(wxCommandEvent& event)
{
    // affiche dans le log sur événement du serveur
    wxString message = event.GetString();

    if(message.StartsWith("message du client"))
    {
        // m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxColour("GOLDENROD")));
        m_textCtrlAffichage->AppendText(message);
        m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
    }
    else
    {
        message << wxT("\n");
        m_textCtrlAffichage->AppendText(wxT("\n") + message);
    }
}

void EvtFramePrincipal::MAJnombreClients(wxCommandEvent& event)
{
    // affiche dans la statusbar sur événement du serveur
    m_statusBar->SetStatusText(event.GetString(), 0);
}

void EvtFramePrincipal::AfficheReponseServeur(wxCommandEvent& event)
{
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(*wxCYAN));
    m_textCtrlAffichage->AppendText(event.GetString());
    m_textCtrlAffichage->SetDefaultStyle(wxTextAttr(wxNullColour));
}

void EvtFramePrincipal::MAJetatBras(wxCommandEvent& event)
{
    wxString texte = event.GetString();
    unsigned int position = texte.find(wxT("-"));
    wxString id_tache = texte.substr(position);
    wxString tache = "";
    texte.EndsWith(id_tache, &tache);
    wxString temp = id_tache;
    id_tache.clear();
    position = temp.find(wxT("-"));
    id_tache << temp.substr(position+1);
    
    if(m_serveur->GetBrasDispo())
    {
        m_textCtrlAffichage->AppendText(wxT("Bras disponible\n"));
        m_serveur->SetBrasDispo(true);

        m_toggleBtnDisponibilite->SetValue(false);
        m_toggleBtnDisponibilite->SetLabel(wxT("Bras disponible"));

        m_staticTextTacheEnCours->Hide();
        m_choiceTacheEnCours->Hide();
        Layout();
    
    }
    else
    {
        m_textCtrlAffichage->AppendText(wxT("Bras non disponible\n"));
        m_serveur->SetBrasDispo(false);

        m_toggleBtnDisponibilite->SetLabel(wxT("Bras non disponible"));
        m_toggleBtnDisponibilite->SetValue(true);

        m_staticTextTacheEnCours->Show();
        m_choiceTacheEnCours->Show();
        
        m_textCtrlAffichage->AppendText(wxT("Tache : ") + tache + wxT(" id tache : ") + id_tache + wxT("\n"));
        
        if(tache.IsSameAs("Mouvement"))
        {
            m_choiceTacheEnCours->SetSelection(0);
        }
        else if(tache.IsSameAs("Processus"))
        {
            m_choiceTacheEnCours->SetSelection(1);
        }
        else if(tache.IsSameAs("Trajectoire"))
        {
            m_choiceTacheEnCours->SetSelection(2);
        }
        else if(tache.IsSameAs("Fabrication"))
        {
            m_choiceTacheEnCours->SetSelection(3);
        }
        else
        {
            
        }
        
        Layout();
    }
    
}