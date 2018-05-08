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
		wxStaticText* m_staticTextDureeTotalAfficher1;
		wxTextCtrl* textCtrlDureeTotalMinuteAfficher;
		wxStaticText* m_staticTextDureeTotalAfficher;
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
		wxStaticText* m_staticTextDureeTotalModifier1;
		wxTextCtrl* textCtrlDureeTotalMinuteModifier;
		wxStaticText* m_staticTextDureeTotalModifier;
		wxTextCtrl* textCtrlDureeTotalSecondeModifier;
		wxListBox* m_listBoxListeTrajectoiresModifier;
		wxStaticLine* m_staticlineModification;
		wxStaticText* m_staticTextNomModifier;
		wxTextCtrl* m_textCtrlNomModifier;
		wxStaticText* m_staticTextNombreBainModifier;
		wxTextCtrl* m_textCtrlNombreBainModifier;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_textCtrl14;
		wxButton* m_buttonModification;
		wxStdDialogButtonSizer* m_sdbSizerModifier;
		wxButton* m_sdbSizerModifierApply;
		wxButton* m_sdbSizerModifierCancel;
		wxScrolledWindow* m_scrolledWindowCreerProcessus;
		wxStaticText* m_staticText18;
		wxStaticLine* m_staticlineCreer;
		wxStaticText* m_staticText19;
		wxStdDialogButtonSizer* m_sdbSizerCreer;
		wxButton* m_sdbSizerCreerSave;
		wxButton* m_sdbSizerCreerCancel;
		wxScrolledWindow* m_scrolledWindowDetruireProcessus;
		wxListBox* m_listBoxDetruireProcessus;
		wxStaticText* m_staticTextDetruire;
		wxStdDialogButtonSizer* m_sdbSizerDetruire;
		wxButton* m_sdbSizerDetruireApply;
		wxScrolledWindow* m_scrolledWindowLancerProcessus;
		wxListBox* m_listBoxLancerProcessus;
		wxStdDialogButtonSizer* m_sdbSizerLancerProcessus;
		wxButton* m_sdbSizerLancerProcessusOK;
		wxPanel* m_panelAffichage;
		wxTextCtrl* m_textCtrlAffichage;
		wxButton* m_buttonViderAffichage;
		wxMenuBar* m_menubarFramePrincipal;
		wxMenu* m_menuFichier;
		wxMenu* m_menuAide;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnButtonConnexionToggle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxAffichageSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxModifierSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonModifierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyButtonModifierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonModiffierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonCreerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveButtonCreerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxDetruireSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyButtonDetruireClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxLancerSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkButtonLancerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonViderAffichageClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuQuitterSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAideSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAproposSelection( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Anodisation - Responsable de production"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1180,750 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

#endif //__FRAMEPRINCIPAL_H__
