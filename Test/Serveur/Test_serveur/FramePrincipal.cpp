///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FramePrincipal.h"

///////////////////////////////////////////////////////////////////////////

FramePrincipal::FramePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 600,500 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Connexion") ), wxHORIZONTAL );
	
	m_panelParametreConnexion = new wxPanel( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerParametreConnexion;
	bSizerParametreConnexion = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerPort;
	bSizerPort = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPort = new wxStaticText( m_panelParametreConnexion, wxID_ANY, wxT("Port : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPort->Wrap( -1 );
	m_staticTextPort->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, true, wxEmptyString ) );
	
	bSizerPort->Add( m_staticTextPort, 0, wxALIGN_CENTER|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_textCtrlPort = new wxTextCtrl( m_panelParametreConnexion, wxID_ANY, wxT("30000"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	bSizerPort->Add( m_textCtrlPort, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizerParametreConnexion->Add( bSizerPort, 1, wxEXPAND, 5 );
	
	
	m_panelParametreConnexion->SetSizer( bSizerParametreConnexion );
	m_panelParametreConnexion->Layout();
	bSizerParametreConnexion->Fit( m_panelParametreConnexion );
	sbSizerConnexion->Add( m_panelParametreConnexion, 1, wxEXPAND | wxALL, 5 );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("\nDémarrer le serveur\n"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnexion->Add( m_toggleBtnConnexion, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_buttonViderAffichage = new wxButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Vider l'affichage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonViderAffichage->Hide();
	
	sbSizerConnexion->Add( m_buttonViderAffichage, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerConnexion, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerAffichage, 2, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_statusBar->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxEmptyString ) );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlPort->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_buttonViderAffichage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickViderAffichage ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlPort->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_buttonViderAffichage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickViderAffichage ), NULL, this );
	
}
