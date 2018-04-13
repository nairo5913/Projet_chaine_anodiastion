/***************************************************************
 * Name:      EvtFramePrincipal.cpp
 * Purpose:   
 * Author:    Boubziz Nassim
 * Created:   29/11/2017
 **************************************************************/
#include "EvtFramePrincipal.h"
#include "./Client.h"
#include <wx/log.h>
#include <iostream>

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent ) 
:
FramePrincipal( parent )
{
    m_connecte=false;
    m_statusBa->SetStatusText(wxT("Déconnecté..."),/*a voir*/);
    
    Connect( ID_CLIENT,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal(::/* a voir */), NULL,this );
    Connect( ID_CLIENT+1,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal(::/* a voir */), NULL,this );
    Connect( ID_CLIENT+2,wxEVT_COMMAND_BUTTON_CLICKED , wxCommandEventHandler( EvtFramePrincipal(::/* a voir */), NULL,this );
    /*a ajouté en fonction des evenement possiblement realisable*/
}

void EvtFramePrincipal::OnButtonConnexionToggle( wxCommandEvent& event)
{
    if (!m_connecte)
        /*si on est pas ocnnecté on verifie les info de connexion avant dessaye de se co*/
        {
            long port=0
            if(m_textCtrlPort->GetValue().ToLong(&port))
            {
                if ((port>1024)&& (port<=65535))
                m_client=new Client(m_textCtrlHote->GetValue(),port,this);
                m_connecte=m_client->IsOK();
            }
        }
        else
        {
            Deconnexion((wxT("Déconnexion depuis le client")));
        }
}

void EvtFramePrincipal::OnFrameClose( wxCloseEvent& event )
{
    if (m_connecte)
    {
        m_client->Close();
        delete m_client;
    }
    Destroy();
}

void EvtFramePrincipal::ConnexionServeur(wxCommandEvent& event)
{
    wxString requete(wxT("100"));
    
}

void EvtFramePrincipal::Erreur(wxCommandEvent& event)
{
    wxString requete(wxT("400"));
}

void EvtFramePrincipal::GereReponse(wxString reponse, wxString reponse_attendue)
{
    wxString reste(wxT(""));
    if (reponse.StartsWith(reponse_attendue,&reste))
    // réponse correcte
    {
        wxString message(wxT("Le serveur a retourné: "));
        message<<reste<<wxT("\n");
        m_textCtrlLog->AppendText(message);
    }
    else if (reponse.IsSameAs(wxT("404")))
    // commande inconnue
    {
        // on ne devrait normalement pas arriver ici...
        wxLogWarning(wxT("Le serveur a retourné: Commande inconnue..."));
    }
    else if (reponse.IsSameAs(wxT("102-")))
    // erreur réseau
    {
        Deconnexion(wxT("PROBLÈME d'entrée/sortie réseau: Déconnexion"));
    }
    else
    {
        // on ne devrait jamais arriver ici...
        wxLogWarning(wxT("Le serveur a retourné une valeur non prévue dans le protocole!!!"));
    }
}
void EvtFramePrincipal::EnvoiReception(wxCommandEvent& event)
{
    wxString requete(wxT("200-"));
    requete<<
}
void EvtFramePrincipal::Information(wxCommandEvent& event)
{
    wxString requete(wxT("500-"));
    
}

void EvtFramePrincipal::Deconnexion(wxCommandEvent& event)
{
    wxString requete(wxT("600-"));
    
}