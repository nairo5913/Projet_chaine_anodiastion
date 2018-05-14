/*******************************************************************************
  *  Fichier:  MyApp.h
  *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
  *  Crée le:  29/04/2018
  *  Utilité:  Lancement de l'application
  *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef MYAPP_H
#define MYAPP_H

#include <wx/app.h>
#include <wx/icon.h>
#include <wx/splash.h>

class MyApp : public wxApp
{
   public:
        virtual bool OnInit();

   private:
        wxLocale m_locale;
};

#endif  // MYAPP_H
