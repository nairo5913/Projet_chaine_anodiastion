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
#include <wx/tglbtn.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/scrolwin.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FramePrincipal
///////////////////////////////////////////////////////////////////////////////
class FramePrincipal : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panelConnexion;
		wxStaticText* m_staticTextDSN;
		wxTextCtrl* m_textCtrlDSN;
		wxToggleButton* m_toggleBtnConnexion;
		wxScrolledWindow* m_scrolledWindowRequete;
		wxStaticText* m_staticTextRequete;
		wxTextCtrl* m_textCtrlSelection;
		wxButton* m_buttonSelection;
		wxTextCtrl* m_textCtrlInsertion;
		wxButton* m_buttonInsertion;
		wxTextCtrl* m_textCtrlMAJ;
		wxButton* m_buttonMAJ;
		wxStaticText* m_staticTextSuppression;
		wxTextCtrl* m_textCtrlSuppression;
		wxButton* m_buttonSuppression;
		wxTextCtrl* m_textCtrlAffichage;
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar1;
		wxMenu* m_menuQuitter;
		wxMenu* m_menuAide;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnToggleButtonConnexion( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickInsertion( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickMAJ( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickSuppression( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuQuitterSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAideSelection( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Client BdD"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 666,615 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialogAide
///////////////////////////////////////////////////////////////////////////////
class MyDialogAide : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* m_textCtrlAffichageAide;
		wxStdDialogButtonSizer* m_sdbSizerBoutonOKAide;
		wxButton* m_sdbSizerBoutonOKAideOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDialogClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialogAide( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Aide"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialogAide();
	
};

#endif //__FRAMEPRINCIPAL_H__
