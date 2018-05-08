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
	this->SetSizeHints( wxSize( 900,750 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	m_panelConnexion = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerConnexion;
	bSizerConnexion = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( m_panelConnexion, wxID_ANY, wxT("Connexion") ), wxVERTICAL );
	
	wxBoxSizer* bSizerLogin;
	bSizerLogin = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextLogin = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre login : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLogin->Wrap( -1 );
	bSizerLogin->Add( m_staticTextLogin, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlLogin = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Responsable"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	bSizerLogin->Add( m_textCtrlLogin, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerLogin->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizerLogin, 1, wxALIGN_TOP|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizerPass;
	bSizerPass = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPass = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre mot de passe : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPass->Wrap( -1 );
	bSizerPass->Add( m_staticTextPass, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlPass = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("responsable"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PASSWORD|wxTE_PROCESS_ENTER );
	bSizerPass->Add( m_textCtrlPass, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerPass->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizerPass, 1, wxALIGN_BOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnexion->Add( m_toggleBtnConnexion, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerConnexion->Add( sbSizerConnexion, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panelConnexion->SetSizer( bSizerConnexion );
	m_panelConnexion->Layout();
	bSizerConnexion->Fit( m_panelConnexion );
	bSizerPrincipal->Add( m_panelConnexion, 0, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_notebookProcessus = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_notebookProcessus->Hide();
	
	m_scrolledWindowAffichageProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowAffichageProcessus->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerAfficherProcessus;
	bSizerAfficherProcessus = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionProcessusAfficher;
	sbSizerSelectionProcessusAfficher = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageProcessus, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionProcessusAfficher->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxAffichageProcessus = new wxListBox( sbSizerSelectionProcessusAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxAffichageProcessus->Append( wxT("01 - Processus 1") );
	m_listBoxAffichageProcessus->Append( wxT("02 - Processus 2") );
	m_listBoxAffichageProcessus->Append( wxT("03 - Processus 3") );
	sbSizerSelectionProcessusAfficher->Add( m_listBoxAffichageProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerAfficherProcessus->Add( sbSizerSelectionProcessusAfficher, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerAfficher;
	sbSizerAfficher = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageProcessus, wxID_ANY, wxT("Affichage") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizerAfficherGauche;
	bSizerAfficherGauche = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerIdAfficher;
	bSizerIdAfficher = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerIdAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextIdAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("ID du processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextIdAfficher->Wrap( -1 );
	bSizerIdAfficher->Add( m_staticTextIdAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlIdAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlIdAfficher->Enable( false );
	m_textCtrlIdAfficher->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerIdAfficher->Add( m_textCtrlIdAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerIdAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherGauche->Add( bSizerIdAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDureeTotalAfficher;
	bSizerDureeTotalAfficher = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticDureeTotalAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Durée total :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDureeTotalAfficher->Wrap( -1 );
	bSizerDureeTotalAfficher->Add( m_staticDureeTotalAfficher, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeTotalHeureAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("02"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalHeureAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalHeureAfficher->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalHeureAfficher->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalHeureAfficher->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalAfficher->Add( m_textCtrlDureeTotalHeureAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalAfficher1 = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalAfficher1->Wrap( -1 );
	bSizerDureeTotalAfficher->Add( m_staticTextDureeTotalAfficher1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textCtrlDureeTotalMinuteAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("52"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !textCtrlDureeTotalMinuteAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	textCtrlDureeTotalMinuteAfficher->SetMaxLength( 2 );
	}
	#else
	textCtrlDureeTotalMinuteAfficher->SetMaxLength( 2 );
	#endif
	textCtrlDureeTotalMinuteAfficher->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalAfficher->Add( textCtrlDureeTotalMinuteAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalAfficher->Wrap( -1 );
	bSizerDureeTotalAfficher->Add( m_staticTextDureeTotalAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textCtrlDureeTotalSecondeAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !textCtrlDureeTotalSecondeAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	textCtrlDureeTotalSecondeAfficher->SetMaxLength( 2 );
	}
	#else
	textCtrlDureeTotalSecondeAfficher->SetMaxLength( 2 );
	#endif
	textCtrlDureeTotalSecondeAfficher->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalAfficher->Add( textCtrlDureeTotalSecondeAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherGauche->Add( bSizerDureeTotalAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerListeTrajectoiresAfficher;
	sbSizerListeTrajectoiresAfficher = new wxStaticBoxSizer( new wxStaticBox( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Liste des trajectoires") ), wxVERTICAL );
	
	m_listBoxListeTrajectoiresAfficher = new wxListBox( sbSizerListeTrajectoiresAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_listBoxListeTrajectoiresAfficher->Append( wxT("01 - Trajectoire 1 - Durée : 00:02:30 - Bain n°3 -> n°2") );
	m_listBoxListeTrajectoiresAfficher->Append( wxT("02 - Trajectoire 2") );
	m_listBoxListeTrajectoiresAfficher->Append( wxT("03 - Trajectoire 3") );
	m_listBoxListeTrajectoiresAfficher->Append( wxT("04 - Trajectoire 4") );
	sbSizerListeTrajectoiresAfficher->Add( m_listBoxListeTrajectoiresAfficher, 2, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerAfficherGauche->Add( sbSizerListeTrajectoiresAfficher, 2, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	sbSizerAfficher->Add( bSizerAfficherGauche, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineAfficher = new wxStaticLine( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizerAfficher->Add( m_staticlineAfficher, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerAfficherDroite;
	bSizerAfficherDroite = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomAffichage;
	bSizerNomAffichage = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomAffichage->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Nom du processus :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomAfficher->Wrap( -1 );
	bSizerNomAffichage->Add( m_staticTextNomAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	bSizerNomAffichage->Add( m_textCtrlNomAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomAffichage->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroite->Add( bSizerNomAffichage, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNombreBainAfficher;
	bSizerNombreBainAfficher = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainAfficher->Wrap( -1 );
	bSizerNombreBainAfficher->Add( m_staticTextNombreBainAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNombreBainAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("03"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlNombreBainAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlNombreBainAfficher->SetMaxLength( 2 );
	}
	#else
	m_textCtrlNombreBainAfficher->SetMaxLength( 2 );
	#endif
	m_textCtrlNombreBainAfficher->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNombreBainAfficher->Add( m_textCtrlNombreBainAfficher, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroite->Add( bSizerNombreBainAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerOrdresTrajectoiresAfficher;
	bSizerOrdresTrajectoiresAfficher = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdresTrajectoiresAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires :\nséparé par ;"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextOrdreTrajectoiresAfficher->Wrap( -1 );
	bSizerOrdresTrajectoiresAfficher->Add( m_staticTextOrdreTrajectoiresAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlOrdreTrajectoiresAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("3;2;1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	bSizerOrdresTrajectoiresAfficher->Add( m_textCtrlOrdreTrajectoiresAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdresTrajectoiresAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroite->Add( bSizerOrdresTrajectoiresAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	sbSizerAfficher->Add( bSizerAfficherDroite, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherProcessus->Add( sbSizerAfficher, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowAffichageProcessus->SetSizer( bSizerAfficherProcessus );
	m_scrolledWindowAffichageProcessus->Layout();
	bSizerAfficherProcessus->Fit( m_scrolledWindowAffichageProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowAffichageProcessus, wxT("Affichager les processus"), true );
	m_scrolledWindowModifierProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowModifierProcessus->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerModifierProcessus;
	bSizerModifierProcessus = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionProcessusModifier;
	sbSizerSelectionProcessusModifier = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierProcessus, wxID_ANY, wxT("Séléction du processus à modifier") ), wxHORIZONTAL );
	
	sbSizerSelectionProcessusModifier->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxModifierProcessus = new wxListBox( sbSizerSelectionProcessusModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxModifierProcessus->Append( wxT("01 - Processus 1") );
	m_listBoxModifierProcessus->Append( wxT("02 - Processus 2") );
	m_listBoxModifierProcessus->Append( wxT("03 - Processus 3") );
	sbSizerSelectionProcessusModifier->Add( m_listBoxModifierProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerModifierProcessus->Add( sbSizerSelectionProcessusModifier, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerModification;
	sbSizerModification = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierProcessus, wxID_ANY, wxT("Modification") ), wxVERTICAL );
	
	wxBoxSizer* bSizerModificationPrincipal;
	bSizerModificationPrincipal = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerModificationGauche;
	bSizerModificationGauche = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerIdModification;
	bSizerIdModification = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerIdModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextIdModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("ID du processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextIdModifier->Wrap( -1 );
	bSizerIdModification->Add( m_staticTextIdModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlIdModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlIdModifier->Enable( false );
	m_textCtrlIdModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerIdModification->Add( m_textCtrlIdModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerIdModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationGauche->Add( bSizerIdModification, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDureeTotalModifier;
	bSizerDureeTotalModifier = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticDureeTotalModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Durée total :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDureeTotalModifier->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticDureeTotalModifier, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeTotalHeureModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("02"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalHeureModifier->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalHeureModifier->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalHeureModifier->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalHeureModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalModifier->Add( m_textCtrlDureeTotalHeureModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalModifier1 = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalModifier1->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticTextDureeTotalModifier1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textCtrlDureeTotalMinuteModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("52"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !textCtrlDureeTotalMinuteModifier->HasFlag( wxTE_MULTILINE ) )
	{
	textCtrlDureeTotalMinuteModifier->SetMaxLength( 2 );
	}
	#else
	textCtrlDureeTotalMinuteModifier->SetMaxLength( 2 );
	#endif
	textCtrlDureeTotalMinuteModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalModifier->Add( textCtrlDureeTotalMinuteModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalModifier->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticTextDureeTotalModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textCtrlDureeTotalSecondeModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !textCtrlDureeTotalSecondeModifier->HasFlag( wxTE_MULTILINE ) )
	{
	textCtrlDureeTotalSecondeModifier->SetMaxLength( 2 );
	}
	#else
	textCtrlDureeTotalSecondeModifier->SetMaxLength( 2 );
	#endif
	textCtrlDureeTotalSecondeModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalModifier->Add( textCtrlDureeTotalSecondeModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationGauche->Add( bSizerDureeTotalModifier, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerListeTrajectoiresModifier;
	sbSizerListeTrajectoiresModifier = new wxStaticBoxSizer( new wxStaticBox( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Liste des trajectoires") ), wxVERTICAL );
	
	m_listBoxListeTrajectoiresModifier = new wxListBox( sbSizerListeTrajectoiresModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_listBoxListeTrajectoiresModifier->Append( wxT("01 - Trajectoire 1 - Durée : 00:02:30 - Bain n°3 -> n°2") );
	m_listBoxListeTrajectoiresModifier->Append( wxT("02 - Trajectoire 2") );
	m_listBoxListeTrajectoiresModifier->Append( wxT("03 - Trajectoire 3") );
	m_listBoxListeTrajectoiresModifier->Append( wxT("04 - Trajectoire 4") );
	m_listBoxListeTrajectoiresModifier->Append( wxEmptyString );
	sbSizerListeTrajectoiresModifier->Add( m_listBoxListeTrajectoiresModifier, 2, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerModificationGauche->Add( sbSizerListeTrajectoiresModifier, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizerModificationPrincipal->Add( bSizerModificationGauche, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineModification = new wxStaticLine( sbSizerModification->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerModificationPrincipal->Add( m_staticlineModification, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerModificationDroite;
	bSizerModificationDroite = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomModification;
	bSizerNomModification = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Nom du processus :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomModifier->Wrap( -1 );
	bSizerNomModification->Add( m_staticTextNomModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	bSizerNomModification->Add( m_textCtrlNomModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( bSizerNomModification, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNombreBainModifier;
	bSizerNombreBainModifier = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainModifier->Wrap( -1 );
	bSizerNombreBainModifier->Add( m_staticTextNombreBainModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNombreBainModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("03"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlNombreBainModifier->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlNombreBainModifier->SetMaxLength( 2 );
	}
	#else
	m_textCtrlNombreBainModifier->SetMaxLength( 2 );
	#endif
	m_textCtrlNombreBainModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNombreBainModifier->Add( m_textCtrlNombreBainModifier, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( bSizerNombreBainModifier, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires :\nséparé par ;"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText17->Wrap( -1 );
	bSizer22->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl14 = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("3;2;1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	bSizer22->Add( m_textCtrl14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( bSizer22, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	bSizerModificationPrincipal->Add( bSizerModificationDroite, 1, wxEXPAND, 5 );
	
	
	sbSizerModification->Add( bSizerModificationPrincipal, 1, wxEXPAND, 5 );
	
	m_buttonModification = new wxButton( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Valider les modification"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerModification->Add( m_buttonModification, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_sdbSizerModifier = new wxStdDialogButtonSizer();
	m_sdbSizerModifierApply = new wxButton( sbSizerModification->GetStaticBox(), wxID_APPLY );
	m_sdbSizerModifier->AddButton( m_sdbSizerModifierApply );
	m_sdbSizerModifierCancel = new wxButton( sbSizerModification->GetStaticBox(), wxID_CANCEL );
	m_sdbSizerModifier->AddButton( m_sdbSizerModifierCancel );
	m_sdbSizerModifier->Realize();
	
	sbSizerModification->Add( m_sdbSizerModifier, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerModifierProcessus->Add( sbSizerModification, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowModifierProcessus->SetSizer( bSizerModifierProcessus );
	m_scrolledWindowModifierProcessus->Layout();
	bSizerModifierProcessus->Fit( m_scrolledWindowModifierProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowModifierProcessus, wxT("Modifier un processus"), false );
	m_scrolledWindowCreerProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowCreerProcessus->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerCreerProcessus;
	bSizerCreerProcessus = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerCreer;
	sbSizerCreer = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowCreerProcessus, wxID_ANY, wxT("Création d'un processus") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizerCreerGauche;
	bSizerCreerGauche = new wxBoxSizer( wxVERTICAL );
	
	m_staticText18 = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizerCreerGauche->Add( m_staticText18, 0, wxALL, 5 );
	
	
	sbSizerCreer->Add( bSizerCreerGauche, 1, wxEXPAND, 5 );
	
	m_staticlineCreer = new wxStaticLine( sbSizerCreer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizerCreer->Add( m_staticlineCreer, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerCreerDroite;
	bSizerCreerDroite = new wxBoxSizer( wxVERTICAL );
	
	m_staticText19 = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizerCreerDroite->Add( m_staticText19, 0, wxALL, 5 );
	
	
	sbSizerCreer->Add( bSizerCreerDroite, 1, wxEXPAND, 5 );
	
	
	bSizerCreerProcessus->Add( sbSizerCreer, 1, wxEXPAND, 5 );
	
	m_sdbSizerCreer = new wxStdDialogButtonSizer();
	m_sdbSizerCreerSave = new wxButton( m_scrolledWindowCreerProcessus, wxID_SAVE );
	m_sdbSizerCreer->AddButton( m_sdbSizerCreerSave );
	m_sdbSizerCreerCancel = new wxButton( m_scrolledWindowCreerProcessus, wxID_CANCEL );
	m_sdbSizerCreer->AddButton( m_sdbSizerCreerCancel );
	m_sdbSizerCreer->Realize();
	
	bSizerCreerProcessus->Add( m_sdbSizerCreer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	m_scrolledWindowCreerProcessus->SetSizer( bSizerCreerProcessus );
	m_scrolledWindowCreerProcessus->Layout();
	bSizerCreerProcessus->Fit( m_scrolledWindowCreerProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowCreerProcessus, wxT("Créer un processus"), false );
	m_scrolledWindowDetruireProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowDetruireProcessus->SetScrollRate( 5, 5 );
	m_scrolledWindowDetruireProcessus->SetMinSize( wxSize( 280,-1 ) );
	
	wxBoxSizer* bSizerDetruireProcessus;
	bSizerDetruireProcessus = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionProcessusDetruire;
	sbSizerSelectionProcessusDetruire = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireProcessus, wxID_ANY, wxT("Séléction du processus à détruire") ), wxHORIZONTAL );
	
	m_listBoxDetruireProcessus = new wxListBox( sbSizerSelectionProcessusDetruire->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE );
	m_listBoxDetruireProcessus->Append( wxT("Processus 1") );
	m_listBoxDetruireProcessus->Append( wxT("Processus 2") );
	m_listBoxDetruireProcessus->Append( wxT("Processus 3 Durrée : 2:05:30") );
	sbSizerSelectionProcessusDetruire->Add( m_listBoxDetruireProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerDetruireProcessus->Add( sbSizerSelectionProcessusDetruire, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerDetruire;
	sbSizerDetruire = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireProcessus, wxID_ANY, wxT("Détruire") ), wxVERTICAL );
	
	m_staticTextDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Vous allez détruire le processus 1"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextDetruire->Wrap( -1 );
	sbSizerDetruire->Add( m_staticTextDetruire, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	sbSizerDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_sdbSizerDetruire = new wxStdDialogButtonSizer();
	m_sdbSizerDetruireApply = new wxButton( sbSizerDetruire->GetStaticBox(), wxID_APPLY );
	m_sdbSizerDetruire->AddButton( m_sdbSizerDetruireApply );
	m_sdbSizerDetruire->Realize();
	
	sbSizerDetruire->Add( m_sdbSizerDetruire, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerDetruireProcessus->Add( sbSizerDetruire, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowDetruireProcessus->SetSizer( bSizerDetruireProcessus );
	m_scrolledWindowDetruireProcessus->Layout();
	bSizerDetruireProcessus->Fit( m_scrolledWindowDetruireProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowDetruireProcessus, wxT("Détruire un processus"), false );
	m_scrolledWindowLancerProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowLancerProcessus->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerLancerProcessus;
	bSizerLancerProcessus = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionProcessusLancer;
	sbSizerSelectionProcessusLancer = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowLancerProcessus, wxID_ANY, wxT("Sélection des processus") ), wxVERTICAL );
	
	sbSizerSelectionProcessusLancer->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxLancerProcessus = new wxListBox( sbSizerSelectionProcessusLancer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxLancerProcessus->Append( wxT("01 - Processus 1") );
	m_listBoxLancerProcessus->Append( wxT("02 - Processus 2") );
	m_listBoxLancerProcessus->Append( wxT("03 - Processus 3") );
	sbSizerSelectionProcessusLancer->Add( m_listBoxLancerProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerLancerProcessus->Add( sbSizerSelectionProcessusLancer, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerLancement;
	sbSizerLancement = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowLancerProcessus, wxID_ANY, wxT("Lancer le processus") ), wxVERTICAL );
	
	
	sbSizerLancement->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_sdbSizerLancerProcessus = new wxStdDialogButtonSizer();
	m_sdbSizerLancerProcessusOK = new wxButton( sbSizerLancement->GetStaticBox(), wxID_OK );
	m_sdbSizerLancerProcessus->AddButton( m_sdbSizerLancerProcessusOK );
	m_sdbSizerLancerProcessus->Realize();
	
	sbSizerLancement->Add( m_sdbSizerLancerProcessus, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerLancerProcessus->Add( sbSizerLancement, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowLancerProcessus->SetSizer( bSizerLancerProcessus );
	m_scrolledWindowLancerProcessus->Layout();
	bSizerLancerProcessus->Fit( m_scrolledWindowLancerProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowLancerProcessus, wxT("Lancer un processus"), false );
	
	bSizerPrincipal->Add( m_notebookProcessus, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelAffichage = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerAffichage;
	bSizerAffichage = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( m_panelAffichage, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxT("Connecter-vous pour pouvoir effectuer des actions.\n"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizerAffichage->Add( m_textCtrlAffichage, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_buttonViderAffichage = new wxButton( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxT("ViderAffichage"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER );
	sbSizerAffichage->Add( m_buttonViderAffichage, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 1 );
	
	
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
	m_menuItemQuitter->SetBitmaps( wxNullBitmap, wxArtProvider::GetBitmap( wxT("gtk-quit"), wxART_MENU ) );
	#endif
	m_menuFichier->Append( m_menuItemQuitter );
	
	m_menubarFramePrincipal->Append( m_menuFichier, wxT("Fichier") ); 
	
	m_menuAide = new wxMenu();
	wxMenuItem* m_menuItemAide;
	m_menuItemAide = new wxMenuItem( m_menuAide, wxID_ANY, wxString( wxT("Aide") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemAide->SetBitmaps( wxArtProvider::GetBitmap( wxART_HELP_SETTINGS, wxART_MENU ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItemAide->SetBitmap( wxArtProvider::GetBitmap( wxART_HELP_SETTINGS, wxART_MENU ) );
	#endif
	m_menuAide->Append( m_menuItemAide );
	
	m_menuAide->AppendSeparator();
	
	wxMenuItem* m_menuItemApropos;
	m_menuItemApropos = new wxMenuItem( m_menuAide, wxID_ANY, wxString( wxT("À propos ...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuAide->Append( m_menuItemApropos );
	
	m_menubarFramePrincipal->Append( m_menuAide, wxT("Aide") ); 
	
	this->SetMenuBar( m_menubarFramePrincipal );
	
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlLogin->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlPass->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_listBoxModifierProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_listBoxModifierProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_buttonModification->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonModifierClick ), NULL, this );
	m_sdbSizerModifierApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_sdbSizerModifierCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModiffierClick ), NULL, this );
	m_sdbSizerCreerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonCreerClick ), NULL, this );
	m_sdbSizerCreerSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_listBoxDetruireProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_listBoxDetruireProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_sdbSizerDetruireApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonDetruireClick ), NULL, this );
	m_listBoxLancerProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_listBoxLancerProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_sdbSizerLancerProcessusOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnOkButtonLancerClick ), NULL, this );
	m_buttonViderAffichage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonViderAffichageClick ), NULL, this );
	this->Connect( m_menuItemQuitter->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuQuitterSelection ) );
	this->Connect( m_menuItemAide->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAideSelection ) );
	this->Connect( m_menuItemApropos->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAproposSelection ) );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlLogin->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_listBoxAffichageProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_listBoxAffichageProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_listBoxModifierProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_listBoxModifierProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_buttonModification->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonModifierClick ), NULL, this );
	m_sdbSizerModifierApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_sdbSizerModifierCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModiffierClick ), NULL, this );
	m_sdbSizerCreerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonCreerClick ), NULL, this );
	m_sdbSizerCreerSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_listBoxDetruireProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_listBoxDetruireProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_sdbSizerDetruireApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonDetruireClick ), NULL, this );
	m_listBoxLancerProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_listBoxLancerProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_sdbSizerLancerProcessusOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnOkButtonLancerClick ), NULL, this );
	m_buttonViderAffichage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonViderAffichageClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuQuitterSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAideSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::OnMenuAproposSelection ) );
	
}
