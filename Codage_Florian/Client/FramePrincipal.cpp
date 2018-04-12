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
	this->SetSizeHints( wxSize( 500,500 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Connexion") ), wxHORIZONTAL );
	
	m_panelParametresConnexion = new wxPanel( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerParametresConnexion;
	bSizerParametresConnexion = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerHote;
	bSizerHote = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextHote = new wxStaticText( m_panelParametresConnexion, wxID_ANY, wxT("Hôte : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHote->Wrap( -1 );
	m_staticTextHote->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxEmptyString ) );
	
	bSizerHote->Add( m_staticTextHote, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlSaisieHote = new wxTextCtrl( m_panelParametresConnexion, wxID_ANY, wxT("localhost"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
	bSizerHote->Add( m_textCtrlSaisieHote, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerParametresConnexion->Add( bSizerHote, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerPort;
	bSizerPort = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPort = new wxStaticText( m_panelParametresConnexion, wxID_ANY, wxT("Port : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPort->Wrap( -1 );
	m_staticTextPort->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxEmptyString ) );
	
	bSizerPort->Add( m_staticTextPort, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlSaisiePort = new wxTextCtrl( m_panelParametresConnexion, wxID_ANY, wxT("30000"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	bSizerPort->Add( m_textCtrlSaisiePort, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerParametresConnexion->Add( bSizerPort, 1, wxEXPAND, 5 );
	
	
	m_panelParametresConnexion->SetSizer( bSizerParametresConnexion );
	m_panelParametresConnexion->Layout();
	bSizerParametresConnexion->Fit( m_panelParametresConnexion );
	sbSizerConnexion->Add( m_panelParametresConnexion, 2, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerButtonConnexion;
	bSizerButtonConnexion = new wxBoxSizer( wxHORIZONTAL );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtonConnexion->Add( m_toggleBtnConnexion, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizerButtonConnexion, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerConnexion, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxALL|wxEXPAND, 5 );
	
	m_panelSaisie = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelSaisie->Hide();
	
	wxStaticBoxSizer* sbSizerSaisie;
	sbSizerSaisie = new wxStaticBoxSizer( new wxStaticBox( m_panelSaisie, wxID_ANY, wxT("Saisie") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrlSaisie = new wxTextCtrl( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer6->Add( m_textCtrlSaisie, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	sbSizerSaisie->Add( bSizer6, 1, wxEXPAND, 5 );
	
	m_staticTextExplications = new wxStaticText( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxT("num protocole (commande ) + parametre"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextExplications->Wrap( -1 );
	m_staticTextExplications->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );
	
	sbSizerSaisie->Add( m_staticTextExplications, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_buttonEnvoyer = new wxButton( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxT("Envoyer"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSaisie->Add( m_buttonEnvoyer, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	m_panelSaisie->SetSizer( sbSizerSaisie );
	m_panelSaisie->Layout();
	sbSizerSaisie->Fit( m_panelSaisie );
	bSizerPrincipal->Add( m_panelSaisie, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerAffichage, 2, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlSaisieHote->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlSaisiePort->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlSaisie->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnClickButtonEnvoyer ), NULL, this );
	m_buttonEnvoyer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonEnvoyer ), NULL, this );
	m_textCtrlAffichage->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnTextEnterSaisie ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlSaisieHote->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlSaisiePort->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlSaisie->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnClickButtonEnvoyer ), NULL, this );
	m_buttonEnvoyer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonEnvoyer ), NULL, this );
	m_textCtrlAffichage->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnTextEnterSaisie ), NULL, this );
	
}
