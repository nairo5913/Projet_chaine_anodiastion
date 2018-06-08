/*******************************************************************************
  *  Fichier:  MyApp.h
  *  Projet:   Chaîne d'anodisation - Gestion du client pour le PC responsable 
               de production
  *  Crée le:  11/04/2018
  *  Utilité:  Lancement de l'application
  *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef MYAPP_H
#define MYAPP_H

#include <wx/app.h>

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
    private:
        wxLocale m_locale;

};

#endif // MYAPP_H
