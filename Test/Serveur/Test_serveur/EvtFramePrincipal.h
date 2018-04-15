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
*  Projet:   Chaîne d'anodisation - Test du client pour le PC responsable
de production avec un serveur
*  Crée le:  11/04/2018
*  Utilité:  Gestion des événements du frame principal
*  Auteur:   Florian Provost
*******************************************************************************/
#define ID_SERVEUR 200

#include <Serveur.h>
#include <wx/msgdlg.h>
class Serveur;

/** Implementing FramePrincipal */
class EvtFramePrincipal : public FramePrincipal
{
	protected:
		// Handlers for FramePrincipal events.
		void OnFrameClose( wxCloseEvent& event );
		void OnButtonDemarrerServeurToggle( wxCommandEvent& event );
	public:
		/** Constructor */
		EvtFramePrincipal( wxWindow* parent );
	//// end generated class members

    private:
        bool m_connecte;
        Serveur *m_serveur;
        
        void MAJnombreClients(wxCommandEvent& event);
        void AfficheMessageServeur(wxCommandEvent& event);
        void ArretServeur(wxString message);
};

#endif // __EvtFramePrincipal__
