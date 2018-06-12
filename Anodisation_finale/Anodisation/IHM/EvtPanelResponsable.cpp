/*******************************************************************************
 *  Fichier:  EvtPanelResponsable.cpp
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  29/04/2018
 *  Utilité:  Gestion des événements du panel responsable
 *  Auteur:   Florian Provost
*******************************************************************************/
#include "EvtPanelResponsable.h"
#include "EvtFramePrincipal.h"

EvtPanelResponsable::EvtPanelResponsable(wxWindow* parent) : PanelResponsable(parent)
{
    m_fabrication = false;
    point_virgule_saisie_creer = true;
    point_virgule_saisie_modifier = true;
    
    // Charger les bitmap pour la disponibilité du bras
    BmpRouge.LoadFile(wxT("../Images/RougeAllume.bmp"), wxBITMAP_TYPE_BMP);
    BmpVert.LoadFile(wxT("../Images/VertAllume.bmp"), wxBITMAP_TYPE_BMP);
}
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Méthode générées par wxFormBuilder                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
void EvtPanelResponsable::OnListBoxAffichageSelection(wxCommandEvent& event)
{
    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(m_listBoxAffichageProcessus->GetStringSelection());
    
    // Vider les text control
    // du coté droit
    m_textCtrlIdAfficher->Clear();
    m_textCtrlDureeTotalHeureAfficher->Clear();
    m_textCtrlDureeTotalMinuteAfficher->Clear();
    m_textCtrlDureeTotalSecondeAfficher->Clear();
    m_listBoxListeTrajectoiresAfficher->Clear();
    
    m_textCtrlAfficherHeureBain1->Clear();
    m_textCtrlAfficherMinuteBain1->Clear();
    m_textCtrlAfficherSecondeBain1->Clear();
    
    m_textCtrlAfficherHeureBain2->Clear();
    m_textCtrlAfficherMinuteBain2->Clear();
    m_textCtrlAfficherSecondeBain2->Clear();
    
    m_textCtrlAfficherHeureBain3->Clear();
    m_textCtrlAfficherMinuteBain3->Clear();
    m_textCtrlAfficherSecondeBain3->Clear();

    // Du coté gauche
    m_textCtrlNomAfficher->Clear();
    m_textCtrlNombreBainAfficher->Clear();
    m_textCtrlOrdreTrajectoiresAfficher->Clear();
    
    // Masquage
    m_staticAfficherDureeTotalBain2->Hide();
    m_textCtrlAfficherHeureBain2->Hide();
    m_staticTextAfficherDureeBain2->Hide();
    m_textCtrlAfficherMinuteBain2->Hide();
    m_staticTextAfficherDureeFinBain2->Hide();
    m_textCtrlAfficherSecondeBain2->Hide();
    m_staticTextAfficherNumBain2->Hide();
    bSizerAfficherDureeBain2->Hide(this);
    
    m_staticAfficherDureeTotalBain3->Hide();
    m_textCtrlAfficherHeureBain3->Hide();
    m_staticTextAfficherDureeBain3->Hide();
    m_textCtrlAfficherMinuteBain3->Hide();
    m_staticTextAfficherDureeFinBain3->Hide();
    m_textCtrlAfficherSecondeBain3->Hide();
    m_staticTextAfficherNumBain3->Hide();
    bSizerAfficherDureeBain3->Hide(this);
    
    bSizerAfficherDureeBain3->Layout();
    bSizerAfficherDureeBain2->Layout();
    bSizerBainAfficherDuree->Layout();
    bSizerAfficherDureeBain1->Layout();
    bSizerAfficherBain->Layout();

    sbSizerGestionBainAfficher->Layout();
    Layout();

    // Remplisage
    m_textCtrlIdAfficher->AppendText(id_selection);

    // Durée total du processus
    if(m_donnees_IHM->RecupereDureeTotal(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_textCtrlDureeTotalHeureAfficher->AppendText(m_frame->DecouperTexteDebut(duree, 2));

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        m_textCtrlDureeTotalMinuteAfficher->AppendText(m_frame->DecouperTexteFin(temp, 3));

        m_textCtrlDureeTotalSecondeAfficher->AppendText(m_frame->DecouperTexteFin(duree, 6));
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Liste des trajectoires du processus
    if(m_donnees_IHM->RecupereListeTrajectoiresProcessus(m_frame->ConversionEnString(id_selection)))
    {
        vector<string> resultat = m_donnees_IHM->GetListeTrajectoiresProcessus();
        m_listBoxListeTrajectoiresAfficher->Clear();
        wxString rempli;
        wxString nom;
        
        for(unsigned int taille = 0; taille < resultat.size(); taille++)
        {
            //cout << "val v2 : " << resultat[taille] << endl;
            taille = taille + 1;

            if(taille % 4 == 0 && taille != 0)
            {
                rempli << wxT("Durée : ") << resultat[taille - 1];
                m_listBoxListeTrajectoiresAfficher->Append(rempli);
                rempli.clear();
            }
            else if(taille % 4 != 0 && taille % 2 == 0)
            {
                nom.clear();
                nom << resultat[taille - 1];

                int separateur = nom.find("   ");
                rempli << m_frame->DecouperTexteDebut(nom, separateur) << wxT(" - ");
            }
            else
            {
                // EnvoiMessage(resultat[taille-1] + wxT("\n"));
                rempli << resultat[taille - 1] << wxT(" - ");
            }

            taille = taille - 1;
        }
        //cout << "fin" << endl <<endl;
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nom du processus
    if(m_donnees_IHM->RecupereNomProcessus(m_frame->ConversionEnString(id_selection)))
    {
        wxString temp = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomProcessus());

        int separateur = temp.find("   ");
        wxString nom = m_frame->DecouperTexteDebut(temp, separateur);

        m_textCtrlNomAfficher->AppendText(nom);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(m_frame->ConversionEnString(id_selection)))
    {
        m_textCtrlNombreBainAfficher->AppendText(m_frame->ConversionEnWxString(m_donnees_IHM->GetNombreBain()));
        string requete;
        requete = "SELECT numero_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                + m_frame->ConversionEnString(id_selection);
        vector<string> numero_bain;
        
        if(m_bdd_anodisation->ExecuteSelect(requete))
        {
            numero_bain = m_bdd_anodisation->GetLastResult();
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
        
        
        
        if(m_donnees_IHM->GetNombreBain() == "1")
        {
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                m_staticTextAfficherNumBain1->SetLabel(m_frame->ConversionEnWxString(numero_bain[1]) + wxT(" :"));
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlAfficherHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlAfficherMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le bain 1 de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
        }
        else if(m_donnees_IHM->GetNombreBain() == "2")
        {
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_staticTextAfficherNumBain1->SetLabel(m_frame->ConversionEnWxString(numero_bain[1]) + wxT(" :"));
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlAfficherHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlAfficherMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 2
            m_staticAfficherDureeTotalBain2->Show();
            m_textCtrlAfficherHeureBain2->Show();
            m_staticTextAfficherDureeBain2->Show();
            m_textCtrlAfficherMinuteBain2->Show();
            m_staticTextAfficherDureeFinBain2->Show();
            m_textCtrlAfficherSecondeBain2->Show();
            m_staticTextAfficherNumBain2->Show();
            bSizerAfficherDureeBain2->Show(this);
            
            bSizerAfficherDureeBain2->Layout();
            bSizerBainAfficherDuree->Layout();
            bSizerAfficherDureeBain1->Layout();
            bSizerAfficherBain->Layout();

            sbSizerGestionBainAfficher->Layout();
            Layout();
            
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[2];
                    
            m_staticTextAfficherNumBain2->SetLabel(m_frame->ConversionEnWxString(numero_bain[2]) + wxT(" :"));
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain2 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain2.empty())
                {
                    m_textCtrlAfficherHeureBain2->AppendText(m_frame->DecouperTexteDebut(duree_bain2[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain2[0], 5);
                    m_textCtrlAfficherMinuteBain2->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain2->AppendText(m_frame->DecouperTexteFin(duree_bain2[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
        }
        else if(m_donnees_IHM->GetNombreBain() == "3")
        {
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_staticTextAfficherNumBain1->SetLabel(m_frame->ConversionEnWxString(numero_bain[1]) + wxT(" :"));
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlAfficherHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlAfficherMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 2
            m_staticAfficherDureeTotalBain2->Show();
            m_textCtrlAfficherHeureBain2->Show();
            m_staticTextAfficherDureeBain2->Show();
            m_textCtrlAfficherMinuteBain2->Show();
            m_staticTextAfficherDureeFinBain2->Show();
            m_textCtrlAfficherSecondeBain2->Show();
            m_staticTextAfficherNumBain2->Show();
            bSizerAfficherDureeBain2->Show(this);
            
            bSizerAfficherDureeBain2->Layout();
            bSizerBainAfficherDuree->Layout();
            bSizerAfficherDureeBain1->Layout();
            bSizerAfficherBain->Layout();

            sbSizerGestionBainAfficher->Layout();
            Layout();
            
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[2];
                    
            m_staticTextAfficherNumBain2->SetLabel(m_frame->ConversionEnWxString(numero_bain[2]) + wxT(" :"));
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain2 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain2.empty())
                {
                    m_textCtrlAfficherHeureBain2->AppendText(m_frame->DecouperTexteDebut(duree_bain2[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain2[0], 5);
                    m_textCtrlAfficherMinuteBain2->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain2->AppendText(m_frame->DecouperTexteFin(duree_bain2[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 3
            m_staticAfficherDureeTotalBain3->Show();
            m_textCtrlAfficherHeureBain3->Show();
            m_staticTextAfficherDureeBain3->Show();
            m_textCtrlAfficherMinuteBain3->Show();
            m_staticTextAfficherDureeFinBain3->Show();
            m_textCtrlAfficherSecondeBain3->Show();
            m_staticTextAfficherNumBain3->Show();
            bSizerAfficherDureeBain3->Show(this);
            
            bSizerAfficherDureeBain3->Layout();
            bSizerBainAfficherDuree->Layout();
            bSizerAfficherDureeBain1->Layout();
            bSizerAfficherBain->Layout();

            sbSizerGestionBainAfficher->Layout();
            Layout();
            
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[3];
                    
            m_staticTextAfficherNumBain3->SetLabel(m_frame->ConversionEnWxString(numero_bain[3]) + wxT(" :"));
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain3 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain3.empty())
                {
                    m_textCtrlAfficherHeureBain3->AppendText(m_frame->DecouperTexteDebut(duree_bain3[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain3[0], 5);
                    m_textCtrlAfficherMinuteBain3->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlAfficherSecondeBain3->AppendText(m_frame->DecouperTexteFin(duree_bain3[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
        }
        else
        {
            EnvoiMessage(wxT("Pas de nombre de bain pour le remplissage.\n"));
        }
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(m_frame->ConversionEnString(id_selection)))
    {
        m_textCtrlOrdreTrajectoiresAfficher->AppendText(m_frame->ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires()));
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}
//
// Saisie au clavier
//
void EvtPanelResponsable::OnCharEntered(wxKeyEvent& event)
{
    event.Skip();
}

void EvtPanelResponsable::OnTextMaxLength(wxCommandEvent& event)
{
    EnvoiMessage(wxT("Nombre maximun de caractères entré dans ce champ.\n"));
}

void EvtPanelResponsable::OnCharEnteredNum(wxKeyEvent& event)
{
    switch(event.GetKeyCode())
    {
        case '0':

            event.Skip();
            break;

        case '1':

            event.Skip();
            break;

        case '2':

            event.Skip();
            break;

        case '3':

            event.Skip();
            break;

        case '4':
            event.Skip();
            break;

        case '5':

            event.Skip();
            break;

        case '6':

            event.Skip();
            break;

        case '7':

            event.Skip();
            break;

        case '8':

            event.Skip();
            break;

        case '9':

            event.Skip();
            break;

        case WXK_BACK:

            event.Skip();
            break;

        case WXK_DELETE:

            event.Skip();
            break;

        case WXK_TAB:

            event.Skip();
            break;

        case WXK_LEFT:

            event.Skip();
            break;

        case WXK_UP:

            event.Skip();
            break;

        case WXK_RIGHT:

            event.Skip();
            break;

        case WXK_DOWN:

            event.Skip();
            break;
        
        case WXK_NUMPAD_ENTER:
            
            event.Skip();
            break;
        
        default:

            // On ne fait rien
            break;
    }
}

void EvtPanelResponsable::OnCharEnteredOrdre(wxKeyEvent& event)
{
    switch(event.GetKeyCode())
    {
        case '0':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '1':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '2':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '3':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '4':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '5':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '6':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '7':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '8':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case '9':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = false;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = false;
                }
            }
            event.Skip();
            break;

        case ';':
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                if(!point_virgule_saisie_modifier)
                {
                    point_virgule_saisie_modifier = true;
                    event.Skip();
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                if(!point_virgule_saisie_creer)
                {
                    point_virgule_saisie_creer = true;
                    event.Skip();
                }
            }
            break;

        case WXK_BACK:  // Retour arrière
            if(event.GetId() == wxID_ORDRE_MODIFIER)
            {
                wxString temp = m_textCtrlOrdreTrajectoiresModifier->GetValue();

                if(!temp.IsEmpty())
                {
                    if(temp.Last() == wxT(';'))
                    {
                        point_virgule_saisie_modifier = false;
                    }

                    if(temp.length() == 1)
                    {
                        point_virgule_saisie_modifier = true;
                    }
                }
                else
                {
                    point_virgule_saisie_modifier = true;
                }
            }
            else if(event.GetId() == wxID_ORDRE_CREER)
            {
                wxString temp = m_textCtrlOrdreTrajectoiresCreer->GetValue();

                if(!temp.IsEmpty())
                {
                    if(temp.Last() == wxT(';'))
                    {
                        point_virgule_saisie_creer = false;
                    }

                    if(temp.length() == 1)
                    {
                        point_virgule_saisie_creer = true;
                    }
                }
                else
                {
                    point_virgule_saisie_creer = true;
                }
            }
            event.Skip();
            break;

        /*case WXK_DELETE: // Touche supprimer

            event.Skip();
            break;*/

        case WXK_TAB:  // Touche Tab

            event.Skip();
            break;

        case WXK_LEFT:  // Touche fleche gauche

            event.Skip();
            break;

        case WXK_UP:  // Touche fleche haut

            event.Skip();
            break;

        case WXK_RIGHT:  // Touche fleche droite

            event.Skip();
            break;

        case WXK_DOWN:  // Touche fleche bas

            event.Skip();
            break;
            
        case WXK_NUMPAD_ENTER: // Touche entrer
            
            event.Skip();
            break;
        
        default:

            // On ne fait rien
            break;
    }
}
//
// Modifier un processus
//
void EvtPanelResponsable::OnListBoxModifierSelection(wxCommandEvent& event)
{
    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(m_listBoxModifierProcessus->GetStringSelection());

    // Vider les text control
    // du coté droit
    m_textCtrlIdModifier->Clear();
    m_textCtrlDureeTotalHeureModifier->Clear();
    m_textCtrlDureeTotalMinuteModifier->Clear();
    m_textCtrlDureeTotalSecondeModifier->Clear();

    // Du coté gauche
    m_textCtrlNomModifier->Clear();
    m_textCtrlOrdreTrajectoiresModifier->Clear();
    m_textCtrlModifierHeureBain1->Clear();
    m_textCtrlModifierMinuteBain1->Clear();
    m_textCtrlModifierSecondeBain1->Clear();
    
    m_textCtrlModifierHeureBain2->Clear();
    m_textCtrlModifierMinuteBain2->Clear();
    m_textCtrlModifierSecondeBain2->Clear();
    
    m_textCtrlModifierHeureBain3->Clear();
    m_textCtrlModifierMinuteBain3->Clear();
    m_textCtrlModifierSecondeBain3->Clear();

    // Remplisage
    m_textCtrlIdModifier->AppendText(id_selection);

    // Durée total du processus
    if(m_donnees_IHM->RecupereDureeTotal(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_textCtrlDureeTotalHeureModifier->AppendText(m_frame->DecouperTexteDebut(duree, 2));

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        m_textCtrlDureeTotalMinuteModifier->AppendText(m_frame->DecouperTexteFin(temp, 3));

        m_textCtrlDureeTotalSecondeModifier->AppendText(m_frame->DecouperTexteFin(duree, 6));
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nom du processus
    if(m_donnees_IHM->RecupereNomProcessus(m_frame->ConversionEnString(id_selection)))
    {
        wxString temp = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomProcessus());

        int separateur = temp.find("   ");
        wxString nom = m_frame->DecouperTexteDebut(temp, separateur);

        m_textCtrlNomModifier->AppendText(nom);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(m_frame->ConversionEnString(id_selection)))
    {
        wxString nombre_bain = m_donnees_IHM->GetNombreBain();

        double temp;
        nombre_bain.ToDouble(&temp);
        int nb_bain = temp;

        m_spinCtrlNombreBainModifier->SetValue(nb_bain);
        m_textCtrlNombreBainAfficher->AppendText(m_frame->ConversionEnWxString(m_donnees_IHM->GetNombreBain()));
        string requete;
        requete = "SELECT numero_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                + m_frame->ConversionEnString(id_selection);
        
        vector<string> numero_bain;
        
        if(m_bdd_anodisation->ExecuteSelect(requete))
        {
            numero_bain = m_bdd_anodisation->GetLastResult();
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }

        switch(nb_bain)
        {
            case 1:

            m_staticModifierDureeTotalBain2->Hide();
            m_choiceModifierBain2->Hide();
            m_staticModifierBain2->Hide();
            m_staticModifierDureeTotalBain2->Hide();
            m_textCtrlModifierHeureBain2->Hide();
            m_staticTextModifierDureeBain2->Hide();
            m_textCtrlModifierMinuteBain2->Hide();
            m_staticTextModifierDureeFinBain2->Hide();
            m_textCtrlModifierSecondeBain2->Hide();
            bSizerModifierDureeBain2->Hide(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();
            
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_choiceModifierBain1->SetStringSelection(numero_bain[1]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlModifierHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlModifierMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            break;

        case 2:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();
            
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_choiceModifierBain1->SetStringSelection(numero_bain[1]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlModifierHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlModifierMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 2
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[2];
            
            m_choiceModifierBain2->SetStringSelection(numero_bain[2]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain2 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain2.empty())
                {
                    m_textCtrlModifierHeureBain2->AppendText(m_frame->DecouperTexteDebut(duree_bain2[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain2[0], 5);
                    m_textCtrlModifierMinuteBain2->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain2->AppendText(m_frame->DecouperTexteFin(duree_bain2[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            break;

        case 3:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Show();
            m_choiceModifierBain3->Show();
            m_staticModifierBain3->Show();
            m_staticModifierDureeTotalBain3->Show();
            m_textCtrlModifierHeureBain3->Show();
            m_staticTextModifierDureeBain3->Show();
            m_textCtrlModifierMinuteBain3->Show();
            m_staticTextModifierDureeFinBain3->Show();
            m_textCtrlModifierSecondeBain3->Show();
            bSizerModifierDureeBain3->Show(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();
            
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_choiceModifierBain1->SetStringSelection(numero_bain[1]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlModifierHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlModifierMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 2
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[2];
            
            m_choiceModifierBain2->SetStringSelection(numero_bain[2]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain2 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain2.empty())
                {
                    m_textCtrlModifierHeureBain2->AppendText(m_frame->DecouperTexteDebut(duree_bain2[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain2[0], 5);
                    m_textCtrlModifierMinuteBain2->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain2->AppendText(m_frame->DecouperTexteFin(duree_bain2[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 3
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[3];
            
            m_choiceModifierBain3->SetStringSelection(numero_bain[3]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain3 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain3.empty())
                {
                    m_textCtrlModifierHeureBain3->AppendText(m_frame->DecouperTexteDebut(duree_bain3[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain3[0], 5);
                    m_textCtrlModifierMinuteBain3->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain3->AppendText(m_frame->DecouperTexteFin(duree_bain3[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            break;

            default:

                break;
        }
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(m_frame->ConversionEnString(id_selection)))
    {
        m_textCtrlOrdreTrajectoiresModifier->AppendText(m_frame->ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires()));
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}

void EvtPanelResponsable::OnSpinCtrlModifierBain(wxSpinEvent& event)
{
    int nombre_bain = m_spinCtrlNombreBainModifier->GetValue();
    // cout << "Nombre de bain : " << nombre_bain << endl;
    switch(nombre_bain)
    {
        case 1:

            m_staticModifierDureeTotalBain2->Hide();
            m_choiceModifierBain2->Hide();
            m_staticModifierBain2->Hide();
            m_staticModifierDureeTotalBain2->Hide();
            m_textCtrlModifierHeureBain2->Hide();
            m_staticTextModifierDureeBain2->Hide();
            m_textCtrlModifierMinuteBain2->Hide();
            m_staticTextModifierDureeFinBain2->Hide();
            m_textCtrlModifierSecondeBain2->Hide();
            bSizerModifierDureeBain2->Hide(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        case 2:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        case 3:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Show();
            m_choiceModifierBain3->Show();
            m_staticModifierBain3->Show();
            m_staticModifierDureeTotalBain3->Show();
            m_textCtrlModifierHeureBain3->Show();
            m_staticTextModifierDureeBain3->Show();
            m_textCtrlModifierMinuteBain3->Show();
            m_staticTextModifierDureeFinBain3->Show();
            m_textCtrlModifierSecondeBain3->Show();
            bSizerModifierDureeBain3->Show(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();

            break;

        default:

            break;
    }
}

void EvtPanelResponsable::OnApplyButtonModifierClick(wxCommandEvent& event)
{
    if(!m_listBoxModifierProcessus->IsEmpty())
    {
        bool erreur = false;
        char* car = ";";
        string nom_processus;
        string duree_total;
        string ordre;
        string duree_bain1, duree_bain2 = "", duree_bain3 = "";
        string num_bain1, num_bain2, num_bain3;
        
        unsigned int nombre_bain = m_spinCtrlNombreBainModifier->GetValue();
        vector<string> ordre_separe;
        
        wxString id_selection = m_frame->GardeIdSelection(m_listBoxModifierProcessus->GetStringSelection());
        wxString message;
        wxUniChar caractere(*car);
        
        // Vérification du champ nom du processus s'il il est rempli
        if(!m_textCtrlNomModifier->IsEmpty())
        {
            nom_processus = m_frame->ConversionEnString(m_textCtrlNomModifier->GetValue());
        }
        else
        {
            erreur = true;
            message << wxT("Le champ nom du processus est vide.\n");
        }
        
        
        
        // Vérification du champ ordre des trajectoires s'il il est rempli
        if(!m_textCtrlDureeTotalHeureModifier->IsEmpty() && !m_textCtrlDureeTotalMinuteModifier->IsEmpty() && !m_textCtrlDureeTotalSecondeModifier->IsEmpty())
        {
            wxString verif = m_frame->VerificationDurree(m_textCtrlDureeTotalHeureModifier->GetValue(), m_textCtrlDureeTotalMinuteModifier->GetValue(), m_textCtrlDureeTotalSecondeModifier->GetValue());
            
            if(verif.IsSameAs(wxT("ok")))
            {
                duree_total = m_frame->ConversionEnString(m_textCtrlDureeTotalHeureModifier->GetValue()) + ":"
                            + m_frame->ConversionEnString(m_textCtrlDureeTotalMinuteModifier->GetValue()) + ":"
                            + m_frame->ConversionEnString(m_textCtrlDureeTotalSecondeModifier->GetValue());
            }
            else
            {
                erreur = true;
                message << wxT("Durée total processus non valide : ") << verif;
            }
        }
        else
        {
            erreur = true;
            message << wxT("L'un ou des champs de la durée total est/sont vide.\n");
        }
    
        // Vérification du champ ordre trajectoire s'il il est rempli
        if(!m_textCtrlOrdreTrajectoiresModifier->IsEmpty())
        {
            wxString ordrewx = m_textCtrlOrdreTrajectoiresModifier->GetValue();
            
            if(ordrewx.length() == 1)
            {
                ordrewx << wxT(";") << ordrewx;
                //wxLogDebug(ordrewx);
            }
            else if(ordrewx.length() == 2)
            {
                ordrewx << ordrewx;
                //wxLogDebug(ordrewx);
            }
            
            if(ordrewx.EndsWith(wxT(";")))
            {
                ordrewx.RemoveLast();
            }
            
            ordre = m_frame->ConversionEnString(ordrewx);
            
            unsigned int nb_point_virgule = ordrewx.Freq(caractere);
            unsigned int position;
            wxString temp;
            
            for(unsigned int i = 0; i < nb_point_virgule+1; i++)
            {
                if(i == 0)
                {
                    position = ordrewx.find(";");
                    ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteDebut(ordrewx, position)));
                }
                else
                {
                    if(i == nb_point_virgule)
                    {
                        position = ordrewx.find(";");
                        ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteFin(ordrewx, position+1)));
                    }
                    else
                    {
                        position = ordrewx.find(";");
                        temp.clear();
                        temp = m_frame->DecouperTexteFin(ordrewx, position+1);
                        position = temp.find(";");
                        ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteDebut(temp, position)));
                        ordrewx.clear();
                        ordrewx = (m_frame->DecouperTexteFin(temp, position));
                    }
                    
                }
            }
        }
        else
        {
            erreur = true;
            message << wxT("Le champ de la trajectoire est vide.\n");
        }
    
        // Vérification en fonction du nombre de bain
        switch(nombre_bain)
        {
            case 1:
                // Vérification des champs du bain 1 qu'il ont bien été rempli
                if(!m_textCtrlModifierHeureBain1->IsEmpty() && !m_textCtrlModifierMinuteBain1->IsEmpty()
                && !m_textCtrlModifierSecondeBain1->IsEmpty())
                {
                    wxString verif = m_frame->VerificationDurree(m_textCtrlModifierHeureBain1->GetValue(), m_textCtrlModifierMinuteBain1->GetValue(), m_textCtrlModifierSecondeBain1->GetValue());
                    
                    if(verif.IsSameAs(wxT("ok")))
                    {
                        duree_bain1 = m_frame->ConversionEnString(m_textCtrlModifierHeureBain1->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierMinuteBain1->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierSecondeBain1->GetValue());
                    }
                    else
                    {
                        erreur = true;
                        message << wxT("Durée total du bain 1 non valide :  ") << verif;
                    }
                }
                else
                {
                    erreur = true;
                    message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
                }
    
                break;
    
            case 2:
                num_bain1 = m_choiceCreerBain1->GetStringSelection();
                num_bain2 = m_choiceCreerBain2->GetStringSelection();
                
                if(num_bain1 == num_bain2)
                {
                    erreur = true;
                    message << wxT("Les deux numéros de bain sont identique.\n");
                }
                
                // Vérification des champs du bain 1 qu'ils ont bien été rempli
                if(!m_textCtrlModifierHeureBain1->IsEmpty() && !m_textCtrlModifierMinuteBain1->IsEmpty()
                && !m_textCtrlModifierSecondeBain1->IsEmpty())
                {
                    wxString verif = m_frame->VerificationDurree(m_textCtrlModifierHeureBain1->GetValue(), m_textCtrlModifierMinuteBain1->GetValue(), m_textCtrlModifierSecondeBain1->GetValue());
                    
                    if(verif.IsSameAs(wxT("ok")))
                    {
                        duree_bain1 = m_frame->ConversionEnString(m_textCtrlModifierHeureBain1->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierMinuteBain1->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierSecondeBain1->GetValue());
                    }
                    else
                    {
                        erreur = true;
                        message << wxT("Durée total du bain 1 non valide :  ") << verif;
                    }
                }
                else
                {
                    erreur = true;
                    message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
                }
    
                // Vérification des champs du bain 2 qu'ils ont bien été rempli
                if(!m_textCtrlModifierHeureBain2->IsEmpty() && !m_textCtrlModifierMinuteBain2->IsEmpty()
                && !m_textCtrlModifierSecondeBain2->IsEmpty())
                {
                    wxString verif = m_frame->VerificationDurree(m_textCtrlModifierHeureBain2->GetValue(), m_textCtrlModifierMinuteBain2->GetValue(), m_textCtrlModifierSecondeBain2->GetValue());
                    
                    if(verif.IsSameAs(wxT("ok")))
                    {
                        duree_bain2 = m_frame->ConversionEnString(m_textCtrlModifierHeureBain2->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierMinuteBain2->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierSecondeBain2->GetValue());
                    }
                    else
                    {
                        erreur = true;
                        message << wxT("Durée total du bain 2 non valide :  ") << verif;
                    }
                }
                else
                {
                    erreur = true;
                    message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
                }
    
                break;
    
            case 3:
                num_bain1 = m_choiceCreerBain1->GetStringSelection();
                num_bain2 = m_choiceCreerBain2->GetStringSelection();
                num_bain3 = m_choiceCreerBain2->GetStringSelection();
                
                if(num_bain1 == num_bain2 && num_bain1 == num_bain3 && num_bain2 == num_bain3)
                {
                    erreur = true;
                    message << wxT("Des numéros de bain sont identique.\n");
                }
                
                // Vérification des champs du bain 1 qu'ils ont bien été rempli
                if(!m_textCtrlModifierHeureBain1->IsEmpty() && !m_textCtrlModifierMinuteBain1->IsEmpty()
                && !m_textCtrlModifierSecondeBain1->IsEmpty())
                {
                    wxString verif = m_frame->VerificationDurree(m_textCtrlModifierHeureBain1->GetValue(), m_textCtrlModifierMinuteBain1->GetValue(), m_textCtrlModifierSecondeBain1->GetValue());
                    
                    if(verif.IsSameAs(wxT("ok")))
                    {
                        duree_bain1 = m_frame->ConversionEnString(m_textCtrlModifierHeureBain1->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierMinuteBain1->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierSecondeBain1->GetValue());
                    }
                    else
                    {
                        erreur = true;
                        message << wxT("Durée total du bain 1 non valide :  ") << verif;
                    }
                }
                else
                {
                    erreur = true;
                    message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
                }
                
                
                
                // Vérification des champs du bain 2 qu'ils ont bien été rempli
                if(!m_textCtrlModifierHeureBain2->IsEmpty() && !m_textCtrlModifierMinuteBain2->IsEmpty()
                && !m_textCtrlModifierSecondeBain2->IsEmpty())
                {
                    wxString verif = m_frame->VerificationDurree(m_textCtrlModifierHeureBain2->GetValue(), m_textCtrlModifierMinuteBain2->GetValue(), m_textCtrlModifierSecondeBain2->GetValue());
                    
                    if(verif.IsSameAs(wxT("ok")))
                    {
                        duree_bain2 = m_frame->ConversionEnString(m_textCtrlModifierHeureBain2->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierMinuteBain2->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierSecondeBain2->GetValue());
                    }
                    else
                    {
                        erreur = true;
                        message << wxT("Durée total du bain 2 non valide :  ") << verif;
                    }
                }
                else
                {
                    erreur = true;
                    message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
                }
                
                
                
                // Vérification des champs du bain 3 qu'ils ont bien été rempli
                if(!m_textCtrlModifierHeureBain3->IsEmpty() && !m_textCtrlModifierMinuteBain3->IsEmpty()
                && !m_textCtrlModifierSecondeBain3->IsEmpty())
                {
                    wxString verif = m_frame->VerificationDurree(m_textCtrlModifierHeureBain3->GetValue(), m_textCtrlModifierMinuteBain3->GetValue(), m_textCtrlModifierSecondeBain3->GetValue());
                    
                    if(verif.IsSameAs(wxT("ok")))
                    {
                        duree_bain3 = m_frame->ConversionEnString(m_textCtrlModifierHeureBain3->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierMinuteBain3->GetValue()) + ":"
                                    + m_frame->ConversionEnString(m_textCtrlModifierSecondeBain3->GetValue());
                    }
                    else
                    {
                        erreur = true;
                        message << wxT("Durée total du bain 3 non valide :  ") << verif;
                    }
                }
                else
                {
                    erreur = true;
                    message << wxT("L'un ou des champs de la durée du bain 3 est/sont vide.\n");
                }
    
                break;
    
            default:
    
                break;
        }
        
        if(erreur)
        {
            string id_p = m_bdd_anodisation->DernierIdProcessus();
            //cout << "id_p : " << id_p << endl;
            wxMessageBox(message, "Responsable de production - Champs invalide !",
                        wxOK_DEFAULT | wxICON_EXCLAMATION | wxCENTRE | wxSTAY_ON_TOP, this);
            EnvoiMessage(message);
        }
        else
        {
            string requete = "UPDATE processus SET nom_processus='" + nom_processus
                        + "', duree_processus='" + duree_total
                        + "', nombre_bain=" +  m_frame->IntEnString(nombre_bain)
                        + "WHERE id_processus=" + m_frame->ConversionEnString(id_selection);
            
            if(m_bdd_anodisation->ExecuteUpdate(requete))
            {
                switch(nombre_bain)
                {
                    case 1:
                        for(unsigned int i =0; i < ordre_separe.size(); i++)
                        {
                            requete = "UPDATE intermediaire_processus_trajectoires SET id_p=" + m_frame->ConversionEnString(id_selection)
                                    + ", id_t=" + ordre_separe[i]
                                    + ", ordre_trajectoires='" + ordre
                                    + "', numero_bain=" + num_bain1
                                    + ", duree_bain='" + duree_bain1
                                    + "' WHERE id_p=" + m_frame->ConversionEnString(id_selection);
                                    
                            //cout << requete << endl;
                            
                            if(!m_bdd_anodisation->ExecuteUpdate(requete))
                            {
                                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                            }
                            
                        }
                        break;
                    
                    case 2:
                        for(unsigned int i =0; i < ordre_separe.size(); i++)
                        {
                            if(i == 1)
                            {
                                requete = "UPDATE intermediaire_processus_trajectoires SET id_p=" + m_frame->ConversionEnString(id_selection)
                                        + ", id_t=" + ordre_separe[i]
                                        + ", ordre_trajectoires='" + ordre
                                        + "', numero_bain=" + num_bain2
                                        + ", duree_bain='" + duree_bain2
                                        + "' WHERE id_p=" + m_frame->ConversionEnString(id_selection);
                                
                                if(!m_bdd_anodisation->ExecuteUpdate(requete))
                                {
                                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                                }
                            }
                            else
                            {
                                requete = "UPDATE intermediaire_processus_trajectoires SET id_p=" + m_frame->ConversionEnString(id_selection)
                                        + ", id_t=" + ordre_separe[i]
                                        + ", ordre_trajectoires='" + ordre
                                        + "', numero_bain=" + num_bain1
                                        + ", duree_bain='" + duree_bain1
                                        + "' WHERE id_p=" + m_frame->ConversionEnString(id_selection);
                                
                                if(!m_bdd_anodisation->ExecuteUpdate(requete))
                                {
                                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                                }
                            }
                            
                        }
                        break;
                    
                    case 3:
                        for(unsigned int i =0; i < ordre_separe.size(); i++)
                        {
                            if(i == 1)
                            {
                                requete = "UPDATE intermediaire_processus_trajectoires SET id_p=" + m_frame->ConversionEnString(id_selection)
                                        + ", id_t=" + ordre_separe[i]
                                        + ", ordre_trajectoires='" + ordre
                                        + "', numero_bain=" + num_bain2
                                        + ", duree_bain='" + duree_bain2
                                        + "' WHERE id_p=" + m_frame->ConversionEnString(id_selection);
                                
                                if(!m_bdd_anodisation->ExecuteUpdate(requete))
                                {
                                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                                }
                            }
                            else if(i == 2)
                            {
                                requete = "UPDATE intermediaire_processus_trajectoires SET id_p=" + m_frame->ConversionEnString(id_selection)
                                        + ", id_t=" + ordre_separe[i]
                                        + ", ordre_trajectoires='" + ordre
                                        + "', numero_bain=" + num_bain3
                                        + ", duree_bain='" + duree_bain3
                                        + "' WHERE id_p=" + m_frame->ConversionEnString(id_selection);
                                
                                if(!m_bdd_anodisation->ExecuteUpdate(requete))
                                {
                                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                                }
                            }
                            else
                            {
                                requete = "UPDATE intermediaire_processus_trajectoires SET id_p=" + m_frame->ConversionEnString(id_selection)
                                        + ", id_t=" + ordre_separe[i]
                                        + ", ordre_trajectoires='" + ordre
                                        + "', numero_bain=" + num_bain1
                                        + ", duree_bain='" + duree_bain1
                                        + "' WHERE id_p=" + m_frame->ConversionEnString(id_selection);
                                
                                if(!m_bdd_anodisation->ExecuteUpdate(requete))
                                {
                                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                                }
                            }
                            
                        }
                        break;
                    
                    default:
                        
                        break;
                    
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            VideListBox();
            RempliListBox();
            m_listBoxModifierProcessus->SetSelection(m_frame->wxStringToInt(id_selection));
            m_listBoxModifierProcessus->SetFocus();
        }
    }
    else
    {
        wxString message = wxT("Modification impossible, car il n’y a aucun processus dans la base de données. Merci d’en créer et de réessayer.");
        wxMessageBox(message, "Responsable de production - Modification impossible !", wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
        EnvoiMessage(message);
    }
}

void EvtPanelResponsable::OnCancelButtonModiffierClick(wxCommandEvent& event)
{
    if(!m_listBoxModifierProcessus->IsEmpty())
    {
        // TODO: Implement OnCancelButtonModiffierClick
        // Récupération de la saisie
        wxString selection = m_listBoxModifierProcessus->GetStringSelection();
    
        // Récupération de l'id du processus
        wxString id_selection = m_frame->GardeIdSelection(selection);
    
        // Vider les text control
        // du coté droit
        m_textCtrlIdModifier->Clear();
        m_textCtrlDureeTotalHeureModifier->Clear();
        m_textCtrlDureeTotalMinuteModifier->Clear();
        m_textCtrlDureeTotalSecondeModifier->Clear();
    
        // Du coté gauche
        m_textCtrlNomModifier->Clear();
        m_textCtrlOrdreTrajectoiresModifier->Clear();
    
        // Remplisage
        m_textCtrlIdModifier->AppendText(id_selection);
    
        // Durée total du processus
        if(m_donnees_IHM->RecupereDureeTotal(m_frame->ConversionEnString(id_selection)))
        {
            wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
            wxString heure = m_frame->DecouperTexteDebut(duree, 2);
            m_textCtrlDureeTotalHeureModifier->AppendText(heure);
    
            wxString temp = m_frame->DecouperTexteDebut(duree, 5);
            wxString minute = m_frame->DecouperTexteFin(temp, 3);
            m_textCtrlDureeTotalMinuteModifier->AppendText(minute);
    
            wxString seconde = m_frame->DecouperTexteFin(duree, 6);
            m_textCtrlDureeTotalSecondeModifier->AppendText(seconde);
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
        }
    
        // Nom du processus
        if(m_donnees_IHM->RecupereNomProcessus(m_frame->ConversionEnString(id_selection)))
        {
            wxString temp = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomProcessus());
    
            int separateur = temp.find("   ");
            wxString nom = m_frame->DecouperTexteDebut(temp, separateur);
    
            m_textCtrlNomModifier->AppendText(nom);
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
            
        }
    
        // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(m_frame->ConversionEnString(id_selection)))
    {
        wxString nombre_bain = m_donnees_IHM->GetNombreBain();

        double temp;
        nombre_bain.ToDouble(&temp);
        int nb_bain = temp;

        m_spinCtrlNombreBainModifier->SetValue(nb_bain);
        m_textCtrlNombreBainAfficher->AppendText(m_frame->ConversionEnWxString(m_donnees_IHM->GetNombreBain()));
        string requete;
        requete = "SELECT numero_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                + m_frame->ConversionEnString(id_selection);
        
        vector<string> numero_bain;
        
        if(m_bdd_anodisation->ExecuteSelect(requete))
        {
            numero_bain = m_bdd_anodisation->GetLastResult();
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }

        switch(nb_bain)
        {
            case 1:

            m_staticModifierDureeTotalBain2->Hide();
            m_choiceModifierBain2->Hide();
            m_staticModifierBain2->Hide();
            m_staticModifierDureeTotalBain2->Hide();
            m_textCtrlModifierHeureBain2->Hide();
            m_staticTextModifierDureeBain2->Hide();
            m_textCtrlModifierMinuteBain2->Hide();
            m_staticTextModifierDureeFinBain2->Hide();
            m_textCtrlModifierSecondeBain2->Hide();
            bSizerModifierDureeBain2->Hide(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();
            
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_choiceModifierBain1->SetStringSelection(numero_bain[1]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlModifierHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlModifierMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            break;

        case 2:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Hide();
            m_choiceModifierBain3->Hide();
            m_staticModifierBain3->Hide();
            m_staticModifierDureeTotalBain3->Hide();
            m_textCtrlModifierHeureBain3->Hide();
            m_staticTextModifierDureeBain3->Hide();
            m_textCtrlModifierMinuteBain3->Hide();
            m_staticTextModifierDureeFinBain3->Hide();
            m_textCtrlModifierSecondeBain3->Hide();
            bSizerModifierDureeBain3->Hide(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();
            
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_choiceModifierBain1->SetStringSelection(numero_bain[1]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlModifierHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlModifierMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 2
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[2];
            
            m_choiceModifierBain2->SetStringSelection(numero_bain[2]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain2 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain2.empty())
                {
                    m_textCtrlModifierHeureBain2->AppendText(m_frame->DecouperTexteDebut(duree_bain2[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain2[0], 5);
                    m_textCtrlModifierMinuteBain2->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain2->AppendText(m_frame->DecouperTexteFin(duree_bain2[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            break;

        case 3:

            m_staticModifierDureeTotalBain2->Show();
            m_choiceModifierBain2->Show();
            m_staticModifierBain2->Show();
            m_staticModifierDureeTotalBain2->Show();
            m_textCtrlModifierHeureBain2->Show();
            m_staticTextModifierDureeBain2->Show();
            m_textCtrlModifierMinuteBain2->Show();
            m_staticTextModifierDureeFinBain2->Show();
            m_textCtrlModifierSecondeBain2->Show();
            bSizerModifierDureeBain2->Show(this);

            m_staticModifierDureeTotalBain3->Show();
            m_choiceModifierBain3->Show();
            m_staticModifierBain3->Show();
            m_staticModifierDureeTotalBain3->Show();
            m_textCtrlModifierHeureBain3->Show();
            m_staticTextModifierDureeBain3->Show();
            m_textCtrlModifierMinuteBain3->Show();
            m_staticTextModifierDureeFinBain3->Show();
            m_textCtrlModifierSecondeBain3->Show();
            bSizerModifierDureeBain3->Show(this);

            bSizerModifierDureeBain2->Layout();
            bSizerModifierDureeBain3->Layout();
            bSizerBainModifierDuree->Layout();
            bSizerModifierDureeBain1->Layout();
            bSizerModifierBain->Layout();

            sbSizerGestionBainModifier->Layout();
            Layout();
            
            // Bain 1
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[1];
            
            m_choiceModifierBain1->SetStringSelection(numero_bain[1]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain1 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain1.empty())
                {
                    m_textCtrlModifierHeureBain1->AppendText(m_frame->DecouperTexteDebut(duree_bain1[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain1[0], 5);
                    m_textCtrlModifierMinuteBain1->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain1->AppendText(m_frame->DecouperTexteFin(duree_bain1[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le premier bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 2
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[2];
            
            m_choiceModifierBain2->SetStringSelection(numero_bain[2]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain2 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain2.empty())
                {
                    m_textCtrlModifierHeureBain2->AppendText(m_frame->DecouperTexteDebut(duree_bain2[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain2[0], 5);
                    m_textCtrlModifierMinuteBain2->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain2->AppendText(m_frame->DecouperTexteFin(duree_bain2[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
            
            
            
            // Bain 3
            requete = "SELECT duree_bain FROM intermediaire_processus_trajectoires WHERE id_p="
                    + m_frame->ConversionEnString(id_selection) + " AND numero_bain=" + numero_bain[3];
            
            m_choiceModifierBain3->SetStringSelection(numero_bain[3]);
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> duree_bain3 = m_bdd_anodisation->GetLastResult();
                
                if(!duree_bain3.empty())
                {
                    m_textCtrlModifierHeureBain3->AppendText(m_frame->DecouperTexteDebut(duree_bain3[0], 2));
                    
                    wxString temp = m_frame->DecouperTexteDebut(duree_bain3[0], 5);
                    m_textCtrlModifierMinuteBain3->AppendText(m_frame->DecouperTexteFin(temp, 3));
                    
                    m_textCtrlModifierSecondeBain3->AppendText(m_frame->DecouperTexteFin(duree_bain3[0], 6));
                }
                else
                {
                    EnvoiMessage(wxT("Il n'y a pas de durée pour le deuxième bain de ce processus.\n"));
                }
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            break;

            default:

                break;
        }
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
        // Ordre des trajectoires
        if(m_donnees_IHM->RecupereOrdreTrajectoires(m_frame->ConversionEnString(id_selection)))
        {
            wxString ordre = m_frame->ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());
    
            m_textCtrlOrdreTrajectoiresModifier->AppendText(ordre);
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
        }
    }
    else
    {
        wxString message = wxT("Annulation impossible, car il n’y a aucun processus dans la base de données pour le remplissage. Merci d’en créer et de réessayer.");
        wxMessageBox(message, "Responsable de production - Annulation impossible !", wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
        EnvoiMessage(message);
    }
}
//
// Créer un processus
//
void EvtPanelResponsable::OnCancelButtonCreerClick(wxCommandEvent& event)
{
    // Vider les champs
    m_textCtrlDureeTotalHeureCreer->Clear();
    m_textCtrlDureeTotalMinuteCreer->Clear();
    m_textCtrlDureeTotalSecondeCreer->Clear();
    m_textCtrlNomCreer->Clear();
    m_textCtrlOrdreTrajectoiresCreer->Clear();
    m_spinCtrlNombreBainCreer->SetValue(1);
    m_textCtrlCreerHeureBain1->Clear();
    m_textCtrlCreerMinuteBain1->Clear();
    m_textCtrlCreerSecondeBain1->Clear();
    m_textCtrlCreerHeureBain2->Clear();
    m_textCtrlCreerMinuteBain2->Clear();
    m_textCtrlCreerSecondeBain2->Clear();
    m_textCtrlCreerHeureBain3->Clear();
    m_textCtrlCreerMinuteBain3->Clear();
    m_textCtrlCreerSecondeBain3->Clear();
    
    m_choiceCreerBain1->SetSelection(0);
    
    // Cacher les réglage des bain 2 et 3
    m_staticCreerDureeTotalBain2->Hide();
    m_choiceCreerBain2->Hide();
    m_choiceCreerBain2->SetSelection(1);
    m_staticCreerBain2->Hide();
    m_textCtrlCreerHeureBain2->Hide();
    m_staticTextCreerDureeBain2->Hide();
    m_textCtrlCreerMinuteBain2->Hide();
    m_staticTextCreerDureeFinBain2->Hide();
    m_textCtrlCreerSecondeBain2->Hide();
    bSizerCreerDureeBain2->Hide(this);

    m_staticCreerDureeTotalBain3->Hide();
    m_choiceCreerBain3->Hide();
    m_choiceCreerBain3->SetSelection(2);
    m_staticCreerBain3->Hide();
    m_textCtrlCreerHeureBain3->Hide();
    m_staticTextCreerDureeBain3->Hide();
    m_textCtrlCreerMinuteBain3->Hide();
    m_staticTextCreerDureeFinBain3->Hide();
    m_textCtrlCreerSecondeBain3->Hide();
    bSizerCreerDureeBain3->Hide(this);

    bSizerCreerDureeBain2->Layout();
    bSizerCreerDureeBain3->Layout();
    bSizerBainCreerDuree->Layout();
    bSizerCreerDureeBain1->Layout();
    bSizerCreerBain->Layout();

    sbSizerGestionBainCreer->Layout();
    Layout();
}

void EvtPanelResponsable::OnSaveButtonCreerClick(wxCommandEvent& event)
{
    bool erreur = false;
    char* car = ";";
    string nom_processus;
    string duree_total;
    string ordre;
    string duree_bain1, duree_bain2 = "", duree_bain3 = "";
    string num_bain1, num_bain2, num_bain3;
    unsigned int nombre_bain = m_spinCtrlNombreBainCreer->GetValue();
    vector<string> ordre_separe;
    wxString message;
    wxUniChar caractere(*car);
    
    // Vérification du champ nom du processus s'il il est rempli
    if(!m_textCtrlNomCreer->IsEmpty())
    {
        nom_processus = m_frame->ConversionEnString(m_textCtrlNomCreer->GetValue());
    }
    else
    {
        erreur = true;
        message << wxT("Le champ nom du processus est vide.\n");
    }

    // Vérification du champ ordre des trajectoires s'il il est rempli
    if(!m_textCtrlDureeTotalHeureCreer->IsEmpty() && !m_textCtrlDureeTotalMinuteCreer->IsEmpty() && !m_textCtrlDureeTotalSecondeCreer->IsEmpty())
    {
        wxString verif = m_frame->VerificationDurree(m_textCtrlDureeTotalHeureCreer->GetValue(), m_textCtrlDureeTotalMinuteCreer->GetValue(), m_textCtrlDureeTotalSecondeCreer->GetValue());
                
        if(verif.IsSameAs(wxT("ok")))
        {
            duree_total = m_frame->ConversionEnString(m_textCtrlDureeTotalHeureCreer->GetValue()) + ":"
                        + m_frame->ConversionEnString(m_textCtrlDureeTotalMinuteCreer->GetValue()) + ":"
                        + m_frame->ConversionEnString(m_textCtrlDureeTotalSecondeCreer->GetValue());
        }
        else
        {
            erreur = true;
            message << wxT("Durée total processus non valide : ") << verif;
        }
    }
    else
    {
        erreur = true;
        message << wxT("L'un ou des champs de la durée total est/sont vide.\n");
    }

    // Vérification du champ ordre trajectoire s'il il est rempli
    if(!m_textCtrlOrdreTrajectoiresCreer->IsEmpty())
    {
        wxString ordrewx = m_textCtrlOrdreTrajectoiresCreer->GetValue();
        
        if(ordrewx.length() == 1)
        {
            ordrewx << wxT(";") << ordrewx;
            wxLogDebug(ordrewx);
        }
        else if(ordrewx.length() == 2)
        {
            ordrewx << ordrewx;
            wxLogDebug(ordrewx);
        }
        
        if(ordrewx.EndsWith(wxT(";")))
        {
            ordrewx.RemoveLast();
        }
        
        ordre = m_frame->ConversionEnString(ordrewx);
        
        unsigned int nb_point_virgule = ordrewx.Freq(caractere);
        unsigned int position;
        wxString temp;
        
        for(unsigned int i = 0; i < nb_point_virgule+1; i++)
        {
            if(i == 0)
            {
                position = ordrewx.find(";");
                ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteDebut(ordrewx, position)));
            }
            else
            {
                if(i == nb_point_virgule)
                {
                    position = ordrewx.find(";");
                    ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteFin(ordrewx, position+1)));
                }
                else
                {
                    position = ordrewx.find(";");
                    temp.clear();
                    temp = m_frame->DecouperTexteFin(ordrewx, position+1);
                    position = temp.find(";");
                    ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteDebut(temp, position)));
                    ordrewx.clear();
                    ordrewx = (m_frame->DecouperTexteFin(temp, position));
                }
                
            }
        }
    }
    else
    {
        erreur = true;
        message << wxT("Le champ de la trajectoire est vide.\n");
    }

    // Vérification en fonction du nombre de bain
    switch(nombre_bain)
    {
        case 1:
            num_bain1 = m_choiceCreerBain1->GetStringSelection();
            // Vérification des champs du bain 1 qu'il ont bien été rempli
            if(!m_textCtrlCreerHeureBain1->IsEmpty() && !m_textCtrlCreerMinuteBain1->IsEmpty()
               && !m_textCtrlCreerSecondeBain1->IsEmpty())
            {
                wxString verif = m_frame->VerificationDurree(m_textCtrlCreerHeureBain1->GetValue(), m_textCtrlCreerMinuteBain1->GetValue(), m_textCtrlCreerSecondeBain1->GetValue());
                
                if(verif.IsSameAs(wxT("ok")))
                {
                    duree_bain1 = m_frame->ConversionEnString(m_textCtrlCreerHeureBain1->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerMinuteBain1->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerSecondeBain1->GetValue());
                }
                else
                {
                    erreur = true;
                    message << wxT("Durée total du bain 1 non valide :  ") << verif;
                }
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }

            break;

        case 2:
            num_bain1 = m_choiceCreerBain1->GetStringSelection();
            num_bain2 = m_choiceCreerBain2->GetStringSelection();
            
            if(num_bain1 == num_bain2)
            {
                erreur = true;
                message << wxT("Les deux numéros de bain sont identique.\n");
            }
            
            // Vérification des champs du bain 1 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain1->IsEmpty() && !m_textCtrlCreerMinuteBain1->IsEmpty()
               && !m_textCtrlCreerSecondeBain1->IsEmpty())
            {
                wxString verif = m_frame->VerificationDurree(m_textCtrlCreerHeureBain1->GetValue(), m_textCtrlCreerMinuteBain1->GetValue(), m_textCtrlCreerSecondeBain1->GetValue());
                
                if(verif.IsSameAs(wxT("ok")))
                {
                    duree_bain1 = m_frame->ConversionEnString(m_textCtrlCreerHeureBain1->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerMinuteBain1->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerSecondeBain1->GetValue());
                }
                else
                {
                    erreur = true;
                    message << wxT("Durée total du bain 1 non valide :  ") << verif;
                }
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }
            
            // Vérification des champs du bain 2 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain2->IsEmpty() && !m_textCtrlCreerMinuteBain2->IsEmpty()
               && !m_textCtrlCreerSecondeBain2->IsEmpty())
            {
                wxString verif = m_frame->VerificationDurree(m_textCtrlCreerHeureBain2->GetValue(), m_textCtrlCreerMinuteBain2->GetValue(), m_textCtrlCreerSecondeBain2->GetValue());
                
                if(verif.IsSameAs(wxT("ok")))
                {
                    duree_bain2 = m_frame->ConversionEnString(m_textCtrlCreerHeureBain2->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerMinuteBain2->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerSecondeBain2->GetValue());
                }
                else
                {
                    erreur = true;
                    message << wxT("Durée total du bain 2 non valide :  ") << verif;
                }
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
            }

            break;

        case 3:
            num_bain1 = m_choiceCreerBain1->GetStringSelection();
            num_bain2 = m_choiceCreerBain2->GetStringSelection();
            num_bain3 = m_choiceCreerBain2->GetStringSelection();
            
            if(num_bain1 == num_bain2 && num_bain1 == num_bain3 && num_bain2 == num_bain3)
            {
                erreur = true;
                message << wxT("Des numéros de bain sont identique.\n");
            }
            
            // Vérification des champs du bain 1 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain1->IsEmpty() && !m_textCtrlCreerMinuteBain1->IsEmpty()
               && !m_textCtrlCreerSecondeBain1->IsEmpty())
            {
                wxString verif = m_frame->VerificationDurree(m_textCtrlCreerHeureBain1->GetValue(), m_textCtrlCreerMinuteBain1->GetValue(), m_textCtrlCreerSecondeBain1->GetValue());
                
                if(verif.IsSameAs(wxT("ok")))
                {
                    duree_bain1 = m_frame->ConversionEnString(m_textCtrlCreerHeureBain1->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerMinuteBain1->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerSecondeBain1->GetValue());
                }
                else
                {
                    erreur = true;
                    message << wxT("Durée total du bain 1 non valide :  ") << verif;
                }
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 1 est/sont vide.\n");
            }

            // Vérification des champs du bain 2 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain2->IsEmpty() && !m_textCtrlCreerMinuteBain2->IsEmpty()
               && !m_textCtrlCreerSecondeBain2->IsEmpty())
            {
                wxString verif = m_frame->VerificationDurree(m_textCtrlCreerHeureBain2->GetValue(), m_textCtrlCreerMinuteBain2->GetValue(), m_textCtrlCreerSecondeBain2->GetValue());
                
                if(verif.IsSameAs(wxT("ok")))
                {
                    duree_bain2 = m_frame->ConversionEnString(m_textCtrlCreerHeureBain2->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerMinuteBain2->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerSecondeBain2->GetValue());
                }
                else
                {
                    erreur = true;
                    message << wxT("Durée total du bain 2 non valide :  ") << verif;
                }
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 2 est/sont vide.\n");
            }

            // Vérification des champs du bain 3 qu'ils ont bien été rempli
            if(!m_textCtrlCreerHeureBain3->IsEmpty() && !m_textCtrlCreerMinuteBain3->IsEmpty()
               && !m_textCtrlCreerSecondeBain3->IsEmpty())
            {
                wxString verif = m_frame->VerificationDurree(m_textCtrlCreerHeureBain3->GetValue(), m_textCtrlCreerMinuteBain3->GetValue(), m_textCtrlCreerSecondeBain3->GetValue());
                
                if(verif.IsSameAs(wxT("ok")))
                {
                    duree_bain3 = m_frame->ConversionEnString(m_textCtrlCreerHeureBain3->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerMinuteBain3->GetValue()) + ":"
                                + m_frame->ConversionEnString(m_textCtrlCreerSecondeBain3->GetValue());
                }
                else
                {
                    erreur = true;
                    message << wxT("Durée total du bain 3 non valide :  ") << verif;
                }
            }
            else
            {
                erreur = true;
                message << wxT("L'un ou des champs de la durée du bain 3 est/sont vide.\n");
            }

            break;

        default:

            break;
    }
    
    if(erreur)
    {
        //string id_p = m_bdd_anodisation->DernierIdProcessus();
        //cout << "id_p : " << id_p << endl;
        wxMessageBox(message, "Responsable de production - Champs vide !", wxOK_DEFAULT | wxICON_EXCLAMATION | wxCENTRE | wxSTAY_ON_TOP, this);
        EnvoiMessage(message);
    }
    else
    {
        string requete = "INSERT INTO processus (nom_processus, duree_processus, nombre_bain) VALUES('" 
                        + nom_processus + "', '"
                        + duree_total + "', "
                        + m_frame->IntEnString(nombre_bain) + ")";
        
        if(m_bdd_anodisation->ExecuteInsert(requete))
        {
            
            string id_p = m_bdd_anodisation->DernierIdProcessus();
            
            switch(nombre_bain)
            {
                case 1:
                    for(unsigned int i =0; i < ordre_separe.size(); i++)
                    {
                        requete = "INSERT INTO intermediaire_processus_trajectoires (id_p, id_t, ordre_trajectoires, numero_bain, duree_bain) VALUES ("
                                + id_p + ", "
                                + ordre_separe[i] + ", '"
                                + ordre + "', "
                                + num_bain1 + ", '"
                                + duree_bain1 + "')";
                                cout << requete << endl;
                        
                        if(!m_bdd_anodisation->ExecuteInsert(requete))
                        {
                            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                        }
                    }
                    break;
                
                case 2:
                    for(unsigned int i =0; i < ordre_separe.size(); i++)
                    {
                        if(i == 1)
                        {
                            requete = "INSERT INTO intermediaire_processus_trajectoires (id_p, id_t, ordre_trajectoires, numero_bain, duree_bain) VALUES ("
                                    + id_p + ", "
                                    + ordre_separe[i] + ", '"
                                    + ordre + "', "
                                    + num_bain2 + ", '"
                                    + duree_bain2 + "')";
                            
                            if(!m_bdd_anodisation->ExecuteInsert(requete))
                            {
                                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                            }
                        }
                        else
                        {
                            requete = "INSERT INTO intermediaire_processus_trajectoires (id_p, id_t, ordre_trajectoires, numero_bain, duree_bain) VALUES ("
                                    + id_p + ", "
                                    + ordre_separe[i] + ", '"
                                    + ordre + "', "
                                    + num_bain1 + ", '"
                                    + duree_bain1 + "')";
                            
                            if(!m_bdd_anodisation->ExecuteInsert(requete))
                            {
                                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                            }
                        }
                    }
                    break;
                
                case 3:
                    for(unsigned int i =0; i < ordre_separe.size(); i++)
                    {
                        if(i == 1)
                        {
                            requete = "INSERT INTO intermediaire_processus_trajectoires (id_p, id_t, ordre_trajectoires, numero_bain, duree_bain) VALUES ("
                                    + id_p + ", "
                                    + ordre_separe[i] + ", '"
                                    + ordre + "', "
                                    + num_bain2 + ", '"
                                    + duree_bain2 + "')";
                            
                            if(!m_bdd_anodisation->ExecuteInsert(requete))
                            {
                                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                            }
                        }
                        else if(i == 2)
                        {
                            requete = "INSERT INTO intermediaire_processus_trajectoires (id_p, id_t, ordre_trajectoires, numero_bain, duree_bain) VALUES ("
                                    + id_p + ", "
                                    + ordre_separe[i] + ", '"
                                    + ordre + "', "
                                    + num_bain3 + ", '"
                                    + duree_bain3 + "')";
                            
                            if(!m_bdd_anodisation->ExecuteInsert(requete))
                            {
                                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                            }
                        }
                        else
                        {
                            requete = "INSERT INTO intermediaire_processus_trajectoires (id_p, id_t, ordre_trajectoires, numero_bain, duree_bain) VALUES ("
                                    + id_p + ", "
                                    + ordre_separe[i] + ", '"
                                    + ordre + "', "
                                    + num_bain1 + ", '"
                                    + duree_bain1 + "')";
                            
                            if(!m_bdd_anodisation->ExecuteInsert(requete))
                            {
                                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                            }
                        }
                    }
                    break;
                
                default:
                    
                    break;
                
            }
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
    }
    
    VideListBox();
    RempliListBox();
}

void EvtPanelResponsable::OnSpinCtrlCreerBain(wxSpinEvent& event)
{
    int nombre_bain = m_spinCtrlNombreBainCreer->GetValue();
    // cout << "Nombre de bain : " << nombre_bain << endl;

    switch(nombre_bain)
    {
        case 1:

            m_staticCreerDureeTotalBain2->Hide();
            m_choiceCreerBain2->Hide();
            m_staticCreerBain2->Hide();
            m_textCtrlCreerHeureBain2->Hide();
            m_staticTextCreerDureeBain2->Hide();
            m_textCtrlCreerMinuteBain2->Hide();
            m_staticTextCreerDureeFinBain2->Hide();
            m_textCtrlCreerSecondeBain2->Hide();
            bSizerCreerDureeBain2->Hide(this);

            m_staticCreerDureeTotalBain3->Hide();
            m_choiceCreerBain3->Hide();
            m_staticCreerBain3->Hide();
            m_textCtrlCreerHeureBain3->Hide();
            m_staticTextCreerDureeBain3->Hide();
            m_textCtrlCreerMinuteBain3->Hide();
            m_staticTextCreerDureeFinBain3->Hide();
            m_textCtrlCreerSecondeBain3->Hide();
            bSizerCreerDureeBain3->Hide(this);

            bSizerCreerDureeBain2->Layout();
            bSizerCreerDureeBain3->Layout();
            bSizerBainCreerDuree->Layout();
            bSizerCreerDureeBain1->Layout();
            bSizerCreerBain->Layout();

            sbSizerGestionBainCreer->Layout();
            Layout();

            break;

        case 2:

            m_staticCreerDureeTotalBain2->Show();
            m_choiceCreerBain2->Show();
            m_staticCreerBain2->Show();
            m_textCtrlCreerHeureBain2->Show();
            m_staticTextCreerDureeBain2->Show();
            m_textCtrlCreerMinuteBain2->Show();
            m_staticTextCreerDureeFinBain2->Show();
            m_textCtrlCreerSecondeBain2->Show();
            bSizerCreerDureeBain2->Show(this);

            m_staticCreerDureeTotalBain3->Hide();
            m_choiceCreerBain3->Hide();
            m_staticCreerBain3->Hide();
            m_textCtrlCreerHeureBain3->Hide();
            m_staticTextCreerDureeBain3->Hide();
            m_textCtrlCreerMinuteBain3->Hide();
            m_staticTextCreerDureeFinBain3->Hide();
            m_textCtrlCreerSecondeBain3->Hide();
            bSizerCreerDureeBain3->Hide(this);

            bSizerCreerDureeBain2->Layout();
            bSizerCreerDureeBain3->Layout();
            bSizerBainCreerDuree->Layout();
            bSizerCreerDureeBain1->Layout();
            bSizerCreerBain->Layout();

            sbSizerGestionBainCreer->Layout();
            Layout();

            break;

        case 3:

            m_staticCreerDureeTotalBain2->Show();
            m_choiceCreerBain2->Show();
            m_staticCreerBain2->Show();
            m_textCtrlCreerHeureBain2->Show();
            m_staticTextCreerDureeBain2->Show();
            m_textCtrlCreerMinuteBain2->Show();
            m_staticTextCreerDureeFinBain2->Show();
            m_textCtrlCreerSecondeBain2->Show();
            bSizerCreerDureeBain2->Show(this);

            m_staticCreerDureeTotalBain3->Show();
            m_choiceCreerBain3->Show();
            m_staticCreerBain3->Show();
            m_textCtrlCreerHeureBain3->Show();
            m_staticTextCreerDureeBain3->Show();
            m_textCtrlCreerMinuteBain3->Show();
            m_staticTextCreerDureeFinBain3->Show();
            m_textCtrlCreerSecondeBain3->Show();
            bSizerCreerDureeBain3->Show(this);

            bSizerCreerDureeBain2->Layout();
            bSizerCreerDureeBain3->Layout();
            bSizerBainCreerDuree->Layout();
            bSizerCreerDureeBain1->Layout();
            bSizerCreerBain->Layout();

            sbSizerGestionBainCreer->Layout();
            Layout();

            break;

        default:

            break;
    }
}
//
// Détruire un processus
//
void EvtPanelResponsable::OnListBoxDetruireSelection(wxCommandEvent& event)
{
    wxString selection = m_listBoxDetruireProcessus->GetStringSelection();

    wxString message;
    int separateur = selection.find(" - ");
    message << m_frame->DecouperTexteFin(selection, separateur + 3) << wxT("\n");
    m_staticTextDetuireTitre->SetLabel(message);

    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(selection);

    // Durée total
    if(m_donnees_IHM->RecupereDureeTotal(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_staticTextDureeTotalValeurDetruire->SetLabel(duree);
    }
    else
    {
        m_staticTextDureeTotalValeurDetruire->SetLabel(wxT("00:00:00"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(m_frame->ConversionEnString(id_selection)))
    {
        m_staticTextNombreBainValeurDetruire->SetLabel(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        m_staticTextNombreBainValeurDetruire->SetLabel(wxT("0"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(m_frame->ConversionEnString(id_selection)))
    {
        wxString ordre = m_frame->ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());

        m_staticTextOrdreTrajectoiresDetruireValeur->SetLabel(ordre);
    }
    else
    {
        m_staticTextOrdreTrajectoiresDetruireValeur->SetLabel(wxT("0;0"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    Layout();
}

void EvtPanelResponsable::OnApplyButtonDetruireClick(wxCommandEvent& event)
{
    if(!m_listBoxDetruireProcessus->IsEmpty())
    {
        wxString selection = m_listBoxDetruireProcessus->GetStringSelection();
        string id_selection = m_frame->ConversionEnString(m_frame->GardeIdSelection(selection));
    
        string requete = "DELETE FROM intermediaire_processus_trajectoires WHERE id_p=" + id_selection;
    
        if(m_bdd_anodisation->ExecuteDelete(requete))
        {
            requete = "DELETE FROM processus WHERE id_processus=" + id_selection;
    
            if(m_bdd_anodisation->ExecuteDelete(requete))
            {
                int separateur = selection.find(" - ");
                
                wxString message;
                message << wxT("Supression du processus : ") << m_frame->DecouperTexteFin(selection, separateur + 3)
                        << wxT(" réussi !\n");
                
                EnvoiMessage(message);
                wxLogMessage(message);
    
                VideListBox();
                RempliListBox();
            }
            else
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }
        }
        else
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
    }
    else
    {
        wxString message = wxT("Destruction impossible, car il n’y a aucun processus dans la base de données. Merci d’en créer et de réessayer.");
        wxMessageBox(message, "Responsable de production - Destruction impossible !",
                    wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
        EnvoiMessage(message);
    }
}
//
// Lancer un processus
//
void EvtPanelResponsable::OnListBoxLancerSelection(wxCommandEvent& event)
{
    wxString selection = m_listBoxLancerProcessus->GetStringSelection();

    wxString message;
    int separateur = selection.find(" - ");
    message << m_frame->DecouperTexteFin(selection, separateur + 3) << wxT("\n");
    m_staticTextLancerTitre->SetLabel(message);

    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(selection);

    // Durée total
    if(m_donnees_IHM->RecupereDureeTotal(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_staticTextDureeTotalValeurLancer->SetLabel(duree);
    }
    else
    {
        m_staticTextDureeTotalValeurLancer->SetLabel(wxT("00:00:00"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(m_frame->ConversionEnString(id_selection)))
    {
        m_staticTextNombreBainValeurLancer->SetLabel(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        m_staticTextNombreBainValeurLancer->SetLabel(wxT("0"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(m_frame->ConversionEnString(id_selection)))
    {
        wxString ordre = m_frame->ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());
        m_staticTextOrdreTrajectoiresValeurLancer->SetLabel(ordre);
    }
    else
    {
        m_staticTextOrdreTrajectoiresValeurLancer->SetLabel(wxT("0;0"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    bSizerLancerDroit->Layout();
    bSizerLancerGauche->Layout();
    bSizerDetailLancer->Layout();
    Layout();
}

void EvtPanelResponsable::OnOkButtonLancerClick(wxCommandEvent& event)
{
    wxString message;
    
    if(!m_listBoxLancerProcessus->IsEmpty())
    {
        if(m_client_connecte)
        {
            if(LancerFabrication(m_frame->GardeIdSelection(m_listBoxLancerProcessus->GetStringSelection())))
            {
                m_client->ExecutionProcessus(m_frame->GardeIdSelection(m_listBoxLancerProcessus->GetStringSelection()));
            
            }
            else
            {
                message << wxT("Le processus n’a pas encore été validé lors d’un test.\n")
                        << wxT("Voulez vous vraiment lancer cette fabrication ?\n");
                int reponse = wxMessageBox(message, "Responsable de production - Lancement à risque !", wxYES_NO | wxICON_QUESTION | wxCENTRE | wxSTAY_ON_TOP, this);
                
                if(reponse == wxYES)
                {
                    m_client->ExecutionProcessus(m_frame->GardeIdSelection(m_listBoxLancerProcessus->GetStringSelection()));
                }
            }
        }
        else
        {
            message << wxT("Le client n'est pas connecté au serveur de la Raspberry pi.");
            wxMessageBox(message, "Responsable de production - Lancement impossible !", wxOK_DEFAULT | wxICON_WARNING | wxCENTRE | wxSTAY_ON_TOP, this);
        }
    }
    else
    {
        message << wxT("Lancement impossible, car il n’y a aucun processus dans la base de données. Merci d’en créer et de réessayer.");
        wxMessageBox(message, "Responsable de production - Lancement impossible !",
                    wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
        EnvoiMessage(message);
    }
}
//
// Tester un processus
//
void EvtPanelResponsable::OnListBoxTesterSelection(wxCommandEvent& event)
{
    wxString selection = m_listBoxTesterProcessus->GetStringSelection();

    wxString message;
    int separateur = selection.find(" - ");
    message << m_frame->DecouperTexteFin(selection, separateur + 3) << wxT("\n");
    m_staticTextTesterTitre->SetLabel(message);

    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(selection);

    // Vider les données
    m_staticTextDureeTotalValeurTester->SetLabel(wxT(""));
    m_staticTextOrdreTrajectoiresValeurTester->SetLabel(wxT(""));

    // Durée total
    if(m_donnees_IHM->RecupereDureeTotal(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotal());
        m_staticTextDureeTotalValeurTester->SetLabel(duree);
    }
    else
    {
        m_staticTextDureeTotalValeurTester->SetLabel(wxT("00:00:00"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Nombre de bain du processus
    if(m_donnees_IHM->RecupereNombreBain(m_frame->ConversionEnString(id_selection)))
    {
        m_staticTextNombreBainValeurTester->SetLabel(m_donnees_IHM->GetNombreBain());
    }
    else
    {
        m_staticTextNombreBainValeurTester->SetLabel(wxT("0"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    // Ordre des trajectoires
    if(m_donnees_IHM->RecupereOrdreTrajectoires(m_frame->ConversionEnString(id_selection)))
    {
        wxString ordre = m_frame->ConversionEnWxString(m_donnees_IHM->GetOrdreTrajectoires());
        m_staticTextOrdreTrajectoiresValeurTester->SetLabel(ordre);
    }
    else
    {
        m_staticTextOrdreTrajectoiresValeurTester->SetLabel(wxT("0;0"));
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    bSizerTesterDroit->Layout();
    bSizerTesterGauche->Layout();
    bSizerDetailTester->Layout();
    Layout();
}

void EvtPanelResponsable::OnStopButtonTesterClick(wxCommandEvent& event)
{
    if(m_client_connecte)
    {
        m_client->StopProcessus();
    }
    else
    {
        wxMessageBox(wxT("Le client n'est pas connecté au serveur de la Raspberry pi."), "Responsable de production - Client non connecté !", wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
    }
}

void EvtPanelResponsable::OnOkButtonTesterClick(wxCommandEvent& event)
{
    wxString message;
    
    if(!m_listBoxTesterProcessus->IsEmpty())
    {
        if(m_client_connecte)
        {
            m_client->TestProcessus(m_frame->GardeIdSelection(m_listBoxTesterProcessus->GetStringSelection()));
            message << wxT("Le processus n’a pas encore été validé.\n")
                        << wxT("Voulez vous le valider maintenant ?\n");
                int reponse = wxMessageBox(message, "Responsable de production - Valider le processus !", wxYES_NO | wxICON_QUESTION | wxCENTRE | wxSTAY_ON_TOP, this);
                
                if(reponse == wxYES)
                {
                    string requete = "UPDATE processus SET processus_valide='true'";
                    
                    if(m_bdd_anodisation->ExecuteUpdate(requete))
                    {
                        message.clear();
                        message << wxT("Le processus à bien été mis a jour et validé dans la base de données.");
                        wxMessageBox(message, "Responsable de production - Validé !", wxOK_DEFAULT | wxICON_INFORMATION | wxCENTRE | wxSTAY_ON_TOP, this);
                        EnvoiMessage(message);
                    }
                    else
                    {
                        EnvoiErreurRemplissage(m_bdd_anodisation->GetLastError());
                    }
                }
        }
        else
        {
            message << wxT("Le client n'est pas connecté au serveur de la Raspberry pi.");
            wxMessageBox(message, "Responsable de production - Client non connecté !", wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
        }
    }
    else
    {
        message << wxT("Test impossible, car il n’y a aucun processus dans la base de données. Merci d’en créer et de réessayer.");
        wxMessageBox(message, "Responsable de production - Test impossible !", wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
        EnvoiMessage(message);
    }
}
//
// Disponibilité bras et détail de la tache en cours
//
void EvtPanelResponsable::OnButtonDisponibiliteBrasClick(wxCommandEvent& event)
{
    if(m_client_connecte)
    {
        if(m_client->DemandeDisponibiliteBras())
        {
            // Cacher les StaticText et TextCtrl
            m_staticTextTypeTache->Hide();
            m_textCtrlTypeTache->Hide();
            m_staticTextNomTache->SetLabel(wxT("Il n’y a pas de tâche en cours."));
            m_textCtrlNomTache->Hide();
            m_staticDureeRestant->Hide();
            m_textCtrlDureeRestantHeure->Hide();
            m_staticTextDureeRestantMinute->Hide();
            m_textCtrlDureeRestantMinute->Hide();
            m_staticTextDureeRestantSeconde->Hide();
            m_textCtrlDureeRestantSeconde->Hide();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras est disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpVert);

            // Désactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Disable();
        }
        else
        {
            // Montrer les StaticText et TextCtrl
            m_staticTextTypeTache->Show();
            m_textCtrlTypeTache->Show();
            m_staticTextNomTache->SetLabel(wxT("Nom de la tâche : "));
            m_textCtrlNomTache->Show();
            m_staticDureeRestant->Show();
            m_textCtrlDureeRestantHeure->Show();
            m_staticTextDureeRestantMinute->Show();
            m_textCtrlDureeRestantMinute->Show();
            m_staticTextDureeRestantSeconde->Show();
            m_textCtrlDureeRestantSeconde->Show();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras n'est pas disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpRouge);

            // Réactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Enable();
        }

        // Réorganiser l'intérieur des sbSizer
        sbSizerTache->Layout();
        sbSizerDisponibiliteBras->Layout();
        Layout();
    }
    else
    {
        wxMessageBox(wxT("Le client n'est pas connecté au serveur de la Raspberry pi."), "Responsable de production - Client non connecté !", wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
    }
}

void EvtPanelResponsable::OnButtonTacheEnCoursClick(wxCommandEvent& event)
{
    if(m_client_connecte)
    {
        vector<string> tache = m_client->DemandeTacheEnCours();

        if(tache[0] == "0")
        {
            // Cacher les StaticText et TextCtrl
            m_staticTextTypeTache->Hide();
            m_textCtrlTypeTache->Hide();
            m_staticTextNomTache->SetLabel(wxT("Il n’y a pas de tâche en cours."));
            m_textCtrlNomTache->Hide();
            m_staticDureeRestant->Hide();
            m_textCtrlDureeRestantHeure->Hide();
            m_staticTextDureeRestantMinute->Hide();
            m_textCtrlDureeRestantMinute->Hide();
            m_staticTextDureeRestantSeconde->Hide();
            m_textCtrlDureeRestantSeconde->Hide();

            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras est disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpVert);

            // Désactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Disable();
        }
        else
        {
            m_staticTextDisponibiliteBras->SetLabel(wxT("Le bras n'est pas disponible"));
            m_bitmapDisponibiliteBras->SetBitmap(BmpRouge);

            // Réactiver le bouton pour demander la tâche en cours
            m_buttonTacheEnCours->Enable();

            // Montrer les StaticText et TextCtrl
            m_staticTextTypeTache->Show();
            m_textCtrlTypeTache->Show();
            m_staticTextNomTache->SetLabel(wxT("Nom de la tâche : "));
            m_textCtrlNomTache->Show();
            m_staticDureeRestant->Show();
            m_textCtrlDureeRestantHeure->Show();
            m_staticTextDureeRestantMinute->Show();
            m_textCtrlDureeRestantMinute->Show();
            m_staticTextDureeRestantSeconde->Show();
            m_textCtrlDureeRestantSeconde->Show();

            // Vider les TextCtrl
            m_textCtrlTypeTache->Clear();
            m_textCtrlNomTache->Clear();
            m_textCtrlDureeRestantHeure->Clear();
            m_textCtrlDureeRestantMinute->Clear();
            m_textCtrlDureeRestantSeconde->Clear();

            // Récupération des valeurs
            wxString type = tache[0];
            wxString id_tache = tache[1];

            wxString message;
            string requete;

            if(type == "Processus")
            {
                m_textCtrlTypeTache->AppendText(wxT("Processus"));

                // Nom du processus
                requete = "SELECT nom_processus FROM processus WHERE id_processus=" + id_tache;

                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> nom = m_bdd_anodisation->GetLastResult();
                    wxString temp = m_frame->ConversionEnWxString(nom[0]);

                    int separateur = temp.find("   ");
                    wxString nomwx = m_frame->DecouperTexteDebut(temp, separateur);
                    m_textCtrlNomTache->AppendText(nomwx);
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
                
                
                
                requete = "SELECT duree_processus FROM processus WHERE id_processus=" + id_tache;
                // Durée total du processus
                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> resultat = m_bdd_anodisation->GetLastResult();
                    wxString duree = m_frame->ConversionEnWxString(resultat[0]);
                    m_textCtrlDureeRestantHeure->AppendText(m_frame->DecouperTexteDebut(duree, 2));
            
                    wxString temp = m_frame->DecouperTexteDebut(duree, 5);
                    m_textCtrlDureeRestantMinute->AppendText(m_frame->DecouperTexteFin(temp, 3));
            
                    m_textCtrlDureeRestantSeconde->AppendText(m_frame->DecouperTexteFin(duree, 6));
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
            else if(type == "Trajectoire")
            {
                m_textCtrlTypeTache->AppendText(wxT("Trajectoire"));

                // Nom de la trajectoire
                requete = "SELECT nom_trajectoire FROM trajectoires WHERE id_trajectoire=" + id_tache;

                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> nom = m_bdd_anodisation->GetLastResult();
                    wxString temp = m_frame->ConversionEnWxString(nom[0]);

                    int separateur = temp.find("   ");
                    wxString nomwx = m_frame->DecouperTexteDebut(temp, separateur);
                    m_textCtrlNomTache->AppendText(nomwx);
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
                
                
                
                requete = "SELECT duree_trajectoire FROM trajectoires WHERE id_trajectoire=" + id_tache;
                // Durée total du processus
                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> resultat = m_bdd_anodisation->GetLastResult();
                    wxString duree = m_frame->ConversionEnWxString(resultat[0]);
                    m_textCtrlDureeRestantHeure->AppendText(m_frame->DecouperTexteDebut(duree, 2));
            
                    wxString temp = m_frame->DecouperTexteDebut(duree, 5);
                    m_textCtrlDureeRestantMinute->AppendText(m_frame->DecouperTexteFin(temp, 3));
            
                    m_textCtrlDureeRestantSeconde->AppendText(m_frame->DecouperTexteFin(duree, 6));
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
            else if(type == "Mouvement")
            {
                m_textCtrlTypeTache->AppendText(wxT("Mouvement"));

                // Nom du mouvement
                requete = "SELECT nom_mouvement FROM mouvements WHERE id_mouvement=" + id_tache;

                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> nom = m_bdd_anodisation->GetLastResult();
                    wxString temp = m_frame->ConversionEnWxString(nom[0]);

                    int separateur = temp.find("   ");
                    wxString nomwx = m_frame->DecouperTexteDebut(temp, separateur);
                    m_textCtrlNomTache->AppendText(nomwx);
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
                
                
                
                requete = "SELECT duree_mouvement FROM mouvements WHERE id_mouvement=" + id_tache;
                // Durée total du processus
                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> resultat = m_bdd_anodisation->GetLastResult();
                    wxString duree = m_frame->ConversionEnWxString(resultat[0]);
                    m_textCtrlDureeRestantHeure->AppendText(m_frame->DecouperTexteDebut(duree, 2));
            
                    wxString temp = m_frame->DecouperTexteDebut(duree, 5);
                    m_textCtrlDureeRestantMinute->AppendText(m_frame->DecouperTexteFin(temp, 3));
            
                    m_textCtrlDureeRestantSeconde->AppendText(m_frame->DecouperTexteFin(duree, 6));
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
            else if(type == "Fabrication")
            {
                m_textCtrlTypeTache->AppendText(wxT("Fabrication"));

                // Nom du processus
                requete = "SELECT nom_processus FROM processus WHERE id_processus=" + id_tache;

                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> nom = m_bdd_anodisation->GetLastResult();
                    wxString temp = m_frame->ConversionEnWxString(nom[0]);

                    int separateur = temp.find("   ");
                    wxString nomwx = m_frame->DecouperTexteDebut(temp, separateur);
                    m_textCtrlNomTache->AppendText(nomwx);
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
                
                
                requete = "SELECT duree_processus FROM processus WHERE id_processus=" + id_tache;
                // Durée total du processus
                if(m_bdd_anodisation->ExecuteSelect(requete))
                {
                    vector<string> resultat = m_bdd_anodisation->GetLastResult();
                    wxString duree = m_frame->ConversionEnWxString(resultat[0]);
                    m_textCtrlDureeRestantHeure->AppendText(m_frame->DecouperTexteDebut(duree, 2));
            
                    wxString temp = m_frame->DecouperTexteDebut(duree, 5);
                    m_textCtrlDureeRestantMinute->AppendText(m_frame->DecouperTexteFin(temp, 3));
            
                    m_textCtrlDureeRestantSeconde->AppendText(m_frame->DecouperTexteFin(duree, 6));
                }
                else
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
            else  // Ne devrais pas arriver
            {
                wxString message = wxT("Une erreur est survenue.\t\t");
                wxLogError(message);
            }
        }

        // Réorganiser l'intérieur des sbSizer
        sbSizerTache->Layout();
        sbSizerDisponibiliteBras->Layout();
        Layout();
    }
    else
    {
        wxMessageBox(wxT("Le client n'est pas connecté au serveur de la Raspberry pi."), "Responsable de production - Client non connecté !", wxOK_DEFAULT | wxICON_ERROR | wxCENTRE | wxSTAY_ON_TOP, this);
    }
}
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                            Méthode du programme                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
bool EvtPanelResponsable::LancerFabrication(wxString id_processus)
{
    bool retour = false;

    string requete = "SELECT processus_valide FROM processus WHERE id_processus=" + m_frame->ConversionEnString(id_processus);
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> resultat = m_bdd_anodisation->GetLastResult();
        
        if(resultat[0] == "1")
        {
            retour = true;
        }
    }
    else
    {
        EnvoiErreurRemplissage(m_bdd_anodisation->GetLastError());
    }

    return retour;
}
//
// IHM
//
void EvtPanelResponsable::RempliListBox()
{
    
    // Vider les titre dont les valeur vont etre changé.
    m_staticTextDetuireTitre->SetLabel(wxT(""));
    m_staticTextLancerTitre->SetLabel(wxT(""));
    m_staticTextTesterTitre->SetLabel(wxT(""));
    wxString message;
    
    if(m_donnees_IHM->RecupereListeProcessus())
    {
        vector<string> liste_processus = m_donnees_IHM->GetListeProcessus();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_processus.size(); taille++)
        {
            if(taille % 2 == 0)
            {
                // EnvoiMessage(liste_processus[taille]);
                rempli.clear();
                rempli << liste_processus[taille] << wxT(" - ");
            }
            else
            {
                // EnvoiMessage(liste_processus[taille] + wxT("\n"));
                nom.clear();
                nom << liste_processus[taille];

                int separateur = nom.find("   ");
                rempli << m_frame->DecouperTexteDebut(nom, separateur);

                // Remplissage des listBox depuis la BdD
                m_listBoxAffichageProcessus->Append(rempli);
                m_listBoxDetruireProcessus->Append(rempli);
                m_listBoxLancerProcessus->Append(rempli);
                m_listBoxModifierProcessus->Append(rempli);
                m_listBoxTesterProcessus->Append(rempli);
            }
        }
        
        
        m_listBoxAffichageProcessus->SetSelection(0);
        m_listBoxDetruireProcessus->SetSelection(0);
        m_listBoxLancerProcessus->SetSelection(0);
        m_listBoxModifierProcessus->SetSelection(0);
        m_listBoxTesterProcessus->SetSelection(0);
    }
    else
    {
        message << wxT("Problème pour le remplisage des wxListBox, contenant l'affichage des processus :\n")
                << m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur());
        EnvoiErreurRemplissage(message);
    }
    
    
    
    if(m_donnees_IHM->RecupereListeTouteTrajectoires())
    {
        vector<string> liste_trajectoire = m_donnees_IHM->GetListeTouteTrajectoires();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_trajectoire.size(); taille++)
        {
            // EnvoiMessage(liste_trajectoire[taille] + wxT("\n"));
            taille = taille + 1;

            if(taille % 4 == 0 && taille != 0)
            {
                rempli << wxT("Durée : ") << liste_trajectoire[taille - 1];
                m_listBoxListeTrajectoiresCreer->Append(rempli);
                m_listBoxListeTrajectoiresModifier->Append(rempli);
                rempli.clear();
            }
            else if(taille % 4 != 0 && taille % 2 == 0)
            {
                nom.clear();
                nom << liste_trajectoire[taille - 1];

                int separateur = nom.find("   ");
                rempli << m_frame->DecouperTexteDebut(nom, separateur) << wxT(" - ");
            }
            else
            {
                // EnvoiMessage(liste_trajectoire[taille-1] + wxT("\n"));
                rempli << liste_trajectoire[taille - 1] << wxT(" - ");
            }

            taille = taille - 1;
        }
    }
    else
    {
        message.clear();
        message << wxT("Problème pour le remplisage des wxListBox, contenant l'affichage des trajectoires :\n")
                << m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur());
        EnvoiErreurRemplissage(message);
    }
    Layout();
}

void EvtPanelResponsable::VideListBox()
{
    m_listBoxAffichageProcessus->Clear();
    m_listBoxDetruireProcessus->Clear();
    m_listBoxLancerProcessus->Clear();
    m_listBoxModifierProcessus->Clear();
    m_listBoxTesterProcessus->Clear();
    m_listBoxListeTrajectoiresAfficher->Clear();
    m_listBoxListeTrajectoiresCreer->Clear();
    m_listBoxListeTrajectoiresModifier->Clear();
}

void EvtPanelResponsable::EnvoiMessage(wxString message)
{
    if(!message.EndsWith(wxT("\n")))
    {
        message << wxT("\n");
    }
    
    wxCommandEvent MyEventMsg(wxEVT_COMMAND_BUTTON_CLICKED, ID_RESPONSABLE);
    MyEventMsg.SetString(message);
    wxPostEvent(m_frame, MyEventMsg);
}

void EvtPanelResponsable::EnvoiErreurRemplissage(wxString message)
{
    wxCommandEvent MyEventMsg(wxEVT_COMMAND_BUTTON_CLICKED, ID_RESPONSABLE + 1);
    MyEventMsg.SetString(message);
    wxPostEvent(m_frame, MyEventMsg);
}