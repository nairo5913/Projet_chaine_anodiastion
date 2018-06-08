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
	
	m_menubar1 = new wxMenuBar( 0 );
	m_menuFichier = new wxMenu();
	wxMenuItem* m_menuItemQuitter;
	m_menuItemQuitter = new wxMenuItem( m_menuFichier, wxID_ANY, wxString( wxT("Quitter") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFichier->Append( m_menuItemQuitter );
	
	m_menubar1->Append( m_menuFichier, wxT("Fichier") ); 
	
	m_menuAide = new wxMenu();
	wxMenuItem* m_menuItemAPropos;
	m_menuItemAPropos = new wxMenuItem( m_menuAide, wxID_ANY, wxString( wxT("À propos") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuAide->Append( m_menuItemAPropos );
	
	m_menubar1->Append( m_menuAide, wxT("Aide") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer;
	sbSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Bouton d'appelle des autres frames") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonFenetre2 = new wxButton( sbSizer->GetStaticBox(), wxID_ANY, wxT("Fenêtre 2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_buttonFenetre2, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonDialogue = new wxButton( sbSizer->GetStaticBox(), wxID_ANY, wxT("Dialogue"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_buttonDialogue, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizer->Add( bSizer6, 1, wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizer, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	this->Connect( m_menuItemQuitter->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuItemQuitterClick ) );
	this->Connect( m_menuItemAPropos->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuItemAProposClick ) );
	m_buttonFenetre2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonFenetre2 ), NULL, this );
	m_buttonDialogue->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonDialogue ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuItemQuitterClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuItemAProposClick ) );
	m_buttonFenetre2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonFenetre2 ), NULL, this );
	m_buttonDialogue->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnClickButtonDialogue ), NULL, this );
	
}

Fenetre2::Fenetre2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizerFenetre2;
	bSizerFenetre2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonRetour = new wxButton( this, wxID_ANY, wxT("Retour FramePrincipal"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_buttonRetour, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	m_checkBox1 = new wxCheckBox( this, wxID_ANY, wxT("Check Me!"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox1, 0, wxALL, 5 );
	
	m_checkBox2 = new wxCheckBox( this, wxID_ANY, wxT("Check Me!"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox2->SetValue(true); 
	bSizer7->Add( m_checkBox2, 0, wxALL, 5 );
	
	
	bSizerFenetre2->Add( bSizer7, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerFenetre2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Fenetre2::OnFrameClose ) );
	m_buttonRetour->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Fenetre2::OnClickButtonRetour ), NULL, this );
}

Fenetre2::~Fenetre2()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Fenetre2::OnFrameClose ) );
	m_buttonRetour->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Fenetre2::OnClickButtonRetour ), NULL, this );
	
}

DialogTest::DialogTest( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,250 ), wxDefaultSize );
	
	wxBoxSizer* bSizerDialog;
	bSizerDialog = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Titre") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("BlaBla"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizer1->Add( bSizer5, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDialog->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer4->Add( m_sdbSizer1, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerDialog->Add( bSizer4, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerDialog );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogTest::OnFrameClose ) );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogTest::OnClickButtonCancel ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogTest::OnClickButtonOK ), NULL, this );
}

DialogTest::~DialogTest()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogTest::OnFrameClose ) );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogTest::OnClickButtonCancel ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogTest::OnClickButtonOK ), NULL, this );
	
}

MyDialogApropos::MyDialogApropos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizerDialogPrincipal;
	bSizerDialogPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerRegleur;
	sbSizerRegleur = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Régleur") ), wxVERTICAL );
	
	
	bSizerDialogPrincipal->Add( sbSizerRegleur, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 10 );
	
	wxStaticBoxSizer* sbSizerResponsableProduction;
	sbSizerResponsableProduction = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Responsable de production") ), wxVERTICAL );
	
	m_staticText3 = new wxStaticText( sbSizerResponsableProduction->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	sbSizerResponsableProduction->Add( m_staticText3, 0, wxALL, 5 );
	
	m_textCtrl1 = new wxTextCtrl( sbSizerResponsableProduction->GetStaticBox(), wxID_ANY, wxT("blabla\nbla\nblablabla"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizerResponsableProduction->Add( m_textCtrl1, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	bSizerDialogPrincipal->Add( sbSizerResponsableProduction, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 10 );
	
	wxBoxSizer* bSizerDialogButtonOK;
	bSizerDialogButtonOK = new wxBoxSizer( wxVERTICAL );
	
	m_sdbSizerDialogOk = new wxStdDialogButtonSizer();
	m_sdbSizerDialogOkOK = new wxButton( this, wxID_OK );
	m_sdbSizerDialogOk->AddButton( m_sdbSizerDialogOkOK );
	m_sdbSizerDialogOk->Realize();
	
	bSizerDialogButtonOK->Add( m_sdbSizerDialogOk, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerDialogPrincipal->Add( bSizerDialogButtonOK, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerDialogPrincipal );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialogApropos::OnFrameClose ) );
	m_sdbSizerDialogOkOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogApropos::OnClickButtonOK ), NULL, this );
}

MyDialogApropos::~MyDialogApropos()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialogApropos::OnFrameClose ) );
	m_sdbSizerDialogOkOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogApropos::OnClickButtonOK ), NULL, this );
	
}
