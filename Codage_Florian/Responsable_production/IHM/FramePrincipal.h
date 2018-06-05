///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FRAMEPRINCIPAL_H__
#define __FRAMEPRINCIPAL_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>
#include <wx/sizer.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/scrolwin.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/bmpbuttn.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_ORDRE_MODIFIER 1000
#define wxID_ORDRE_CREER 1001

///////////////////////////////////////////////////////////////////////////////
/// Class FramePrincipal
///////////////////////////////////////////////////////////////////////////////
class FramePrincipal : public wxFrame 
{
	private:
	
	protected:
		wxStaticBoxSizer* sbSizerConnexion;
		wxStaticText* m_staticTextLogin;
		wxTextCtrl* m_textCtrlLogin;
		wxStaticText* m_staticTextPass;
		wxTextCtrl* m_textCtrlPass;
		wxToggleButton* m_toggleBtnConnexion;
		wxStaticBitmap* m_bitmapLogoOzanam;
		wxNotebook* m_notebookProcessus;
		wxScrolledWindow* m_scrolledWindowAffichageProcessus;
		wxListBox* m_listBoxAffichageProcessus;
		wxStaticText* m_staticTextIdAfficher;
		wxTextCtrl* m_textCtrlIdAfficher;
		wxStaticText* m_staticDureeTotalAfficher;
		wxTextCtrl* m_textCtrlDureeTotalHeureAfficher;
		wxStaticText* m_staticTextDureeTotalMinuteAfficher;
		wxTextCtrl* m_textCtrlDureeTotalMinuteAfficher;
		wxStaticText* m_staticTextDureeTotalSecondeAfficher;
		wxTextCtrl* m_textCtrlDureeTotalSecondeAfficher;
		wxListBox* m_listBoxListeTrajectoiresAfficher;
		wxStaticLine* m_staticlineAfficher;
		wxStaticText* m_staticTextNomAfficher;
		wxTextCtrl* m_textCtrlNomAfficher;
		wxStaticText* m_staticTextOrdreTrajectoiresAfficher;
		wxTextCtrl* m_textCtrlOrdreTrajectoiresAfficher;
		wxStaticBoxSizer* sbSizerGestionBainAfficher;
		wxStaticText* m_staticTextNombreBainAfficher;
		wxTextCtrl* m_textCtrlNombreBainAfficher;
		wxBoxSizer* bSizerAfficherBain;
		wxBoxSizer* bSizerBainAfficherDuree;
		wxBoxSizer* bSizerAfficherDureeBain1;
		wxStaticText* m_staticAfficherDureeTotalBain1;
		wxTextCtrl* m_textCtrlAfficherHeureBain1;
		wxStaticText* m_staticTextAfficherDureeBain1;
		wxTextCtrl* m_textCtrlAfficherMinuteBain1;
		wxStaticText* m_staticTextAfficherDureeFinBain1;
		wxTextCtrl* m_textCtrlAfficherSecondeBain1;
		wxBoxSizer* bSizerAfficherDureeBain2;
		wxStaticText* m_staticAfficherDureeTotalBain2;
		wxTextCtrl* m_textCtrlAfficherHeureBain2;
		wxStaticText* m_staticTextAfficherDureeBain2;
		wxTextCtrl* m_textCtrlAfficherMinuteBain2;
		wxStaticText* m_staticTextAfficherDureeFinBain2;
		wxTextCtrl* m_textCtrlAfficherSecondeBain2;
		wxBoxSizer* bSizerAfficherDureeBain3;
		wxStaticText* m_staticAfficherDureeTotalBain3;
		wxTextCtrl* m_textCtrlAfficherHeureBain3;
		wxStaticText* m_staticTextAfficherDureeBain3;
		wxTextCtrl* m_textCtrlAfficherMinuteBain3;
		wxStaticText* m_staticTextAfficherDureeFinBain3;
		wxTextCtrl* m_textCtrlAfficherSecondeBain3;
		wxScrolledWindow* m_scrolledWindowModifierProcessus;
		wxListBox* m_listBoxModifierProcessus;
		wxStaticText* m_staticTextIdModifier;
		wxTextCtrl* m_textCtrlIdModifier;
		wxStaticText* m_staticDureeTotalModifier;
		wxTextCtrl* m_textCtrlDureeTotalHeureModifier;
		wxStaticText* m_staticTextDureeTotalMinuteModifier;
		wxTextCtrl* m_textCtrlDureeTotalMinuteModifier;
		wxStaticText* m_staticTextDureeTotalSecondeModifier;
		wxTextCtrl* m_textCtrlDureeTotalSecondeModifier;
		wxListBox* m_listBoxListeTrajectoiresModifier;
		wxStaticLine* m_staticlineModification;
		wxStaticText* m_staticTextNomModifier;
		wxTextCtrl* m_textCtrlNomModifier;
		wxStaticText* m_staticTextOrdreTrajectoiresModifier;
		wxTextCtrl* m_textCtrlOrdreTrajectoiresModifier;
		wxStaticBoxSizer* sbSizerGestionBainModifier;
		wxBoxSizer* bSizerNombreBainModifier;
		wxStaticText* m_staticTextNombreBainModifier;
		wxSpinCtrl* m_spinCtrlNombreBainModifier;
		wxBoxSizer* bSizerModifierBain;
		wxBoxSizer* bSizerBainModifierDuree;
		wxBoxSizer* bSizerModifierDureeBain1;
		wxStaticText* m_staticModifierDureeTotalBain1;
		wxTextCtrl* m_textCtrlModifierHeureBain1;
		wxStaticText* m_staticTextModifierDureeBain1;
		wxTextCtrl* m_textCtrlModifierMinuteBain1;
		wxStaticText* m_staticTextModifierDureeFinBain1;
		wxTextCtrl* m_textCtrlModifierSecondeBain1;
		wxBoxSizer* bSizerModifierDureeBain2;
		wxStaticText* m_staticModifierDureeTotalBain2;
		wxTextCtrl* m_textCtrlModifierHeureBain2;
		wxStaticText* m_staticTextModifierDureeBain2;
		wxTextCtrl* m_textCtrlModifierMinuteBain2;
		wxStaticText* m_staticTextModifierDureeFinBain2;
		wxTextCtrl* m_textCtrlModifierSecondeBain2;
		wxBoxSizer* bSizerModifierDureeBain3;
		wxStaticText* m_staticModifierDureeTotalBain3;
		wxTextCtrl* m_textCtrlModifierHeureBain3;
		wxStaticText* m_staticTextModifierDureeBain3;
		wxTextCtrl* m_textCtrlModifierMinuteBain3;
		wxStaticText* m_staticTextModifierDureeFinBain3;
		wxTextCtrl* m_textCtrlModifierSecondeBain3;
		wxStaticLine* m_staticline10;
		wxStdDialogButtonSizer* m_sdbSizerModifier;
		wxButton* m_sdbSizerModifierApply;
		wxButton* m_sdbSizerModifierCancel;
		wxScrolledWindow* m_scrolledWindowCreerProcessus;
		wxStaticText* m_staticDureeTotalCreer;
		wxTextCtrl* m_textCtrlDureeTotalHeureCreer;
		wxStaticText* m_staticTextDureeTotalMinuteCreer;
		wxTextCtrl* m_textCtrlDureeTotalMinuteCreer;
		wxStaticText* m_staticTextDureeTotalSecondeCreer;
		wxTextCtrl* m_textCtrlDureeTotalSecondeCreer;
		wxStaticText* m_staticTextOrdreTrajectoiresCreer;
		wxTextCtrl* m_textCtrlOrdreTrajectoiresCreer;
		wxListBox* m_listBoxListeTrajectoiresCreer;
		wxStaticLine* m_staticlineCreer;
		wxStaticText* m_staticTextNomCreer;
		wxTextCtrl* m_textCtrlNomCreer;
		wxStaticBoxSizer* sbSizerGestionBainCreer;
		wxBoxSizer* bSizerNombreBainCreer;
		wxStaticText* m_staticTextNombreBainCreer;
		wxSpinCtrl* m_spinCtrlNombreBainCreer;
		wxBoxSizer* bSizerCreerBain;
		wxBoxSizer* bSizerBainCreerDuree;
		wxBoxSizer* bSizerCreerDureeBain1;
		wxStaticText* m_staticCreerDureeTotalBain1;
		wxTextCtrl* m_textCtrlCreerHeureBain1;
		wxStaticText* m_staticTextCreerDureeBain1;
		wxTextCtrl* m_textCtrlCreerMinuteBain1;
		wxStaticText* m_staticTextcreerDureeFinBain1;
		wxTextCtrl* m_textCtrlCreerSecondeBain1;
		wxBoxSizer* bSizerCreerDureeBain2;
		wxStaticText* m_staticCreerDureeTotalBain2;
		wxTextCtrl* m_textCtrlCreerHeureBain2;
		wxStaticText* m_staticTextCreerDureeBain2;
		wxTextCtrl* m_textCtrlCreerMinuteBain2;
		wxStaticText* m_staticTextCreerDureeFinBain2;
		wxTextCtrl* m_textCtrlCreerSecondeBain2;
		wxBoxSizer* bSizerCreerDureeBain3;
		wxStaticText* m_staticCreerDureeTotalBain3;
		wxTextCtrl* m_textCtrlCreerHeureBain3;
		wxStaticText* m_staticTextCreerDureeBain3;
		wxTextCtrl* m_textCtrlCreerMinuteBain3;
		wxStaticText* m_staticTextCreerDureeFinBain3;
		wxTextCtrl* m_textCtrlCreerSecondeBain3;
		wxStdDialogButtonSizer* m_sdbSizerCreer;
		wxButton* m_sdbSizerCreerSave;
		wxButton* m_sdbSizerCreerCancel;
		wxScrolledWindow* m_scrolledWindowDetruireProcessus;
		wxListBox* m_listBoxDetruireProcessus;
		wxStaticText* m_staticTextDetruire;
		wxStaticText* m_staticTextDetuireTitre;
		wxBoxSizer* bSizerDureeTotalDetruire;
		wxStaticText* m_staticTextDureeTotalProcessusDetruire;
		wxStaticText* m_staticTextDureeTotalValeurDetruire;
		wxStaticLine* m_staticlineSeparateurGaucheDroiteDetruire;
		wxBoxSizer* bSizerNombreBainDetruire;
		wxStaticText* m_staticTextNombreBainDetruire;
		wxStaticText* m_staticTextNombreBainValeurDetruire;
		wxBoxSizer* bSizerOrdreTrajectoiresDetruire;
		wxStaticText* m_staticTextOrdreTrajectoiresDetruire;
		wxStaticText* m_staticTextOrdreTrajectoiresDetruireValeur;
		wxStaticLine* m_staticlineSeparateurDetailBoutonDetruire;
		wxStdDialogButtonSizer* m_sdbSizerDetruire;
		wxButton* m_sdbSizerDetruireApply;
		wxScrolledWindow* m_scrolledWindowLancerProcessus;
		wxListBox* m_listBoxLancerProcessus;
		wxStaticText* m_staticTextLancer;
		wxStaticText* m_staticTextLancerTitre;
		wxBoxSizer* bSizerDetailLancer;
		wxBoxSizer* bSizerLancerDroit;
		wxBoxSizer* bSizerDureeTotalLancer;
		wxStaticText* m_staticTextDureeTotalProcessusLancer;
		wxStaticText* m_staticTextDureeTotalValeurLancer;
		wxStaticLine* m_staticlineSeparateurGaucheDroiteLancer;
		wxBoxSizer* bSizerLancerGauche;
		wxBoxSizer* bSizerNombreBainLancer;
		wxStaticText* m_staticTextNombreBainLancer;
		wxStaticText* m_staticTextNombreBainValeurLancer;
		wxBoxSizer* bSizerOrdreTrajectoiresLancer;
		wxStaticText* m_staticTextOrdreTrajectoiresLancer;
		wxStaticText* m_staticTextOrdreTrajectoiresValeurLancer;
		wxStaticLine* m_staticlineSeparateurDetailBoutonLancer;
		wxStdDialogButtonSizer* m_sdbSizerLancerProcessus;
		wxButton* m_sdbSizerLancerProcessusOK;
		wxScrolledWindow* m_scrolledWindowTesterProcessus;
		wxListBox* m_listBoxTesterProcessus;
		wxStaticText* m_staticTextTester;
		wxStaticText* m_staticTextTesterTitre;
		wxBoxSizer* bSizerDetailTester;
		wxBoxSizer* bSizerTesterDroit;
		wxBoxSizer* bSizerDureeTotalTester;
		wxStaticText* m_staticTextDureeTotalProcessusTester;
		wxStaticText* m_staticTextDureeTotalValeurTester;
		wxStaticLine* m_staticlineSeparateurGaucheDroiteTester;
		wxBoxSizer* bSizerTesterGauche;
		wxBoxSizer* bSizerNombreBainTester;
		wxStaticText* m_staticTextNombreBainTester;
		wxStaticText* m_staticTextNombreBainValeurTester;
		wxBoxSizer* bSizerOrdreTrajectoiresTester;
		wxStaticText* m_staticTextOrdreTrajectoiresTester;
		wxStaticText* m_staticTextOrdreTrajectoiresValeurTester;
		wxStaticLine* m_staticlineSeparateurDetailBoutonsTester;
		wxBitmapButton* m_bpButtonStopTester;
		wxBitmapButton* m_bpButtonOKTester;
		wxScrolledWindow* m_scrolledWindowInfoBras;
		wxStaticBoxSizer* sbSizerDisponibiliteBras;
		wxStaticBitmap* m_bitmapDisponibiliteBras;
		wxStaticText* m_staticTextDisponibiliteBras;
		wxStaticBoxSizer* sbSizerTache;
		wxBoxSizer* bSizerTypeTache;
		wxStaticText* m_staticTextTypeTache;
		wxTextCtrl* m_textCtrlTypeTache;
		wxBoxSizer* bSizerNomTache;
		wxStaticText* m_staticTextNomTache;
		wxTextCtrl* m_textCtrlNomTache;
		wxBoxSizer* bSizerDureeRestant;
		wxStaticText* m_staticDureeRestant;
		wxTextCtrl* m_textCtrlDureeRestantHeure;
		wxStaticText* m_staticTextDureeRestantMinute;
		wxTextCtrl* m_textCtrlDureeRestantMinute;
		wxStaticText* m_staticTextDureeRestantSeconde;
		wxTextCtrl* m_textCtrlDureeRestantSeconde;
		wxButton* m_buttonDisponibiliteBras;
		wxButton* m_buttonTacheEnCours;
		wxPanel* m_panelAffichage;
		wxTextCtrl* m_textCtrlAffichage;
		wxButton* m_buttonViderAffichage;
		wxMenuBar* m_menubarFramePrincipal;
		wxMenu* m_menuFichier;
		wxMenu* m_menuVues;
		wxMenu* m_menuAide;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCharEntered( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnButtonConnexionToggle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextMaxLength( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxAffichageSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCharEnteredNum( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnListBoxModifierSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyButtonModifierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCharEnteredOrdre( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnSpinCtrlModifierBain( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonModiffierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveButtonCreerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpinCtrlCreerBain( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonCreerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxDetruireSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyButtonDetruireClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxLancerSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkButtonLancerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxTesterSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopButtonTesterClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkButtonTesterClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonDisponibiliteBrasClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTacheEnCoursClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonViderAffichageClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuQuitterSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuViderAffichageSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAideSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAproposSelection( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Anodisation - Responsable de production"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1200,750 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FrameApropos
///////////////////////////////////////////////////////////////////////////////
class FrameApropos : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panelApropos;
		wxStaticText* m_staticTextTitre;
		wxStaticBitmap* m_bitmapLogoOzanam;
		wxStaticText* m_staticText40;
		wxStdDialogButtonSizer* m_sdbSizerApropos;
		wxButton* m_sdbSizerAproposOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseFrame( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnOkButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FrameApropos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Anodisation - À propos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~FrameApropos();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FrameAide
///////////////////////////////////////////////////////////////////////////////
class FrameAide : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panelAide;
		wxStaticText* m_staticTextTitre;
		wxStdDialogButtonSizer* m_sdbSizerApropos;
		wxButton* m_sdbSizerAproposOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseFrame( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnOkButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FrameAide( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Anodisation - Aide"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,500 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~FrameAide();
	
};

#endif //__FRAMEPRINCIPAL_H__
