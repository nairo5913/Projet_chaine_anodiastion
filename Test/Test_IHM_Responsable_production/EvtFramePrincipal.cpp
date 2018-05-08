/*******************************************************************************
  *  Fichier:  EvtFramePrincipal.h
  *  Projet:   
  *  Crée le:  //2018
  *  Utilité:  Gestion des événements du frame principal
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal(wxWindow* parent) : FramePrincipal(parent)
{
    //
}

void EvtFramePrincipal::OnFrameClose(wxCloseEvent& event)
{
    // TODO: Implement OnFrameClose
    Destroy();
}

void EvtFramePrincipal::OnMenuQuitterSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuQuitterSelection
    Destroy();
}

void EvtFramePrincipal::OnMenuAideSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuAideSelection
}

void EvtFramePrincipal::OnMenuAproposSelection(wxCommandEvent& event)
{
    // TODO: Implement OnMenuAproposSelection
}
