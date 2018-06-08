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
	
	m_notebookProcessus = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP );
	m_notebookProcessus->Hide();
	
	m_scrolledWindowAffichageProcessus = new wxScrolledWindow( m_notebookProcessus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowAffichageProcessus->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerAfficherProcessus;
	bSizerAfficherProcessus = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionProcessusAfficher;
	sbSizerSelectionProcessusAfficher = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageProcessus, wxID_ANY, wxT("Sélection du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionProcessusAfficher->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxAffichageProcessus = new wxListBox( sbSizerSelectionProcessusAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_SINGLE ); 
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
	
	wxBoxSizer* bSizerOrdresTrajectoiresAfficher;
	bSizerOrdresTrajectoiresAfficher = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdresTrajectoiresAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresAfficher = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires :\nséparé par ;"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextOrdreTrajectoiresAfficher->Wrap( -1 );
	bSizerOrdresTrajectoiresAfficher->Add( m_staticTextOrdreTrajectoiresAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlOrdreTrajectoiresAfficher = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlOrdreTrajectoiresAfficher->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlOrdreTrajectoiresAfficher->SetMaxLength( 20 );
	}
	#else
	m_textCtrlOrdreTrajectoiresAfficher->SetMaxLength( 20 );
	#endif
	bSizerOrdresTrajectoiresAfficher->Add( m_textCtrlOrdreTrajectoiresAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdresTrajectoiresAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroite->Add( bSizerOrdresTrajectoiresAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	sbSizerGestionBainAfficher = new wxStaticBoxSizer( new wxStaticBox( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Gestion des bains") ), wxVERTICAL );
	
	wxBoxSizer* bSizerNombreBainAfficher;
	bSizerNombreBainAfficher = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainAfficher->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainAfficher = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainAfficher->Wrap( -1 );
	bSizerNombreBainAfficher->Add( m_staticTextNombreBainAfficher, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNombreBainAfficher = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
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
	
	
	sbSizerGestionBainAfficher->Add( bSizerNombreBainAfficher, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizerAfficherBain = new wxBoxSizer( wxVERTICAL );
	
	bSizerBainAfficherDuree = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerAfficherDureeBain1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerAfficherDureeBain1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticAfficherDureeTotalBain1 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT("Durée du bain "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticAfficherDureeTotalBain1->Wrap( -1 );
	bSizerAfficherDureeBain1->Add( m_staticAfficherDureeTotalBain1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextAfficherNumBain1 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT("0 :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherNumBain1->Wrap( -1 );
	bSizerAfficherDureeBain1->Add( m_staticTextAfficherNumBain1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_textCtrlAfficherHeureBain1 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherHeureBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherHeureBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherHeureBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherHeureBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain1->Add( m_textCtrlAfficherHeureBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextAfficherDureeBain1 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherDureeBain1->Wrap( -1 );
	bSizerAfficherDureeBain1->Add( m_staticTextAfficherDureeBain1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAfficherMinuteBain1 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherMinuteBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherMinuteBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherMinuteBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherMinuteBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain1->Add( m_textCtrlAfficherMinuteBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextAfficherDureeFinBain1 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherDureeFinBain1->Wrap( -1 );
	bSizerAfficherDureeBain1->Add( m_staticTextAfficherDureeFinBain1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAfficherSecondeBain1 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherSecondeBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherSecondeBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherSecondeBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherSecondeBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain1->Add( m_textCtrlAfficherSecondeBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerAfficherDureeBain1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerBainAfficherDuree->Add( bSizerAfficherDureeBain1, 1, wxEXPAND, 5 );
	
	bSizerAfficherDureeBain2 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerAfficherDureeBain2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticAfficherDureeTotalBain2 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT("Durée du bain "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticAfficherDureeTotalBain2->Wrap( -1 );
	m_staticAfficherDureeTotalBain2->Hide();
	
	bSizerAfficherDureeBain2->Add( m_staticAfficherDureeTotalBain2, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextAfficherNumBain2 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT("0 :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherNumBain2->Wrap( -1 );
	m_staticTextAfficherNumBain2->Hide();
	
	bSizerAfficherDureeBain2->Add( m_staticTextAfficherNumBain2, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxTOP, 5 );
	
	m_textCtrlAfficherHeureBain2 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherHeureBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherHeureBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherHeureBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherHeureBain2->Hide();
	m_textCtrlAfficherHeureBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain2->Add( m_textCtrlAfficherHeureBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextAfficherDureeBain2 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherDureeBain2->Wrap( -1 );
	m_staticTextAfficherDureeBain2->Hide();
	
	bSizerAfficherDureeBain2->Add( m_staticTextAfficherDureeBain2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAfficherMinuteBain2 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherMinuteBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherMinuteBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherMinuteBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherMinuteBain2->Hide();
	m_textCtrlAfficherMinuteBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain2->Add( m_textCtrlAfficherMinuteBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextAfficherDureeFinBain2 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherDureeFinBain2->Wrap( -1 );
	m_staticTextAfficherDureeFinBain2->Hide();
	
	bSizerAfficherDureeBain2->Add( m_staticTextAfficherDureeFinBain2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAfficherSecondeBain2 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherSecondeBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherSecondeBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherSecondeBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherSecondeBain2->Hide();
	m_textCtrlAfficherSecondeBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain2->Add( m_textCtrlAfficherSecondeBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerAfficherDureeBain2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerBainAfficherDuree->Add( bSizerAfficherDureeBain2, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherBain->Add( bSizerBainAfficherDuree, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerAfficherBain->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerAfficherDureeBain3 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerAfficherDureeBain3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticAfficherDureeTotalBain3 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT("Durée du bain "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticAfficherDureeTotalBain3->Wrap( -1 );
	m_staticAfficherDureeTotalBain3->Hide();
	
	bSizerAfficherDureeBain3->Add( m_staticAfficherDureeTotalBain3, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextAfficherNumBain3 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT("0 :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherNumBain3->Wrap( -1 );
	m_staticTextAfficherNumBain3->Hide();
	
	bSizerAfficherDureeBain3->Add( m_staticTextAfficherNumBain3, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxTOP, 5 );
	
	m_textCtrlAfficherHeureBain3 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherHeureBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherHeureBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherHeureBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherHeureBain3->Hide();
	m_textCtrlAfficherHeureBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain3->Add( m_textCtrlAfficherHeureBain3, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextAfficherDureeBain3 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherDureeBain3->Wrap( -1 );
	m_staticTextAfficherDureeBain3->Hide();
	
	bSizerAfficherDureeBain3->Add( m_staticTextAfficherDureeBain3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAfficherMinuteBain3 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherMinuteBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherMinuteBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherMinuteBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherMinuteBain3->Hide();
	m_textCtrlAfficherMinuteBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain3->Add( m_textCtrlAfficherMinuteBain3, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextAfficherDureeFinBain3 = new wxStaticText( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAfficherDureeFinBain3->Wrap( -1 );
	m_staticTextAfficherDureeFinBain3->Hide();
	
	bSizerAfficherDureeBain3->Add( m_staticTextAfficherDureeFinBain3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAfficherSecondeBain3 = new wxTextCtrl( sbSizerGestionBainAfficher->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlAfficherSecondeBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlAfficherSecondeBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlAfficherSecondeBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlAfficherSecondeBain3->Hide();
	m_textCtrlAfficherSecondeBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerAfficherDureeBain3->Add( m_textCtrlAfficherSecondeBain3, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerAfficherDureeBain3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherBain->Add( bSizerAfficherDureeBain3, 1, wxEXPAND, 5 );
	
	
	sbSizerGestionBainAfficher->Add( bSizerAfficherBain, 2, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerAfficherDroite->Add( sbSizerGestionBainAfficher, 2, wxEXPAND, 5 );
	
	
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
	m_listBoxModifierProcessus = new wxListBox( sbSizerSelectionProcessusModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_SINGLE ); 
	sbSizerSelectionProcessusModifier->Add( m_listBoxModifierProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerModifierProcessus->Add( sbSizerSelectionProcessusModifier, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerModifier;
	sbSizerModifier = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierProcessus, wxID_ANY, wxT("Modification") ), wxVERTICAL );
	
	wxBoxSizer* bSizerModificationPrincipal;
	bSizerModificationPrincipal = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerModificationGauche;
	bSizerModificationGauche = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerIdModification;
	bSizerIdModification = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerIdModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextIdModifier = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("ID du processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextIdModifier->Wrap( -1 );
	bSizerIdModification->Add( m_staticTextIdModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlIdModifier = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlIdModifier->Enable( false );
	m_textCtrlIdModifier->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerIdModification->Add( m_textCtrlIdModifier, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerIdModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationGauche->Add( bSizerIdModification, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDureeTotalModifier;
	bSizerDureeTotalModifier = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticDureeTotalModifier = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Durée total :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDureeTotalModifier->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticDureeTotalModifier, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeTotalHeureModifier = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
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
	
	m_staticTextDureeTotalMinuteModifier = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalMinuteModifier->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticTextDureeTotalMinuteModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalMinuteModifier = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
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
	
	m_staticTextDureeTotalSecondeModifier = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalSecondeModifier->Wrap( -1 );
	bSizerDureeTotalModifier->Add( m_staticTextDureeTotalSecondeModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeTotalSecondeModifier = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
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
	sbSizerListeTrajectoiresModifier = new wxStaticBoxSizer( new wxStaticBox( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Liste des trajectoires") ), wxVERTICAL );
	
	m_listBoxListeTrajectoiresModifier = new wxListBox( sbSizerListeTrajectoiresModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizerListeTrajectoiresModifier->Add( m_listBoxListeTrajectoiresModifier, 2, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerModificationGauche->Add( sbSizerListeTrajectoiresModifier, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizerModificationPrincipal->Add( bSizerModificationGauche, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineModification = new wxStaticLine( sbSizerModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerModificationPrincipal->Add( m_staticlineModification, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizerModificationDroite;
	bSizerModificationDroite = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomModification;
	bSizerNomModification = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomModification->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomModifier = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Nom du processus :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomModifier->Wrap( -1 );
	bSizerNomModification->Add( m_staticTextNomModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomModifier = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
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
	
	wxBoxSizer* bSizerOrdreTrajectoiresModifier;
	bSizerOrdreTrajectoiresModifier = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdreTrajectoiresModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresModifier = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires :\nséparé par ;"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextOrdreTrajectoiresModifier->Wrap( -1 );
	bSizerOrdreTrajectoiresModifier->Add( m_staticTextOrdreTrajectoiresModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlOrdreTrajectoiresModifier = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ORDRE_MODIFIER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlOrdreTrajectoiresModifier->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlOrdreTrajectoiresModifier->SetMaxLength( 20 );
	}
	#else
	m_textCtrlOrdreTrajectoiresModifier->SetMaxLength( 20 );
	#endif
	bSizerOrdreTrajectoiresModifier->Add( m_textCtrlOrdreTrajectoiresModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdreTrajectoiresModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( bSizerOrdreTrajectoiresModifier, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	sbSizerGestionBainModifier = new wxStaticBoxSizer( new wxStaticBox( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Gestion des bains") ), wxVERTICAL );
	
	bSizerNombreBainModifier = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainModifier = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainModifier->Wrap( -1 );
	bSizerNombreBainModifier->Add( m_staticTextNombreBainModifier, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrlNombreBainModifier = new wxSpinCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 3, 1 );
	m_spinCtrlNombreBainModifier->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerNombreBainModifier->Add( m_spinCtrlNombreBainModifier, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainModifier->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerGestionBainModifier->Add( bSizerNombreBainModifier, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	bSizerModifierBain = new wxBoxSizer( wxVERTICAL );
	
	bSizerBainModifierDuree = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerModifierDureeBain1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerModifierDureeBain1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticModifierDureeTotalBain1 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT("Durée du bain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifierDureeTotalBain1->Wrap( -1 );
	bSizerModifierDureeBain1->Add( m_staticModifierDureeTotalBain1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxString m_choiceModifierBain1Choices[] = { wxT("1"), wxT("2"), wxT("3") };
	int m_choiceModifierBain1NChoices = sizeof( m_choiceModifierBain1Choices ) / sizeof( wxString );
	m_choiceModifierBain1 = new wxChoice( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceModifierBain1NChoices, m_choiceModifierBain1Choices, wxCB_SORT );
	m_choiceModifierBain1->SetSelection( 0 );
	m_choiceModifierBain1->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerModifierDureeBain1->Add( m_choiceModifierBain1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_staticModifierBain1 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(" : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifierBain1->Wrap( -1 );
	bSizerModifierDureeBain1->Add( m_staticModifierBain1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_textCtrlModifierHeureBain1 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierHeureBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierHeureBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierHeureBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierHeureBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain1->Add( m_textCtrlModifierHeureBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextModifierDureeBain1 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextModifierDureeBain1->Wrap( -1 );
	bSizerModifierDureeBain1->Add( m_staticTextModifierDureeBain1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlModifierMinuteBain1 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierMinuteBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierMinuteBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierMinuteBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierMinuteBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain1->Add( m_textCtrlModifierMinuteBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextModifierDureeFinBain1 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextModifierDureeFinBain1->Wrap( -1 );
	bSizerModifierDureeBain1->Add( m_staticTextModifierDureeFinBain1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlModifierSecondeBain1 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierSecondeBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierSecondeBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierSecondeBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierSecondeBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain1->Add( m_textCtrlModifierSecondeBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerModifierDureeBain1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerBainModifierDuree->Add( bSizerModifierDureeBain1, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	bSizerModifierDureeBain2 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerModifierDureeBain2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticModifierDureeTotalBain2 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT("Durée du bain "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifierDureeTotalBain2->Wrap( -1 );
	m_staticModifierDureeTotalBain2->Hide();
	
	bSizerModifierDureeBain2->Add( m_staticModifierDureeTotalBain2, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxString m_choiceModifierBain2Choices[] = { wxT("1"), wxT("2"), wxT("3") };
	int m_choiceModifierBain2NChoices = sizeof( m_choiceModifierBain2Choices ) / sizeof( wxString );
	m_choiceModifierBain2 = new wxChoice( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceModifierBain2NChoices, m_choiceModifierBain2Choices, wxCB_SORT );
	m_choiceModifierBain2->SetSelection( 1 );
	m_choiceModifierBain2->Hide();
	m_choiceModifierBain2->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerModifierDureeBain2->Add( m_choiceModifierBain2, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxTOP, 5 );
	
	m_staticModifierBain2 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(" : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifierBain2->Wrap( -1 );
	m_staticModifierBain2->Hide();
	
	bSizerModifierDureeBain2->Add( m_staticModifierBain2, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_textCtrlModifierHeureBain2 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierHeureBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierHeureBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierHeureBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierHeureBain2->Hide();
	m_textCtrlModifierHeureBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain2->Add( m_textCtrlModifierHeureBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextModifierDureeBain2 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextModifierDureeBain2->Wrap( -1 );
	m_staticTextModifierDureeBain2->Hide();
	
	bSizerModifierDureeBain2->Add( m_staticTextModifierDureeBain2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlModifierMinuteBain2 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierMinuteBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierMinuteBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierMinuteBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierMinuteBain2->Hide();
	m_textCtrlModifierMinuteBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain2->Add( m_textCtrlModifierMinuteBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextModifierDureeFinBain2 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextModifierDureeFinBain2->Wrap( -1 );
	m_staticTextModifierDureeFinBain2->Hide();
	
	bSizerModifierDureeBain2->Add( m_staticTextModifierDureeFinBain2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlModifierSecondeBain2 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierSecondeBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierSecondeBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierSecondeBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierSecondeBain2->Hide();
	m_textCtrlModifierSecondeBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain2->Add( m_textCtrlModifierSecondeBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerModifierDureeBain2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerBainModifierDuree->Add( bSizerModifierDureeBain2, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerModifierBain->Add( bSizerBainModifierDuree, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerModifierBain->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerModifierDureeBain3 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerModifierDureeBain3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticModifierDureeTotalBain3 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT("Durée du bain "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifierDureeTotalBain3->Wrap( -1 );
	m_staticModifierDureeTotalBain3->Hide();
	
	bSizerModifierDureeBain3->Add( m_staticModifierDureeTotalBain3, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxString m_choiceModifierBain3Choices[] = { wxT("1"), wxT("2"), wxT("3") };
	int m_choiceModifierBain3NChoices = sizeof( m_choiceModifierBain3Choices ) / sizeof( wxString );
	m_choiceModifierBain3 = new wxChoice( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceModifierBain3NChoices, m_choiceModifierBain3Choices, wxCB_SORT );
	m_choiceModifierBain3->SetSelection( 2 );
	m_choiceModifierBain3->Hide();
	m_choiceModifierBain3->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerModifierDureeBain3->Add( m_choiceModifierBain3, 0, wxALIGN_TOP, 5 );
	
	m_staticModifierBain3 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(" : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifierBain3->Wrap( -1 );
	m_staticModifierBain3->Hide();
	
	bSizerModifierDureeBain3->Add( m_staticModifierBain3, 0, wxTOP|wxBOTTOM, 5 );
	
	m_textCtrlModifierHeureBain3 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierHeureBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierHeureBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierHeureBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierHeureBain3->Hide();
	m_textCtrlModifierHeureBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain3->Add( m_textCtrlModifierHeureBain3, 1, 0, 5 );
	
	m_staticTextModifierDureeBain3 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextModifierDureeBain3->Wrap( -1 );
	m_staticTextModifierDureeBain3->Hide();
	
	bSizerModifierDureeBain3->Add( m_staticTextModifierDureeBain3, 0, wxALL, 5 );
	
	m_textCtrlModifierMinuteBain3 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierMinuteBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierMinuteBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierMinuteBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierMinuteBain3->Hide();
	m_textCtrlModifierMinuteBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain3->Add( m_textCtrlModifierMinuteBain3, 1, 0, 5 );
	
	m_staticTextModifierDureeFinBain3 = new wxStaticText( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextModifierDureeFinBain3->Wrap( -1 );
	m_staticTextModifierDureeFinBain3->Hide();
	
	bSizerModifierDureeBain3->Add( m_staticTextModifierDureeFinBain3, 0, wxALL, 5 );
	
	m_textCtrlModifierSecondeBain3 = new wxTextCtrl( sbSizerGestionBainModifier->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlModifierSecondeBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlModifierSecondeBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlModifierSecondeBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlModifierSecondeBain3->Hide();
	m_textCtrlModifierSecondeBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerModifierDureeBain3->Add( m_textCtrlModifierSecondeBain3, 1, 0, 5 );
	
	
	bSizerModifierDureeBain3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierBain->Add( bSizerModifierDureeBain3, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizerGestionBainModifier->Add( bSizerModifierBain, 2, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerModificationDroite->Add( sbSizerGestionBainModifier, 2, wxALIGN_CENTER|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerModificationPrincipal->Add( bSizerModificationDroite, 1, wxEXPAND, 5 );
	
	
	sbSizerModifier->Add( bSizerModificationPrincipal, 1, wxEXPAND, 5 );
	
	m_staticline10 = new wxStaticLine( sbSizerModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizerModifier->Add( m_staticline10, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	m_sdbSizerModifier = new wxStdDialogButtonSizer();
	m_sdbSizerModifierApply = new wxButton( sbSizerModifier->GetStaticBox(), wxID_APPLY );
	m_sdbSizerModifier->AddButton( m_sdbSizerModifierApply );
	m_sdbSizerModifierCancel = new wxButton( sbSizerModifier->GetStaticBox(), wxID_CANCEL );
	m_sdbSizerModifier->AddButton( m_sdbSizerModifierCancel );
	m_sdbSizerModifier->Realize();
	
	sbSizerModifier->Add( m_sdbSizerModifier, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerModifierProcessus->Add( sbSizerModifier, 1, wxALL|wxEXPAND, 5 );
	
	
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
	
	wxBoxSizer* bSizerOrdresTrajectoiresCreer;
	bSizerOrdresTrajectoiresCreer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdresTrajectoiresCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresCreer = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires :\nséparé par ;"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextOrdreTrajectoiresCreer->Wrap( -1 );
	bSizerOrdresTrajectoiresCreer->Add( m_staticTextOrdreTrajectoiresCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlOrdreTrajectoiresCreer = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ORDRE_CREER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlOrdreTrajectoiresCreer->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlOrdreTrajectoiresCreer->SetMaxLength( 20 );
	}
	#else
	m_textCtrlOrdreTrajectoiresCreer->SetMaxLength( 20 );
	#endif
	bSizerOrdresTrajectoiresCreer->Add( m_textCtrlOrdreTrajectoiresCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdresTrajectoiresCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerGauche->Add( bSizerOrdresTrajectoiresCreer, 1, wxALL|wxEXPAND, 5 );
	
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
	
	sbSizerGestionBainCreer = new wxStaticBoxSizer( new wxStaticBox( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Gestion des bains") ), wxVERTICAL );
	
	bSizerNombreBainCreer = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNombreBainCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNombreBainCreer = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT("Nombre de bain :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainCreer->Wrap( -1 );
	bSizerNombreBainCreer->Add( m_staticTextNombreBainCreer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrlNombreBainCreer = new wxSpinCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 3, 1 );
	m_spinCtrlNombreBainCreer->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerNombreBainCreer->Add( m_spinCtrlNombreBainCreer, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainCreer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerGestionBainCreer->Add( bSizerNombreBainCreer, 1, wxALL|wxEXPAND, 5 );
	
	bSizerCreerBain = new wxBoxSizer( wxVERTICAL );
	
	bSizerBainCreerDuree = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCreerDureeBain1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerCreerDureeBain1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticCreerDureeTotalBain1 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT("Durée du bain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCreerDureeTotalBain1->Wrap( -1 );
	bSizerCreerDureeBain1->Add( m_staticCreerDureeTotalBain1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxString m_choiceCreerBain1Choices[] = { wxT("1"), wxT("2"), wxT("3") };
	int m_choiceCreerBain1NChoices = sizeof( m_choiceCreerBain1Choices ) / sizeof( wxString );
	m_choiceCreerBain1 = new wxChoice( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCreerBain1NChoices, m_choiceCreerBain1Choices, wxCB_SORT );
	m_choiceCreerBain1->SetSelection( 0 );
	m_choiceCreerBain1->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerCreerDureeBain1->Add( m_choiceCreerBain1, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticCreerBain1 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(" : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCreerBain1->Wrap( -1 );
	bSizerCreerDureeBain1->Add( m_staticCreerBain1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_textCtrlCreerHeureBain1 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerHeureBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerHeureBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerHeureBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerHeureBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain1->Add( m_textCtrlCreerHeureBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextCreerDureeBain1 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCreerDureeBain1->Wrap( -1 );
	bSizerCreerDureeBain1->Add( m_staticTextCreerDureeBain1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlCreerMinuteBain1 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerMinuteBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerMinuteBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerMinuteBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerMinuteBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain1->Add( m_textCtrlCreerMinuteBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextcreerDureeFinBain1 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextcreerDureeFinBain1->Wrap( -1 );
	bSizerCreerDureeBain1->Add( m_staticTextcreerDureeFinBain1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlCreerSecondeBain1 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerSecondeBain1->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerSecondeBain1->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerSecondeBain1->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerSecondeBain1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain1->Add( m_textCtrlCreerSecondeBain1, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerCreerDureeBain1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerBainCreerDuree->Add( bSizerCreerDureeBain1, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	bSizerCreerDureeBain2 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerCreerDureeBain2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticCreerDureeTotalBain2 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT("Durée du bain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCreerDureeTotalBain2->Wrap( -1 );
	m_staticCreerDureeTotalBain2->Hide();
	
	bSizerCreerDureeBain2->Add( m_staticCreerDureeTotalBain2, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxString m_choiceCreerBain2Choices[] = { wxT("1"), wxT("2"), wxT("3") };
	int m_choiceCreerBain2NChoices = sizeof( m_choiceCreerBain2Choices ) / sizeof( wxString );
	m_choiceCreerBain2 = new wxChoice( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCreerBain2NChoices, m_choiceCreerBain2Choices, wxCB_SORT );
	m_choiceCreerBain2->SetSelection( 1 );
	m_choiceCreerBain2->Hide();
	m_choiceCreerBain2->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerCreerDureeBain2->Add( m_choiceCreerBain2, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticCreerBain2 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(" : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCreerBain2->Wrap( -1 );
	m_staticCreerBain2->Hide();
	
	bSizerCreerDureeBain2->Add( m_staticCreerBain2, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlCreerHeureBain2 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerHeureBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerHeureBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerHeureBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerHeureBain2->Hide();
	m_textCtrlCreerHeureBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain2->Add( m_textCtrlCreerHeureBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextCreerDureeBain2 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCreerDureeBain2->Wrap( -1 );
	m_staticTextCreerDureeBain2->Hide();
	
	bSizerCreerDureeBain2->Add( m_staticTextCreerDureeBain2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlCreerMinuteBain2 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerMinuteBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerMinuteBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerMinuteBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerMinuteBain2->Hide();
	m_textCtrlCreerMinuteBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain2->Add( m_textCtrlCreerMinuteBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextCreerDureeFinBain2 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCreerDureeFinBain2->Wrap( -1 );
	m_staticTextCreerDureeFinBain2->Hide();
	
	bSizerCreerDureeBain2->Add( m_staticTextCreerDureeFinBain2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlCreerSecondeBain2 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerSecondeBain2->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerSecondeBain2->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerSecondeBain2->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerSecondeBain2->Hide();
	m_textCtrlCreerSecondeBain2->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain2->Add( m_textCtrlCreerSecondeBain2, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerCreerDureeBain2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerBainCreerDuree->Add( bSizerCreerDureeBain2, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerCreerBain->Add( bSizerBainCreerDuree, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCreerBain->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerCreerDureeBain3 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerCreerDureeBain3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticCreerDureeTotalBain3 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT("Durée du bain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCreerDureeTotalBain3->Wrap( -1 );
	m_staticCreerDureeTotalBain3->Hide();
	
	bSizerCreerDureeBain3->Add( m_staticCreerDureeTotalBain3, 0, wxALL, 5 );
	
	wxString m_choiceCreerBain3Choices[] = { wxT("1"), wxT("2"), wxT("3") };
	int m_choiceCreerBain3NChoices = sizeof( m_choiceCreerBain3Choices ) / sizeof( wxString );
	m_choiceCreerBain3 = new wxChoice( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCreerBain3NChoices, m_choiceCreerBain3Choices, wxCB_SORT );
	m_choiceCreerBain3->SetSelection( 2 );
	m_choiceCreerBain3->Hide();
	m_choiceCreerBain3->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizerCreerDureeBain3->Add( m_choiceCreerBain3, 0, wxALIGN_TOP, 5 );
	
	m_staticCreerBain3 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(" : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCreerBain3->Wrap( -1 );
	m_staticCreerBain3->Hide();
	
	bSizerCreerDureeBain3->Add( m_staticCreerBain3, 0, wxTOP|wxBOTTOM, 5 );
	
	m_textCtrlCreerHeureBain3 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerHeureBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerHeureBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerHeureBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerHeureBain3->Hide();
	m_textCtrlCreerHeureBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain3->Add( m_textCtrlCreerHeureBain3, 1, 0, 5 );
	
	m_staticTextCreerDureeBain3 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCreerDureeBain3->Wrap( -1 );
	m_staticTextCreerDureeBain3->Hide();
	
	bSizerCreerDureeBain3->Add( m_staticTextCreerDureeBain3, 0, wxALL, 5 );
	
	m_textCtrlCreerMinuteBain3 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerMinuteBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerMinuteBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerMinuteBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerMinuteBain3->Hide();
	m_textCtrlCreerMinuteBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain3->Add( m_textCtrlCreerMinuteBain3, 1, 0, 5 );
	
	m_staticTextCreerDureeFinBain3 = new wxStaticText( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCreerDureeFinBain3->Wrap( -1 );
	m_staticTextCreerDureeFinBain3->Hide();
	
	bSizerCreerDureeBain3->Add( m_staticTextCreerDureeFinBain3, 0, wxALL, 5 );
	
	m_textCtrlCreerSecondeBain3 = new wxTextCtrl( sbSizerGestionBainCreer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	#ifdef __WXGTK__
	if ( !m_textCtrlCreerSecondeBain3->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCreerSecondeBain3->SetMaxLength( 2 );
	}
	#else
	m_textCtrlCreerSecondeBain3->SetMaxLength( 2 );
	#endif
	m_textCtrlCreerSecondeBain3->Hide();
	m_textCtrlCreerSecondeBain3->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerCreerDureeBain3->Add( m_textCtrlCreerSecondeBain3, 1, 0, 5 );
	
	
	bSizerCreerDureeBain3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerBain->Add( bSizerCreerDureeBain3, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizerGestionBainCreer->Add( bSizerCreerBain, 2, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerCreerDroite->Add( sbSizerGestionBainCreer, 1, wxEXPAND, 5 );
	
	
	sbSizerCreer->Add( bSizerCreerDroite, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCreerProcessus->Add( sbSizerCreer, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerCreer = new wxStdDialogButtonSizer();
	m_sdbSizerCreerSave = new wxButton( m_scrolledWindowCreerProcessus, wxID_SAVE );
	m_sdbSizerCreer->AddButton( m_sdbSizerCreerSave );
	m_sdbSizerCreerCancel = new wxButton( m_scrolledWindowCreerProcessus, wxID_CANCEL );
	m_sdbSizerCreer->AddButton( m_sdbSizerCreerCancel );
	m_sdbSizerCreer->Realize();
	
	bSizerCreerProcessus->Add( m_sdbSizerCreer, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
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
	m_listBoxDetruireProcessus = new wxListBox( sbSizerSelectionProcessusDetruire->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_SINGLE ); 
	sbSizerSelectionProcessusDetruire->Add( m_listBoxDetruireProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerDetruireProcessus->Add( sbSizerSelectionProcessusDetruire, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerDetruire;
	sbSizerDetruire = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireProcessus, wxID_ANY, wxT("Détruire") ), wxVERTICAL );
	
	wxBoxSizer* bSizerTitreDetruire;
	bSizerTitreDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Vous allez détruire le processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDetruire->Wrap( -1 );
	m_staticTextDetruire->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerTitreDetruire->Add( m_staticTextDetruire, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextDetuireTitre = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDetuireTitre->Wrap( -1 );
	m_staticTextDetuireTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerTitreDetruire->Add( m_staticTextDetuireTitre, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizerDetruire->Add( bSizerTitreDetruire, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizerDetailDetruire;
	bSizerDetailDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerDetruireDroit;
	bSizerDetruireDroit = new wxBoxSizer( wxVERTICAL );
	
	bSizerDureeTotalDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeTotalProcessusDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Durée total : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalProcessusDetruire->Wrap( -1 );
	bSizerDureeTotalDetruire->Add( m_staticTextDureeTotalProcessusDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalValeurDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
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
	
	m_staticTextNombreBainValeurDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainValeurDetruire->Wrap( -1 );
	bSizerNombreBainDetruire->Add( m_staticTextNombreBainValeurDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerDetruireGauche->Add( bSizerNombreBainDetruire, 1, wxEXPAND, 5 );
	
	bSizerOrdreTrajectoiresDetruire = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdreTrajectoiresDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresDetruire = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresDetruire->Wrap( -1 );
	bSizerOrdreTrajectoiresDetruire->Add( m_staticTextOrdreTrajectoiresDetruire, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextOrdreTrajectoiresDetruireValeur = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresDetruireValeur->Wrap( -1 );
	bSizerOrdreTrajectoiresDetruire->Add( m_staticTextOrdreTrajectoiresDetruireValeur, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdreTrajectoiresDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerDetruireGauche->Add( bSizerOrdreTrajectoiresDetruire, 1, wxEXPAND, 5 );
	
	
	bSizerDetailDetruire->Add( bSizerDetruireGauche, 1, wxEXPAND, 5 );
	
	
	sbSizerDetruire->Add( bSizerDetailDetruire, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineSeparateurDetailBoutonDetruire = new wxStaticLine( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizerDetruire->Add( m_staticlineSeparateurDetailBoutonDetruire, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
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
	m_listBoxLancerProcessus = new wxListBox( sbSizerSelectionProcessusLancer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_SINGLE ); 
	sbSizerSelectionProcessusLancer->Add( m_listBoxLancerProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerLancerProcessus->Add( sbSizerSelectionProcessusLancer, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerLancement;
	sbSizerLancement = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowLancerProcessus, wxID_ANY, wxT("Lancer le processus") ), wxVERTICAL );
	
	wxBoxSizer* bSizerTitreLancer;
	bSizerTitreLancer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("Vous allez lancer la fabrication du processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLancer->Wrap( -1 );
	m_staticTextLancer->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerTitreLancer->Add( m_staticTextLancer, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextLancerTitre = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLancerTitre->Wrap( -1 );
	m_staticTextLancerTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerTitreLancer->Add( m_staticTextLancerTitre, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizerLancement->Add( bSizerTitreLancer, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
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
	
	m_staticTextNombreBainValeurLancer = new wxStaticText( sbSizerLancement->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
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
	sbSizerLancement->Add( m_staticlineSeparateurDetailBoutonLancer, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
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
	sbSizerSelectionProcessusTester = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowTesterProcessus, wxID_ANY, wxT("Sélection du processus à tester") ), wxVERTICAL );
	
	sbSizerSelectionProcessusTester->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxTesterProcessus = new wxListBox( sbSizerSelectionProcessusTester->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_SINGLE ); 
	sbSizerSelectionProcessusTester->Add( m_listBoxTesterProcessus, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerTesterProcessus->Add( sbSizerSelectionProcessusTester, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTester;
	sbSizerTester = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowTesterProcessus, wxID_ANY, wxT("Tester le processus") ), wxVERTICAL );
	
	wxBoxSizer* bSizerTitreTester;
	bSizerTitreTester = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Vous allez lancer le test du processus : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTester->Wrap( -1 );
	m_staticTextTester->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerTitreTester->Add( m_staticTextTester, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticTextTesterTitre = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Processus 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTesterTitre->Wrap( -1 );
	m_staticTextTesterTitre->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerTitreTester->Add( m_staticTextTesterTitre, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizerTester->Add( bSizerTitreTester, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizerDetailTester = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerTesterDroit = new wxBoxSizer( wxVERTICAL );
	
	bSizerDureeTotalTester = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeTotalTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeTotalProcessusTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Durée total : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeTotalProcessusTester->Wrap( -1 );
	bSizerDureeTotalTester->Add( m_staticTextDureeTotalProcessusTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeTotalValeurTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
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
	
	m_staticTextNombreBainValeurTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNombreBainValeurTester->Wrap( -1 );
	bSizerNombreBainTester->Add( m_staticTextNombreBainValeurTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNombreBainTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTesterGauche->Add( bSizerNombreBainTester, 1, wxEXPAND, 5 );
	
	bSizerOrdreTrajectoiresTester = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOrdreTrajectoiresTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextOrdreTrajectoiresTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Ordre des trajectoires : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresTester->Wrap( -1 );
	bSizerOrdreTrajectoiresTester->Add( m_staticTextOrdreTrajectoiresTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextOrdreTrajectoiresValeurTester = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOrdreTrajectoiresValeurTester->Wrap( -1 );
	bSizerOrdreTrajectoiresTester->Add( m_staticTextOrdreTrajectoiresValeurTester, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerOrdreTrajectoiresTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerTesterGauche->Add( bSizerOrdreTrajectoiresTester, 1, wxEXPAND, 5 );
	
	
	bSizerDetailTester->Add( bSizerTesterGauche, 1, wxEXPAND, 5 );
	
	
	sbSizerTester->Add( bSizerDetailTester, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineSeparateurDetailBoutonsTester = new wxStaticLine( sbSizerTester->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizerTester->Add( m_staticlineSeparateurDetailBoutonsTester, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizerButonTester;
	bSizerButonTester = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButtonStopTester = new wxBitmapButton( sbSizerTester->GetStaticBox(), wxID_ANY, wxBitmap( wxT("../Images/stop_petit.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizerButonTester->Add( m_bpButtonStopTester, 0, wxALIGN_BOTTOM|wxTOP|wxRIGHT, 3 );
	
	m_bpButtonOKTester = new wxBitmapButton( sbSizerTester->GetStaticBox(), wxID_ANY, wxBitmap( wxT("../Images/ok-button-petit.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizerButonTester->Add( m_bpButtonOKTester, 0, wxALIGN_BOTTOM|wxTOP|wxLEFT, 3 );
	
	
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
	
	sbSizerTache = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowInfoBras, wxID_ANY, wxT("Tâche en cours") ), wxVERTICAL );
	
	
	sbSizerTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerTypeTache = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerTypeTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextTypeTache = new wxStaticText( sbSizerTache->GetStaticBox(), wxID_ANY, wxT("Type de tâche : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTypeTache->Wrap( -1 );
	m_staticTextTypeTache->Hide();
	
	bSizerTypeTache->Add( m_staticTextTypeTache, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlTypeTache = new wxTextCtrl( sbSizerTache->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlTypeTache->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlTypeTache->SetMaxLength( 11 );
	}
	#else
	m_textCtrlTypeTache->SetMaxLength( 11 );
	#endif
	m_textCtrlTypeTache->Hide();
	
	bSizerTypeTache->Add( m_textCtrlTypeTache, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerTypeTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerTache->Add( bSizerTypeTache, 1, wxEXPAND, 5 );
	
	
	sbSizerTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerNomTache = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomTache = new wxStaticText( sbSizerTache->GetStaticBox(), wxID_ANY, wxT("Veuillez demander la tâche en cours."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomTache->Wrap( -1 );
	bSizerNomTache->Add( m_staticTextNomTache, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomTache = new wxTextCtrl( sbSizerTache->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlNomTache->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlNomTache->SetMaxLength( 100 );
	}
	#else
	m_textCtrlNomTache->SetMaxLength( 100 );
	#endif
	m_textCtrlNomTache->Hide();
	
	bSizerNomTache->Add( m_textCtrlNomTache, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerTache->Add( bSizerNomTache, 1, wxEXPAND, 5 );
	
	
	sbSizerTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerDureeRestant = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeRestant->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticDureeRestant = new wxStaticText( sbSizerTache->GetStaticBox(), wxID_ANY, wxT("Durée total :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDureeRestant->Wrap( -1 );
	m_staticDureeRestant->Hide();
	
	bSizerDureeRestant->Add( m_staticDureeRestant, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeRestantHeure = new wxTextCtrl( sbSizerTache->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeRestantHeure->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeRestantHeure->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeRestantHeure->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeRestantHeure->Hide();
	m_textCtrlDureeRestantHeure->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeRestant->Add( m_textCtrlDureeRestantHeure, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeRestantMinute = new wxStaticText( sbSizerTache->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeRestantMinute->Wrap( -1 );
	m_staticTextDureeRestantMinute->Hide();
	
	bSizerDureeRestant->Add( m_staticTextDureeRestantMinute, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeRestantMinute = new wxTextCtrl( sbSizerTache->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeRestantMinute->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeRestantMinute->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeRestantMinute->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeRestantMinute->Hide();
	m_textCtrlDureeRestantMinute->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeRestant->Add( m_textCtrlDureeRestantMinute, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeRestantSeconde = new wxStaticText( sbSizerTache->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeRestantSeconde->Wrap( -1 );
	m_staticTextDureeRestantSeconde->Hide();
	
	bSizerDureeRestant->Add( m_staticTextDureeRestantSeconde, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeRestantSeconde = new wxTextCtrl( sbSizerTache->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlDureeRestantSeconde->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlDureeRestantSeconde->SetMaxLength( 2 );
	}
	#else
	m_textCtrlDureeRestantSeconde->SetMaxLength( 2 );
	#endif
	m_textCtrlDureeRestantSeconde->Hide();
	m_textCtrlDureeRestantSeconde->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeRestant->Add( m_textCtrlDureeRestantSeconde, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeRestant->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerTache->Add( bSizerDureeRestant, 1, wxEXPAND, 5 );
	
	
	sbSizerTache->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerInfos->Add( sbSizerTache, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerInfoBrasPrincipal->Add( bSizerInfos, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBouttons;
	bSizerBouttons = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerBoutonBras;
	bSizerBoutonBras = new wxBoxSizer( wxVERTICAL );
	
	m_buttonDisponibiliteBras = new wxButton( m_scrolledWindowInfoBras, wxID_ANY, wxT("Demander la disponibilité du bras"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBoutonBras->Add( m_buttonDisponibiliteBras, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerBouttons->Add( bSizerBoutonBras, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBoutonTache;
	bSizerBoutonTache = new wxBoxSizer( wxVERTICAL );
	
	m_buttonTacheEnCours = new wxButton( m_scrolledWindowInfoBras, wxID_ANY, wxT("Demander la tâche en cours"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBoutonTache->Add( m_buttonTacheEnCours, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
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
	m_notebookProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_scrolledWindowAffichageProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_listBoxAffichageProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelection ), NULL, this );
	m_staticTextIdAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlIdAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticDureeTotalAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureAfficher->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextDureeTotalMinuteAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalMinuteAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalMinuteAfficher->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextDureeTotalSecondeAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalSecondeAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalSecondeAfficher->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_listBoxListeTrajectoiresAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextNomAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNomAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNomAfficher->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextOrdreTrajectoiresAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlOrdreTrajectoiresAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlOrdreTrajectoiresAfficher->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextNombreBainAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNombreBainAfficher->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNombreBainAfficher->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherHeureBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherHeureBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherMinuteBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherMinuteBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherSecondeBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherSecondeBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherHeureBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherHeureBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherMinuteBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherMinuteBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherSecondeBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherSecondeBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherHeureBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherHeureBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherMinuteBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherMinuteBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherSecondeBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherSecondeBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_scrolledWindowModifierProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxModifierProcessus->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_listBoxModifierProcessus->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlNomModifier->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlNomModifier->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_spinCtrlNombreBainModifier->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FramePrincipal::OnSpinCtrlModifierBain ), NULL, this );
	m_textCtrlModifierHeureBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierHeureBain1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierHeureBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierMinuteBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierMinuteBain1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierMinuteBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierSecondeBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierSecondeBain1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierSecondeBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierHeureBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierHeureBain2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierHeureBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierMinuteBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierMinuteBain2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierMinuteBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierSecondeBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierSecondeBain2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierSecondeBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierHeureBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierHeureBain3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierHeureBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierMinuteBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierMinuteBain3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierMinuteBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierSecondeBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierSecondeBain3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierSecondeBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_sdbSizerModifierApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_sdbSizerModifierCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModiffierClick ), NULL, this );
	m_scrolledWindowCreerProcessus->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlNomCreer->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlNomCreer->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_spinCtrlNombreBainCreer->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FramePrincipal::OnSpinCtrlCreerBain ), NULL, this );
	m_textCtrlCreerHeureBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerHeureBain1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerHeureBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerMinuteBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerMinuteBain1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerMinuteBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerSecondeBain1->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerSecondeBain1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerSecondeBain1->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerHeureBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerHeureBain2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerHeureBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerMinuteBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerMinuteBain2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerMinuteBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerSecondeBain2->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerSecondeBain2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerSecondeBain2->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerHeureBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerHeureBain3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerHeureBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerMinuteBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerMinuteBain3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerMinuteBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerSecondeBain3->Connect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerSecondeBain3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerSecondeBain3->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
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
	m_staticTextLogin->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlLogin->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlLogin->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextPass->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
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
	m_textCtrlDureeTotalHeureAfficher->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextDureeTotalMinuteAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalMinuteAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalMinuteAfficher->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextDureeTotalSecondeAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalSecondeAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalSecondeAfficher->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_listBoxListeTrajectoiresAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_staticTextNomAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNomAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNomAfficher->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextOrdreTrajectoiresAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlOrdreTrajectoiresAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlOrdreTrajectoiresAfficher->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_staticTextNombreBainAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNombreBainAfficher->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlNombreBainAfficher->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherHeureBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherHeureBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherMinuteBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherMinuteBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherSecondeBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherSecondeBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherHeureBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherHeureBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherMinuteBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherMinuteBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherSecondeBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherSecondeBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherHeureBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherHeureBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherMinuteBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherMinuteBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlAfficherSecondeBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlAfficherSecondeBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_scrolledWindowModifierProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_listBoxModifierProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_listBoxModifierProcessus->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelection ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlDureeTotalHeureModifier->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlDureeTotalMinuteModifier->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlDureeTotalSecondeModifier->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlNomModifier->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlNomModifier->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlOrdreTrajectoiresModifier->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_spinCtrlNombreBainModifier->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FramePrincipal::OnSpinCtrlModifierBain ), NULL, this );
	m_textCtrlModifierHeureBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierHeureBain1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierHeureBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierMinuteBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierMinuteBain1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierMinuteBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierSecondeBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierSecondeBain1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierSecondeBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierHeureBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierHeureBain2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierHeureBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierMinuteBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierMinuteBain2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierMinuteBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierSecondeBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierSecondeBain2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierSecondeBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierHeureBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierHeureBain3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierHeureBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierMinuteBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierMinuteBain3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierMinuteBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlModifierSecondeBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlModifierSecondeBain3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_textCtrlModifierSecondeBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_sdbSizerModifierApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierClick ), NULL, this );
	m_sdbSizerModifierCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModiffierClick ), NULL, this );
	m_scrolledWindowCreerProcessus->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEntered ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlDureeTotalHeureCreer->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlDureeTotalMinuteCreer->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlDureeTotalSecondeCreer->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredOrdre ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlOrdreTrajectoiresCreer->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlNomCreer->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlNomCreer->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_spinCtrlNombreBainCreer->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FramePrincipal::OnSpinCtrlCreerBain ), NULL, this );
	m_textCtrlCreerHeureBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerHeureBain1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerHeureBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerMinuteBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerMinuteBain1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerMinuteBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerSecondeBain1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerSecondeBain1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerSecondeBain1->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerHeureBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerHeureBain2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerHeureBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerMinuteBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerMinuteBain2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerMinuteBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerSecondeBain2->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerSecondeBain2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerSecondeBain2->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerHeureBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerHeureBain3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerHeureBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerMinuteBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerMinuteBain3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerMinuteBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
	m_textCtrlCreerSecondeBain3->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FramePrincipal::OnCharEnteredNum ), NULL, this );
	m_textCtrlCreerSecondeBain3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerClick ), NULL, this );
	m_textCtrlCreerSecondeBain3->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( FramePrincipal::OnTextMaxLength ), NULL, this );
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
