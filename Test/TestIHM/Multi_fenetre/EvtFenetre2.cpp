/*******************************************************************************
*  Fichier:  EvtFenetre2.cpp
*  Projet:   Chaîne d'anodisation - Test d'IHM
*  Crée le:  14/04/2018
*  Utilité:  Gestion des événements de la fenêtre 2
*  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFenetre2.h"

EvtFenetre2::EvtFenetre2(wxWindow* parent) : Fenetre2(parent)
{
    //
}

void EvtFenetre2::OnFrameClose(wxCloseEvent& event)
{
    Destroy();
}

void EvtFenetre2::OnClickButtonRetour(wxCommandEvent& event)
{
    Destroy();
}
