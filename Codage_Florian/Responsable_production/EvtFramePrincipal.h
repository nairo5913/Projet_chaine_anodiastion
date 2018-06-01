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
////////////////////////////////////////////////////////////////////////////////
// Définition
////////////////////////////////////////////////////////////////////////////////
#define ID_CLIENT 100
#define DSN "Anodisation"
#define IP "localhost" /*"192.168.1.143"*/
#define PORT 30000

////////////////////////////////////////////////////////////////////////////////
// Inclusion des fichiers .h
////////////////////////////////////////////////////////////////////////////////
#include "Client.h"
class Client;
#include "DataAnodisation.h"
#include "DonneesIHM.h"
#include "EvtFrameAide.h"
#include "EvtFrameApropos.h"
#include "Protocoles.h"

////////////////////////////////////////////////////////////////////////////////
// Librairies
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <list>
using std::list;
#include <string>
using std::string;
#include <vector>
using std::vector;
/*** Librairies wxWidgets ***/
// Couleur wxWidget
#include <wx/colour.h>
#include <wx/gdicmn.h>
// Boite de dialogue wxWidgets
#include <wx/log.h>
// wxMessageBox
#include <wx/msgdlg.h>
// Spash screen
#include <wx/splash.h>

/** Implementing FramePrincipal */
class EvtFramePrincipal : public FramePrincipal
{
    protected:
        // Handlers for FramePrincipal events.
        void OnCharEntered(wxKeyEvent& event);
        void OnFrameClose(wxCloseEvent& event);
        void OnButtonConnexionToggle(wxCommandEvent& event);
        void OnListBoxAffichageSelection(wxCommandEvent& event);
        void OnListBoxModifierSelection(wxCommandEvent& event);
        void OnCharEnteredNum(wxKeyEvent& event);
        void OnCharEnteredOrdre(wxKeyEvent& event);
        void OnApplyButtonModifierClick(wxCommandEvent& event);
        void OnCancelButtonModiffierClick(wxCommandEvent& event);
        void OnCancelButtonCreerClick(wxCommandEvent& event);
        void OnSaveButtonCreerClick(wxCommandEvent& event);
        void OnListBoxDetruireSelection(wxCommandEvent& event);
        void OnApplyButtonDetruireClick(wxCommandEvent& event);
        void OnListBoxLancerSelection(wxCommandEvent& event);
        void OnOkButtonLancerClick(wxCommandEvent& event);
        void OnListBoxTesterSelection(wxCommandEvent& event);
        void OnStopButtonTesterClick(wxCommandEvent& event);
        void OnOkButtonTesterClick(wxCommandEvent& event);
        void OnButtonDisponibiliteBrasClick(wxCommandEvent& event);
        void OnButtonTacheEnCoursClick(wxCommandEvent& event);
        void OnButtonViderAffichageClick(wxCommandEvent& event);
        void OnMenuQuitterSelection(wxCommandEvent& event);
        void OnMenuViderAffichageSelection(wxCommandEvent& event);
        void OnMenuAideSelection(wxCommandEvent& event);
        void OnMenuAproposSelection(wxCommandEvent& event);

    public:
        /** Constructor */
        EvtFramePrincipal(wxWindow* parent);
//// end generated class members
        public:
        string ConversionEnString(wxString texte);
        wxString DecouperTexteDebut(wxString texte, int position);
        wxString DecouperTexteFin(wxString texte, int position);
        wxString ConversionEnWxString(string texte);

    protected:
        // Affichage et action des events du client
        void AgitServeurPerdu(wxCommandEvent& event);
        void AfficheInfoClient(wxCommandEvent& event);
        void AfficheMessageClient(wxCommandEvent& event);

    private:
        Client* m_client;
        DataAnodisation* m_bdd_anodisation;
        DonneesIHM* m_donnees_IHM;
        bool m_bdd_connecte;
        bool m_client_connecte;
        bool m_fabrication;
        bool m_identifie;
        bool point_virgule_saisie_creer;
        bool point_virgule_saisie_modifier;
        wxBitmap BmpRouge, BmpVert;
        
        bool LancerFabrication(wxString id_processus);
        // Tester le login et le mot de passe
        bool VerificationLogin(wxString login, wxString pass);
        // Modification de la barre de statut
        void AfficheStatus(wxString texte, int position);
        // Afficher les erreurs des requete pour le remplisage de l'IHM
        void AfficheErreurRemplisage(wxString erreur);
        
        // Déconnection du client
        void DeconnexionClient(wxString message);
        void RempliListBox();
        void VideListBox();
        // Fonction de mise en forme de la séléction pour garder que le début (id)
        wxString GardeIdSelection(wxString texte);
};

#endif  // __EvtFramePrincipal__
