/*******************************************************************************
  *  Fichier:  MyApp.cpp
  *  Projet:   
  *  Crée le:  //2018
  *  Utilité:  Lancement de l'application
  *  Auteur:   Boubziz Nassim
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
    
    // Paramétrage de l'icone
    // Définition de l'icon (Dessin)
    static const char * sample_xpm[] = 
    {
        // Columns rows colors chars-per-pixel
        "32 32 6 1",
        "  c black",
        ". c navy",
        "X c red",
        "o c yellow",
        "O c gray100",
        "+ c None",
        // Pixels
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++              ++++++++++",
        "++++++++ ............ ++++++++++",
        "++++++++ ............ ++++++++++",
        "++++++++ .OO......... ++++++++++",
        "++++++++ .OO......... ++++++++++",
        "++++++++ .OO......... ++++++++++",
        "++++++++ .OO......              ",
        "++++++++ .OO...... oooooooooooo ",
        "         .OO...... oooooooooooo ",
        " XXXXXXX .OO...... oOOooooooooo ",
        " XXXXXXX .OO...... oOOooooooooo ",
        " XOOXXXX ......... oOOooooooooo ",
        " XOOXXXX ......... oOOooooooooo ",
        " XOOXXXX           oOOooooooooo ",
        " XOOXXXXXXXXX ++++ oOOooooooooo ",
        " XOOXXXXXXXXX ++++ oOOooooooooo ",
        " XOOXXXXXXXXX ++++ oOOooooooooo ",
        " XOOXXXXXXXXX ++++ oooooooooooo ",
        " XOOXXXXXXXXX ++++ oooooooooooo ",
        " XXXXXXXXXXXX ++++              ",
        " XXXXXXXXXXXX ++++++++++++++++++",
        "              ++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
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
