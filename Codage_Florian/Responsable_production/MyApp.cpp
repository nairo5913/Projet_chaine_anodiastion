/*******************************************************************************
 *  Fichier:  MyApp.cpp
 *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
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
    
    // Paramétrage de l'icone
    // Définition de l'icon (Dessin)
    static const char * sample_xpm[] = 
    {
        // Columns rows colors chars-per-pixel
        "32 32 4 1",
        "  c black",
        "X c red",
        "+ c gray100",
        "O c None",
        // Pixels
        "+++++++++++++++++++++++++++++++O",
        "++++++       +++++       ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "+      XXXXX       XXXXX      +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+      XXXXX       XXXXX      +O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "+      XXXXX       XXXXX      +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+ XXXXXXXXXXXXXXXXXXXXXXXXXXX +O",
        "+      XXXXX       XXXXX      +O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++ XXXXX +++++ XXXXX ++++++O",
        "++++++       +++++       ++++++O",
        "+++++++++++++++++++++++++++++++O",
        "+++++++++++++++++++++++++++++++O"
    };
    
    // Création de l'icone
    wxIcon *icon = new wxIcon(sample_xpm);
    
    // Splash screen (logo Ozanam)
    wxBitmap bitmap;
    if(bitmap.LoadFile("../Images/logo_ozanam.png", wxBITMAP_TYPE_PNG))
    {
        wxSplashScreen* splash =
            new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT, 1500, NULL, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE | wxSTAY_ON_TOP);
    }
    
    // Mise en place de l'icone
    frame_principal->SetIcon(*icon);
    
    frame_principal->Show();
    //usleep(20000);
    
    return true;
}
