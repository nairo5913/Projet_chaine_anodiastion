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
	this->SetSizeHints( wxSize( 666,615 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	m_panelConnexion = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerConnexion;
	bSizerConnexion = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( m_panelConnexion, wxID_ANY, wxT("Connexion") ), wxHORIZONTAL );
	
	m_staticTextDSN = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("DSN : "), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextDSN->Wrap( -1 );
	sbSizerConnexion->Add( m_staticTextDSN, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDSN = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Anodisation"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	sbSizerConnexion->Add( m_textCtrlDSN, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnexion->Add( m_toggleBtnConnexion, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerConnexion->Add( sbSizerConnexion, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelConnexion->SetSizer( bSizerConnexion );
	m_panelConnexion->Layout();
	bSizerConnexion->Fit( m_panelConnexion );
	bSizerPrincipal->Add( m_panelConnexion, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_scrolledWindowRequete = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowRequete->SetScrollRate( 5, 5 );
	m_scrolledWindowRequete->Hide();
	
	wxBoxSizer* bSizerRequete;
	bSizerRequete = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextRequete = new wxStaticText( m_scrolledWindowRequete, wxID_ANY, wxT("Pannel pour efféctuer les différentes requête sur la base de données."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextRequete->Wrap( -1 );
	bSizerRequete->Add( m_staticTextRequete, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerRequete;
	sbSizerRequete = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowRequete, wxID_ANY, wxT("Requête") ), wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerSelection;
	sbSizerSelection = new wxStaticBoxSizer( new wxStaticBox( sbSizerRequete->GetStaticBox(), wxID_ANY, wxT("Sélection") ), wxHORIZONTAL );
	
	m_textCtrlSelection = new wxTextCtrl( sbSizerSelection->GetStaticBox(), wxID_ANY, wxT("SELECT * FROM processus"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	sbSizerSelection->Add( m_textCtrlSelection, 1, wxALIGN_CENTER|wxALL, 5 );
	
	m_buttonSelection = new wxButton( sbSizerSelection->GetStaticBox(), wxID_ANY, wxT("Éxécution de la sélection"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSelection->Add( m_buttonSelection, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerRequete->Add( sbSizerSelection, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerInsertion;
	sbSizerInsertion = new wxStaticBoxSizer( new wxStaticBox( sbSizerRequete->GetStaticBox(), wxID_ANY, wxT("Insertion") ), wxHORIZONTAL );
	
	m_textCtrlInsertion = new wxTextCtrl( sbSizerInsertion->GetStaticBox(), wxID_ANY, wxT("INSERT INTO processus(val1, val2) VALUES (val1, val2)"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	sbSizerInsertion->Add( m_textCtrlInsertion, 1, wxALIGN_CENTER|wxALL, 5 );
	
	m_buttonInsertion = new wxButton( sbSizerInsertion->GetStaticBox(), wxID_ANY, wxT("Éxécution de l'insertion"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerInsertion->Add( m_buttonInsertion, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerRequete->Add( sbSizerInsertion, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerMAJ;
	sbSizerMAJ = new wxStaticBoxSizer( new wxStaticBox( sbSizerRequete->GetStaticBox(), wxID_ANY, wxT("Mise à jour de données") ), wxHORIZONTAL );
	
	m_textCtrlMAJ = new wxTextCtrl( sbSizerMAJ->GetStaticBox(), wxID_ANY, wxT("UPDATE processus SET col1 = val1, col2 = val2 WHERE id = 1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	sbSizerMAJ->Add( m_textCtrlMAJ, 1, wxALIGN_CENTER|wxALL, 5 );
	
	m_buttonMAJ = new wxButton( sbSizerMAJ->GetStaticBox(), wxID_ANY, wxT("Éxécution de la mise à jour"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerMAJ->Add( m_buttonMAJ, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerRequete->Add( sbSizerMAJ, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSuppression;
	sbSizerSuppression = new wxStaticBoxSizer( new wxStaticBox( sbSizerRequete->GetStaticBox(), wxID_ANY, wxT("Suppression") ), wxVERTICAL );
	
	m_staticTextSuppression = new wxStaticText( sbSizerSuppression->GetStaticBox(), wxID_ANY, wxT("Temporairement désactiver le temps de mettre en marche le reste.\n\nRéactiver \"m_textCtrlSuppression\" et \"m_buttonSuppression\""), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextSuppression->Wrap( -1 );
	sbSizerSuppression->Add( m_staticTextSuppression, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrlSuppression = new wxTextCtrl( sbSizerSuppression->GetStaticBox(), wxID_ANY, wxT("DELETE FROM processus WHERE id = 1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_textCtrlSuppression->Enable( false );
	
	bSizer7->Add( m_textCtrlSuppression, 1, wxALIGN_CENTER|wxALL, 5 );
	
	m_buttonSuppression = new wxButton( sbSizerSuppression->GetStaticBox(), wxID_ANY, wxT("Éxécution de la suppression"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonSuppression->Enable( false );
	
	bSizer7->Add( m_buttonSuppression, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	sbSizerSuppression->Add( bSizer7, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	sbSizerRequete->Add( sbSizerSuppression, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerRequete->Add( sbSizerRequete, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowRequete->SetSizer( bSizerRequete );
	m_scrolledWindowRequete->Layout();
	bSizerRequete->Fit( m_scrolledWindowRequete );
	bSizerPrincipal->Add( m_scrolledWindowRequete, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( sbSizerAffichage, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_menuQuitter = new wxMenu();
	wxMenuItem* m_menuItemQuitter;
	m_menuItemQuitter = new wxMenuItem( m_menuQuitter, wxID_ANY, wxString( wxT("Quitter") ) + wxT('\t') + wxT("Alt+F4"), wxEmptyString, wxITEM_NORMAL );
	m_menuQuitter->Append( m_menuItemQuitter );
	
	m_menubar1->Append( m_menuQuitter, wxT("Fichier") ); 
	
	m_menuAide = new wxMenu();
	wxMenuItem* m_menuItemAide;
	m_menuItemAide = new wxMenuItem( m_menuAide, wxID_ANY, wxString( wxT("Aide") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	m_menuAide->Append( m_menuItemAide );
	
	m_menubar1->Append( m_menuAide, wxT("Aide") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlDSN->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnToggleButtonConnexion ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnToggleButtonConnexion ), NULL, this );
	m_textCtrlSelection->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickSelection ), NULL, this );
	m_buttonSelection->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickSelection ), NULL, this );
	m_textCtrlInsertion->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickInsertion ), NULL, this );
	m_buttonInsertion->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickInsertion ), NULL, this );
	m_textCtrlMAJ->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickMAJ ), NULL, this );
	m_buttonMAJ->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickMAJ ), NULL, this );
	m_textCtrlSuppression->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickSuppression ), NULL, this );
	m_buttonSuppression->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickSuppression ), NULL, this );
	this->Connect( m_menuItemQuitter->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuQuitterSelection ) );
	this->Connect( m_menuItemAide->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAideSelection ) );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlDSN->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnToggleButtonConnexion ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnToggleButtonConnexion ), NULL, this );
	m_textCtrlSelection->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickSelection ), NULL, this );
	m_buttonSelection->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickSelection ), NULL, this );
	m_textCtrlInsertion->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickInsertion ), NULL, this );
	m_buttonInsertion->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickInsertion ), NULL, this );
	m_textCtrlMAJ->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickMAJ ), NULL, this );
	m_buttonMAJ->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickMAJ ), NULL, this );
	m_textCtrlSuppression->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonClickSuppression ), NULL, this );
	m_buttonSuppression->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickSuppression ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuQuitterSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAideSelection ) );
	
}

MyDialogAide::MyDialogAide( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerDialogAide;
	bSizerDialogAide = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerAffichageAide;
	bSizerAffichageAide = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrlAffichageAide = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_RICH2 );
	bSizerAffichageAide->Add( m_textCtrlAffichageAide, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerDialogAide->Add( bSizerAffichageAide, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBouttonAide;
	bSizerBouttonAide = new wxBoxSizer( wxVERTICAL );
	
	m_sdbSizerBoutonOKAide = new wxStdDialogButtonSizer();
	m_sdbSizerBoutonOKAideOK = new wxButton( this, wxID_OK );
	m_sdbSizerBoutonOKAide->AddButton( m_sdbSizerBoutonOKAideOK );
	m_sdbSizerBoutonOKAide->Realize();
	
	bSizerBouttonAide->Add( m_sdbSizerBoutonOKAide, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDialogAide->Add( bSizerBouttonAide, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerDialogAide );
	this->Layout();
	bSizerDialogAide->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialogAide::OnDialogClose ) );
	m_sdbSizerBoutonOKAideOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogAide::OnOKButtonClick ), NULL, this );
}

MyDialogAide::~MyDialogAide()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialogAide::OnDialogClose ) );
	m_sdbSizerBoutonOKAideOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogAide::OnOKButtonClick ), NULL, this );
	
}
