/*******************************************************************************
  *  Fichier:  EvtFramePrincipal.cpp
  *  Projet:   Chaîne d'anodisation - Test des requetes SQL en C++ afin de voir 
               la structure de la BdD
  *  Crée le:  07/04/2018
  *  Utilité:  
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent )
:
FramePrincipal( parent )
{
    
}

void EvtFramePrincipal::OnClickButtonConnexion( wxCommandEvent& event )
{
    // TODO: Implement OnClickButtonConnexion
}

void EvtFramePrincipal::OnClickButtonExecutionRequete( wxCommandEvent& event )
{
    // TODO: Implement OnClickButtonExecutionRequete
}

void EvtFramePrincipal::AfficheStatus(wxString texte, int position)
{
    m_statusBar->SetStatusText(texte, position);
}

void EvtFramePrincipal::AfficheResultat(wxString texte)
{
    
}