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
	this->SetSizeHints( wxSize( 600,400 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Connexion") ), wxHORIZONTAL );
	
	m_staticTextDSN = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("DSN : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDSN->Wrap( -1 );
	sbSizerConnexion->Add( m_staticTextDSN, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDSN = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Anodisation"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	sbSizerConnexion->Add( m_textCtrlDSN, 1, wxALIGN_CENTER|wxALL, 5 );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnexion->Add( m_toggleBtnConnexion, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizerPrincipal->Add( sbSizerConnexion, 1, wxALL|wxEXPAND, 10 );
	
	wxStaticBoxSizer* sbSizerSaisieRequete;
	sbSizerSaisieRequete = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Entrez la requête") ), wxVERTICAL );
	
	m_textCtrlSaisieRequete = new wxTextCtrl( sbSizerSaisieRequete->GetStaticBox(), wxID_ANY, wxT("SELECT * FROM processus"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSaisieRequete->Add( m_textCtrlSaisieRequete, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 10 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonExecutionRequete = new wxButton( sbSizerSaisieRequete->GetStaticBox(), wxID_ANY, wxT("Éxécution de la requête"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonExecutionRequete->Enable( false );
	
	bSizer2->Add( m_buttonExecutionRequete, 1, wxALIGN_BOTTOM|wxALL, 15 );
	
	
	sbSizerSaisieRequete->Add( bSizer2, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizerPrincipal->Add( sbSizerSaisieRequete, 1, wxALL|wxEXPAND, 10 );
	
	wxStaticBoxSizer* sbSizerResultat;
	sbSizerResultat = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Résultat") ), wxVERTICAL );
	
	m_textCtrlResultat = new wxTextCtrl( sbSizerResultat->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	sbSizerResultat->Add( m_textCtrlResultat, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 8 );
	
	
	bSizerPrincipal->Add( sbSizerResultat, 2, wxALL|wxEXPAND, 10 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, 0, wxID_ANY );
	m_statusBar->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonConnexion ), NULL, this );
	m_textCtrlSaisieRequete->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnClickButtonExecutionRequete ), NULL, this );
	m_buttonExecutionRequete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonExecutionRequete ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonConnexion ), NULL, this );
	m_textCtrlSaisieRequete->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnClickButtonExecutionRequete ), NULL, this );
	m_buttonExecutionRequete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonExecutionRequete ), NULL, this );
	
}
