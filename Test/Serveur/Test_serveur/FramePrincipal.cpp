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
	
	m_toggleBtnConnexion = new wxToggleButton( this, wxID_ANY, wxT("\nDémarrer le serveur\n"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerHaut->Add( m_toggleBtnConnexion, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDisponibilite;
	bSizerDisponibilite = new wxBoxSizer( wxVERTICAL );
	
	m_toggleBtnDisponibilite = new wxToggleButton( this, wxID_ANY, wxT("Bras disponible"), wxDefaultPosition, wxDefaultSize, 0 );
	m_toggleBtnDisponibilite->Hide();
	
	bSizerDisponibilite->Add( m_toggleBtnDisponibilite, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTacheEnCours;
	bSizerTacheEnCours = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextTacheEnCours = new wxStaticText( this, wxID_ANY, wxT("Choix de la tâche en cours :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTacheEnCours->Wrap( -1 );
	m_staticTextTacheEnCours->Hide();
	
	bSizerTacheEnCours->Add( m_staticTextTacheEnCours, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	wxString m_choiceTacheEnCoursChoices[] = { wxT("Mouvement"), wxT("Processsus"), wxT("Trajectoire") };
	int m_choiceTacheEnCoursNChoices = sizeof( m_choiceTacheEnCoursChoices ) / sizeof( wxString );
	m_choiceTacheEnCours = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTacheEnCoursNChoices, m_choiceTacheEnCoursChoices, wxCB_SORT );
	m_choiceTacheEnCours->SetSelection( 0 );
	m_choiceTacheEnCours->Hide();
	
	bSizerTacheEnCours->Add( m_choiceTacheEnCours, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 5 );
	
	
	bSizerDisponibilite->Add( bSizerTacheEnCours, 1, wxEXPAND, 5 );
	
	
	bSizerHaut->Add( bSizerDisponibilite, 1, wxEXPAND, 5 );
	
	
	bSizerPrincipal->Add( bSizerHaut, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerPrincipal->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALIGN_CENTER|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_buttonViderAffichage = new wxButton( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxT("Vider l'affichage"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER );
	sbSizerAffichage->Add( m_buttonViderAffichage, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerPrincipal->Add( sbSizerAffichage, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizerPrincipal );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_statusBar->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuFichier = new wxMenu();
	wxMenuItem* m_menuItemQuitter;
	m_menuItemQuitter = new wxMenuItem( m_menuFichier, wxID_ANY, wxString( wxT("Quitter") ) + wxT('\t') + wxT("Alt+F4"), wxEmptyString, wxITEM_NORMAL );
	m_menuFichier->Append( m_menuItemQuitter );
	
	m_menubar->Append( m_menuFichier, wxT("Fichier") ); 
	
	m_menuEdition = new wxMenu();
	m_menuItemChangerDisponibiliteBras = new wxMenuItem( m_menuEdition, wxID_ANY, wxString( wxT("Changer la disponibilité du bras") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuEdition->Append( m_menuItemChangerDisponibiliteBras );
	
	m_menuEdition->AppendSeparator();
	
	m_menuTypeMouvement = new wxMenu();
	wxMenuItem* m_menuTypeMouvementItem = new wxMenuItem( m_menuEdition, wxID_ANY, wxT("Changer le type de tâche en cours"), wxEmptyString, wxITEM_NORMAL, m_menuTypeMouvement );
	m_menuItemMouvement = new wxMenuItem( m_menuTypeMouvement, wxID_ANY, wxString( wxT("Mouvement") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuTypeMouvement->Append( m_menuItemMouvement );
	
	m_menuItemProcessus = new wxMenuItem( m_menuTypeMouvement, wxID_ANY, wxString( wxT("Processus") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuTypeMouvement->Append( m_menuItemProcessus );
	
	m_menuItemTrajectoire = new wxMenuItem( m_menuTypeMouvement, wxID_ANY, wxString( wxT("Trajectoire") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuTypeMouvement->Append( m_menuItemTrajectoire );
	
	m_menuEdition->Append( m_menuTypeMouvementItem );
	
	m_menubar->Append( m_menuEdition, wxT("Édition") ); 
	
	m_menuVues = new wxMenu();
	wxMenuItem* m_menuItemViderAffichage;
	m_menuItemViderAffichage = new wxMenuItem( m_menuVues, wxID_ANY, wxString( wxT("Vider l'affichage") ) + wxT('\t') + wxT("F3"), wxEmptyString, wxITEM_NORMAL );
	m_menuVues->Append( m_menuItemViderAffichage );
	
	m_menubar->Append( m_menuVues, wxT("Vues") ); 
	
	this->SetMenuBar( m_menubar );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_toggleBtnDisponibilite->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnToggleButtonDisponibiliteClick ), NULL, this );
	m_choiceTacheEnCours->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( FramePrincipal::OnChoiceTache ), NULL, this );
	m_buttonViderAffichage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickViderAffichage ), NULL, this );
	m_statusBar->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_menubar->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	this->Connect( m_menuItemQuitter->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionQuitter ) );
	this->Connect( m_menuItemChangerDisponibiliteBras->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionChangerDisponibiliteBras ) );
	this->Connect( m_menuItemMouvement->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionMouvement ) );
	this->Connect( m_menuItemProcessus->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionProcessus ) );
	this->Connect( m_menuItemTrajectoire->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionTrajectoire ) );
	this->Connect( m_menuItemViderAffichage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionViderAffichage ) );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDemarrerServeurToggle ), NULL, this );
	m_toggleBtnDisponibilite->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnToggleButtonDisponibiliteClick ), NULL, this );
	m_choiceTacheEnCours->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( FramePrincipal::OnChoiceTache ), NULL, this );
	m_buttonViderAffichage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonClickViderAffichage ), NULL, this );
	m_statusBar->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_menubar->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionQuitter ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionChangerDisponibiliteBras ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionMouvement ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionProcessus ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionTrajectoire ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuSelectionViderAffichage ) );
	
}
