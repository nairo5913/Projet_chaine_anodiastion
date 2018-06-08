/*******************************************************************************
*  Fichier:  EvtDialogApropos.cpp
*  Projet:   Chaîne d'anodisation - Test d'IHM
*  Crée le:  15/04/2018
*  Utilité:  Gestion des événements du dialog à propos
*  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtMyDialogApropos.h"

EvtMyDialogApropos::EvtMyDialogApropos( wxWindow* parent )
:
MyDialogApropos( parent )
{
    //
}

void EvtMyDialogApropos::OnFrameClose( wxCloseEvent& event )
{
// TODO: Implement OnFrameClose
Destroy();
}

void EvtMyDialogApropos::OnClickButtonOK( wxCommandEvent& event )
{
// TODO: Implement OnClickButtonOK
Destroy();
}
