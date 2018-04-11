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
	this->SetSizeHints( wxSize( 400,200 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Connexion") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextHote = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Hôte : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHote->Wrap( -1 );
	bSizer4->Add( m_staticTextHote, 0, wxALL, 5 );
	
	m_textCtrlSaisieHote = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	bSizer4->Add( m_textCtrlSaisieHote, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPort = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Port : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPort->Wrap( -1 );
	bSizer41->Add( m_staticTextPort, 0, wxALL, 5 );
	
	m_textCtrlSaisiePort = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	bSizer41->Add( m_textCtrlSaisiePort, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer41, 1, wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizer5, 2, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonConnexion = new wxButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_buttonConnexion, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerConnexion->Add( bSizer9, 1, wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerConnexion, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSaisie;
	sbSizerSaisie = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Saisie") ), wxVERTICAL );
	
	m_textCtrlSaisie = new wxTextCtrl( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSaisie->Add( m_textCtrlSaisie, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_buttonEnvoyer = new wxButton( sbSizerSaisie->GetStaticBox(), wxID_ANY, wxT("Envoyer"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSaisie->Add( m_buttonEnvoyer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerPrincipal->Add( sbSizerSaisie, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlaffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlaffichage, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerAffichage, 2, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
}

FramePrincipal::~FramePrincipal()
{
}
