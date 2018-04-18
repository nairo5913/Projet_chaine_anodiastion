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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/checkbox.h>
#include <wx/stattext.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FramePrincipal
///////////////////////////////////////////////////////////////////////////////
class FramePrincipal : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menuFichier;
		wxMenu* m_menuAide;
		wxButton* m_buttonFenetre2;
		wxButton* m_buttonDialogue;
		wxStatusBar* m_statusBar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnMenuItemQuitterClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuItemAProposClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickButtonFenetre2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickButtonDialogue( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Frame principal"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Fenetre2
///////////////////////////////////////////////////////////////////////////////
class Fenetre2 : public wxFrame 
{
	private:
	
	protected:
		wxButton* m_buttonRetour;
		wxCheckBox* m_checkBox1;
		wxCheckBox* m_checkBox2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnClickButtonRetour( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Fenetre2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Fenêtre 2"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Fenetre2();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogTest
///////////////////////////////////////////////////////////////////////////////
class DialogTest : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnClickButtonCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickButtonOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogTest( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Boite de dialogue test"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,250 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogTest();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialogApropos
///////////////////////////////////////////////////////////////////////////////
class MyDialogApropos : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl1;
		wxStdDialogButtonSizer* m_sdbSizerDialogOk;
		wxButton* m_sdbSizerDialogOkOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnClickButtonOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialogApropos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("À propos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 728,547 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialogApropos();
	
};

#endif //__FRAMEPRINCIPAL_H__
