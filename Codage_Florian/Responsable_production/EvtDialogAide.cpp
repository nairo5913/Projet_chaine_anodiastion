/*******************************************************************************
*  Fichier:  EvtDialogAide.cpp
*  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
*  Crée le:  13/05/2018
*  Utilité:  Gestion des événements de la boite de dialogue aide
*  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtDialogAide.h"

EvtDialogAide::EvtDialogAide(wxWindow* parent) : DialogAide(parent)
{
    //
}

void EvtDialogAide::OnDialogClose(wxCloseEvent& event)
{
    // TODO: Implement OnDialogClose
    Destroy();
}

void EvtDialogAide::OnOkButtonClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonClick
    Destroy();
}
