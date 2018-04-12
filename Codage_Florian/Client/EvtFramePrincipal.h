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
*  Projet:   Chaîne d'anodisation - Gestion du client pour le PC responsable
de production
*  Crée le:  11/04/2018
*  Utilité:  Gestion des événements du frame principal
*  Auteur:   Florian Provost
*******************************************************************************/
#define ID_CLIENT 100
class Client;
#include "Protocoles.h"
#include <wx/log.h>
#include <iostream>

/** Implementing FramePrincipal */
class EvtFramePrincipal : public FramePrincipal
{
	protected:
		// Handlers for FramePrincipal events.
		void OnFrameClose( wxCloseEvent& event );
		void OnButtonConnexionToggle( wxCommandEvent& event );
		void OnClickButtonEnvoyer( wxCommandEvent& event );
		void OnTextEnterSaisie( wxCommandEvent& event );
	public:
		/** Constructor */
		EvtFramePrincipal( wxWindow* parent );
	//// end generated class members
    protected:
        void AfficheMessageClient(wxCommandEvent& event);
        void AfficheInfoClient(wxCommandEvent& event);
        void AgitServeurPerdu(wxCommandEvent& event);
        void GereReponse(wxString reponse, wxString reponse_attendue);
    private:
        Client *m_client;
        bool m_connecte;

        void Deconnexion(wxString message);


};

#endif // __EvtFramePrincipal__
