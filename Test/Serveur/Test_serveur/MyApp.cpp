/*******************************************************************************
 *  Fichier:  MyApp.cpp
 *  Projet:   Chaîne d'anodisation - Test du client pour le PC responsable 
              de production avec un serveur
 *  Crée le:  11/04/2018
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
#include <wx/icon.h>

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // on choisit le français comme langue
    m_locale.Init(wxLANGUAGE_FRENCH );

    EvtFramePrincipal* frame_principal = new EvtFramePrincipal(0);
    
    static const char * sample_xpm[] = 
    {
        /* columns rows colors chars-per-pixel */
        "32 32 4 1",
        "  c black",
        "X c green",
        "+ c gray100",
        "O c None",
        /* pixels */
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++",
        "++++                        ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++ XXX                    ++++",
        "++++ XXX +++++++++++++++++++++++",
        "++++ XXX +++++++++++++++++++++++",
        "++++ XXX +++++++++++++++++++++++",
        "++++ XXX +++++++++++++++++++++++",
        "++++ XXX +++++++++++++++++++++++",
        "++++ XXX                    ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++                    XXX ++++",
        "+++++++++++++++++++++++ XXX ++++",
        "+++++++++++++++++++++++ XXX ++++",
        "+++++++++++++++++++++++ XXX ++++",
        "+++++++++++++++++++++++ XXX ++++",
        "+++++++++++++++++++++++ XXX ++++",
        "+++++++++++++++++++++++ XXX ++++",
        "++++                    XXX ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++ XXXXXXXXXXXXXXXXXXXXXX ++++",
        "++++                        ++++",
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