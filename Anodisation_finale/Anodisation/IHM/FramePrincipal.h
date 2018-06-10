///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
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
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include "EvtPanelResponsable.h"
#include "EvtPanelRegleur.h"
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
		wxStaticBoxSizer* sbSizerConnexion;
		wxStaticText* m_staticTextLogin;
		wxTextCtrl* m_textCtrlLogin;
		wxStaticText* m_staticTextPass;
		wxTextCtrl* m_textCtrlPass;
		wxToggleButton* m_toggleBtnConnexion;
		wxStaticBitmap* m_bitmapLogoOzanam;
		wxPanel* m_panelChoix;
		wxStaticLine* m_staticline11;
		wxButton* m_buttonChoixTrajectoires;
		wxButton* m_buttonChoixMouvements;
		EvtPanelResponsable *m_evt_panel_responsable;
		EvtPanelRegleur *m_evt_panel_regleur;
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
		virtual void OnButtonChoixTrajectoiresClicks( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonChoixMouvementsClicks( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonViderAffichageClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuQuitterSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuViderAffichageSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAideSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAproposSelection( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Anodisation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1200,750 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
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
