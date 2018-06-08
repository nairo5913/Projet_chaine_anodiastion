/***************************************************************
 * Name:      MyApp.h
 * Purpose:   Defines Application Class
 * Author:    Boubziz Nassim
 * Created:   29/11/2017
 **************************************************************/
#ifndef MYAPP_H
#define MYAPP_H

#include <wx/app.h>
#include "EvtFramePrincipal.h"

class MyApp : public wxApp
//class MyApp : public wxAppConsole
{
    public:
        virtual bool OnInit();
        //virtual int OnRun();
    private:
        wxLocale m_locale;

};

#endif // MYAPP_H
