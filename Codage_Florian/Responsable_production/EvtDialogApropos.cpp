/*******************************************************************************
*  Fichier:  EvtDialogApropos.cpp
*  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
*  Crée le:  13/05/2018
*  Utilité:  Gestion des événements de la boite de dialogue À propos
*  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtDialogApropos.h"

EvtDialogApropos::EvtDialogApropos(wxWindow* parent) : DialogApropos(parent)
{
    //
}

void EvtDialogApropos::OnDialogClose(wxCloseEvent& event)
{
    // TODO: Implement OnDialogClose
    Destroy();
}

void EvtDialogApropos::OnOkButtonClick(wxCommandEvent& event)
{
    // TODO: Implement OnOkButtonClick
    Destroy();
}
