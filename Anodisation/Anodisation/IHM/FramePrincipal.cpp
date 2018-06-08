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
	this->SetSizeHints( wxSize( 1000,750 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerConnexion;
	bSizerConnexion = new wxBoxSizer( wxVERTICAL );
	
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Connexion") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizerParametreConnexion;
	bSizerParametreConnexion = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerLogin;
	bSizerLogin = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextLogin = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre login :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLogin->Wrap( -1 );
	bSizerLogin->Add( m_staticTextLogin, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_textCtrlLogin = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Responsable"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	#ifdef __WXGTK__
	if ( !m_textCtrlLogin->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlLogin->SetMaxLength( 30 );
	}
	#else
	m_textCtrlLogin->SetMaxLength( 30 );
	#endif
	bSizerLogin->Add( m_textCtrlLogin, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerParametreConnexion->Add( bSizerLogin, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerPass;
	bSizerPass = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPass = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre mot de passe :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPass->Wrap( -1 );
	bSizerPass->Add( m_staticTextPass, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_textCtrlPass = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("responsable"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PASSWORD|wxTE_PROCESS_ENTER );
	#ifdef __WXGTK__
	if ( !m_textCtrlPass->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlPass->SetMaxLength( 32 );
	}
	#else
	m_textCtrlPass->SetMaxLength( 32 );
	#endif
	bSizerPass->Add( m_textCtrlPass, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerParametreConnexion->Add( bSizerPass, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBoutonConnexion;
	bSizerBoutonConnexion = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerBoutonConnexion->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBoutonConnexion->Add( m_toggleBtnConnexion, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerParametreConnexion->Add( bSizerBoutonConnexion, 1, wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizerParametreConnexion, 2, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerLogoOzanam;
	bSizerLogoOzanam = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerLogoOzanam->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bitmapLogoOzanam = new wxStaticBitmap( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxBitmap( wxT("../Images/logo_campus.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerLogoOzanam->Add( m_bitmapLogoOzanam, 0, wxALIGN_CENTER|wxRIGHT, 15 );
	
	
	sbSizerConnexion->Add( bSizerLogoOzanam, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerConnexion->Add( sbSizerConnexion, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerPrincipal->Add( bSizerConnexion, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizerPanelNoteBook;
	bSizerPanelNoteBook = new wxBoxSizer( wxHORIZONTAL );
	
	m_evt_panel_responsable=new EvtPanelResponsable(this);
	bSizerPanelNoteBook->Add( m_evt_panel_responsable, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_evt_panel_regleur=new EvtPanelRegleur(this);
	bSizerPanelNoteBook->Add( m_evt_panel_regleur, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerPrincipal->Add( bSizerPanelNoteBook, 1, wxEXPAND, 5 );
	
	m_panelAffichage = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerAffichage;
	bSizerAffichage = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( m_panelAffichage, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxT("\n\n\t\tConnectez-vous pour pouvoir effectuer des actions.\n"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_RICH2 );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALIGN_CENTER|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_buttonViderAffichage = new wxButton( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxT("ViderAffichage"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER );
	sbSizerAffichage->Add( m_buttonViderAffichage, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerAffichage->Add( sbSizerAffichage, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panelAffichage->SetSizer( bSizerAffichage );
	m_panelAffichage->Layout();
	bSizerAffichage->Fit( m_panelAffichage );
	bSizerPrincipal->Add( m_panelAffichage, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_menubarFramePrincipal = new wxMenuBar( 0 );
	m_menuFichier = new wxMenu();
	wxMenuItem* m_menuItemQuitter;
	m_menuItemQuitter = new wxMenuItem( m_menuFichier, wxID_ANY, wxString( wxT("Quitter") ) + wxT('\t') + wxT("Alt+F4"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemQuitter->SetBitmaps( wxNullBitmap, wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItemQuitter->SetBitmap( wxNullBitmap );
	#endif
	m_menuFichier->Append( m_menuItemQuitter );
	
	m_menubarFramePrincipal->Append( m_menuFichier, wxT("Fichier") ); 
	
	m_menuVues = new wxMenu();
	wxMenuItem* m_menuItemViderAffichage;
	m_menuItemViderAffichage = new wxMenuItem( m_menuVues, wxID_ANY, wxString( wxT("Vider l'affichage") ) + wxT('\t') + wxT("F3"), wxEmptyString, wxITEM_NORMAL );
	m_menuVues->Append( m_menuItemViderAffichage );
	
	m_menubarFramePrincipal->Append( m_menuVues, wxT("Vues") ); 
	
	m_menuAide = new wxMenu();
	wxMenuItem* m_menuItemAide;
	m_menuItemAide = new wxMenuItem( m_menuAide, wxID_ANY, wxString( wxT("Aide") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemAide->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItemAide->SetBitmap( wxNullBitmap );
	#endif
	m_menuAide->Append( m_menuItemAide );
	
	m_menuAide->AppendSeparator();
	
	wxMenuItem* m_menuItemApropos;
	m_menuItemApropos = new wxMenuItem( m_menuAide, wxID_ANY, wxString( wxT("À propos ...") ) + wxT('\t') + wxT("F2"), wxEmptyString, wxITEM_NORMAL );
	m_menuAide->Append( m_menuItemApropos );
	
	m_menubarFramePrincipal->Append( m_menuAide, wxT("Aide") ); 
	
	this->SetMenuBar( m_menubarFramePrincipal );
	
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_staticTextLogin->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlLogin->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlLogin->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextPass->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlPass->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlPass->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_panelAffichage->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlAffichage->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_buttonViderAffichage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonViderAffichageClick ), NULL, this );
	m_buttonViderAffichage->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_menubarFramePrincipal->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	this->Connect( m_menuItemQuitter->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuQuitterSelection ) );
	this->Connect( m_menuItemViderAffichage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuViderAffichageSelection ) );
	this->Connect( m_menuItemAide->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAideSelection ) );
	this->Connect( m_menuItemApropos->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAproposSelection ) );
	m_statusBar->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_staticTextLogin->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlLogin->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlLogin->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextPass->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_panelAffichage->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlAffichage->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_buttonViderAffichage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonViderAffichageClick ), NULL, this );
	m_buttonViderAffichage->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_menubarFramePrincipal->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuQuitterSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuViderAffichageSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAideSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAproposSelection ) );
	m_statusBar->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	
}

FrameApropos::FrameApropos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,600 ), wxDefaultSize );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	m_panelApropos = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerApropos;
	bSizerApropos = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextTitre = new wxStaticText( m_panelApropos, wxID_ANY, wxT("À propos du projet"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextTitre->Wrap( -1 );
	m_staticTextTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerApropos->Add( m_staticTextTitre, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20 );
	
	wxStaticBoxSizer* sbSizerResponsable;
	sbSizerResponsable = new wxStaticBoxSizer( new wxStaticBox( m_panelApropos, wxID_ANY, wxT("Responsable de production") ), wxVERTICAL );
	
	
	bSizerApropos->Add( sbSizerResponsable, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerRegleur;
	sbSizerRegleur = new wxStaticBoxSizer( new wxStaticBox( m_panelApropos, wxID_ANY, wxT("Régleur") ), wxVERTICAL );
	
	
	bSizerApropos->Add( sbSizerRegleur, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerAuteur;
	sbSizerAuteur = new wxStaticBoxSizer( new wxStaticBox( m_panelApropos, wxID_ANY, wxT("Auteur") ), wxVERTICAL );
	
	m_bitmapLogoOzanam = new wxStaticBitmap( sbSizerAuteur->GetStaticBox(), wxID_ANY, wxBitmap( wxT("../Images/logo_ozanam.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerAuteur->Add( m_bitmapLogoOzanam, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText40 = new wxStaticText( sbSizerAuteur->GetStaticBox(), wxID_ANY, wxT("Le Programme à été conçu et coder dans le cadre du projet bras d'annodisation du BTS SNIR (Système Numérique option Informatique et Réseaux).\nLa partie responsable de production, ainsi que la base de données ont été faites par Florian Provost.\nLa partie régleur par Nassim Boubziz.\nLa Raspberry Pi a été fait par Paul Despalier\n\n"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_staticText40->Wrap( -1 );
	sbSizerAuteur->Add( m_staticText40, 0, wxALL, 5 );
	
	
	bSizerApropos->Add( sbSizerAuteur, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelApropos->SetSizer( bSizerApropos );
	m_panelApropos->Layout();
	bSizerApropos->Fit( m_panelApropos );
	bSizerPrincipal->Add( m_panelApropos, 1, wxEXPAND, 5 );
	
	m_sdbSizerApropos = new wxStdDialogButtonSizer();
	m_sdbSizerAproposOK = new wxButton( this, wxID_OK );
	m_sdbSizerApropos->AddButton( m_sdbSizerAproposOK );
	m_sdbSizerApropos->Realize();
	
	bSizerPrincipal->Add( m_sdbSizerApropos, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FrameApropos::OnCloseFrame ) );
	m_sdbSizerAproposOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameApropos::OnOkButtonClick ), NULL, this );
}

FrameApropos::~FrameApropos()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FrameApropos::OnCloseFrame ) );
	m_sdbSizerAproposOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameApropos::OnOkButtonClick ), NULL, this );
	
}

FrameAide::FrameAide( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 700,500 ), wxDefaultSize );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	m_panelAide = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerAide;
	bSizerAide = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextTitre = new wxStaticText( m_panelAide, wxID_ANY, wxT("Aide"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextTitre->Wrap( -1 );
	m_staticTextTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerAide->Add( m_staticTextTitre, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20 );
	
	wxStaticBoxSizer* sbSizerResponsable;
	sbSizerResponsable = new wxStaticBoxSizer( new wxStaticBox( m_panelAide, wxID_ANY, wxT("Responsable de production") ), wxVERTICAL );
	
	
	bSizerAide->Add( sbSizerResponsable, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerRegleur;
	sbSizerRegleur = new wxStaticBoxSizer( new wxStaticBox( m_panelAide, wxID_ANY, wxT("Régleur") ), wxVERTICAL );
	
	
	bSizerAide->Add( sbSizerRegleur, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer32;
	sbSizer32 = new wxStaticBoxSizer( new wxStaticBox( m_panelAide, wxID_ANY, wxT("label") ), wxVERTICAL );
	
	
	bSizerAide->Add( sbSizer32, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelAide->SetSizer( bSizerAide );
	m_panelAide->Layout();
	bSizerAide->Fit( m_panelAide );
	bSizerPrincipal->Add( m_panelAide, 1, wxEXPAND, 5 );
	
	m_sdbSizerApropos = new wxStdDialogButtonSizer();
	m_sdbSizerAproposOK = new wxButton( this, wxID_OK );
	m_sdbSizerApropos->AddButton( m_sdbSizerAproposOK );
	m_sdbSizerApropos->Realize();
	
	bSizerPrincipal->Add( m_sdbSizerApropos, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FrameAide::OnCloseFrame ) );
	m_sdbSizerAproposOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameAide::OnOkButtonClick ), NULL, this );
}

FrameAide::~FrameAide()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FrameAide::OnCloseFrame ) );
	m_sdbSizerAproposOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameAide::OnOkButtonClick ), NULL, this );
	
}
