#ifndef __EvtPanelResponsable__
#define __EvtPanelResponsable__

/**
@file
Subclass of PanelResponsable, which is generated by wxFormBuilder.
*/

#include "PanelResponsable.h"

//// end generated include
/*******************************************************************************
 *  Fichier:  EvtPanelResponsable.h
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  29/04/2018
 *  Utilité:  Gestion des événements du panel responsable
 *  Auteur:   Florian Provost
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
// Inclusion des fichiers .h
////////////////////////////////////////////////////////////////////////////////
#include "../Client/Protocoles.h"
#include "../Client/Client.h"
class Client;
#include "../BdD/DataAnodisation.h"
class DataAnodisation;
#include "../BdD/DonneesIHMresponsable.h"
class DonneesIHMresponsable;
class EvtFramePrincipal;

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
#include <sstream>
using std::ostringstream;
/*** Librairies wxWidgets ***/
// Couleur wxWidget
#include <wx/colour.h>
#include <wx/gdicmn.h>
// Boite de dialogue wxWidgets
#include <wx/log.h>
// wxMessageBox
#include <wx/msgdlg.h>

#include <wx/unichar.h>

/** Implementing PanelResponsable */
class EvtPanelResponsable : public PanelResponsable
{
    protected:
        // Handlers for PanelResponsable events.
        void OnCharEntered(wxKeyEvent& event);
        void OnListBoxAffichageSelection(wxCommandEvent& event);
        void OnTextMaxLength(wxCommandEvent& event);
        void OnCharEnteredNum(wxKeyEvent& event);
        void OnListBoxModifierSelection(wxCommandEvent& event);
        void OnApplyButtonModifierClick(wxCommandEvent& event);
        void OnCharEnteredOrdre(wxKeyEvent& event);
        void OnSpinCtrlModifierBain(wxSpinEvent& event);
        void OnCancelButtonModiffierClick(wxCommandEvent& event);
        void OnSaveButtonCreerClick(wxCommandEvent& event );
        void OnSpinCtrlCreerBain(wxSpinEvent& event);
        void OnCancelButtonCreerClick(wxCommandEvent& event);
        void OnListBoxDetruireSelection(wxCommandEvent& event);
        void OnApplyButtonDetruireClick(wxCommandEvent& event);
        void OnListBoxLancerSelection(wxCommandEvent& event);
        void OnOkButtonLancerClick(wxCommandEvent& event);
        void OnListBoxTesterSelection(wxCommandEvent& event);
        void OnStopButtonTesterClick(wxCommandEvent& event);
        void OnOkButtonTesterClick(wxCommandEvent& event);
        void OnButtonDisponibiliteBrasClick(wxCommandEvent& event);
        void OnButtonTacheEnCoursClick(wxCommandEvent& event);
    public:
        /** Constructor */
        EvtPanelResponsable( wxWindow* parent );
    //// end generated class members
    public:
        void RempliListBox();
        void VideListBox();
        
        // Acesseur
        void SetBdD(DataAnodisation* bdd_anodisation){m_bdd_anodisation = bdd_anodisation;};
        void SetClient(Client* client){m_client = client;};
        void SetClientConnecte(bool client_connecte){m_client_connecte = client_connecte;};
        void SetDonneesIHM(DonneesIHMresponsable* donnees_IHM){m_donnees_IHM = donnees_IHM;};
        void SetFrame(EvtFramePrincipal* frame){m_frame = frame;};
        
    private:
        Client* m_client;
        DataAnodisation* m_bdd_anodisation;
        DonneesIHMresponsable* m_donnees_IHM;
        EvtFramePrincipal* m_frame;
        bool m_bdd_connecte;
        bool m_client_connecte;
        bool m_fabrication;
        bool point_virgule_saisie_creer;
        bool point_virgule_saisie_modifier;
        wxBitmap BmpRouge, BmpVert;
        
        bool LancerFabrication(wxString id_processus);
        void EnvoiMessage(wxString message);
        void EnvoiErreurRemplissage(wxString message);
};

#endif // __EvtPanelResponsable__
