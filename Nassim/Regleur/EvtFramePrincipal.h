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
*  Projet:
*  Crée le:  //2018
*  Utilité:  Gestion des événements du frame principal
*  Auteur:   Florian Provost
*******************************************************************************/

/** Implementing FramePrincipal */
class EvtFramePrincipal : public FramePrincipal
{
	protected:
		// Handlers for FramePrincipal events.
		void OnFrameClose( wxCloseEvent& event );
		void OnButtonConnexionToggle( wxCommandEvent& event );
		void OnButtonChoixTrajectoiresClicks( wxCommandEvent& event );
		void OnButtonChoixMouvementsClicks( wxCommandEvent& event );
		void OnListBoxAffichageSelectionMouvements( wxCommandEvent& event );
		void OnListBoxModifierSelectionMouvements( wxCommandEvent& event );
		void OnApplyButtonModifierMouvementClick( wxCommandEvent& event );
		void OnCancelButtonModifierMouvementClick( wxCommandEvent& event );
		void OnSaveButtonCreerMouvementClick( wxCommandEvent& event );
		void OnListBoxDetruireSelectionMouvements( wxCommandEvent& event );
		void OnYesButtonDetruireMouvementClick( wxCommandEvent& event );
		void OnListBoxTesterSelectionMouvements( wxCommandEvent& event );
		void OnYesButtonTesterMouvementClick( wxCommandEvent& event );
		void OnListBoxAffichageSelectionTrajectoires( wxCommandEvent& event );
		void OnListBoxModifierSelectionTrajectoires( wxCommandEvent& event );
		void OnApplyButtonModifierTrajectoiresClick( wxCommandEvent& event );
		void OnCancelButtonModifierTrajectoiresClick( wxCommandEvent& event );
		void OnSaveButtonCreerTrajectoiresClick( wxCommandEvent& event );
		void OnListBoxDetruireSelectionTrajectoires( wxCommandEvent& event );
		void OnYesButtonDetruireTrajectoiresClick( wxCommandEvent& event );
		void OnListBoxTesterSelectionTrajectoires( wxCommandEvent& event );
		void OnYesButtonTesterTrajectoiresClick( wxCommandEvent& event );
		void OnButtonViderAffichageClick( wxCommandEvent& event );
	public:
		/** Constructor */
		EvtFramePrincipal( wxWindow* parent );
	//// end generated class members
    private:
        
    protected:

    public:









};

#endif // __EvtFramePrincipal__
