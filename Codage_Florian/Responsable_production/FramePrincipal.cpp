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
	this->SetSizeHints( wxSize( 1000,750 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizerPrincipal;
	bSizerPrincipal = new wxBoxSizer( wxVERTICAL );
	
	m_panelConnexion = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerConnexion;
	bSizerConnexion = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerConnexion;
	sbSizerConnexion = new wxStaticBoxSizer( new wxStaticBox( m_panelConnexion, wxID_ANY, wxT("Connexion") ), wxVERTICAL );
	
	wxBoxSizer* bSizerLogin;
	bSizerLogin = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextLogin = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre login :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLogin->Wrap( -1 );
	bSizerLogin->Add( m_staticTextLogin, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlLogin = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Responsable"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	bSizerLogin->Add( m_textCtrlLogin, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerLogin->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizerLogin, 1, wxALIGN_TOP|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizerPass;
	bSizerPass = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPass = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre mot de passe :"), wxDefaultPosition, wxDefaultSize, 0 );
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
	sbSizerSelectionProcessusAfficher = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageProcessus, wxID_ANY, wxT("Sélection du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionProcessusAfficher->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxAffichageProcessus = new wxListBox( sbSizerSelectionProcessusAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
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
	
	m_textCtrlIdAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
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
	
	m_textCtrlDureeTotalHeureAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
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
	
	m_staticTextDureeTotalMinuteAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalMinuteAfficher->Wrap( -1 );
	bSizerDureeTotalAfficher->Add( m_staticTextDureeTotalMinuteAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalMinuteAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalMinuteAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalMinuteAfficher->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalMinuteAfficher->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalMinuteAfficher->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalAfficher->Add( m_textCtrlDureeTotalMinuteAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalSecondeAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalSecondeAfficher->Wrap( -1 );
	bSizerDureeTotalAfficher->Add( m_staticTextDureeTotalSecondeAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalSecondeAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalSecondeAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalSecondeAfficher->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalSecondeAfficher->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalSecondeAfficher->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalAfficher->Add( m_textCtrlDureeTotalSecondeAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherGauche->Add( bSizerDureeTotalAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerListeTrajectoiresAfficher;
	sbSizerListeTrajectoiresAfficher = new wxStaticBoxSizer( new wxStaticBox( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Liste des trajectoires du processus") ), wxVERTICAL );
	
	m_listBoxListeTrajectoiresAfficher = new wxListBox( sbSizerListeTrajectoiresAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
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
	
	m_textCtrlNomAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlNomAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlNomAfficher->SetMaxLength( 100 );
	}
	#else
	m_textCtrlNomAfficher->SetMaxLength( 100 );
	#endif
	bSizerNomAffichage->Add( m_textCtrlNomAfficher, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomAffichage->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroite->Add( bSizerNomAffichage, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNombreBainAfficher;
	bSizerNombreBainAfficher = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainAfficher->Wrap( -1 );
	bSizerNombreBainAfficher->Add( m_staticTextNombreBainAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNombreBainAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
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
	
	m_textCtrlOrdreTrajectoiresAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	bSizerOrdresTrajectoiresAfficher->Add( m_textCtrlOrdreTrajectoiresAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdresTrajectoiresAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroite->Add( bSizerOrdresTrajectoiresAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	sbSizerAfficher->Add( bSizerAfficherDroite, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerAfficherProcessus->Add( sbSizerAfficher, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowAffichageProcessus->SetSizer( bSizerAfficherProcessus );
	m_scrolledWindowAffichageProcessus->Layout();
	bSizerAfficherProcessus->Fit( m_scrolledWindowAffichageProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowAffichageProcessus, wxT("Afficher les processus"), true );
	m_scrolledWindowModifierProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowModifierProcessus->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerModifierProcessus;
	bSizerModifierProcessus = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionProcessusModifier;
	sbSizerSelectionProcessusModifier = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierProcessus, wxID_ANY, wxT("Sélection du processus à modifier") ), wxHORIZONTAL );
	
	sbSizerSelectionProcessusModifier->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxModifierProcessus = new wxListBox( sbSizerSelectionProcessusModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
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
	
	m_textCtrlIdModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
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
	
	m_textCtrlDureeTotalHeureModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
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
	
	m_staticTextDureeTotalMinuteModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalMinuteModifier->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticTextDureeTotalMinuteModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalMinuteModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalMinuteModifier->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalMinuteModifier->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalMinuteModifier->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalMinuteModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalModifier->Add( m_textCtrlDureeTotalMinuteModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalSecondeModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalSecondeModifier->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticTextDureeTotalSecondeModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalSecondeModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalSecondeModifier->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalSecondeModifier->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalSecondeModifier->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalSecondeModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalModifier->Add( m_textCtrlDureeTotalSecondeModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationGauche->Add( bSizerDureeTotalModifier, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerListeTrajectoiresModifier;
	sbSizerListeTrajectoiresModifier = new wxStaticBoxSizer( new wxStaticBox( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Liste des trajectoires") ), wxVERTICAL );
	
	m_listBoxListeTrajectoiresModifier = new wxListBox( sbSizerListeTrajectoiresModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
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
	
	m_textCtrlNomModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlNomModifier->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlNomModifier->SetMaxLength( 100 );
	}
	#else
	m_textCtrlNomModifier->SetMaxLength( 100 );
	#endif
	bSizerNomModification->Add( m_textCtrlNomModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( bSizerNomModification, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNombreBainModifier;
	bSizerNombreBainModifier = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainModifier->Wrap( -1 );
	bSizerNombreBainModifier->Add( m_staticTextNombreBainModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrlNombreBainModifier = new wxSpinCtrl( sbSizerModification->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 6, 1 );
	m_spinCtrlNombreBainModifier->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerNombreBainModifier->Add( m_spinCtrlNombreBainModifier, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( bSizerNombreBainModifier, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerOrdreTrajectoiresModifier;
	bSizerOrdreTrajectoiresModifier = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdreTrajectoiresModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresModifier = new wxStaticText( sbSizerModification->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires :\nséparé par ;"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextOrdreTrajectoiresModifier->Wrap( -1 );
	bSizerOrdreTrajectoiresModifier->Add( m_staticTextOrdreTrajectoiresModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlOrdreTrajectoiresModifier = new wxTextCtrl( sbSizerModification->GetStaticBox(), wxID_ORDRE_MODIFIER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	bSizerOrdreTrajectoiresModifier->Add( m_textCtrlOrdreTrajectoiresModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdreTrajectoiresModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( bSizerOrdreTrajectoiresModifier, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	bSizerModificationPrincipal->Add( bSizerModificationDroite, 1, wxEXPAND, 5 );
	
	
	sbSizerModification->Add( bSizerModificationPrincipal, 1, wxEXPAND, 5 );
	
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
	sbSizerCreer = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowCreerProcessus, wxID_ANY, wxT("Création d’un processus") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizerCreerGauche;
	bSizerCreerGauche = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerDureeTotalCreer;
	bSizerDureeTotalCreer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticDureeTotalCreer = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Durée total :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDureeTotalCreer->Wrap( -1 );
	bSizerDureeTotalCreer->Add( m_staticDureeTotalCreer, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeTotalHeureCreer = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalHeureCreer->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalHeureCreer->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalHeureCreer->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalHeureCreer->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalCreer->Add( m_textCtrlDureeTotalHeureCreer, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalMinuteCreer = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalMinuteCreer->Wrap( -1 );
	bSizerDureeTotalCreer->Add( m_staticTextDureeTotalMinuteCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalMinuteCreer = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalMinuteCreer->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalMinuteCreer->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalMinuteCreer->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalMinuteCreer->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalCreer->Add( m_textCtrlDureeTotalMinuteCreer, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalSecondeCreer = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalSecondeCreer->Wrap( -1 );
	bSizerDureeTotalCreer->Add( m_staticTextDureeTotalSecondeCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalSecondeCreer = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeTotalSecondeCreer->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeTotalSecondeCreer->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeTotalSecondeCreer->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeTotalSecondeCreer->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeTotalCreer->Add( m_textCtrlDureeTotalSecondeCreer, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerGauche->Add( bSizerDureeTotalCreer, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerListeTrajectoiresModifier1;
	sbSizerListeTrajectoiresModifier1 = new wxStaticBoxSizer( new wxStaticBox( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Liste des trajectoires") ), wxVERTICAL );
	
	m_listBoxListeTrajectoiresCreer = new wxListBox( sbSizerListeTrajectoiresModifier1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizerListeTrajectoiresModifier1->Add( m_listBoxListeTrajectoiresCreer, 2, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerCreerGauche->Add( sbSizerListeTrajectoiresModifier1, 2, wxALL|wxEXPAND, 5 );
	
	
	sbSizerCreer->Add( bSizerCreerGauche, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineCreer = new wxStaticLine( sbSizerCreer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizerCreer->Add( m_staticlineCreer, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerCreerDroite;
	bSizerCreerDroite = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomCreer;
	bSizerNomCreer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomCreer = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Nom du processus :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomCreer->Wrap( -1 );
	bSizerNomCreer->Add( m_staticTextNomCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomCreer = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlNomCreer->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlNomCreer->SetMaxLength( 100 );
	}
	#else
	m_textCtrlNomCreer->SetMaxLength( 100 );
	#endif
	bSizerNomCreer->Add( m_textCtrlNomCreer, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerDroite->Add( bSizerNomCreer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNombreBainCreer;
	bSizerNombreBainCreer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainCreer = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainCreer->Wrap( -1 );
	bSizerNombreBainCreer->Add( m_staticTextNombreBainCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrlNombreBainCreer = new wxSpinCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 6, 1 );
	m_spinCtrlNombreBainCreer->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerNombreBainCreer->Add( m_spinCtrlNombreBainCreer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerDroite->Add( bSizerNombreBainCreer, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerOrdresTrajectoiresCreer;
	bSizerOrdresTrajectoiresCreer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdresTrajectoiresCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresCreer = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires :\nséparé par ;"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextOrdreTrajectoiresCreer->Wrap( -1 );
	bSizerOrdresTrajectoiresCreer->Add( m_staticTextOrdreTrajectoiresCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlOrdreTrajectoiresCreer = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ORDRE_CREER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	bSizerOrdresTrajectoiresCreer->Add( m_textCtrlOrdreTrajectoiresCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdresTrajectoiresCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerDroite->Add( bSizerOrdresTrajectoiresCreer, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizerCreer->Add( bSizerCreerDroite, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCreerProcessus->Add( sbSizerCreer, 1, wxALL|wxEXPAND, 5 );
	
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
	sbSizerSelectionProcessusDetruire = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireProcessus, wxID_ANY, wxT("Sélection du processus à détruire") ), wxHORIZONTAL );
	
	sbSizerSelectionProcessusDetruire->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxDetruireProcessus = new wxListBox( sbSizerSelectionProcessusDetruire->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE ); 
	sbSizerSelectionProcessusDetruire->Add( m_listBoxDetruireProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerDetruireProcessus->Add( sbSizerSelectionProcessusDetruire, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerDetruire;
	sbSizerDetruire = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireProcessus, wxID_ANY, wxT("Détruire") ), wxVERTICAL );
	
	wxBoxSizer* bSizerTitreDetruire;
	bSizerTitreDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Vous allez détruire le processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDetruire->Wrap( -1 );
	m_staticTextDetruire->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTitreDetruire->Add( m_staticTextDetruire, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextDetuireTitre = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDetuireTitre->Wrap( -1 );
	m_staticTextDetuireTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTitreDetruire->Add( m_staticTextDetuireTitre, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizerDetruire->Add( bSizerTitreDetruire, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxALL, 5 );
	
	wxBoxSizer* bSizerDetailDetruire;
	bSizerDetailDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerDetruireDroit;
	bSizerDetruireDroit = new wxBoxSizer( wxVERTICAL );
	
	bSizerDureeTotalDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeTotalProcessusDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Durée total : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalProcessusDetruire->Wrap( -1 );
	bSizerDureeTotalDetruire->Add( m_staticTextDureeTotalProcessusDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalValeurDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalValeurDetruire->Wrap( -1 );
	bSizerDureeTotalDetruire->Add( m_staticTextDureeTotalValeurDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerDetruireDroit->Add( bSizerDureeTotalDetruire, 1, wxEXPAND, 5 );
	
	
	bSizerDetailDetruire->Add( bSizerDetruireDroit, 1, wxEXPAND, 5 );
	
	m_staticlineSeparateurGaucheDroiteDetruire = new wxStaticLine( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerDetailDetruire->Add( m_staticlineSeparateurGaucheDroiteDetruire, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerDetruireGauche;
	bSizerDetruireGauche = new wxBoxSizer( wxVERTICAL );
	
	bSizerNombreBainDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Nombre de bain : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainDetruire->Wrap( -1 );
	bSizerNombreBainDetruire->Add( m_staticTextNombreBainDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextNombreBainValeurDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("a faire"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainValeurDetruire->Wrap( -1 );
	bSizerNombreBainDetruire->Add( m_staticTextNombreBainValeurDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerDetruireGauche->Add( bSizerNombreBainDetruire, 1, wxEXPAND, 5 );
	
	bSizerOrdreTrajectoiresDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdreTrajectoiresDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresDetruire->Wrap( -1 );
	bSizerOrdreTrajectoiresDetruire->Add( m_staticTextOrdreTrajectoiresDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextOrdreTrajectoiresDetruireValeur = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("0;0;0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresDetruireValeur->Wrap( -1 );
	bSizerOrdreTrajectoiresDetruire->Add( m_staticTextOrdreTrajectoiresDetruireValeur, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdreTrajectoiresDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerDetruireGauche->Add( bSizerOrdreTrajectoiresDetruire, 1, wxEXPAND, 5 );
	
	
	bSizerDetailDetruire->Add( bSizerDetruireGauche, 1, wxEXPAND, 5 );
	
	
	sbSizerDetruire->Add( bSizerDetailDetruire, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineSeparateurDetailBoutonDetruire = new wxStaticLine( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizerDetruire->Add( m_staticlineSeparateurDetailBoutonDetruire, 0, wxEXPAND | wxALL, 5 );
	
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
	sbSizerSelectionProcessusLancer = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowLancerProcessus, wxID_ANY, wxT("Sélection du processus à lancer") ), wxVERTICAL );
	
	sbSizerSelectionProcessusLancer->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxLancerProcessus = new wxListBox( sbSizerSelectionProcessusLancer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	sbSizerSelectionProcessusLancer->Add( m_listBoxLancerProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerLancerProcessus->Add( sbSizerSelectionProcessusLancer, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerLancement;
	sbSizerLancement = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowLancerProcessus, wxID_ANY, wxT("Lancer le processus") ), wxVERTICAL );
	
	wxBoxSizer* bSizerTitreLancer;
	bSizerTitreLancer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("Vous allez lancer la fabrication du processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLancer->Wrap( -1 );
	m_staticTextLancer->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTitreLancer->Add( m_staticTextLancer, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextLancerTitre = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLancerTitre->Wrap( -1 );
	m_staticTextLancerTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTitreLancer->Add( m_staticTextLancerTitre, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizerLancement->Add( bSizerTitreLancer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizerDetailLancer = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerLancerDroit = new wxBoxSizer( wxVERTICAL );
	
	bSizerDureeTotalLancer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalLancer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeTotalProcessusLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("Durée total : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalProcessusLancer->Wrap( -1 );
	bSizerDureeTotalLancer->Add( m_staticTextDureeTotalProcessusLancer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalValeurLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalValeurLancer->Wrap( -1 );
	bSizerDureeTotalLancer->Add( m_staticTextDureeTotalValeurLancer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalLancer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerLancerDroit->Add( bSizerDureeTotalLancer, 1, wxEXPAND, 5 );
	
	
	bSizerDetailLancer->Add( bSizerLancerDroit, 1, wxEXPAND, 5 );
	
	m_staticlineSeparateurGaucheDroiteLancer = new wxStaticLine( sbSizerLancement->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerDetailLancer->Add( m_staticlineSeparateurGaucheDroiteLancer, 0, wxEXPAND | wxALL, 5 );
	
	bSizerLancerGauche = new wxBoxSizer( wxVERTICAL );
	
	bSizerNombreBainLancer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainLancer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("Nombre de bain : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainLancer->Wrap( -1 );
	bSizerNombreBainLancer->Add( m_staticTextNombreBainLancer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextNombreBainValeurLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("a faire"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainValeurLancer->Wrap( -1 );
	bSizerNombreBainLancer->Add( m_staticTextNombreBainValeurLancer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainLancer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerLancerGauche->Add( bSizerNombreBainLancer, 1, wxEXPAND, 5 );
	
	bSizerOrdreTrajectoiresLancer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdreTrajectoiresLancer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresLancer->Wrap( -1 );
	bSizerOrdreTrajectoiresLancer->Add( m_staticTextOrdreTrajectoiresLancer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextOrdreTrajectoiresValeurLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresValeurLancer->Wrap( -1 );
	bSizerOrdreTrajectoiresLancer->Add( m_staticTextOrdreTrajectoiresValeurLancer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdreTrajectoiresLancer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerLancerGauche->Add( bSizerOrdreTrajectoiresLancer, 1, wxEXPAND, 5 );
	
	
	bSizerDetailLancer->Add( bSizerLancerGauche, 1, wxEXPAND, 5 );
	
	
	sbSizerLancement->Add( bSizerDetailLancer, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineSeparateurDetailBoutonLancer = new wxStaticLine( sbSizerLancement->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizerLancement->Add( m_staticlineSeparateurDetailBoutonLancer, 0, wxEXPAND | wxALL, 5 );
	
	m_sdbSizerLancerProcessus = new wxStdDialogButtonSizer();
	m_sdbSizerLancerProcessusOK = new wxButton( sbSizerLancement->GetStaticBox(), wxID_OK );
	m_sdbSizerLancerProcessus->AddButton( m_sdbSizerLancerProcessusOK );
	m_sdbSizerLancerProcessus->Realize();
	
	sbSizerLancement->Add( m_sdbSizerLancerProcessus, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerLancerProcessus->Add( sbSizerLancement, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowLancerProcessus->SetSizer( bSizerLancerProcessus );
	m_scrolledWindowLancerProcessus->Layout();
	bSizerLancerProcessus->Fit( m_scrolledWindowLancerProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowLancerProcessus, wxT("Lancer une fabrication"), false );
	m_scrolledWindowTesterProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowTesterProcessus->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerTesterProcessus;
	bSizerTesterProcessus = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionProcessusTester;
	sbSizerSelectionProcessusTester = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowTesterProcessus, wxID_ANY, wxT("Sélection du processus à Tester") ), wxVERTICAL );
	
	sbSizerSelectionProcessusTester->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxTesterProcessus = new wxListBox( sbSizerSelectionProcessusTester->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	sbSizerSelectionProcessusTester->Add( m_listBoxTesterProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerTesterProcessus->Add( sbSizerSelectionProcessusTester, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTester;
	sbSizerTester = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowTesterProcessus, wxID_ANY, wxT("Tester le processus") ), wxVERTICAL );
	
	wxBoxSizer* bSizerTitreTester;
	bSizerTitreTester = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Vous allez lancer le test du processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTester->Wrap( -1 );
	m_staticTextTester->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTitreTester->Add( m_staticTextTester, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextTesterTitre = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTesterTitre->Wrap( -1 );
	m_staticTextTesterTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTitreTester->Add( m_staticTextTesterTitre, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizerTester->Add( bSizerTitreTester, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizerDetailTester = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerTesterDroit = new wxBoxSizer( wxVERTICAL );
	
	bSizerDureeTotalTester = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeTotalProcessusTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Durée total : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalProcessusTester->Wrap( -1 );
	bSizerDureeTotalTester->Add( m_staticTextDureeTotalProcessusTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalValeurTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalValeurTester->Wrap( -1 );
	bSizerDureeTotalTester->Add( m_staticTextDureeTotalValeurTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeTotalTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTesterDroit->Add( bSizerDureeTotalTester, 1, wxEXPAND, 5 );
	
	
	bSizerDetailTester->Add( bSizerTesterDroit, 1, wxEXPAND, 5 );
	
	m_staticlineSeparateurGaucheDroiteTester = new wxStaticLine( sbSizerTester->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerDetailTester->Add( m_staticlineSeparateurGaucheDroiteTester, 0, wxEXPAND | wxALL, 5 );
	
	bSizerTesterGauche = new wxBoxSizer( wxVERTICAL );
	
	bSizerNombreBainTester = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Nombre de bain : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainTester->Wrap( -1 );
	bSizerNombreBainTester->Add( m_staticTextNombreBainTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextNombreBainValeurTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("a faire"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainValeurTester->Wrap( -1 );
	bSizerNombreBainTester->Add( m_staticTextNombreBainValeurTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTesterGauche->Add( bSizerNombreBainTester, 1, wxEXPAND, 5 );
	
	bSizerOrdreTrajectoiresTester = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdreTrajectoiresTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresTester->Wrap( -1 );
	bSizerOrdreTrajectoiresTester->Add( m_staticTextOrdreTrajectoiresTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextOrdreTrajectoiresValeurTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("0;0;0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresValeurTester->Wrap( -1 );
	bSizerOrdreTrajectoiresTester->Add( m_staticTextOrdreTrajectoiresValeurTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdreTrajectoiresTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTesterGauche->Add( bSizerOrdreTrajectoiresTester, 1, wxEXPAND, 5 );
	
	
	bSizerDetailTester->Add( bSizerTesterGauche, 1, wxEXPAND, 5 );
	
	
	sbSizerTester->Add( bSizerDetailTester, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineSeparateurDetailBoutonsTester = new wxStaticLine( sbSizerTester->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizerTester->Add( m_staticlineSeparateurDetailBoutonsTester, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerButonTester;
	bSizerButonTester = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButtonStopTester = new wxBitmapButton( sbSizerTester->GetStaticBox(), wxID_ANY, wxBitmap( wxT("../Images/stop_petit.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizerButonTester->Add( m_bpButtonStopTester, 0, wxALIGN_BOTTOM|wxRIGHT, 3 );
	
	m_bpButtonOKTester = new wxBitmapButton( sbSizerTester->GetStaticBox(), wxID_ANY, wxBitmap( wxT("../Images/ok-button-petit.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizerButonTester->Add( m_bpButtonOKTester, 0, wxALIGN_BOTTOM|wxLEFT, 3 );
	
	
	sbSizerTester->Add( bSizerButonTester, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5 );
	
	
	bSizerTesterProcessus->Add( sbSizerTester, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowTesterProcessus->SetSizer( bSizerTesterProcessus );
	m_scrolledWindowTesterProcessus->Layout();
	bSizerTesterProcessus->Fit( m_scrolledWindowTesterProcessus );
	m_notebookProcessus->AddPage( m_scrolledWindowTesterProcessus, wxT("Tester un processus"), false );
	m_scrolledWindowInfoBras = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowInfoBras->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerInfoBrasPrincipal;
	bSizerInfoBrasPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerInfos;
	bSizerInfos = new wxBoxSizer( wxHORIZONTAL );
	
	sbSizerDisponibiliteBras = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowInfoBras, wxID_ANY, wxT("Disponibilité du bras") ), wxVERTICAL );
	
	wxBoxSizer* bSizerDisponibiliteBras;
	bSizerDisponibiliteBras = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmapDisponibiliteBras = new wxStaticBitmap( sbSizerDisponibiliteBras->GetStaticBox(), wxID_ANY, wxBitmap( wxT("../Images/EteintBlanc.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDisponibiliteBras->Add( m_bitmapDisponibiliteBras, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticTextDisponibiliteBras = new wxStaticText( sbSizerDisponibiliteBras->GetStaticBox(), wxID_ANY, wxT("Veulliez demander la disponibilité du bras."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDisponibiliteBras->Wrap( -1 );
	bSizerDisponibiliteBras->Add( m_staticTextDisponibiliteBras, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerDisponibiliteBras->Add( bSizerDisponibiliteBras, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizerInfos->Add( sbSizerDisponibiliteBras, 1, wxALL|wxEXPAND, 5 );
	
	sbSizerTacheEnCours = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowInfoBras, wxID_ANY, wxT("Tâche en cours") ), wxVERTICAL );
	
	m_panelTacheEnCours = new wxPanel( sbSizerTacheEnCours->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelTacheEnCours->Hide();
	
	bSizerTacheEnCoursPrincipal = new wxBoxSizer( wxVERTICAL );
	
	
	bSizerTacheEnCoursPrincipal->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTypeTache;
	bSizerTypeTache = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerTypeTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextTypeTache = new wxStaticText( m_panelTacheEnCours, wxID_ANY, wxT("Type de tâche : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTypeTache->Wrap( -1 );
	bSizerTypeTache->Add( m_staticTextTypeTache, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlTypeTache = new wxTextCtrl( m_panelTacheEnCours, wxID_ANY, wxT("Processus"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlTypeTache->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlTypeTache->SetMaxLength( 9 );
	}
	#else
	m_textCtrlTypeTache->SetMaxLength( 9 );
	#endif
	bSizerTypeTache->Add( m_textCtrlTypeTache, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerTypeTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTacheEnCoursPrincipal->Add( bSizerTypeTache, 1, wxEXPAND, 5 );
	
	
	bSizerTacheEnCoursPrincipal->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNomTache;
	bSizerNomTache = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomTache = new wxStaticText( m_panelTacheEnCours, wxID_ANY, wxT("Nom de la tâche : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomTache->Wrap( -1 );
	bSizerNomTache->Add( m_staticTextNomTache, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomTache = new wxTextCtrl( m_panelTacheEnCours, wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	bSizerNomTache->Add( m_textCtrlNomTache, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTacheEnCoursPrincipal->Add( bSizerNomTache, 1, wxEXPAND, 5 );
	
	
	bSizerTacheEnCoursPrincipal->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDureeRestant;
	bSizerDureeRestant = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeRestant->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticDureeRestant = new wxStaticText( m_panelTacheEnCours, wxID_ANY, wxT("Durée total :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDureeRestant->Wrap( -1 );
	bSizerDureeRestant->Add( m_staticDureeRestant, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeRestantHeure = new wxTextCtrl( m_panelTacheEnCours, wxID_ANY, wxT("02"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeRestantHeure->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeRestantHeure->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeRestantHeure->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeRestantHeure->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeRestant->Add( m_textCtrlDureeRestantHeure, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeRestantMinute = new wxStaticText( m_panelTacheEnCours, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeRestantMinute->Wrap( -1 );
	bSizerDureeRestant->Add( m_staticTextDureeRestantMinute, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textCtrlDureeRestantMinute = new wxTextCtrl( m_panelTacheEnCours, wxID_ANY, wxT("52"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !textCtrlDureeRestantMinute->HasFlag( wxTE_MULTILINE ) )
	{
	textCtrlDureeRestantMinute->SetMaxLength( 2 );
	}
	#else
	textCtrlDureeRestantMinute->SetMaxLength( 2 );
	#endif
	textCtrlDureeRestantMinute->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeRestant->Add( textCtrlDureeRestantMinute, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeRestantSeconde = new wxStaticText( m_panelTacheEnCours, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeRestantSeconde->Wrap( -1 );
	bSizerDureeRestant->Add( m_staticTextDureeRestantSeconde, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textCtrlDureeRestantSeconde = new wxTextCtrl( m_panelTacheEnCours, wxID_ANY, wxT("00"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !textCtrlDureeRestantSeconde->HasFlag( wxTE_MULTILINE ) )
	{
	textCtrlDureeRestantSeconde->SetMaxLength( 2 );
	}
	#else
	textCtrlDureeRestantSeconde->SetMaxLength( 2 );
	#endif
	textCtrlDureeRestantSeconde->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeRestant->Add( textCtrlDureeRestantSeconde, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeRestant->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTacheEnCoursPrincipal->Add( bSizerDureeRestant, 1, wxEXPAND, 5 );
	
	
	bSizerTacheEnCoursPrincipal->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	m_panelTacheEnCours->SetSizer( bSizerTacheEnCoursPrincipal );
	m_panelTacheEnCours->Layout();
	bSizerTacheEnCoursPrincipal->Fit( m_panelTacheEnCours );
	sbSizerTacheEnCours->Add( m_panelTacheEnCours, 1, wxEXPAND | wxALL, 5 );
	
	m_panelPasTache = new wxPanel( sbSizerTacheEnCours->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelPasTache->Hide();
	
	wxBoxSizer* bSizerPasTache;
	bSizerPasTache = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPasTache = new wxStaticText( m_panelPasTache, wxID_ANY, wxT("Il n'y a pas de tâche en cours"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextPasTache->Wrap( -1 );
	bSizer53->Add( m_staticTextPasTache, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerPasTache->Add( bSizer53, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panelPasTache->SetSizer( bSizerPasTache );
	m_panelPasTache->Layout();
	bSizerPasTache->Fit( m_panelPasTache );
	sbSizerTacheEnCours->Add( m_panelPasTache, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizerInfos->Add( sbSizerTacheEnCours, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerInfoBrasPrincipal->Add( bSizerInfos, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBouttons;
	bSizerBouttons = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerBoutonBras;
	bSizerBoutonBras = new wxBoxSizer( wxVERTICAL );
	
	m_buttonDisponibiliteBras = new wxButton( m_scrolledWindowInfoBras, wxID_ANY, wxT("Demander la disponibilité du bras"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBoutonBras->Add( m_buttonDisponibiliteBras, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerBouttons->Add( bSizerBoutonBras, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBoutonTache;
	bSizerBoutonTache = new wxBoxSizer( wxVERTICAL );
	
	m_buttonTacheEnCours = new wxButton( m_scrolledWindowInfoBras, wxID_ANY, wxT("Demander la tâche en cours"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBoutonTache->Add( m_buttonTacheEnCours, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerBouttons->Add( bSizerBoutonTache, 1, wxEXPAND, 5 );
	
	
	bSizerInfoBrasPrincipal->Add( bSizerBouttons, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	m_scrolledWindowInfoBras->SetSizer( bSizerInfoBrasPrincipal );
	m_scrolledWindowInfoBras->Layout();
	bSizerInfoBrasPrincipal->Fit( m_scrolledWindowInfoBras );
	m_notebookProcessus->AddPage( m_scrolledWindowInfoBras, wxT("Information sur le bras"), false );
	
	bSizerPrincipal->Add( m_notebookProcessus, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelAffichage = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerAffichage;
	bSizerAffichage = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerAffichage;
	sbSizerAffichage = new wxStaticBoxSizer( new wxStaticBox( m_panelAffichage, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_textCtrlAffichage = new wxTextCtrl( sbSizerAffichage->GetStaticBox(), wxID_ANY, wxT("\n\n\t\tConnectez-vous pour pouvoir effectuer des actions.\n"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_RICH2 );
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
	m_panelConnexion->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextLogin->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlLogin->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlLogin->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_staticTextPass->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlPass->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlPass->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_notebookProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_scrolledWindowAffichageProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_staticTextIdAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlIdAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticDureeTotalAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextDureeTotalMinuteAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalMinuteAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextDureeTotalSecondeAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalSecondeAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxListeTrajectoiresAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextNomAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNomAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextNombreBainAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNombreBainAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextOrdreTrajectoiresAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlOrdreTrajectoiresAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_scrolledWindowModifierProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxModifierProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_listBoxModifierProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_sdbSizerModifierApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_sdbSizerModifierCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModiffierClick ), NULL, this );
	m_scrolledWindowCreerProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_sdbSizerCreerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonCreerClick ), NULL, this );
	m_sdbSizerCreerSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_scrolledWindowDetruireProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxDetruireProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_listBoxDetruireProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_sdbSizerDetruireApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonDetruireClick ), NULL, this );
	m_scrolledWindowLancerProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxLancerProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_listBoxLancerProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_sdbSizerLancerProcessusOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnOkButtonLancerClick ), NULL, this );
	m_scrolledWindowTesterProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxTesterProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelection ), NULL, this );
	m_listBoxTesterProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelection ), NULL, this );
	m_bpButtonStopTester->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnStopButtonTesterClick ), NULL, this );
	m_bpButtonOKTester->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnOkButtonTesterClick ), NULL, this );
	m_scrolledWindowInfoBras->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_buttonDisponibiliteBras->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDisponibiliteBrasClick ), NULL, this );
	m_buttonTacheEnCours->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonTacheEnCoursClick ), NULL, this );
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
	m_panelConnexion->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextLogin->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlLogin->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlLogin->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_staticTextPass->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_notebookProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_scrolledWindowAffichageProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxAffichageProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxAffichageProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_listBoxAffichageProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_staticTextIdAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlIdAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticDureeTotalAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextDureeTotalMinuteAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalMinuteAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextDureeTotalSecondeAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalSecondeAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxListeTrajectoiresAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextNomAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNomAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextNombreBainAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNombreBainAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextOrdreTrajectoiresAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlOrdreTrajectoiresAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_scrolledWindowModifierProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxModifierProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_listBoxModifierProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_sdbSizerModifierApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_sdbSizerModifierCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModiffierClick ), NULL, this );
	m_scrolledWindowCreerProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_sdbSizerCreerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonCreerClick ), NULL, this );
	m_sdbSizerCreerSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_scrolledWindowDetruireProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxDetruireProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_listBoxDetruireProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelection ), NULL, this );
	m_sdbSizerDetruireApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonDetruireClick ), NULL, this );
	m_scrolledWindowLancerProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxLancerProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_listBoxLancerProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxLancerSelection ), NULL, this );
	m_sdbSizerLancerProcessusOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnOkButtonLancerClick ), NULL, this );
	m_scrolledWindowTesterProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxTesterProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelection ), NULL, this );
	m_listBoxTesterProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelection ), NULL, this );
	m_bpButtonStopTester->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnStopButtonTesterClick ), NULL, this );
	m_bpButtonOKTester->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnOkButtonTesterClick ), NULL, this );
	m_scrolledWindowInfoBras->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_buttonDisponibiliteBras->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonDisponibiliteBrasClick ), NULL, this );
	m_buttonTacheEnCours->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonTacheEnCoursClick ), NULL, this );
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
	m_staticTextTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
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
	
	m_staticText40 = new wxStaticText( sbSizerAuteur->GetStaticBox(), wxID_ANY, wxT("Le Programme à été conçu et coder dans le cadre du projet bras d'annodisation du BTS SNIR (Système Numérique option Informatique et Réseaux).\nLa partie responsable de production, ainsi que la base de données ont été faites par Florian Provost.\nLa partie régleur par Nassim Boubziz.\nLe banc d'anodisation, la Raspberry Pi et tout ce qui est lié au bras a été fait par Paul Despalier\n\n"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
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
	m_staticTextTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
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
