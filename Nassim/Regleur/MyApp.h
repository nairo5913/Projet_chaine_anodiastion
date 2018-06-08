/*******************************************************************************
  *  Fichier:  MyApp.h
  *  Projet:   
  *  Crée le:  //2018
  *  Utilité:  Lancement de l'application
  *  Auteur:   Boubziz Nassim
*******************************************************************************/
#ifndef MYAPP_H
#define MYAPP_H

#include <wx/app.h>
#include <wx/icon.h>

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
    private:
        wxLocale m_locale;
};

#endif // MYAPP_H
