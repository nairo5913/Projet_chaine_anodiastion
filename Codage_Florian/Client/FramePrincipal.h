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
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/tglbtn.h>
#include <wx/statbox.h>
#include <wx/button.h>
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
		wxPanel* m_panelParametresConnexion;
		wxStaticText* m_staticTextHote;
		wxTextCtrl* m_textCtrlHote;
		wxStaticText* m_staticTextPort;
		wxTextCtrl* m_textCtrlPort;
		wxToggleButton* m_toggleBtnConnexion;
		wxPanel* m_panelSaisie;
		wxTextCtrl* m_textCtrlSaisie;
		wxStaticText* m_staticTextExplications;
		wxButton* m_buttonEnvoyer;
		wxTextCtrl* m_textCtrlAffichage;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnButtonConnexionToggle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickButtonEnvoyer( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Client -> Serveur"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,500 ), long style = wxCAPTION|wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

#endif //__FRAMEPRINCIPAL_H__
