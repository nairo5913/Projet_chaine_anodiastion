/*******************************************************************************
  *  Fichier:  MyApp.cpp
  *  Projet:   Chaîne d'anodisation - Gestion du client BdD pour le PC du 
               responsable de production
  *  Crée le:  29/04/2018
  *  Utilité:  Lancement de l'application
  *  Auteur:   Florian Provost
*******************************************************************************/
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "MyApp.h"
#include "EvtFramePrincipal.h"

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // on choisit le français comme langue
    m_locale.Init(wxLANGUAGE_FRENCH );

    EvtFramePrincipal* frame_principal = new EvtFramePrincipal(0);
    
    static const char * sample_xpm[] = 
    {
        // Colonnes Lignes Couleurs chars-par-pixel
        "32 32 4 1",
        "  c black",
        "X c cyan",
        "+ c gray100",
        "O c None",
        // pixels 
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++        ++++++++++++++++++++++",
        "+  XXXXXX  +   +++++++   +++++++",
        "+ XXXXXXXX + X  ++++++ X  ++++++",
        "+ XXXXXXXX + XX  +++++ XX  +++++",
        "+ XXXXXXXX + XXX  ++++ XXX  ++++",
        "+ XX    XX + XXXX  +++ XXXX  +++",
        "+ XX OO XX + XXXXX  ++ XXXXX  ++",
        "+ XX OO XX + XXXXXX  + XXXXXX  +",
        "+ XX OO XX + XXXXXXX + XXXXXXX +",
        "+ XX    XX + XXXXXXX + XXXXXXX +",
        "+ XXXXXXXX + XXXXXXX + XXXXXXX +",
        "+ XXXXXXXX + XXXXXXX + XXXXXXX +",
        "+ XXXXXXXX + XXXXXXX + XXXXXXX +",
        "+ XXXXXXX  + X  XXXX + X  XXXX +",
        "+          + X O XXX + X O XXX +",
        "+ XXXXXXX  + X  XXXX + X  XXXX +",
        "+ XXXXXXXX + XXXXXXX + XXXXXXX +",
        "+ XXXXXXXX + XXXXXXX + XXXXXXX +",
        "+ XXXXXXXX + XXXXXXX + XXXXXXX +",
        "+ XX    XX + XXXXXXX + XXXXXXX +",
        "+ XX OO XX + XXXXXX  + XXXXXX  +",
        "+ XX OO XX + XXXXX  ++ XXXXX  ++",
        "+ XX    XX + XXXX  +++ XXXX  +++",
        "+ XXXXXXXX + XXX  ++++ XXX  ++++",
        "+ XXXXXXXX + XX  +++++ XX  +++++",
        "+ XXXXXXXX + X  ++++++ X  ++++++",
        "+  XXXXXX  +   +++++++   +++++++",
        "++        ++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++"
    };
    
    // Création de l'icone
    wxIcon *icon = new wxIcon(sample_xpm);
    // Mise en place
    frame_principal->SetIcon(*icon);
    
    frame_principal->Show();

    return true;
}