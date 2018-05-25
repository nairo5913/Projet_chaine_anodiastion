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
	
	wxBoxSizer* bSizerHaut;
	bSizerHaut = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Connexion") ), wxHORIZONTAL );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("\nDémarrer le serveur\n"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnexion->Add( m_toggleBtnConnexion, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	bSizerHaut->Add( sbSizerConnexion, 1, wxALL|wxEXPAND, 5 );
	
	sbSizerGestion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Gestion") ), wxVERTICAL );
	
	m_buttonViderAffichage = new wxButton( sbSizerGestion->GetStaticBox(), wxID_ANY, wxT("Vider l'affichage"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerGestion->Add( m_buttonViderAffichage, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	m_toggleBtnDisponibilite = new wxToggleButton( sbSizerGestion->GetStaticBox(), wxID_ANY, wxT("Changer la disponibilité du bras\nen disponible"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerGestion->Add( m_toggleBtnDisponibilite, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerHaut->Add( sbSizerGestion, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( bSizerHaut, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerAffichage, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_statusBar->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_buttonViderAffichage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickViderAffichage ), NULL, this );
	m_toggleBtnDisponibilite->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnToggleButtonDisponibiliteClick ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_buttonViderAffichage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickViderAffichage ), NULL, this );
	m_toggleBtnDisponibilite->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnToggleButtonDisponibiliteClick ), NULL, this );
	
}
