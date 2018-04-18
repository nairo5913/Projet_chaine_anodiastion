/*******************************************************************************
*  Fichier:  EvtFramePrincipal.cpp
*  Projet:   Chaîne d'anodisation - Test d'IHM
*  Crée le:  14/04/2018
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
    Destroy();
}

void EvtFramePrincipal::OnMenuItemQuitterClick(wxCommandEvent& event)
{
    Destroy();
}

void EvtFramePrincipal::OnMenuItemAProposClick(wxCommandEvent& event)
{
    // TODO: Implement OnMenuItemAProposClick
    EvtMyDialogApropos* dialog_apropos = new EvtMyDialogApropos(0);
    dialog_apropos->Show();
}

void EvtFramePrincipal::OnClickButtonFenetre2(wxCommandEvent& event)
{
    EvtFenetre2* fenetre_2 = new EvtFenetre2(0);
    fenetre_2->Show();
}

void EvtFramePrincipal::OnClickButtonDialogue(wxCommandEvent& event)
{
    EvtDialogTest* dialog_test = new EvtDialogTest(0);
    dialog_test->Show();
}
