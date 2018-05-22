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
	
	m_staticTextLogin = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre login : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLogin->Wrap( -1 );
	bSizerLogin->Add( m_staticTextLogin, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlLogin = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Régleur"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	bSizerLogin->Add( m_textCtrlLogin, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerLogin->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizerLogin, 1, wxALIGN_TOP|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizerPass;
	bSizerPass = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextPass = new wxStaticText( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Entrez votre mot de passe : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPass->Wrap( -1 );
	bSizerPass->Add( m_staticTextPass, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlPass = new wxTextCtrl( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("regleur"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PASSWORD|wxTE_PROCESS_ENTER );
	bSizerPass->Add( m_textCtrlPass, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerPass->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerConnexion->Add( bSizerPass, 1, wxALIGN_BOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_toggleBtnConnexion = new wxToggleButton( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxT("Connexion"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnexion->Add( m_toggleBtnConnexion, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_panelChoix = new wxPanel( sbSizerConnexion->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelChoix->Hide();
	
	wxBoxSizer* bSizerChoixPrincipal;
	bSizerChoixPrincipal = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerChoix;
	bSizerChoix = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonChoixTrajectoires = new wxButton( m_panelChoix, wxID_ANY, wxT("Gestion Trajectoires"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerChoix->Add( m_buttonChoixTrajectoires, 0, wxALL, 5 );
	
	m_buttonChoixMouvements = new wxButton( m_panelChoix, wxID_ANY, wxT("Gestion Mouvements"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerChoix->Add( m_buttonChoixMouvements, 0, wxALL, 5 );
	
	
	bSizerChoixPrincipal->Add( bSizerChoix, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panelChoix->SetSizer( bSizerChoixPrincipal );
	m_panelChoix->Layout();
	bSizerChoixPrincipal->Fit( m_panelChoix );
	sbSizerConnexion->Add( m_panelChoix, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizerConnexion->Add( sbSizerConnexion, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panelConnexion->SetSizer( bSizerConnexion );
	m_panelConnexion->Layout();
	bSizerConnexion->Fit( m_panelConnexion );
	bSizerPrincipal->Add( m_panelConnexion, 0, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_notebookMouvements = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_notebookMouvements->Hide();
	
	m_scrolledWindowAffichageMouvements = new wxScrolledWindow( m_notebookMouvements, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowAffichageMouvements->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerAfficherMouvements;
	bSizerAfficherMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionAfficherMouvements;
	sbSizerSelectionAfficherMouvements = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageMouvements, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionAfficherMouvements->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxAffichageMouvements = new wxListBox( sbSizerSelectionAfficherMouvements->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxAffichageMouvements->Append( wxT("Mouvement 1") );
	m_listBoxAffichageMouvements->Append( wxT("Mouvement 2") );
	m_listBoxAffichageMouvements->Append( wxT("Mouvement 3") );
	m_listBoxAffichageMouvements->Append( wxT("Mouvement 4") );
	sbSizerSelectionAfficherMouvements->Add( m_listBoxAffichageMouvements, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerAfficherMouvements->Add( sbSizerSelectionAfficherMouvements, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerAfficher;
	sbSizerAfficher = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageMouvements, wxID_ANY, wxT("Affichage") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizerAfficherGaucheMouvements;
	bSizerAfficherGaucheMouvements = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomAffichageMouvements;
	bSizerNomAffichageMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomAffichageMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomAfficherMouvements = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Nom du Mouvement :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomAfficherMouvements->Wrap( -1 );
	bSizerNomAffichageMouvements->Add( m_staticTextNomAfficherMouvements, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomAfficherMouvements = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Mouvement 1"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizerNomAffichageMouvements->Add( m_textCtrlNomAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomAffichageMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherGaucheMouvements->Add( bSizerNomAffichageMouvements, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNomAffichageMouvements1;
	bSizerNomAffichageMouvements1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomAffichageMouvements1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeHeureAfficherMouvements1 = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Durée :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeHeureAfficherMouvements1->Wrap( -1 );
	bSizerNomAffichageMouvements1->Add( m_staticTextDureeHeureAfficherMouvements1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeHeureAfficherMouvements1 = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlDureeHeureAfficherMouvements1->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureAfficherMouvements1->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomAffichageMouvements1->Add( m_textCtrlDureeHeureAfficherMouvements1, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeMinuteAfficherMouvements = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT(" :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeMinuteAfficherMouvements->Wrap( -1 );
	bSizerNomAffichageMouvements1->Add( m_staticTextDureeMinuteAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeHeureAfficherMouvements11 = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlDureeHeureAfficherMouvements11->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureAfficherMouvements11->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomAffichageMouvements1->Add( m_textCtrlDureeHeureAfficherMouvements11, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeSecondeAfficherMouvements = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeSecondeAfficherMouvements->Wrap( -1 );
	bSizerNomAffichageMouvements1->Add( m_staticTextDureeSecondeAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeHeureAfficherMouvements12 = new wxTextCtrl( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlDureeHeureAfficherMouvements12->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureAfficherMouvements12->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomAffichageMouvements1->Add( m_textCtrlDureeHeureAfficherMouvements12, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomAffichageMouvements1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherGaucheMouvements->Add( bSizerNomAffichageMouvements1, 1, wxEXPAND, 5 );
	
	
	sbSizerAfficher->Add( bSizerAfficherGaucheMouvements, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineAfficherMouvements = new wxStaticLine( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizerAfficher->Add( m_staticlineAfficherMouvements, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerAfficherDroiteMouvements;
	bSizerAfficherDroiteMouvements = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerPartieBrasAfficherMouvements;
	bSizerPartieBrasAfficherMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerPartieBrasAfficherMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextPartieBrasAfficheMouvementsr = new wxStaticText( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Sélection de la partie du  bras :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPartieBrasAfficheMouvementsr->Wrap( -1 );
	bSizerPartieBrasAfficherMouvements->Add( m_staticTextPartieBrasAfficheMouvementsr, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choicePartieBrasAfficherMouvementChoices[] = { wxT("Bassin"), wxT("Épaule"), wxT("Coude"), wxT("Poigné") };
	int m_choicePartieBrasAfficherMouvementNChoices = sizeof( m_choicePartieBrasAfficherMouvementChoices ) / sizeof( wxString );
	m_choicePartieBrasAfficherMouvement = new wxChoice( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePartieBrasAfficherMouvementNChoices, m_choicePartieBrasAfficherMouvementChoices, 0 );
	m_choicePartieBrasAfficherMouvement->SetSelection( 0 );
	m_choicePartieBrasAfficherMouvement->Enable( false );
	
	bSizerPartieBrasAfficherMouvements->Add( m_choicePartieBrasAfficherMouvement, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerPartieBrasAfficherMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroiteMouvements->Add( bSizerPartieBrasAfficherMouvements, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCoordonneesAfficherMouvements;
	sbSizerCoordonneesAfficherMouvements = new wxStaticBoxSizer( new wxStaticBox( sbSizerAfficher->GetStaticBox(), wxID_ANY, wxT("Coordonnées") ), wxHORIZONTAL );
	
	
	sbSizerCoordonneesAfficherMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextxAfficherMouvements = new wxStaticText( sbSizerCoordonneesAfficherMouvements->GetStaticBox(), wxID_ANY, wxT("x :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextxAfficherMouvements->Wrap( -1 );
	sbSizerCoordonneesAfficherMouvements->Add( m_staticTextxAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlxAfficherMouvements = new wxTextCtrl( sbSizerCoordonneesAfficherMouvements->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlxAfficherMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlxAfficherMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlxAfficherMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlxAfficherMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlxAfficherMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesAfficherMouvements->Add( m_textCtrlxAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextyAfficherMouvements = new wxStaticText( sbSizerCoordonneesAfficherMouvements->GetStaticBox(), wxID_ANY, wxT("y :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextyAfficherMouvements->Wrap( -1 );
	sbSizerCoordonneesAfficherMouvements->Add( m_staticTextyAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlyAfficherMouvements = new wxTextCtrl( sbSizerCoordonneesAfficherMouvements->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlyAfficherMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlyAfficherMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlyAfficherMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlyAfficherMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlyAfficherMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesAfficherMouvements->Add( m_textCtrlyAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextzAfficherMouvements = new wxStaticText( sbSizerCoordonneesAfficherMouvements->GetStaticBox(), wxID_ANY, wxT("z :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextzAfficherMouvements->Wrap( -1 );
	sbSizerCoordonneesAfficherMouvements->Add( m_staticTextzAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlzAfficherMouvements = new wxTextCtrl( sbSizerCoordonneesAfficherMouvements->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlzAfficherMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlzAfficherMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlzAfficherMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlzAfficherMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlzAfficherMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesAfficherMouvements->Add( m_textCtrlzAfficherMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizerCoordonneesAfficherMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroiteMouvements->Add( sbSizerCoordonneesAfficherMouvements, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizerAfficher->Add( bSizerAfficherDroiteMouvements, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherMouvements->Add( sbSizerAfficher, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowAffichageMouvements->SetSizer( bSizerAfficherMouvements );
	m_scrolledWindowAffichageMouvements->Layout();
	bSizerAfficherMouvements->Fit( m_scrolledWindowAffichageMouvements );
	m_notebookMouvements->AddPage( m_scrolledWindowAffichageMouvements, wxT("Afficher les mouvements"), true );
	m_scrolledWindowModifierMouvements = new wxScrolledWindow( m_notebookMouvements, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowModifierMouvements->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerModifierMouvements;
	bSizerModifierMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionModifierMouvements;
	sbSizerSelectionModifierMouvements = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierMouvements, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionModifierMouvements->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxModifierMouvements = new wxListBox( sbSizerSelectionModifierMouvements->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxModifierMouvements->Append( wxT("Mouvement 1") );
	m_listBoxModifierMouvements->Append( wxT("Mouvement 2") );
	m_listBoxModifierMouvements->Append( wxT("Mouvement 3") );
	m_listBoxModifierMouvements->Append( wxT("Mouvement 4") );
	sbSizerSelectionModifierMouvements->Add( m_listBoxModifierMouvements, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerModifierMouvements->Add( sbSizerSelectionModifierMouvements, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerModifier;
	sbSizerModifier = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierMouvements, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	wxBoxSizer* bSizerModifierPrincipal;
	bSizerModifierPrincipal = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerModifierGaucheMouvements;
	bSizerModifierGaucheMouvements = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomModifierMouvements;
	bSizerNomModifierMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomModifierMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomModifierMouvements = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Nom du Mouvement :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomModifierMouvements->Wrap( -1 );
	bSizerNomModifierMouvements->Add( m_staticTextNomModifierMouvements, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomModifierMouvements = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Mouvement 1"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizerNomModifierMouvements->Add( m_textCtrlNomModifierMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomModifierMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierGaucheMouvements->Add( bSizerNomModifierMouvements, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNomModificationMouvements;
	bSizerNomModificationMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomModificationMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeHeureModifierMouvements = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Durée :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeHeureModifierMouvements->Wrap( -1 );
	bSizerNomModificationMouvements->Add( m_staticTextDureeHeureModifierMouvements, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeHeureModifierMouvements = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeHeureModifierMouvements->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureModifierMouvements->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomModificationMouvements->Add( m_textCtrlDureeHeureModifierMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeMinuteModifierMouvement = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT(" :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeMinuteModifierMouvement->Wrap( -1 );
	bSizerNomModificationMouvements->Add( m_staticTextDureeMinuteModifierMouvement, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeMinutesModifierMouvements = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeMinutesModifierMouvements->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeMinutesModifierMouvements->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomModificationMouvements->Add( m_textCtrlDureeMinutesModifierMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeSecondeModifierMouvements = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeSecondeModifierMouvements->Wrap( -1 );
	bSizerNomModificationMouvements->Add( m_staticTextDureeSecondeModifierMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeSecondeModifierMouvements = new wxTextCtrl( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeSecondeModifierMouvements->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeSecondeModifierMouvements->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomModificationMouvements->Add( m_textCtrlDureeSecondeModifierMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomModificationMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierGaucheMouvements->Add( bSizerNomModificationMouvements, 1, wxEXPAND, 5 );
	
	
	bSizerModifierPrincipal->Add( bSizerModifierGaucheMouvements, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineModifierMouvements = new wxStaticLine( sbSizerModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerModifierPrincipal->Add( m_staticlineModifierMouvements, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerModifierDroiteMouvements;
	bSizerModifierDroiteMouvements = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerPartieBrasModifierMouvements;
	bSizerPartieBrasModifierMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerPartieBrasModifierMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextPartieBrasModifierMouvementsr = new wxStaticText( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Sélection de la partie du  bras :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPartieBrasModifierMouvementsr->Wrap( -1 );
	bSizerPartieBrasModifierMouvements->Add( m_staticTextPartieBrasModifierMouvementsr, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choicePartieBrasModifierMouvementChoices[] = { wxT("Bassin"), wxT("Épaule"), wxT("Coude"), wxT("Poigné") };
	int m_choicePartieBrasModifierMouvementNChoices = sizeof( m_choicePartieBrasModifierMouvementChoices ) / sizeof( wxString );
	m_choicePartieBrasModifierMouvement = new wxChoice( sbSizerModifier->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePartieBrasModifierMouvementNChoices, m_choicePartieBrasModifierMouvementChoices, 0 );
	m_choicePartieBrasModifierMouvement->SetSelection( 0 );
	m_choicePartieBrasModifierMouvement->Enable( false );
	
	bSizerPartieBrasModifierMouvements->Add( m_choicePartieBrasModifierMouvement, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerPartieBrasModifierMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierDroiteMouvements->Add( bSizerPartieBrasModifierMouvements, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCoordonneesModifierMouvements;
	sbSizerCoordonneesModifierMouvements = new wxStaticBoxSizer( new wxStaticBox( sbSizerModifier->GetStaticBox(), wxID_ANY, wxT("Coordonnées") ), wxHORIZONTAL );
	
	
	sbSizerCoordonneesModifierMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextxModifierMouvements = new wxStaticText( sbSizerCoordonneesModifierMouvements->GetStaticBox(), wxID_ANY, wxT("x :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextxModifierMouvements->Wrap( -1 );
	sbSizerCoordonneesModifierMouvements->Add( m_staticTextxModifierMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlxModifierMouvements = new wxTextCtrl( sbSizerCoordonneesModifierMouvements->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlxModifierMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlxModifierMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlxModifierMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlxModifierMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlxModifierMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesModifierMouvements->Add( m_textCtrlxModifierMouvements, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextyModifierMouvements = new wxStaticText( sbSizerCoordonneesModifierMouvements->GetStaticBox(), wxID_ANY, wxT("y :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextyModifierMouvements->Wrap( -1 );
	sbSizerCoordonneesModifierMouvements->Add( m_staticTextyModifierMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlyModifierMouvements = new wxTextCtrl( sbSizerCoordonneesModifierMouvements->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlyModifierMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlyModifierMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlyModifierMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlyModifierMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlyModifierMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesModifierMouvements->Add( m_textCtrlyModifierMouvements, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextzModifierMouvements = new wxStaticText( sbSizerCoordonneesModifierMouvements->GetStaticBox(), wxID_ANY, wxT("z :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextzModifierMouvements->Wrap( -1 );
	sbSizerCoordonneesModifierMouvements->Add( m_staticTextzModifierMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlzModifierMouvements = new wxTextCtrl( sbSizerCoordonneesModifierMouvements->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlzModifierMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlzModifierMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlzModifierMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlzModifierMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlzModifierMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesModifierMouvements->Add( m_textCtrlzModifierMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizerCoordonneesModifierMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierDroiteMouvements->Add( sbSizerCoordonneesModifierMouvements, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer6 = new wxStdDialogButtonSizer();
	m_sdbSizer6Apply = new wxButton( sbSizerModifier->GetStaticBox(), wxID_APPLY );
	m_sdbSizer6->AddButton( m_sdbSizer6Apply );
	m_sdbSizer6Cancel = new wxButton( sbSizerModifier->GetStaticBox(), wxID_CANCEL );
	m_sdbSizer6->AddButton( m_sdbSizer6Cancel );
	m_sdbSizer6->Realize();
	
	bSizerModifierDroiteMouvements->Add( m_sdbSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerModifierPrincipal->Add( bSizerModifierDroiteMouvements, 1, wxEXPAND, 5 );
	
	
	sbSizerModifier->Add( bSizerModifierPrincipal, 1, wxEXPAND, 5 );
	
	
	bSizerModifierMouvements->Add( sbSizerModifier, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowModifierMouvements->SetSizer( bSizerModifierMouvements );
	m_scrolledWindowModifierMouvements->Layout();
	bSizerModifierMouvements->Fit( m_scrolledWindowModifierMouvements );
	m_notebookMouvements->AddPage( m_scrolledWindowModifierMouvements, wxT("Modifier les mouvements"), false );
	m_scrolledWindowCreerMouvements = new wxScrolledWindow( m_notebookMouvements, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowCreerMouvements->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerCreerMouvements;
	bSizerCreerMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerCreer;
	sbSizerCreer = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowCreerMouvements, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	wxBoxSizer* bSizerCreerPrincipal;
	bSizerCreerPrincipal = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerModifierCreerMouvements;
	bSizerModifierCreerMouvements = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomCreerMouvements1;
	bSizerNomCreerMouvements1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomCreerMouvements1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomCreerMouvements = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Nom du Mouvement :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomCreerMouvements->Wrap( -1 );
	bSizerNomCreerMouvements1->Add( m_staticTextNomCreerMouvements, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomCreerMouvements = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Mouvement 1"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizerNomCreerMouvements1->Add( m_textCtrlNomCreerMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomCreerMouvements1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierCreerMouvements->Add( bSizerNomCreerMouvements1, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNomCreerMouvements;
	bSizerNomCreerMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomCreerMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeHeureCreerMouvements = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Durée :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeHeureCreerMouvements->Wrap( -1 );
	bSizerNomCreerMouvements->Add( m_staticTextDureeHeureCreerMouvements, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeHeureCreerMouvements = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeHeureCreerMouvements->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureCreerMouvements->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomCreerMouvements->Add( m_textCtrlDureeHeureCreerMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeMinuteCreerMouvement = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT(" :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeMinuteCreerMouvement->Wrap( -1 );
	bSizerNomCreerMouvements->Add( m_staticTextDureeMinuteCreerMouvement, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeMinutesCreerMouvements = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeMinutesCreerMouvements->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeMinutesCreerMouvements->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomCreerMouvements->Add( m_textCtrlDureeMinutesCreerMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeSecondeCreerMouvements = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeSecondeCreerMouvements->Wrap( -1 );
	bSizerNomCreerMouvements->Add( m_staticTextDureeSecondeCreerMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeSecondeCreerMouvements = new wxTextCtrl( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeSecondeCreerMouvements->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeSecondeCreerMouvements->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerNomCreerMouvements->Add( m_textCtrlDureeSecondeCreerMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomCreerMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierCreerMouvements->Add( bSizerNomCreerMouvements, 1, wxEXPAND, 5 );
	
	
	bSizerCreerPrincipal->Add( bSizerModifierCreerMouvements, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineCreerMouvements = new wxStaticLine( sbSizerCreer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerCreerPrincipal->Add( m_staticlineCreerMouvements, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerCreerDroiteMouvements;
	bSizerCreerDroiteMouvements = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerPartieBrasCreerMouvements;
	bSizerPartieBrasCreerMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerPartieBrasCreerMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextPartieBrasCreerMouvementsr = new wxStaticText( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Sélection de la partie du  bras :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPartieBrasCreerMouvementsr->Wrap( -1 );
	bSizerPartieBrasCreerMouvements->Add( m_staticTextPartieBrasCreerMouvementsr, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choicePartieBrasCreerMouvementChoices[] = { wxT("Bassin"), wxT("Épaule"), wxT("Coude"), wxT("Poigné") };
	int m_choicePartieBrasCreerMouvementNChoices = sizeof( m_choicePartieBrasCreerMouvementChoices ) / sizeof( wxString );
	m_choicePartieBrasCreerMouvement = new wxChoice( sbSizerCreer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePartieBrasCreerMouvementNChoices, m_choicePartieBrasCreerMouvementChoices, 0 );
	m_choicePartieBrasCreerMouvement->SetSelection( 0 );
	m_choicePartieBrasCreerMouvement->Enable( false );
	
	bSizerPartieBrasCreerMouvements->Add( m_choicePartieBrasCreerMouvement, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerPartieBrasCreerMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerDroiteMouvements->Add( bSizerPartieBrasCreerMouvements, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCoordonneesCreerMouvements;
	sbSizerCoordonneesCreerMouvements = new wxStaticBoxSizer( new wxStaticBox( sbSizerCreer->GetStaticBox(), wxID_ANY, wxT("Coordonnées") ), wxHORIZONTAL );
	
	
	sbSizerCoordonneesCreerMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextCreerMouvements = new wxStaticText( sbSizerCoordonneesCreerMouvements->GetStaticBox(), wxID_ANY, wxT("x :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCreerMouvements->Wrap( -1 );
	sbSizerCoordonneesCreerMouvements->Add( m_staticTextCreerMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlxCreerMouvements = new wxTextCtrl( sbSizerCoordonneesCreerMouvements->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlxCreerMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlxCreerMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlxCreerMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlxCreerMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlxCreerMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesCreerMouvements->Add( m_textCtrlxCreerMouvements, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextyCreerMouvements = new wxStaticText( sbSizerCoordonneesCreerMouvements->GetStaticBox(), wxID_ANY, wxT("y :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextyCreerMouvements->Wrap( -1 );
	sbSizerCoordonneesCreerMouvements->Add( m_staticTextyCreerMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlyCreerMouvements = new wxTextCtrl( sbSizerCoordonneesCreerMouvements->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlyCreerMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlyCreerMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlyCreerMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlyCreerMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlyCreerMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesCreerMouvements->Add( m_textCtrlyCreerMouvements, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextzCreerMouvements = new wxStaticText( sbSizerCoordonneesCreerMouvements->GetStaticBox(), wxID_ANY, wxT("z :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextzCreerMouvements->Wrap( -1 );
	sbSizerCoordonneesCreerMouvements->Add( m_staticTextzCreerMouvements, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlzCreerMouvements = new wxTextCtrl( sbSizerCoordonneesCreerMouvements->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlzCreerMouvements->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlzCreerMouvements->SetMaxLength( 3 );
	}
	#else
	m_textCtrlzCreerMouvements->SetMaxLength( 3 );
	#endif
	m_textCtrlzCreerMouvements->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlzCreerMouvements->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesCreerMouvements->Add( m_textCtrlzCreerMouvements, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizerCoordonneesCreerMouvements->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerDroiteMouvements->Add( sbSizerCoordonneesCreerMouvements, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer61 = new wxStdDialogButtonSizer();
	m_sdbSizer61Save = new wxButton( sbSizerCreer->GetStaticBox(), wxID_SAVE );
	m_sdbSizer61->AddButton( m_sdbSizer61Save );
	m_sdbSizer61->Realize();
	
	bSizerCreerDroiteMouvements->Add( m_sdbSizer61, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerCreerPrincipal->Add( bSizerCreerDroiteMouvements, 1, wxEXPAND, 5 );
	
	
	sbSizerCreer->Add( bSizerCreerPrincipal, 1, wxEXPAND, 5 );
	
	
	bSizerCreerMouvements->Add( sbSizerCreer, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowCreerMouvements->SetSizer( bSizerCreerMouvements );
	m_scrolledWindowCreerMouvements->Layout();
	bSizerCreerMouvements->Fit( m_scrolledWindowCreerMouvements );
	m_notebookMouvements->AddPage( m_scrolledWindowCreerMouvements, wxT("Création des mouvements"), false );
	m_scrolledWindowDetruireMouvements1 = new wxScrolledWindow( m_notebookMouvements, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowDetruireMouvements1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerDetruireMouvements;
	bSizerDetruireMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionDetruireMouvements;
	sbSizerSelectionDetruireMouvements = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireMouvements1, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionDetruireMouvements->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxDetruireMouvements = new wxListBox( sbSizerSelectionDetruireMouvements->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxDetruireMouvements->Append( wxT("Mouvement 1") );
	m_listBoxDetruireMouvements->Append( wxT("Mouvement 2") );
	m_listBoxDetruireMouvements->Append( wxT("Mouvement 3") );
	m_listBoxDetruireMouvements->Append( wxT("Mouvement 4") );
	sbSizerSelectionDetruireMouvements->Add( m_listBoxDetruireMouvements, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerDetruireMouvements->Add( sbSizerSelectionDetruireMouvements, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerDetruire;
	sbSizerDetruire = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireMouvements1, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_staticTextDetruireMouvement = new wxStaticText( sbSizerDetruire->GetStaticBox(), wxID_ANY, wxT("Eẗes vous sur de vouloir supprimer ce mouvement ?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDetruireMouvement->Wrap( -1 );
	sbSizerDetruire->Add( m_staticTextDetruireMouvement, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	sbSizerDetruire->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_sdbSizerDetruireMouvement = new wxStdDialogButtonSizer();
	m_sdbSizerDetruireMouvementYes = new wxButton( sbSizerDetruire->GetStaticBox(), wxID_YES );
	m_sdbSizerDetruireMouvement->AddButton( m_sdbSizerDetruireMouvementYes );
	m_sdbSizerDetruireMouvement->Realize();
	
	sbSizerDetruire->Add( m_sdbSizerDetruireMouvement, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerDetruireMouvements->Add( sbSizerDetruire, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowDetruireMouvements1->SetSizer( bSizerDetruireMouvements );
	m_scrolledWindowDetruireMouvements1->Layout();
	bSizerDetruireMouvements->Fit( m_scrolledWindowDetruireMouvements1 );
	m_notebookMouvements->AddPage( m_scrolledWindowDetruireMouvements1, wxT("Détruire un mouvement"), false );
	m_scrolledWindowDetruireMouvements11 = new wxScrolledWindow( m_notebookMouvements, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowDetruireMouvements11->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerTesterMouvements;
	bSizerTesterMouvements = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionTesterMouvements;
	sbSizerSelectionTesterMouvements = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireMouvements11, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionTesterMouvements->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxTesterMouvements = new wxListBox( sbSizerSelectionTesterMouvements->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxTesterMouvements->Append( wxT("Mouvement 1") );
	m_listBoxTesterMouvements->Append( wxT("Mouvement 2") );
	m_listBoxTesterMouvements->Append( wxT("Mouvement 3") );
	m_listBoxTesterMouvements->Append( wxT("Mouvement 4") );
	sbSizerSelectionTesterMouvements->Add( m_listBoxTesterMouvements, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerTesterMouvements->Add( sbSizerSelectionTesterMouvements, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTester;
	sbSizerTester = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireMouvements11, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_staticTextTesterMouvement = new wxStaticText( sbSizerTester->GetStaticBox(), wxID_ANY, wxT("Eẗes vous sur de vouloir lancer ce test?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTesterMouvement->Wrap( -1 );
	sbSizerTester->Add( m_staticTextTesterMouvement, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	sbSizerTester->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_sdbSizerTesterMouvement = new wxStdDialogButtonSizer();
	m_sdbSizerTesterMouvementYes = new wxButton( sbSizerTester->GetStaticBox(), wxID_YES );
	m_sdbSizerTesterMouvement->AddButton( m_sdbSizerTesterMouvementYes );
	m_sdbSizerTesterMouvement->Realize();
	
	sbSizerTester->Add( m_sdbSizerTesterMouvement, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerTesterMouvements->Add( sbSizerTester, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowDetruireMouvements11->SetSizer( bSizerTesterMouvements );
	m_scrolledWindowDetruireMouvements11->Layout();
	bSizerTesterMouvements->Fit( m_scrolledWindowDetruireMouvements11 );
	m_notebookMouvements->AddPage( m_scrolledWindowDetruireMouvements11, wxT("TEST"), false );
	
	bSizerPrincipal->Add( m_notebookMouvements, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_notebookTrajectoires = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_notebookTrajectoires->Hide();
	
	m_scrolledWindowAffichageTrajectoires = new wxScrolledWindow( m_notebookTrajectoires, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowAffichageTrajectoires->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerAfficherTrajectoires;
	bSizerAfficherTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionAfficherTrajectoires;
	sbSizerSelectionAfficherTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageTrajectoires, wxID_ANY, wxT("Séléction de la trajectoires à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionAfficherTrajectoires->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxAffichageTrajectoires = new wxListBox( sbSizerSelectionAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxAffichageTrajectoires->Append( wxT("Trajectoire 1") );
	m_listBoxAffichageTrajectoires->Append( wxT("Trajectoire 2") );
	m_listBoxAffichageTrajectoires->Append( wxT("Trajectoire 3") );
	m_listBoxAffichageTrajectoires->Append( wxT("Trajectoire 4") );
	sbSizerSelectionAfficherTrajectoires->Add( m_listBoxAffichageTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerAfficherTrajectoires->Add( sbSizerSelectionAfficherTrajectoires, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerAfficherTrajectoires;
	sbSizerAfficherTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowAffichageTrajectoires, wxID_ANY, wxT("Affichage") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizerAfficherGaucheTrajectoires;
	bSizerAfficherGaucheTrajectoires = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomAffichageTrajectoires;
	bSizerNomAffichageTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomAffichageTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomAfficherTrajectoire = new wxStaticText( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("Nom du Mouvement :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomAfficherTrajectoire->Wrap( -1 );
	bSizerNomAffichageTrajectoires->Add( m_staticTextNomAfficherTrajectoire, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomAfficherTrajectoires = new wxTextCtrl( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("Mouvement 1"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizerNomAffichageTrajectoires->Add( m_textCtrlNomAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomAffichageTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherGaucheTrajectoires->Add( bSizerNomAffichageTrajectoires, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDureeAffichageTrajectoires;
	bSizerDureeAffichageTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeAffichageTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeHeureAfficherTrajectoires = new wxStaticText( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("Durée :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeHeureAfficherTrajectoires->Wrap( -1 );
	bSizerDureeAffichageTrajectoires->Add( m_staticTextDureeHeureAfficherTrajectoires, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeHeureAfficherTrajectoires = new wxTextCtrl( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlDureeHeureAfficherTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureAfficherTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeAffichageTrajectoires->Add( m_textCtrlDureeHeureAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeMinuteAfficherTrajectoires = new wxStaticText( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT(" :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeMinuteAfficherTrajectoires->Wrap( -1 );
	bSizerDureeAffichageTrajectoires->Add( m_staticTextDureeMinuteAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeMinutesAfficherTrajectoires = new wxTextCtrl( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlDureeMinutesAfficherTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeMinutesAfficherTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeAffichageTrajectoires->Add( m_textCtrlDureeMinutesAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeSecondeAfficherTrajectoires = new wxStaticText( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeSecondeAfficherTrajectoires->Wrap( -1 );
	bSizerDureeAffichageTrajectoires->Add( m_staticTextDureeSecondeAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeSecondesAfficherTrajectoires = new wxTextCtrl( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_textCtrlDureeSecondesAfficherTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeSecondesAfficherTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeAffichageTrajectoires->Add( m_textCtrlDureeSecondesAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeAffichageTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherGaucheTrajectoires->Add( bSizerDureeAffichageTrajectoires, 1, wxEXPAND, 5 );
	
	
	sbSizerAfficherTrajectoires->Add( bSizerAfficherGaucheTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineAfficherMouvements1 = new wxStaticLine( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizerAfficherTrajectoires->Add( m_staticlineAfficherMouvements1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerAfficherDroiteTrajectoires;
	bSizerAfficherDroiteTrajectoires = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerPartieBrasAfficherTrajectoires;
	bSizerPartieBrasAfficherTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerPartieBrasAfficherTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextPartieBrasAfficheTrajectoires = new wxStaticText( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("Sélection de la partie du  bras :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPartieBrasAfficheTrajectoires->Wrap( -1 );
	bSizerPartieBrasAfficherTrajectoires->Add( m_staticTextPartieBrasAfficheTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choicePartieBrasAfficherTrajectoiresChoices[] = { wxT("Bassin"), wxT("Épaule"), wxT("Coude"), wxT("Poigné") };
	int m_choicePartieBrasAfficherTrajectoiresNChoices = sizeof( m_choicePartieBrasAfficherTrajectoiresChoices ) / sizeof( wxString );
	m_choicePartieBrasAfficherTrajectoires = new wxChoice( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePartieBrasAfficherTrajectoiresNChoices, m_choicePartieBrasAfficherTrajectoiresChoices, 0 );
	m_choicePartieBrasAfficherTrajectoires->SetSelection( 0 );
	m_choicePartieBrasAfficherTrajectoires->Enable( false );
	
	bSizerPartieBrasAfficherTrajectoires->Add( m_choicePartieBrasAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerPartieBrasAfficherTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroiteTrajectoires->Add( bSizerPartieBrasAfficherTrajectoires, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCoordonneesAfficherTrajectoires;
	sbSizerCoordonneesAfficherTrajectoires = new wxStaticBoxSizer( new wxStaticBox( sbSizerAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("Coordonnées") ), wxHORIZONTAL );
	
	
	sbSizerCoordonneesAfficherTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextxAfficherTrajectoires = new wxStaticText( sbSizerCoordonneesAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("x :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextxAfficherTrajectoires->Wrap( -1 );
	sbSizerCoordonneesAfficherTrajectoires->Add( m_staticTextxAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlxAfficherTrajectoires = new wxTextCtrl( sbSizerCoordonneesAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlxAfficherTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlxAfficherTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlxAfficherTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlxAfficherTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlxAfficherTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesAfficherTrajectoires->Add( m_textCtrlxAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextyAfficherTrajectoires = new wxStaticText( sbSizerCoordonneesAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("y :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextyAfficherTrajectoires->Wrap( -1 );
	sbSizerCoordonneesAfficherTrajectoires->Add( m_staticTextyAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlyAfficherTrajectoires = new wxTextCtrl( sbSizerCoordonneesAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlyAfficherTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlyAfficherTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlyAfficherTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlyAfficherTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlyAfficherTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesAfficherTrajectoires->Add( m_textCtrlyAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextzAfficherTrajectoires = new wxStaticText( sbSizerCoordonneesAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("z :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextzAfficherTrajectoires->Wrap( -1 );
	sbSizerCoordonneesAfficherTrajectoires->Add( m_staticTextzAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlzAfficherTrajectoires = new wxTextCtrl( sbSizerCoordonneesAfficherTrajectoires->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlzAfficherTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlzAfficherTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlzAfficherTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlzAfficherTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlzAfficherTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesAfficherTrajectoires->Add( m_textCtrlzAfficherTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizerCoordonneesAfficherTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherDroiteTrajectoires->Add( sbSizerCoordonneesAfficherTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizerAfficherTrajectoires->Add( bSizerAfficherDroiteTrajectoires, 1, wxEXPAND, 5 );
	
	
	bSizerAfficherTrajectoires->Add( sbSizerAfficherTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowAffichageTrajectoires->SetSizer( bSizerAfficherTrajectoires );
	m_scrolledWindowAffichageTrajectoires->Layout();
	bSizerAfficherTrajectoires->Fit( m_scrolledWindowAffichageTrajectoires );
	m_notebookTrajectoires->AddPage( m_scrolledWindowAffichageTrajectoires, wxT("Afficher les trajectoires"), true );
	m_scrolledWindowModifierTrajectoires = new wxScrolledWindow( m_notebookTrajectoires, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowModifierTrajectoires->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerModifierTrajectoires;
	bSizerModifierTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionModifierMouvements1;
	sbSizerSelectionModifierMouvements1 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierTrajectoires, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionModifierMouvements1->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxModifierTrajectoires = new wxListBox( sbSizerSelectionModifierMouvements1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxModifierTrajectoires->Append( wxT("Mouvement 1") );
	m_listBoxModifierTrajectoires->Append( wxT("Mouvement 2") );
	m_listBoxModifierTrajectoires->Append( wxT("Mouvement 3") );
	m_listBoxModifierTrajectoires->Append( wxT("Mouvement 4") );
	sbSizerSelectionModifierMouvements1->Add( m_listBoxModifierTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerModifierTrajectoires->Add( sbSizerSelectionModifierMouvements1, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTrajectoires;
	sbSizerTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowModifierTrajectoires, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	wxBoxSizer* bSizerModifierPrincipalTrajectoires;
	bSizerModifierPrincipalTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerModifierGaucheTrajectoires;
	bSizerModifierGaucheTrajectoires = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomModifierTrajectoires;
	bSizerNomModifierTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomModifierTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomModifierTrajectoires = new wxStaticText( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Nom du Mouvement :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomModifierTrajectoires->Wrap( -1 );
	bSizerNomModifierTrajectoires->Add( m_staticTextNomModifierTrajectoires, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomModifierTrajectoires = new wxTextCtrl( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Mouvement 1"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizerNomModifierTrajectoires->Add( m_textCtrlNomModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomModifierTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierGaucheTrajectoires->Add( bSizerNomModifierTrajectoires, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDureeModificationTrajectoires;
	bSizerDureeModificationTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeModificationTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeHeureModifierTrajectoires = new wxStaticText( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Durée :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeHeureModifierTrajectoires->Wrap( -1 );
	bSizerDureeModificationTrajectoires->Add( m_staticTextDureeHeureModifierTrajectoires, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeHeureModifierTrajectoires = new wxTextCtrl( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeHeureModifierTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureModifierTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeModificationTrajectoires->Add( m_textCtrlDureeHeureModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeMinuteModifierTrajectoires = new wxStaticText( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT(" :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeMinuteModifierTrajectoires->Wrap( -1 );
	bSizerDureeModificationTrajectoires->Add( m_staticTextDureeMinuteModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeMinutesModifierTrajectoires = new wxTextCtrl( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeMinutesModifierTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeMinutesModifierTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeModificationTrajectoires->Add( m_textCtrlDureeMinutesModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeSecondeModifierTrajectoires = new wxStaticText( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeSecondeModifierTrajectoires->Wrap( -1 );
	bSizerDureeModificationTrajectoires->Add( m_staticTextDureeSecondeModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeSecondeModifierTrajectoires = new wxTextCtrl( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeSecondeModifierTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeSecondeModifierTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeModificationTrajectoires->Add( m_textCtrlDureeSecondeModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeModificationTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierGaucheTrajectoires->Add( bSizerDureeModificationTrajectoires, 1, wxEXPAND, 5 );
	
	
	bSizerModifierPrincipalTrajectoires->Add( bSizerModifierGaucheTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineModifierTrajectoires = new wxStaticLine( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerModifierPrincipalTrajectoires->Add( m_staticlineModifierTrajectoires, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerModifierDroiteTrajectoires;
	bSizerModifierDroiteTrajectoires = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerPartieBrasModifierTrajectoires;
	bSizerPartieBrasModifierTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerPartieBrasModifierTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextPartieBrasModifierTrajectoires = new wxStaticText( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Sélection de la partie du  bras :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPartieBrasModifierTrajectoires->Wrap( -1 );
	bSizerPartieBrasModifierTrajectoires->Add( m_staticTextPartieBrasModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choicePartieBrasModifierTrajectoiresChoices[] = { wxT("Bassin"), wxT("Épaule"), wxT("Coude"), wxT("Poigné") };
	int m_choicePartieBrasModifierTrajectoiresNChoices = sizeof( m_choicePartieBrasModifierTrajectoiresChoices ) / sizeof( wxString );
	m_choicePartieBrasModifierTrajectoires = new wxChoice( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePartieBrasModifierTrajectoiresNChoices, m_choicePartieBrasModifierTrajectoiresChoices, 0 );
	m_choicePartieBrasModifierTrajectoires->SetSelection( 0 );
	m_choicePartieBrasModifierTrajectoires->Enable( false );
	
	bSizerPartieBrasModifierTrajectoires->Add( m_choicePartieBrasModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerPartieBrasModifierTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierDroiteTrajectoires->Add( bSizerPartieBrasModifierTrajectoires, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCoordonneesModifierTrajectoires;
	sbSizerCoordonneesModifierTrajectoires = new wxStaticBoxSizer( new wxStaticBox( sbSizerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Coordonnées") ), wxHORIZONTAL );
	
	
	sbSizerCoordonneesModifierTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextxModifierTrajectoires = new wxStaticText( sbSizerCoordonneesModifierTrajectoires->GetStaticBox(), wxID_ANY, wxT("x :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextxModifierTrajectoires->Wrap( -1 );
	sbSizerCoordonneesModifierTrajectoires->Add( m_staticTextxModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlxModifierTrajectoires = new wxTextCtrl( sbSizerCoordonneesModifierTrajectoires->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlxModifierTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlxModifierTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlxModifierTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlxModifierTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlxModifierTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesModifierTrajectoires->Add( m_textCtrlxModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextyModifierTrajectoires = new wxStaticText( sbSizerCoordonneesModifierTrajectoires->GetStaticBox(), wxID_ANY, wxT("y :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextyModifierTrajectoires->Wrap( -1 );
	sbSizerCoordonneesModifierTrajectoires->Add( m_staticTextyModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlyModifierTrajectoires = new wxTextCtrl( sbSizerCoordonneesModifierTrajectoires->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlyModifierTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlyModifierTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlyModifierTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlyModifierTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlyModifierTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesModifierTrajectoires->Add( m_textCtrlyModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextzModifierTrajectoires = new wxStaticText( sbSizerCoordonneesModifierTrajectoires->GetStaticBox(), wxID_ANY, wxT("z :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextzModifierTrajectoires->Wrap( -1 );
	sbSizerCoordonneesModifierTrajectoires->Add( m_staticTextzModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlzModifierTrajectoires = new wxTextCtrl( sbSizerCoordonneesModifierTrajectoires->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlzModifierTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlzModifierTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlzModifierTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlzModifierTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlzModifierTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesModifierTrajectoires->Add( m_textCtrlzModifierTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizerCoordonneesModifierTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierDroiteTrajectoires->Add( sbSizerCoordonneesModifierTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerModifierTrajectoires = new wxStdDialogButtonSizer();
	m_sdbSizerModifierTrajectoiresApply = new wxButton( sbSizerTrajectoires->GetStaticBox(), wxID_APPLY );
	m_sdbSizerModifierTrajectoires->AddButton( m_sdbSizerModifierTrajectoiresApply );
	m_sdbSizerModifierTrajectoiresCancel = new wxButton( sbSizerTrajectoires->GetStaticBox(), wxID_CANCEL );
	m_sdbSizerModifierTrajectoires->AddButton( m_sdbSizerModifierTrajectoiresCancel );
	m_sdbSizerModifierTrajectoires->Realize();
	
	bSizerModifierDroiteTrajectoires->Add( m_sdbSizerModifierTrajectoires, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerModifierPrincipalTrajectoires->Add( bSizerModifierDroiteTrajectoires, 1, wxEXPAND, 5 );
	
	
	sbSizerTrajectoires->Add( bSizerModifierPrincipalTrajectoires, 1, wxEXPAND, 5 );
	
	
	bSizerModifierTrajectoires->Add( sbSizerTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowModifierTrajectoires->SetSizer( bSizerModifierTrajectoires );
	m_scrolledWindowModifierTrajectoires->Layout();
	bSizerModifierTrajectoires->Fit( m_scrolledWindowModifierTrajectoires );
	m_notebookTrajectoires->AddPage( m_scrolledWindowModifierTrajectoires, wxT("Modifier les trajectoires"), false );
	m_scrolledWindowCreerTrajectoires = new wxScrolledWindow( m_notebookTrajectoires, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowCreerTrajectoires->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerCreerTrajectoires;
	bSizerCreerTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerCreerTrajectoires;
	sbSizerCreerTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowCreerTrajectoires, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	wxBoxSizer* bSizerCreerPrincipalTrajectoires;
	bSizerCreerPrincipalTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerModifierCreerTrajectoires;
	bSizerModifierCreerTrajectoires = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerNomCreerTrajectoires;
	bSizerNomCreerTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerNomCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextNomCreerTrajectoires = new wxStaticText( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Nom du Mouvement :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNomCreerTrajectoires->Wrap( -1 );
	bSizerNomCreerTrajectoires->Add( m_staticTextNomCreerTrajectoires, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNomCreerTrajectoires = new wxTextCtrl( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Trajectoire 1"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizerNomCreerTrajectoires->Add( m_textCtrlNomCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerNomCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierCreerTrajectoires->Add( bSizerNomCreerTrajectoires, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDureeCreerTrajectoires;
	bSizerDureeCreerTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerDureeCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextDureeHeureCreerTrajectoires = new wxStaticText( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Durée :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeHeureCreerTrajectoires->Wrap( -1 );
	bSizerDureeCreerTrajectoires->Add( m_staticTextDureeHeureCreerTrajectoires, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDureeHeureCreerTrajectoires = new wxTextCtrl( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeHeureCreerTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeHeureCreerTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeCreerTrajectoires->Add( m_textCtrlDureeHeureCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeMinuteCreerTrajectoires = new wxStaticText( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT(" :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeMinuteCreerTrajectoires->Wrap( -1 );
	bSizerDureeCreerTrajectoires->Add( m_staticTextDureeMinuteCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeMinutesCreerTrajectoires = new wxTextCtrl( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeMinutesCreerTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeMinutesCreerTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeCreerTrajectoires->Add( m_textCtrlDureeMinutesCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextDureeSecondeCreerTrajectoires = new wxStaticText( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDureeSecondeCreerTrajectoires->Wrap( -1 );
	bSizerDureeCreerTrajectoires->Add( m_staticTextDureeSecondeCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlDureeSecondeCreerTrajectoires = new wxTextCtrl( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("00"), wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE );
	m_textCtrlDureeSecondeCreerTrajectoires->SetMinSize( wxSize( 35,-1 ) );
	m_textCtrlDureeSecondeCreerTrajectoires->SetMaxSize( wxSize( 35,-1 ) );
	
	bSizerDureeCreerTrajectoires->Add( m_textCtrlDureeSecondeCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDureeCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerModifierCreerTrajectoires->Add( bSizerDureeCreerTrajectoires, 1, wxEXPAND, 5 );
	
	
	bSizerCreerPrincipalTrajectoires->Add( bSizerModifierCreerTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	m_staticlineCreerTrajectoires = new wxStaticLine( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizerCreerPrincipalTrajectoires->Add( m_staticlineCreerTrajectoires, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizerCreerDroiteTrajectoires;
	bSizerCreerDroiteTrajectoires = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerPartieBrasCreerTrajectoires;
	bSizerPartieBrasCreerTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerPartieBrasCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextPartieBrasCreerTrajectoires = new wxStaticText( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Sélection de la partie du  bras :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPartieBrasCreerTrajectoires->Wrap( -1 );
	bSizerPartieBrasCreerTrajectoires->Add( m_staticTextPartieBrasCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choicePartieBrasCreerTrajectoiresChoices[] = { wxT("Bassin"), wxT("Épaule"), wxT("Coude"), wxT("Poigné") };
	int m_choicePartieBrasCreerTrajectoiresNChoices = sizeof( m_choicePartieBrasCreerTrajectoiresChoices ) / sizeof( wxString );
	m_choicePartieBrasCreerTrajectoires = new wxChoice( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePartieBrasCreerTrajectoiresNChoices, m_choicePartieBrasCreerTrajectoiresChoices, 0 );
	m_choicePartieBrasCreerTrajectoires->SetSelection( 0 );
	m_choicePartieBrasCreerTrajectoires->Enable( false );
	
	bSizerPartieBrasCreerTrajectoires->Add( m_choicePartieBrasCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerPartieBrasCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerDroiteTrajectoires->Add( bSizerPartieBrasCreerTrajectoires, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCoordonneesCreerTrajectoires;
	sbSizerCoordonneesCreerTrajectoires = new wxStaticBoxSizer( new wxStaticBox( sbSizerCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("Coordonnées") ), wxHORIZONTAL );
	
	
	sbSizerCoordonneesCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextCreerTrajectoires = new wxStaticText( sbSizerCoordonneesCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("x :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCreerTrajectoires->Wrap( -1 );
	sbSizerCoordonneesCreerTrajectoires->Add( m_staticTextCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlxCreerTrajectoires = new wxTextCtrl( sbSizerCoordonneesCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlxCreerTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlxCreerTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlxCreerTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlxCreerTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlxCreerTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesCreerTrajectoires->Add( m_textCtrlxCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextyCreerTrajectoires = new wxStaticText( sbSizerCoordonneesCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("y :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextyCreerTrajectoires->Wrap( -1 );
	sbSizerCoordonneesCreerTrajectoires->Add( m_staticTextyCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlyCreerTrajectoires = new wxTextCtrl( sbSizerCoordonneesCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlyCreerTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlyCreerTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlyCreerTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlyCreerTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlyCreerTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesCreerTrajectoires->Add( m_textCtrlyCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextzCreerTrajectoires = new wxStaticText( sbSizerCoordonneesCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("z :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextzCreerTrajectoires->Wrap( -1 );
	sbSizerCoordonneesCreerTrajectoires->Add( m_staticTextzCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlzCreerTrajectoires = new wxTextCtrl( sbSizerCoordonneesCreerTrajectoires->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	#ifdef __WXGTK__
	if ( !m_textCtrlzCreerTrajectoires->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlzCreerTrajectoires->SetMaxLength( 3 );
	}
	#else
	m_textCtrlzCreerTrajectoires->SetMaxLength( 3 );
	#endif
	m_textCtrlzCreerTrajectoires->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrlzCreerTrajectoires->SetMaxSize( wxSize( 50,-1 ) );
	
	sbSizerCoordonneesCreerTrajectoires->Add( m_textCtrlzCreerTrajectoires, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizerCoordonneesCreerTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizerCreerDroiteTrajectoires->Add( sbSizerCoordonneesCreerTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerCreerTrajectoires = new wxStdDialogButtonSizer();
	m_sdbSizerCreerTrajectoiresSave = new wxButton( sbSizerCreerTrajectoires->GetStaticBox(), wxID_SAVE );
	m_sdbSizerCreerTrajectoires->AddButton( m_sdbSizerCreerTrajectoiresSave );
	m_sdbSizerCreerTrajectoires->Realize();
	
	bSizerCreerDroiteTrajectoires->Add( m_sdbSizerCreerTrajectoires, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerCreerPrincipalTrajectoires->Add( bSizerCreerDroiteTrajectoires, 1, wxEXPAND, 5 );
	
	
	sbSizerCreerTrajectoires->Add( bSizerCreerPrincipalTrajectoires, 1, wxEXPAND, 5 );
	
	
	bSizerCreerTrajectoires->Add( sbSizerCreerTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowCreerTrajectoires->SetSizer( bSizerCreerTrajectoires );
	m_scrolledWindowCreerTrajectoires->Layout();
	bSizerCreerTrajectoires->Fit( m_scrolledWindowCreerTrajectoires );
	m_notebookTrajectoires->AddPage( m_scrolledWindowCreerTrajectoires, wxT("Création de trajectoires"), false );
	m_scrolledWindowDetruireTrajectoires = new wxScrolledWindow( m_notebookTrajectoires, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowDetruireTrajectoires->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerDetruireTrajectoires;
	bSizerDetruireTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionDetruireTrajectoires;
	sbSizerSelectionDetruireTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireTrajectoires, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionDetruireTrajectoires->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxDetruireTrajectoires = new wxListBox( sbSizerSelectionDetruireTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxDetruireTrajectoires->Append( wxT("Mouvement 1") );
	m_listBoxDetruireTrajectoires->Append( wxT("Mouvement 2") );
	m_listBoxDetruireTrajectoires->Append( wxT("Mouvement 3") );
	m_listBoxDetruireTrajectoires->Append( wxT("Mouvement 4") );
	sbSizerSelectionDetruireTrajectoires->Add( m_listBoxDetruireTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerDetruireTrajectoires->Add( sbSizerSelectionDetruireTrajectoires, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerDetruireTrajectoires;
	sbSizerDetruireTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowDetruireTrajectoires, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_staticTextDetruireTrajectoires = new wxStaticText( sbSizerDetruireTrajectoires->GetStaticBox(), wxID_ANY, wxT("Eẗes vous sur de vouloir supprimer ce mouvement ?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDetruireTrajectoires->Wrap( -1 );
	sbSizerDetruireTrajectoires->Add( m_staticTextDetruireTrajectoires, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	sbSizerDetruireTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_sdbSizerDetruireTrajectoires = new wxStdDialogButtonSizer();
	m_sdbSizerDetruireTrajectoiresYes = new wxButton( sbSizerDetruireTrajectoires->GetStaticBox(), wxID_YES );
	m_sdbSizerDetruireTrajectoires->AddButton( m_sdbSizerDetruireTrajectoiresYes );
	m_sdbSizerDetruireTrajectoires->Realize();
	
	sbSizerDetruireTrajectoires->Add( m_sdbSizerDetruireTrajectoires, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerDetruireTrajectoires->Add( sbSizerDetruireTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowDetruireTrajectoires->SetSizer( bSizerDetruireTrajectoires );
	m_scrolledWindowDetruireTrajectoires->Layout();
	bSizerDetruireTrajectoires->Fit( m_scrolledWindowDetruireTrajectoires );
	m_notebookTrajectoires->AddPage( m_scrolledWindowDetruireTrajectoires, wxT("Détruire une trajectoire"), false );
	m_scrolledWindowTestTrajectoires = new wxScrolledWindow( m_notebookTrajectoires, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxT("i") );
	m_scrolledWindowTestTrajectoires->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerTesterTrajectoires;
	bSizerTesterTrajectoires = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSelectionTesterTrajectoires;
	sbSizerSelectionTesterTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowTestTrajectoires, wxID_ANY, wxT("Séléction du processus à afficher") ), wxHORIZONTAL );
	
	sbSizerSelectionTesterTrajectoires->SetMinSize( wxSize( 280,-1 ) ); 
	m_listBoxTesterTrajectoires = new wxListBox( sbSizerSelectionTesterTrajectoires->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT );
	m_listBoxTesterTrajectoires->Append( wxT("Mouvement 1") );
	m_listBoxTesterTrajectoires->Append( wxT("Mouvement 2") );
	m_listBoxTesterTrajectoires->Append( wxT("Mouvement 3") );
	m_listBoxTesterTrajectoires->Append( wxT("Mouvement 4") );
	sbSizerSelectionTesterTrajectoires->Add( m_listBoxTesterTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerTesterTrajectoires->Add( sbSizerSelectionTesterTrajectoires, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTesterTrajectoires;
	sbSizerTesterTrajectoires = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindowTestTrajectoires, wxID_ANY, wxT("Affichage") ), wxVERTICAL );
	
	m_staticTextTesterTrajectoires = new wxStaticText( sbSizerTesterTrajectoires->GetStaticBox(), wxID_ANY, wxT("Eẗes vous sur de vouloir lancer ce test?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTesterTrajectoires->Wrap( -1 );
	sbSizerTesterTrajectoires->Add( m_staticTextTesterTrajectoires, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	sbSizerTesterTrajectoires->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_sdbSizerTesterTrajectoires = new wxStdDialogButtonSizer();
	m_sdbSizerTesterTrajectoiresYes = new wxButton( sbSizerTesterTrajectoires->GetStaticBox(), wxID_YES );
	m_sdbSizerTesterTrajectoires->AddButton( m_sdbSizerTesterTrajectoiresYes );
	m_sdbSizerTesterTrajectoires->Realize();
	
	sbSizerTesterTrajectoires->Add( m_sdbSizerTesterTrajectoires, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizerTesterTrajectoires->Add( sbSizerTesterTrajectoires, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowTestTrajectoires->SetSizer( bSizerTesterTrajectoires );
	m_scrolledWindowTestTrajectoires->Layout();
	bSizerTesterTrajectoires->Fit( m_scrolledWindowTestTrajectoires );
	m_notebookTrajectoires->AddPage( m_scrolledWindowTestTrajectoires, wxT("TEST"), false );
	
	bSizerPrincipal->Add( m_notebookTrajectoires, 1, wxEXPAND | wxALL, 5 );
	
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
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlLogin->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlPass->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_buttonChoixTrajectoires->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonChoixTrajectoiresClicks ), NULL, this );
	m_buttonChoixMouvements->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonChoixMouvementsClicks ), NULL, this );
	m_listBoxAffichageMouvements->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionMouvements ), NULL, this );
	m_listBoxAffichageMouvements->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionMouvements ), NULL, this );
	m_listBoxModifierMouvements->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionMouvements ), NULL, this );
	m_listBoxModifierMouvements->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionMouvements ), NULL, this );
	m_sdbSizer6Apply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierMouvementClick ), NULL, this );
	m_sdbSizer6Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModifierMouvementClick ), NULL, this );
	m_sdbSizer61Save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerMouvementClick ), NULL, this );
	m_listBoxDetruireMouvements->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionMouvements ), NULL, this );
	m_listBoxDetruireMouvements->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionMouvements ), NULL, this );
	m_sdbSizerDetruireMouvementYes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonDetruireMouvementClick ), NULL, this );
	m_listBoxTesterMouvements->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionMouvements ), NULL, this );
	m_listBoxTesterMouvements->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionMouvements ), NULL, this );
	m_sdbSizerTesterMouvementYes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonTesterMouvementClick ), NULL, this );
	m_listBoxAffichageTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionTrajectoires ), NULL, this );
	m_listBoxAffichageTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionTrajectoires ), NULL, this );
	m_listBoxModifierTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionTrajectoires ), NULL, this );
	m_listBoxModifierTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionTrajectoires ), NULL, this );
	m_sdbSizerModifierTrajectoiresApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierTrajectoiresClick ), NULL, this );
	m_sdbSizerModifierTrajectoiresCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModifierTrajectoiresClick ), NULL, this );
	m_sdbSizerCreerTrajectoiresSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerTrajectoiresClick ), NULL, this );
	m_listBoxDetruireTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionTrajectoires ), NULL, this );
	m_listBoxDetruireTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionTrajectoires ), NULL, this );
	m_sdbSizerDetruireTrajectoiresYes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonDetruireTrajectoiresClick ), NULL, this );
	m_listBoxTesterTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionTrajectoires ), NULL, this );
	m_listBoxTesterTrajectoires->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionTrajectoires ), NULL, this );
	m_sdbSizerTesterTrajectoiresYes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonTesterTrajectoiresClick ), NULL, this );
	m_buttonViderAffichage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonViderAffichageClick ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( FramePrincipal::OnFrameClose ) );
	m_textCtrlLogin->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_textCtrlPass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_toggleBtnConnexion->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonConnexionToggle ), NULL, this );
	m_buttonChoixTrajectoires->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonChoixTrajectoiresClicks ), NULL, this );
	m_buttonChoixMouvements->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonChoixMouvementsClicks ), NULL, this );
	m_listBoxAffichageMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionMouvements ), NULL, this );
	m_listBoxAffichageMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionMouvements ), NULL, this );
	m_listBoxModifierMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionMouvements ), NULL, this );
	m_listBoxModifierMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionMouvements ), NULL, this );
	m_sdbSizer6Apply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierMouvementClick ), NULL, this );
	m_sdbSizer6Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModifierMouvementClick ), NULL, this );
	m_sdbSizer61Save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerMouvementClick ), NULL, this );
	m_listBoxDetruireMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionMouvements ), NULL, this );
	m_listBoxDetruireMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionMouvements ), NULL, this );
	m_sdbSizerDetruireMouvementYes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonDetruireMouvementClick ), NULL, this );
	m_listBoxTesterMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionMouvements ), NULL, this );
	m_listBoxTesterMouvements->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionMouvements ), NULL, this );
	m_sdbSizerTesterMouvementYes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonTesterMouvementClick ), NULL, this );
	m_listBoxAffichageTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionTrajectoires ), NULL, this );
	m_listBoxAffichageTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxAffichageSelectionTrajectoires ), NULL, this );
	m_listBoxModifierTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionTrajectoires ), NULL, this );
	m_listBoxModifierTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxModifierSelectionTrajectoires ), NULL, this );
	m_sdbSizerModifierTrajectoiresApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnApplyButtonModifierTrajectoiresClick ), NULL, this );
	m_sdbSizerModifierTrajectoiresCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnCancelButtonModifierTrajectoiresClick ), NULL, this );
	m_sdbSizerCreerTrajectoiresSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnSaveButtonCreerTrajectoiresClick ), NULL, this );
	m_listBoxDetruireTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionTrajectoires ), NULL, this );
	m_listBoxDetruireTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxDetruireSelectionTrajectoires ), NULL, this );
	m_sdbSizerDetruireTrajectoiresYes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonDetruireTrajectoiresClick ), NULL, this );
	m_listBoxTesterTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionTrajectoires ), NULL, this );
	m_listBoxTesterTrajectoires->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FramePrincipal::OnListBoxTesterSelectionTrajectoires ), NULL, this );
	m_sdbSizerTesterTrajectoiresYes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnYesButtonTesterTrajectoiresClick ), NULL, this );
	m_buttonViderAffichage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FramePrincipal::OnButtonViderAffichageClick ), NULL, this );
	
}
