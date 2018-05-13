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
*  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
*  Crée le:  29/04/2018
*  Utilité:  Gestion des événements du frame principal
*  Auteur:   Florian Provost
*******************************************************************************/
#define ID_CLIENT 100

#include "Protocoles.h"
#include "EvtDialogApropos.h"
#include "EvtDialogAide.h"
#include "DataAnodisation.h"
#include "Client.h"
class Client;

#include <wx/log.h>
#include <wx/colour.h>
#include <wx/splash.h>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

/** Implementing FramePrincipal */
class EvtFramePrincipal : public FramePrincipal
{
	protected:
		// Handlers for FramePrincipal events.
		void OnFrameClose( wxCloseEvent& event );
		void OnButtonConnexionToggle( wxCommandEvent& event );
		void OnListBoxAffichageSelection( wxCommandEvent& event );
		void OnListBoxModifierSelection( wxCommandEvent& event );
		void OnApplyButtonModifierClick( wxCommandEvent& event );
		void OnCancelButtonModiffierClick( wxCommandEvent& event );
		void OnCancelButtonCreerClick( wxCommandEvent& event );
		void OnSaveButtonCreerClick( wxCommandEvent& event );
		void OnListBoxDetruireSelection( wxCommandEvent& event );
		void OnApplyButtonDetruireClick( wxCommandEvent& event );
		void OnListBoxLancerSelection( wxCommandEvent& event );
		void OnOkButtonLancerClick( wxCommandEvent& event );
		void OnListBoxTesterSelection( wxCommandEvent& event );
		void OnStopButtonTesterClick( wxCommandEvent& event );
		void OnOkButtonTesterClick( wxCommandEvent& event );
		void OnButtonViderAffichageClick( wxCommandEvent& event );
		void OnMenuQuitterSelection( wxCommandEvent& event );
		void OnMenuAideSelection( wxCommandEvent& event );
		void OnMenuAproposSelection( wxCommandEvent& event );
		void OnMenuViderAffichageSelection( wxCommandEvent& event );
	public:
		/** Constructor */
		EvtFramePrincipal( wxWindow* parent );
	//// end generated class members
    protected:

    public:

    private:
        Client *m_client;
        bool m_connecte;
        bool m_identifie;
        // fonction de mise en forme de la séléction des wxListBox pour garder que le début (id) ou nom (pour le wxStaticText)
        //
        // Tester le login et le mot de passe
        bool VerificationLogin(wxString login, wxString pass);















};

#endif // __EvtFramePrincipal__
