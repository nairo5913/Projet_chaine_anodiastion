///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FramePrincipal.h"

///////////////////////////////////////////////////////////////////////////

FramePrincipal::FramePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,400 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Connexion") ), wxVERTICAL );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnexion->Add( m_toggleBtnConnexion, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerConnexion, 1, wxALL|wxEXPAND, 5 );
	
	m_panelSaisie = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelSaisie->Hide();
	
	wxBoxSizer* bSizerSaisie;
	bSizerSaisie = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerSaisie;
	sbSizerSaisie = new wxStaticBoxSizer( new wxStaticBox( m_panelSaisie, wxID_ANY, wxT("Saisie") ), wxHORIZONTAL );
	
	m_staticTextSaisie = new wxStaticText( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxT("Requete :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSaisie->Wrap( -1 );
	m_staticTextSaisie->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Sans") ) );
	
	sbSizerSaisie->Add( m_staticTextSaisie, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_textCtrlSaisie = new wxTextCtrl( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	sbSizerSaisie->Add( m_textCtrlSaisie, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonSaisie = new wxButton( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxT("Saisie"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSaisie->Add( m_buttonSaisie, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizerSaisie->Add( sbSizerSaisie, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelSaisie->SetSizer( bSizerSaisie );
	m_panelSaisie->Layout();
	bSizerSaisie->Fit( m_panelSaisie );
	bSizerPrincipal->Add( m_panelSaisie, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerAffichage, 2, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlSaisie->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnClickButtonSaisie ), NULL, this );
	m_buttonSaisie->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonSaisie ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlSaisie->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnClickButtonSaisie ), NULL, this );
	m_buttonSaisie->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonSaisie ), NULL, this );
	
}
