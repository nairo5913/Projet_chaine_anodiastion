#ifndef __EvtFramePrincipal__
#define __EvtFramePrincipal__

/**
@file
Subclass of FramePrincipal, which is generated by wxFormBuilder.
*/

#include "FramePrincipal.h"

//// end generated include
/*******************************************************************************
  *  Fichier:  EvtFramePrincipal.h
  *  Projet:   Chaîne d'anodisation - Test des requetes SQL en C++ afin de voir 
               la structure de la BdD
  *  Crée le:  07/04/2018
  *  Utilité:  
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "DataAnnodiastion.h"

/** Implementing FramePrincipal */
class EvtFramePrincipal : public FramePrincipal
{
	protected:
		// Handlers for FramePrincipal events.
		void OnClickButtonConnexion( wxCommandEvent& event );
		void OnClickButtonExecutionRequete( wxCommandEvent& event );
	public:
		/** Constructor */
		EvtFramePrincipal( wxWindow* parent );
	//// end generated class members
    private:
        DataAnnodiastion *m_data_anodisation; 
        void AfficheStatus(wxString texte, int position);
        void AfficheResultat(wxString texte);
};

#endif // __EvtFramePrincipal__
