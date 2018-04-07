#ifndef MYAPP_H
#define MYAPP_H
/*******************************************************************************
  *  Fichier:  MyApp.h
  *  Projet:   Chaîne d'anodisation - Test des requetes SQL en C++ afin de voir 
               la structure de la BdD
  *  Crée le:  07/04/2018
  *  Utilité:  Lancement de l'application
  *  Auteur:   Florian Provost
*******************************************************************************/
#include <wx/app.h>

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
    private:
        wxLocale m_locale;

};

#endif // MYAPP_H
