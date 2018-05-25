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
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/spinctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/statbmp.h>
#include <wx/notebook.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FramePrincipal
///////////////////////////////////////////////////////////////////////////////
class FramePrincipal : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panelConnexion;
		wxStaticText* m_staticTextLogin;
		wxTextCtrl* m_textCtrlLogin;
		wxStaticText* m_staticTextPass;
		wxTextCtrl* m_textCtrlPass;
		wxToggleButton* m_toggleBtnConnexion;
		wxNotebook* m_notebookProcessus;
		wxScrolledWindow* m_scrolledWindowAffichageProcessus;
		wxListBox* m_listBoxAffichageProcessus;
		wxStaticText* m_staticTextIdAfficher;
		wxTextCtrl* m_textCtrlIdAfficher;
		wxStaticText* m_staticDureeTotalAfficher;
		wxTextCtrl* m_textCtrlDureeTotalHeureAfficher;
		wxStaticText* m_staticTextDureeTotalMinuteAfficher;
		wxTextCtrl* textCtrlDureeTotalMinuteAfficher;
		wxStaticText* m_staticTextDureeTotalSecondeAfficher;
		wxTextCtrl* textCtrlDureeTotalSecondeAfficher;
		wxListBox* m_listBoxListeTrajectoiresAfficher;
		wxStaticLine* m_staticlineAfficher;
		wxStaticText* m_staticTextNomAfficher;
		wxTextCtrl* m_textCtrlNomAfficher;
		wxStaticText* m_staticTextNombreBainAfficher;
		wxTextCtrl* m_textCtrlNombreBainAfficher;
		wxStaticText* m_staticTextOrdreTrajectoiresAfficher;
		wxTextCtrl* m_textCtrlOrdreTrajectoiresAfficher;
		wxScrolledWindow* m_scrolledWindowModifierProcessus;
		wxListBox* m_listBoxModifierProcessus;
		wxStaticText* m_staticTextIdModifier;
		wxTextCtrl* m_textCtrlIdModifier;
		wxStaticText* m_staticDureeTotalModifier;
		wxTextCtrl* m_textCtrlDureeTotalHeureModifier;
		wxStaticText* m_staticTextDureeTotalMinuteModifier;
		wxTextCtrl* textCtrlDureeTotalMinuteModifier;
		wxStaticText* m_staticTextDureeTotalSecondeModifier;
		wxTextCtrl* textCtrlDureeTotalSecondeModifier;
		wxListBox* m_listBoxListeTrajectoiresModifier;
		wxStaticLine* m_staticlineModification;
		wxStaticText* m_staticTextNomModifier;
		wxTextCtrl* m_textCtrlNomModifier;
		wxStaticText* m_staticTextNombreBainModifier;
		wxTextCtrl* m_textCtrlNombreBainModifier;
		wxStaticText* m_staticTextOrdreTrajectoiresModifier;
		wxTextCtrl* m_textCtrlOrdreTrajectoiresModifier;
		wxStdDialogButtonSizer* m_sdbSizerModifier;
		wxButton* m_sdbSizerModifierApply;
		wxButton* m_sdbSizerModifierCancel;
		wxScrolledWindow* m_scrolledWindowCreerProcessus;
		wxStaticText* m_staticDureeTotalCreer;
		wxTextCtrl* m_textCtrlDureeTotalHeureCreer;
		wxStaticText* m_staticTextDureeTotalMinuteCreer;
		wxTextCtrl* textCtrlDureeTotalMinuteCreer;
		wxStaticText* m_staticTextDureeTotalSecondeCreer;
		wxTextCtrl* textCtrlDureeTotalSecondeCreer;
		wxListBox* m_listBoxListeTrajectoiresCreer;
		wxStaticLine* m_staticlineCreer;
		wxStaticText* m_staticTextNomCreer;
		wxTextCtrl* m_textCtrlNomCreer;
		wxStaticText* m_staticTextNombreBainCreer;
		wxSpinCtrl* m_spinCtrlNombreBainCreer;
		wxStaticText* m_staticTextOrdreTrajectoiresCreer;
		wxTextCtrl* m_textCtrlOrdreTrajectoiresCreer;
		wxStdDialogButtonSizer* m_sdbSizerCreer;
		wxButton* m_sdbSizerCreerSave;
		wxButton* m_sdbSizerCreerCancel;
		wxScrolledWindow* m_scrolledWindowDetruireProcessus;
		wxListBox* m_listBoxDetruireProcessus;
		wxStaticText* m_staticTextDetruire;
		wxStaticText* m_staticTextDetuireTitre;
		wxStdDialogButtonSizer* m_sdbSizerDetruire;
		wxButton* m_sdbSizerDetruireApply;
		wxScrolledWindow* m_scrolledWindowLancerProcessus;
		wxListBox* m_listBoxLancerProcessus;
		wxStaticText* m_staticTextLancer;
		wxStaticText* m_staticTextLancerTitre;
		wxStdDialogButtonSizer* m_sdbSizerLancerProcessus;
		wxButton* m_sdbSizerLancerProcessusOK;
		wxScrolledWindow* m_scrolledWindowTesterProcessus;
		wxListBox* m_listBoxTesterProcessus;
		wxStaticText* m_staticTextTester;
		wxStaticText* m_staticTextTesterTitre;
		wxBitmapButton* m_bpButtonStopTester;
		wxBitmapButton* m_bpButtonOKTester;
		wxScrolledWindow* m_scrolledWindowInfoBras;
		wxStaticBoxSizer* sbSizerDisponibiliteBras;
		wxPanel* m_panelBrasDisponible;
		wxStaticBitmap* m_bitmapBrasDisponible;
		wxStaticText* m_staticTextBrasDisponible;
		wxPanel* m_panelBrasIndisponible;
		wxStaticBitmap* m_bitmapBrasIndisponible;
		wxStaticText* m_staticTextBrasIndisponible;
		wxStaticBoxSizer* sbSizerTacheEnCours;
		wxPanel* m_panelTacheEnCours;
		wxStaticText* m_staticTextTypeTache;
		wxTextCtrl* m_textCtrlTypeTache;
		wxStaticText* m_staticTextNomTache;
		wxTextCtrl* m_textCtrlNomTache;
		wxStaticText* m_staticDureeRestant;
		wxTextCtrl* m_textCtrlDureeRestantHeure;
		wxStaticText* m_staticTextDureeRestantMinute;
		wxTextCtrl* textCtrlDureeRestantMinute;
		wxStaticText* m_staticTextDureeRestantSeconde;
		wxTextCtrl* textCtrlDureeRestantSeconde;
		wxPanel* m_panelPasTache;
		wxStaticText* m_staticTextPasTache;
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
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnButtonConnexionToggle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxAffichageSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxModifierSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyButtonModifierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonModiffierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonCreerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveButtonCreerClick( wxCommandEvent& event ) { event.Skip(); }
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
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Anodisation - Responsable de production"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1200,750 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
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
