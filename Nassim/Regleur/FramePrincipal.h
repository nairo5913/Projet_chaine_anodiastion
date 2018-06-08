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
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
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
		wxPanel* m_panelChoix;
		wxButton* m_buttonChoixTrajectoires;
		wxButton* m_buttonChoixMouvements;
		wxNotebook* m_notebookMouvements;
		wxScrolledWindow* m_scrolledWindowAffichageMouvements;
		wxListBox* m_listBoxAffichageMouvements;
		wxStaticText* m_staticTextNomAfficherMouvements;
		wxTextCtrl* m_textCtrlNomAfficherMouvements;
		wxStaticText* m_staticTextDureeHeureAfficherMouvements1;
		wxTextCtrl* m_textCtrlDureeHeureAfficherMouvements;
		wxStaticText* m_staticTextDureeMinuteAfficherMouvements;
		wxTextCtrl* m_textCtrlDureeMinuteAfficherMouvements;
		wxStaticText* m_staticTextDureeSecondeAfficherMouvements;
		wxTextCtrl* m_textCtrlDureeSecondeAfficherMouvements;
		wxStaticLine* m_staticlineAfficherMouvements;
		wxStaticText* m_staticTextxAfficherMouvements;
		wxTextCtrl* m_textCtrlxAfficherMouvements;
		wxStaticText* m_staticTextyAfficherMouvements;
		wxTextCtrl* m_textCtrlyAfficherMouvements;
		wxStaticText* m_staticTextzAfficherMouvements;
		wxTextCtrl* m_textCtrlzAfficherMouvements;
		wxScrolledWindow* m_scrolledWindowModifierMouvements;
		wxListBox* m_listBoxModifierMouvements;
		wxStaticText* m_staticTextNomModifierMouvements;
		wxTextCtrl* m_textCtrlNomModifierMouvements;
		wxStaticText* m_staticTextDureeHeureModifierMouvements;
		wxTextCtrl* m_textCtrlDureeHeureModifierMouvements;
		wxStaticText* m_staticTextDureeMinuteModifierMouvement;
		wxTextCtrl* m_textCtrlDureeMinutesModifierMouvements;
		wxStaticText* m_staticTextDureeSecondeModifierMouvements;
		wxTextCtrl* m_textCtrlDureeSecondeModifierMouvements;
		wxStaticLine* m_staticlineModifierMouvements;
		wxStaticText* m_staticTextxModifierMouvements;
		wxTextCtrl* m_textCtrlxModifierMouvements;
		wxStaticText* m_staticTextyModifierMouvements;
		wxTextCtrl* m_textCtrlyModifierMouvements;
		wxStaticText* m_staticTextzModifierMouvements;
		wxTextCtrl* m_textCtrlzModifierMouvements;
		wxStdDialogButtonSizer* m_sdbSizer6;
		wxButton* m_sdbSizer6Apply;
		wxButton* m_sdbSizer6Cancel;
		wxScrolledWindow* m_scrolledWindowCreerMouvements;
		wxStaticText* m_staticTextNomCreerMouvements;
		wxTextCtrl* m_textCtrlNomCreerMouvements;
		wxStaticText* m_staticTextDureeHeureCreerMouvements;
		wxTextCtrl* m_textCtrlDureeHeureCreerMouvements;
		wxStaticText* m_staticTextDureeMinuteCreerMouvement;
		wxTextCtrl* m_textCtrlDureeMinutesCreerMouvements;
		wxStaticText* m_staticTextDureeSecondeCreerMouvements;
		wxTextCtrl* m_textCtrlDureeSecondeCreerMouvements;
		wxStaticLine* m_staticlineCreerMouvements;
		wxStaticText* m_staticTextCreerMouvements;
		wxTextCtrl* m_textCtrlxCreerMouvements;
		wxStaticText* m_staticTextyCreerMouvements;
		wxTextCtrl* m_textCtrlyCreerMouvements;
		wxStaticText* m_staticTextzCreerMouvements;
		wxTextCtrl* m_textCtrlzCreerMouvements;
		wxStdDialogButtonSizer* m_sdbSizer61;
		wxButton* m_sdbSizer61Save;
		wxScrolledWindow* m_scrolledWindowDetruireMouvements1;
		wxListBox* m_listBoxDetruireMouvements;
		wxStaticText* m_staticTextDetruireMouvement;
		wxStdDialogButtonSizer* m_sdbSizerDetruireMouvement;
		wxButton* m_sdbSizerDetruireMouvementYes;
		wxScrolledWindow* m_scrolledWindowDetruireMouvements11;
		wxListBox* m_listBoxTesterMouvements;
		wxStaticText* m_staticTextTesterMouvement;
		wxStdDialogButtonSizer* m_sdbSizerTesterMouvement;
		wxButton* m_sdbSizerTesterMouvementYes;
		wxButton* m_sdbSizerTesterMouvementCancel;
		wxButton* m_sdbSizerTesterMouvementHelp;
		wxNotebook* m_notebookTrajectoires;
		wxScrolledWindow* m_scrolledWindowAffichageTrajectoires;
		wxListBox* m_listBoxAffichageTrajectoires;
		wxStaticText* m_staticTextNomAfficherTrajectoire;
		wxTextCtrl* m_textCtrlNomAfficherTrajectoires;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_textCtrlBaindedepartAfficher;
		wxStaticText* m_staticText43;
		wxTextCtrl* m_textCtrlBainDarriveeAfficher;
		wxStaticText* m_staticTextDureeHeureAfficherTrajectoires;
		wxTextCtrl* m_textCtrlDureeHeureAfficherTrajectoires;
		wxStaticText* m_staticTextDureeMinuteAfficherTrajectoires;
		wxTextCtrl* m_textCtrlDureeMinutesAfficherTrajectoires;
		wxStaticText* m_staticTextDureeSecondeAfficherTrajectoires;
		wxTextCtrl* m_textCtrlDureeSecondesAfficherTrajectoires;
		wxStaticLine* m_staticlineAfficherMouvements1;
		wxListBox* m_listBoxCompositionTrajectoire;
		wxScrolledWindow* m_scrolledWindowModifierTrajectoires;
		wxListBox* m_listBoxModifierTrajectoires;
		wxStaticText* m_staticTextNomModifierTrajectoires;
		wxTextCtrl* m_textCtrlNomModifierTrajectoires;
		wxStaticText* m_staticText44;
		wxTextCtrl* m_textCtrlBainDeDepartModifier;
		wxStaticText* m_staticText45;
		wxTextCtrl* m_textCtrlBainDarriveeModifier;
		wxStaticText* m_staticTextDureeHeureModifierTrajectoires;
		wxTextCtrl* m_textCtrlDureeHeureModifierTrajectoires;
		wxStaticText* m_staticTextDureeMinuteModifierTrajectoires;
		wxTextCtrl* m_textCtrlDureeMinutesModifierTrajectoires;
		wxStaticText* m_staticTextDureeSecondeModifierTrajectoires;
		wxTextCtrl* m_textCtrlDureeSecondeModifierTrajectoires;
		wxStaticLine* m_staticlineModifierTrajectoires;
		wxListBox* m_listBoxModifierCompositionTrajectoire;
		wxStaticText* m_staticText47;
		wxTextCtrl* m_textCtrlOrdreMouvements;
		wxStdDialogButtonSizer* m_sdbSizerModifierTrajectoires;
		wxButton* m_sdbSizerModifierTrajectoiresApply;
		wxButton* m_sdbSizerModifierTrajectoiresCancel;
		wxScrolledWindow* m_scrolledWindowCreerTrajectoires;
		wxStaticText* m_staticTextNomCreerTrajectoires;
		wxTextCtrl* m_textCtrlNomCreerTrajectoires;
		wxStaticText* m_staticTextDureeHeureCreerTrajectoires;
		wxTextCtrl* m_textCtrlDureeHeureCreerTrajectoires;
		wxStaticText* m_staticTextDureeMinuteCreerTrajectoires;
		wxTextCtrl* m_textCtrlDureeMinutesCreerTrajectoires;
		wxStaticText* m_staticTextDureeSecondeCreerTrajectoires;
		wxTextCtrl* m_textCtrlDureeSecondeCreerTrajectoires;
		wxStaticText* m_staticText46;
		wxTextCtrl* m_textCtrlDepartTrajectoireCreation;
		wxStaticText* m_staticText471;
		wxTextCtrl* m_textCtrlAriveeTrajectoireCreation;
		wxStaticText* m_staticTextOrganisationMouvements;
		wxTextCtrl* m_textCtrlOrganisationTrajectoires;
		wxStaticLine* m_staticlineCreerTrajectoires;
		wxListBox* m_listBoxCreerTrajectoires;
		wxStdDialogButtonSizer* m_sdbSizerCreerTrajectoires;
		wxButton* m_sdbSizerCreerTrajectoiresSave;
		wxScrolledWindow* m_scrolledWindowDetruireTrajectoires;
		wxListBox* m_listBoxDetruireTrajectoires;
		wxStaticText* m_staticTextDetruireTrajectoires;
		wxStdDialogButtonSizer* m_sdbSizerDetruireTrajectoires;
		wxButton* m_sdbSizerDetruireTrajectoiresYes;
		wxScrolledWindow* m_scrolledWindowTestTrajectoires;
		wxListBox* m_listBoxTesterTrajectoires;
		wxStaticText* m_staticTextTesterTrajectoires;
		wxStdDialogButtonSizer* m_sdbSizerTesterTrajectoires;
		wxButton* m_sdbSizerTesterTrajectoiresYes;
		wxButton* m_sdbSizerTesterTrajectoiresCancel;
		wxButton* m_sdbSizerTesterTrajectoiresHelp;
		wxPanel* m_panelAffichage;
		wxTextCtrl* m_textCtrlAffichage;
		wxButton* m_buttonViderAffichage;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnButtonConnexionToggle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonChoixTrajectoiresClicks( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonChoixMouvementsClicks( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxAffichageSelectionMouvements( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxModifierSelectionMouvements( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyButtonModifierMouvementClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonModifierMouvementClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveButtonCreerMouvementClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxDetruireSelectionMouvements( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnYesButtonDetruireMouvementClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxTesterSelectionMouvements( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonTestMouvementClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInfoBrasTestMouvementClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnYesButtonTesterMouvementClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxAffichageSelectionTrajectoires( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxModifierSelectionTrajectoires( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyButtonModifierTrajectoiresClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonModifierTrajectoiresClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxSelectionMouvementsCreationTrajectoire( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveButtonCreerTrajectoiresClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxDetruireSelectionTrajectoires( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnYesButtonDetruireTrajectoiresClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListBoxTesterSelectionTrajectoires( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonTestTrajectoireClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInfoBrasTestTrajectoireClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnYesButtonTesterTrajectoiresClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonViderAffichageClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Anodisation - Régleur"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1145,750 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

#endif //__FRAMEPRINCIPAL_H__
