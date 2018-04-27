/***************************************************************
 * Name:      EvtFramePrincipal.cpp
 * Purpose:   
 * Author:    Boubziz Nassim
 * Created:   29/11/2017
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "MyApp.h"
#include <wx/cmdline.h>
#include <iostream>
using std::cout;
using std::endl;
#include <wx/icon.h>

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // on choisit le français comme langue
    m_locale.Init(wxLANGUAGE_FRENCH );

    EvtFramePrincipal* frame_principal = new EvtFramePrincipal(0);
    frame_principal->Show();
    
    return true;
}
