#ifndef MYAPP_H
#define MYAPP_H
/***************************************************************
 * Name:      MyApp.h
 * Purpose:   Defines Application Class
 * Author:    Florian Provost
 * Created:   24/11/2017
 * Copyright: 
 * License:
 **************************************************************/


#include <wx/app.h>

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
    private:
        wxLocale m_locale;

};

#endif // MYAPP_H
