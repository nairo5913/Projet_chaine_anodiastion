/*******************************************************************************
  *  Fichier:  EvtFrameApropos.cpp
  *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
  *  Crée le:  15/05/2018
  *  Utilité:  Gestion des événements du frame à propos
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFrameApropos.h"

EvtFrameApropos::EvtFrameApropos(wxWindow* parent) : FrameApropos(parent)
{
    //
}

void EvtFrameApropos::OnCloseFrame(wxCloseEvent& event)
{
    // TODO: Implement OnCloseFrame
    Destroy();
}

void EvtFrameApropos::OnOkButtonClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonClick
    Destroy();
}
