/*******************************************************************************
  *  Fichier:  EvtFramePrincipal.cpp
  *  Projet:   Chaîne d'anodisation - Test des requetes SQL en C++ afin de voir 
               la structure de la BdD
  *  Crée le:  07/04/2018
  *  Utilité:  Gestion des événements du frame principal
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent )
:
FramePrincipal( parent )
{
    m_bdd_anodisation = NULL;
}

void EvtFramePrincipal::OnClickButtonConnexion( wxCommandEvent& event )
{
    // On éfface le log
    m_textCtrlResultat->Clear();
    
    // Modification du séparateur central de la wxStatusBar
    int widths[2];
    widths[0] = -1; widths[1] = 130;
    m_statusBar->SetStatusWidths(2, widths);
    
    // Si le bouton vient d'être enfoncé: connexion demandée
    if (m_toggleBtnConnexion->GetValue() == true)
    {
        string strconnexion(m_textCtrlDSN->GetValue().mb_str());
        m_bdd_anodisation = new DataAnnodiastion(strconnexion);
        
        // vérifier l'état de la connection
        if (m_bdd_anodisation->IsConnexionOK())
        {
            AfficheStatus(wxT("Connecté !"), 1);
            // Modifier le label du bouton de connexion
            m_toggleBtnConnexion->SetLabel(wxT("Déconnexion"));
            m_buttonExecutionRequete->Enable();
            Layout();
        }
        else
        {
            AfficheStatus(wxT("Erreur de connexion"), 1);
            wxString erreur(m_bdd_anodisation->GetLastError().c_str(), wxConvUTF8);
            AfficheResultat(erreur);
            // Relâcher le bouton de connexion
            m_toggleBtnConnexion->SetValue(false);
            // Désactiver le bouton d'envoi des requêtes
            m_buttonExecutionRequete->Disable();
        }
    }
    else
    {
        delete m_bdd_anodisation;
        m_bdd_anodisation = NULL;
        AfficheStatus(wxT("Déconnecté"), 1);
        AfficheStatus(wxT(""),0);
        m_toggleBtnConnexion->SetLabel(wxT("Connexion"));
        m_buttonExecutionRequete->Disable();
    }
}

void EvtFramePrincipal::OnClickButtonExecutionRequete( wxCommandEvent& event )
{
    m_textCtrlResultat->Clear();
    string strrequete(m_textCtrlSaisieRequete->GetLineText(0).mb_str());
    wxString res(wxT(""));
    
    if (m_bdd_anodisation->ExecuteSelect(strrequete))
    {
        AfficheStatus(wxT("La requête à réussie"), 0);
        
        for(unsigned int i = 0; i < m_bdd_anodisation->GetLastResult().size(); i++)
        {
            wxString temp((m_bdd_anodisation->GetLastResult())[i].c_str(), wxConvUTF8);
            res << temp << wxT(" ");
            
            if(i%2)
            {
                res << wxT("\n");
            }
        }
        AfficheResultat(res);
        res.Clear();
    }
    else
    {
        AfficheStatus(wxT("La requête à échouée"), 0);
        wxString erreur(m_bdd_anodisation->GetLastError().c_str(), wxConvUTF8);
        AfficheResultat(erreur);
    }
}

void EvtFramePrincipal::AfficheStatus(wxString texte, int position)
{
    m_statusBar->SetStatusText(texte, position);
}

void EvtFramePrincipal::AfficheResultat(wxString texte)
{
    m_textCtrlResultat->AppendText(texte);
}