/*******************************************************************************
 *  Fichier:  EvtFrameAide.cpp
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  15/05/2018
 *  Utilité:  Gestion des événements du frame aide
 *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFrameAide.h"

EvtFrameAide::EvtFrameAide(wxWindow* parent) : FrameAide(parent)
{
    // 
}

void EvtFrameAide::OnCloseFrame(wxCloseEvent& event)
{
    // TODO: Implement OnCloseFrame
    Destroy();
}

void EvtFrameAide::OnOkButtonClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonClick
    Destroy();
}
