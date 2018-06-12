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
*  Projet:   Chaîne d'anodisation - Test d'IHM
*  Crée le:  14/04/2018
*  Utilité:  Gestion des événements du frame principal
*  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtFenetre2.h"
#include "EvtDialogTest.h"
#include "EvtMyDialogApropos.h"

/** Implementing FramePrincipal */
class EvtFramePrincipal : public FramePrincipal
{
	protected:
		// Handlers for FramePrincipal events.
		void OnFrameClose( wxCloseEvent& event );
		void OnMenuItemQuitterClick( wxCommandEvent& event );
		void OnMenuItemAProposClick( wxCommandEvent& event );
		void OnClickButtonFenetre2( wxCommandEvent& event );
		void OnClickButtonDialogue( wxCommandEvent& event );
	public:
		/** Constructor */
		EvtFramePrincipal( wxWindow* parent );
	//// end generated class members

    private:








};

#endif // __EvtFramePrincipal__