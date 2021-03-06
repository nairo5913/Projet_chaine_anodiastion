#ifndef __EvtFenetre2__
#define __EvtFenetre2__

/**
@file
Subclass of Fenetre2, which is generated by wxFormBuilder.
*/

#include "FramePrincipal.h"

//// end generated include
/*******************************************************************************
*  Fichier:  EvtFenetre2.h
*  Projet:   Chaîne d'anodisation - Test d'IHM
*  Crée le:  14/04/2018
*  Utilité:  Gestion des événements de la fenetre 2
*  Auteur:   Florian Provost
*******************************************************************************/

/** Implementing Fenetre2 */
class EvtFenetre2 : public Fenetre2
{
	protected:
		// Handlers for Fenetre2 events.
		void OnFrameClose( wxCloseEvent& event );
		void OnClickButtonRetour( wxCommandEvent& event );
	public:
		/** Constructor */
		EvtFenetre2( wxWindow* parent );
	//// end generated class members








};

#endif // __EvtFenetre2__
