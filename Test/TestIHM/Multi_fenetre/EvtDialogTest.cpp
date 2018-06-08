/*******************************************************************************
*  Fichier:  EvtDialogTest.cpp
*  Projet:   Chaîne d'anodisation - Test d'IHM
*  Crée le:  14/04/2018
*  Utilité:  Gestion des événements du dialog test
*  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtDialogTest.h"

EvtDialogTest::EvtDialogTest(wxWindow* parent) : DialogTest(parent)
{
    //
}

void EvtDialogTest::OnFrameClose(wxCloseEvent& event)
{
    Destroy();
}

void EvtDialogTest::OnClickButtonCancel(wxCommandEvent& event)
{
    Destroy();
}

void EvtDialogTest::OnClickButtonOK(wxCommandEvent& event)
{
    Destroy();
}
