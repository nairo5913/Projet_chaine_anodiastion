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
#include <wx/tglbtn.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FramePrincipal
///////////////////////////////////////////////////////////////////////////////
class FramePrincipal : public wxFrame 
{
	private:
	
	protected:
		wxToggleButton* m_toggleBtnConnexion;
		wxToggleButton* m_toggleBtnDisponibilite;
		wxStaticText* m_staticTextTacheEnCours;
		wxChoice* m_choiceTacheEnCours;
		wxStaticLine* m_staticline3;
		wxTextCtrl* m_textCtrlAffichage;
		wxButton* m_buttonViderAffichage;
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar;
		wxMenu* m_menuFichier;
		wxMenu* m_menuEdition;
		wxMenuItem* m_menuItemChangerDisponibiliteBras;
		wxMenu* m_menuTypeMouvement;
		wxMenuItem* m_menuItemMouvement;
		wxMenuItem* m_menuItemProcessus;
		wxMenuItem* m_menuItemTrajectoire;
		wxMenu* m_menuVues;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCharEntered( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnButtonDemarrerServeurToggle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToggleButtonDisponibiliteClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChoiceTache( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickViderAffichage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionQuitter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionChangerDisponibiliteBras( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionMouvement( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionProcessus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionTrajectoire( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionViderAffichage( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Serveur de communication"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,550 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

#endif //__FRAMEPRINCIPAL_H__
