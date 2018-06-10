/*******************************************************************************
 *  Fichier:  EvtPanelRegleur.cpp
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  //2018
 *  Utilité:  Gestion des événements du panel régleur
 *  Auteur:   Nassim Boubziz
              Florian Provost
*******************************************************************************/
#include "EvtPanelRegleur.h"
#include "EvtFramePrincipal.h"

EvtPanelRegleur::EvtPanelRegleur(wxWindow* parent) : PanelRegleur(parent)
{
    //
}
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Méthode générées par wxFormBuilder                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
                               //////////////////
                               //              //
                               //  Mouvements  //
                               //              //
                               //////////////////
void EvtPanelRegleur::OnListBoxAffichageSelectionMouvements(wxCommandEvent& event)
{
    wxString id_selection = m_frame->GardeIdSelection(m_listBoxAffichageMouvements->GetStringSelection());

    m_textCtrlDureeHeureAfficherMouvements->Clear();
    m_textCtrlDureeMinuteAfficherMouvements->Clear();
    m_textCtrlDureeSecondeAfficherMouvements->Clear();
    m_textCtrlNomAfficherMouvements->Clear();
    m_textCtrlxAfficherMouvements->Clear();
    m_textCtrlyAfficherMouvements->Clear();
    m_textCtrlzAfficherMouvements->Clear();

    if(m_donnees_IHM->RecupereNomMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString nom = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomMouvement());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = m_frame->DecouperTexteDebut(nom, separateur);
        m_textCtrlNomAfficherMouvements->AppendText(nomdecoupe);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereDureeTotalMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotalMouvement());
        wxString heure = m_frame->DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureAfficherMouvements->AppendText(heure);

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        wxString minute = m_frame->DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinuteAfficherMouvements->AppendText(minute);

        wxString seconde = m_frame->DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeAfficherMouvements->AppendText(seconde);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeXMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeXMouvement());
        m_textCtrlxAfficherMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeYMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeYMouvement());
        m_textCtrlyAfficherMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeZMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeZMouvement());
        m_textCtrlzAfficherMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}
//
// Modifier un mouvement
//
void EvtPanelRegleur::OnListBoxModifierSelectionMouvements(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierMouvements->GetStringSelection();

    // Récupération de l'id du mouvement
    wxString id_selection = m_frame->GardeIdSelection(selection);
    
    m_textCtrlDureeHeureModifierMouvements->Clear();
    m_textCtrlDureeMinutesModifierMouvements->Clear();
    m_textCtrlDureeSecondeModifierMouvements->Clear();
    m_textCtrlNomModifierMouvements->Clear();
    m_textCtrlxModifierMouvements->Clear();
    m_textCtrlyModifierMouvements->Clear();
    m_textCtrlzModifierMouvements->Clear();

    if(m_donnees_IHM->RecupereNomMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString nom = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomMouvement());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = m_frame->DecouperTexteDebut(nom, separateur);
        m_textCtrlNomModifierMouvements->AppendText(nomdecoupe);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereDureeTotalMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotalMouvement());
        wxString heure = m_frame->DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierMouvements->AppendText(heure);

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        wxString minute = m_frame->DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierMouvements->AppendText(minute);

        wxString seconde = m_frame->DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierMouvements->AppendText(seconde);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeXMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeXMouvement());
        m_textCtrlxModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeYMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeYMouvement());
        m_textCtrlyModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeZMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeZMouvement());
        m_textCtrlzModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}

void EvtPanelRegleur::OnApplyButtonModifierMouvementClick(wxCommandEvent& event)
{
    bool ereur = false;
    string donnee_x;
    string donnee_y;
    string donnee_z;
    string nom_mouvement;
    string duree_total;
    wxString message;
    wxString id_selectionwx = m_listBoxModifierMouvements->GetStringSelection();

    if(!m_textCtrlNomModifierMouvements->IsEmpty())
    {
        nom_mouvement = m_frame->ConversionEnString(m_textCtrlNomModifierMouvements->GetValue());
    }
    else
    {
        ereur = true;
        message << "le champs \"Nom du Mouvement\" est vide.\n";
    }

    if(!m_textCtrlxModifierMouvements->IsEmpty())
    {
        donnee_x = m_frame->ConversionEnString(m_textCtrlxModifierMouvements->GetValue());
    }
    else
    {
        ereur = true;
        message << "Le champs de la donnée X est vide.\n";
    }

    if(!m_textCtrlyModifierMouvements->IsEmpty())
    {
        donnee_y = m_frame->ConversionEnString(m_textCtrlyModifierMouvements->GetValue());
    }
    else
    {
        ereur = true;
        message << "Le champs de donnee Y est vide .\n";
    }

    if(!m_textCtrlzModifierMouvements->IsEmpty())
    {
        donnee_z = m_frame->ConversionEnString(m_textCtrlzModifierMouvements->GetValue());
    }
    else
    {
        ereur = true;
        message << "Le champs de donnee Z est vide.\n";
    }

    if(!m_textCtrlDureeHeureModifierMouvements->IsEmpty() && !m_textCtrlDureeMinutesModifierMouvements->IsEmpty()
       && !m_textCtrlDureeSecondeModifierMouvements->IsEmpty())
    {
        duree_total = m_frame->ConversionEnString(m_textCtrlDureeHeureModifierMouvements->GetValue()) + ":"
                    + m_frame->ConversionEnString(m_textCtrlDureeMinutesModifierMouvements->GetValue()) + ":"
                    + m_frame->ConversionEnString(m_textCtrlDureeSecondeModifierMouvements->GetValue());
    }
    else
    {
        ereur = true;
        message << "Les champs concernant la durée d'éxcution du mouvements ne sont pas tous remplis.\n";
    }

    if(!ereur)
    {
        string id_selection = m_frame->ConversionEnString(m_frame->GardeIdSelection(id_selectionwx));
        string requete = "UPDATE mouvements SET nom_mouvement ='" + nom_mouvement + "', axe_x =" + donnee_x
                       + ", axe_y = " + donnee_y + ", axe_z=" + donnee_z + ", duree_mouvement='" + duree_total
                       + "' WHERE id_mouvement=" + id_selection;
        cout << requete << endl;

        if(!m_bdd_anodisation->ExecuteInsert(requete))
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
    }
    else
    {
        wxLogError(message);
    }

    VideListBoxMouvements();
    RempliListBoxMouvements();
}

void EvtPanelRegleur::OnCancelButtonModifierMouvementClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierMouvements->GetStringSelection();

    // Récupération de l'id du mouvement
    wxString id_selection = m_frame->GardeIdSelection(selection);

    m_textCtrlDureeHeureModifierMouvements->Clear();
    m_textCtrlDureeMinutesModifierMouvements->Clear();
    m_textCtrlDureeSecondeModifierMouvements->Clear();
    m_textCtrlNomModifierMouvements->Clear();
    m_textCtrlxModifierMouvements->Clear();
    m_textCtrlyModifierMouvements->Clear();
    m_textCtrlzModifierMouvements->Clear();

    if(m_donnees_IHM->RecupereNomMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString nom = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomMouvement());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = m_frame->DecouperTexteDebut(nom, separateur);
        m_textCtrlNomModifierMouvements->AppendText(nomdecoupe);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereDureeTotalMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotalMouvement());
        wxString heure = m_frame->DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierMouvements->AppendText(heure);

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        wxString minute = m_frame->DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierMouvements->AppendText(minute);

        wxString seconde = m_frame->DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierMouvements->AppendText(seconde);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeXMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeXMouvement());
        m_textCtrlxModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeYMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeYMouvement());
        m_textCtrlyModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAxeZMouvement(m_frame->ConversionEnString(id_selection)))
    {
        wxString coordonnee = m_frame->ConversionEnWxString(m_donnees_IHM->GetAxeZMouvement());
        m_textCtrlzModifierMouvements->AppendText(coordonnee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}
//
// Creer un mouvement
//
void EvtPanelRegleur::OnSaveButtonCreerMouvementClick(wxCommandEvent& event)
{
    bool erreur = false;
    string donnee_x;
    string donnee_y;
    string donnee_z;
    string nom_mouvement;
    string duree_total;
    wxString message;

    if(!m_textCtrlNomCreerMouvements->IsEmpty())
    {
        nom_mouvement = m_frame->ConversionEnString(m_textCtrlNomCreerMouvements->GetValue());
    }
    else
    {
        erreur = true;
        message << "le champs \"Nom du Mouvement\" est vide.\n";
    }

    if(!m_textCtrlxCreerMouvements->IsEmpty())
    {
        donnee_x = m_frame->ConversionEnString(m_textCtrlxCreerMouvements->GetValue());
    }
    else
    {
        erreur = true;
        message << "Le champs de la donnée X est vide.\n";
    }

    if(!m_textCtrlyCreerMouvements->IsEmpty())
    {
        donnee_y = m_frame->ConversionEnString(m_textCtrlyCreerMouvements->GetValue());
    }
    else
    {
        erreur = true;
        message << "Le champs de donnee Y est vide .\n";
    }

    if(!m_textCtrlzCreerMouvements->IsEmpty())
    {
        donnee_z = m_frame->ConversionEnString(m_textCtrlzCreerMouvements->GetValue());
    }
    else
    {
        erreur = true;
        message << "Le champs de donnee Z est vide.\n";
    }

    if(!m_textCtrlDureeHeureCreerMouvements->IsEmpty() && !m_textCtrlDureeMinutesCreerMouvements->IsEmpty()
       && !m_textCtrlDureeSecondeCreerMouvements->IsEmpty())
    {
        duree_total = m_frame->ConversionEnString(m_textCtrlDureeHeureCreerMouvements->GetValue()) + ":"
                    + m_frame->ConversionEnString(m_textCtrlDureeMinutesCreerMouvements->GetValue()) + ":"
                    + m_frame->ConversionEnString(m_textCtrlDureeSecondeCreerMouvements->GetValue());
    }
    else
    {
        erreur = true;
        message << "Les champs concernant la durée d'éxcution du mouvements ne sont pas tous rempli.\n";
    }

    if(!erreur)
    {
        string requete = "INSERT INTO mouvements (nom_mouvement, axe_x, axe_y, axe_z, duree_mouvement) VALUES('"
                       + nom_mouvement + "','" + donnee_x + "','" + donnee_y + "','" + donnee_z + "','" + duree_total
                       + "')";
        
        if(!m_bdd_anodisation->ExecuteInsert(requete))
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
    }
    else
    {
        wxLogError(message);
    }

    VideListBoxMouvements();
    RempliListBoxMouvements();
}
//
// Détruire un mouvement
//
void EvtPanelRegleur::OnListBoxDetruireSelectionMouvements(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxDetruireSelectionMouvements
}

void EvtPanelRegleur::OnYesButtonDetruireMouvementClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxDetruireMouvements->GetStringSelection();
    string id_selection = m_frame->ConversionEnString(m_frame->GardeIdSelection(selection));
    string requete = "SELECT id_t FROM intermediaire_mouvements_trajectoires WHERE id_m=" + id_selection;

    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> resultat = m_bdd_anodisation->GetLastResult();
        requete = "DELETE FROM intermediaire_mouvements_trajectoires WHERE id_m=" + id_selection;

        if(m_bdd_anodisation->ExecuteDelete(requete))
        {
            requete = "DELETE FROM mouvements WHERE id_mouvement=" + id_selection;

            if(!m_bdd_anodisation->ExecuteDelete(requete))
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            for(unsigned int i; i < resultat.size(); i++)
            {
                requete = "DELETE FROM trajectoires WHERE id_trajectoire=" + resultat[i];

                if(!m_bdd_anodisation->ExecuteDelete(requete))
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
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

    VideListBoxMouvements();
    RempliListBoxMouvements();
}
//
// Tester un mouvement
//
void EvtPanelRegleur::OnListBoxTesterSelectionMouvements(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxTesterSelectionMouvements
}

void EvtPanelRegleur::OnCancelButtonTestMouvementClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxTesterMouvements->GetStringSelection();
    wxString id_selection = m_frame->GardeIdSelection(selection);
    if(m_client_connecte)
    {
        m_client->StopTestMouvement(id_selection);
    }
    else
    {
       EnvoiMessage(wxT("Le serveur n'est pas connecté\n"));
    }
}

void EvtPanelRegleur::OnInfoBrasTestMouvementClick(wxCommandEvent& event)
{
     if(m_client_connecte)
    {
        bool reponse;
        reponse = m_client->DemandeDisponibiliteBras();

        if(reponse)
        {
        }
    }
    else
    {
        EnvoiMessage(wxT("Le serveur n'est pas connecté\n"));
    }
}

void EvtPanelRegleur::OnYesButtonTesterMouvementClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxTesterMouvements->GetStringSelection();
    wxString id_selection = m_frame->GardeIdSelection(selection);
    if(m_client_connecte)
    {
        m_client->TestMouvement(id_selection);
    }
    else
    {
        EnvoiMessage(wxT("Le serveur n'est pas connecté\n"));
    }
}
                               //////////////////
                               //              //
                               // Trajectoires //
                               //              //
                               //////////////////
void EvtPanelRegleur::OnListBoxAffichageSelectionTrajectoires(wxCommandEvent& event)
{
    wxString selection = m_listBoxAffichageTrajectoires->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(selection);
    
    // Vider les text control
    // du coté droit

    m_textCtrlDureeHeureAfficherTrajectoires->Clear();
    m_textCtrlDureeMinutesAfficherTrajectoires->Clear();
    m_textCtrlDureeSecondesAfficherTrajectoires->Clear();
    m_listBoxCompositionTrajectoire->Clear();
    m_textCtrlNomAfficherTrajectoires->Clear();
    m_textCtrlBaindedepartAfficher->Clear();
    m_textCtrlBainDarriveeAfficher->Clear();

    // Remplisage
    if(m_donnees_IHM->RecupereNomTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString nom = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomTrajectoire());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = m_frame->DecouperTexteDebut(nom, separateur);

        m_textCtrlNomAfficherTrajectoires->AppendText(nomdecoupe);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereDureeTotalTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotalTrajectoire());
        wxString heure = m_frame->DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureAfficherTrajectoires->AppendText(heure);

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        wxString minute = m_frame->DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesAfficherTrajectoires->AppendText(minute);

        wxString seconde = m_frame->DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondesAfficherTrajectoires->AppendText(seconde);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereDepartTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString depart = m_frame->ConversionEnWxString(m_donnees_IHM->GetDepartTrajectoire());
        m_textCtrlBaindedepartAfficher->AppendText(depart);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAriveeTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString arivee = m_frame->ConversionEnWxString(m_donnees_IHM->GetArriveeTrajectoire());
        m_textCtrlBainDarriveeAfficher->AppendText(arivee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}
//
// Modifier une trajectoire
//
void EvtPanelRegleur::OnListBoxModifierSelectionTrajectoires(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierTrajectoires->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(selection);

    // Vider les text control
    // du coté droit

    m_textCtrlDureeHeureModifierTrajectoires->Clear();
    m_textCtrlDureeMinutesModifierTrajectoires->Clear();
    m_textCtrlDureeSecondeModifierTrajectoires->Clear();
    m_listBoxCompositionTrajectoire->Clear();
    m_textCtrlOrdreMouvements->Clear();
    m_textCtrlNomModifierTrajectoires->Clear();
    m_textCtrlBainDeDepartModifier->Clear();
    m_textCtrlBainDarriveeModifier->Clear();

    // Remplisage

    if(m_donnees_IHM->RecupereNomTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString nom = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomTrajectoire());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = m_frame->DecouperTexteDebut(nom, separateur);

        m_textCtrlNomModifierTrajectoires->AppendText(nomdecoupe);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    if(m_donnees_IHM->RecupereDureeTotalTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotalTrajectoire());
        wxString heure = m_frame->DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierTrajectoires->AppendText(heure);

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        wxString minute = m_frame->DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierTrajectoires->AppendText(minute);

        wxString seconde = m_frame->DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierTrajectoires->AppendText(seconde);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    if(m_donnees_IHM->RecupereDepartTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString depart = m_frame->ConversionEnWxString(m_donnees_IHM->GetDepartTrajectoire());
        m_textCtrlBainDeDepartModifier->AppendText(depart);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    if(m_donnees_IHM->RecupereAriveeTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString arivee = m_frame->ConversionEnWxString(m_donnees_IHM->GetArriveeTrajectoire());
        m_textCtrlBainDarriveeModifier->AppendText(arivee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }

    if(m_donnees_IHM->RecupereOrdreMouvements(m_frame->ConversionEnString(id_selection)))
    {
        wxString ordre = m_frame->ConversionEnWxString(m_donnees_IHM->GetOrdreMouvements());
        m_textCtrlOrdreMouvements->AppendText(ordre);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}

void EvtPanelRegleur::OnApplyButtonModifierTrajectoiresClick(wxCommandEvent& event)
{
    bool erreur = false;
    char* car = ";";
    string donnee_depart;
    string donnee_arrive;
    vector<string> ordre_separe;
    string donnee_ordre;
    string nom_trajectoire;
    string duree_total;
    wxUniChar caractere(*car);
    wxString message;
    wxString id_selectionwx = m_listBoxModifierTrajectoires->GetStringSelection();

    if(!m_textCtrlNomModifierTrajectoires->IsEmpty())
    {
        nom_trajectoire = m_frame->ConversionEnString(m_textCtrlNomModifierTrajectoires->GetValue());
    }
    else
    {
        erreur = true;
        message << "le champs \"Nom de la trajectoire\" est vide.\n";
    }

    if(!m_textCtrlBainDeDepartModifier->IsEmpty())
    {
        donnee_depart = m_frame->ConversionEnString(m_textCtrlBainDeDepartModifier->GetValue());
    }
    else
    {
        erreur = true;
        message << "Le bain de départ n'est pas donné.\n";
    }

    if(!m_textCtrlBainDarriveeModifier->IsEmpty())
    {
        donnee_arrive = m_frame->ConversionEnString(m_textCtrlBainDarriveeModifier->GetValue());
    }
    else
    {
        erreur = true;
        message << "Le bain de d'arrivé n'est pas donné .\n";
    }

    if(!m_textCtrlOrdreMouvements->IsEmpty())
    {
        wxString ordrewx = m_textCtrlOrdreMouvements->GetValue();

        if(ordrewx.EndsWith(";"))
        {
            ordrewx.RemoveLast();
        }

        donnee_ordre = m_frame->ConversionEnString(ordrewx);

        unsigned int nb_point_virgule = ordrewx.Freq(caractere);
        unsigned int position;
        wxString temp;

        for(unsigned int i = 0; i < nb_point_virgule + 1; i++)
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
                    ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteFin(ordrewx, position + 1)));
                }
                else
                {
                    position = ordrewx.find(";");
                    temp.clear();
                    temp = m_frame->DecouperTexteFin(ordrewx, position + 1);
                    position = temp.find(";");
                    ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteDebut(temp, position)));
                    ordrewx.clear();
                    ordrewx = (m_frame->DecouperTexteFin(temp, position));
                }
            }
        }

        for(unsigned int i = 0; i < ordre_separe.size(); i++)
        {
            cout << ordre_separe[i] << endl;
        }
    }
    else
    {
        erreur = true;
        message << "L'organisation des mouvements n'est pas donné.\n";
    }

    if(!m_textCtrlDureeHeureModifierTrajectoires->IsEmpty() && !m_textCtrlDureeMinutesModifierTrajectoires->IsEmpty()
       && !m_textCtrlDureeSecondeModifierTrajectoires->IsEmpty())
    {
        duree_total = m_frame->ConversionEnString(m_textCtrlDureeHeureModifierTrajectoires->GetValue()) + ":"
                    + m_frame->ConversionEnString(m_textCtrlDureeMinutesModifierTrajectoires->GetValue()) + ":"
                    + m_frame->ConversionEnString(m_textCtrlDureeSecondeModifierTrajectoires->GetValue());
    }
    else
    {
        erreur = true;
        message << "Les champs concernant la durée d'éxcution de la trajectoire ne sont pas tous remplis.\n";
    }

    if(!erreur)
    {
        string id_selection = m_frame->ConversionEnString(m_frame->GardeIdSelection(id_selectionwx));
        string requete = "UPDATE trajectoires SET nom_trajectoire='" + nom_trajectoire + "', duree_trajectoire ='"
                       + duree_total + "' WHERE id_trajectoire=" + id_selection;

        if(!m_bdd_anodisation->ExecuteUpdate(requete))
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
        else
        {
            vector<string> resultat = m_bdd_anodisation->GetLastResult();
            string id_trajectoire = resultat[0];

            for(unsigned int i = 0; i < ordre_separe.size(); i++)
            {
                requete = "UPDATE intermediaire_mouvements_trajectoires SET id_m='" + ordre_separe[i]
                          + "', point_depart='" + donnee_depart + "', point_arrive='" + donnee_arrive + "' WHERE id_t="
                          + id_selection;

                if(!m_bdd_anodisation->ExecuteInsert(requete))
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
        }
    }
    else
    {
        wxLogError(message);
    }

    VideListBoxTrajectoires();
    RempliListBoxTrajectoires();
}

void EvtPanelRegleur::OnCancelButtonModifierTrajectoiresClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxModifierTrajectoires->GetStringSelection();

    // Récupération de l'id du processus
    wxString id_selection = m_frame->GardeIdSelection(selection);

    // Vider les text control
    // du coté droit

    m_textCtrlDureeHeureModifierTrajectoires->Clear();
    m_textCtrlDureeMinutesModifierTrajectoires->Clear();
    m_textCtrlDureeSecondeModifierTrajectoires->Clear();
    m_listBoxCompositionTrajectoire->Clear();
    m_textCtrlNomModifierTrajectoires->Clear();
    m_textCtrlBainDeDepartModifier->Clear();
    m_textCtrlBainDarriveeModifier->Clear();

    // Remplisage

    if(m_donnees_IHM->RecupereNomTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString nom = m_frame->ConversionEnWxString(m_donnees_IHM->GetNomTrajectoire());
        int separateur = nom.find(wxT("   "));
        wxString nomdecoupe = m_frame->DecouperTexteDebut(nom, separateur);

        m_textCtrlNomModifierTrajectoires->AppendText(nomdecoupe);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereDureeTotalTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString duree = m_frame->ConversionEnWxString(m_donnees_IHM->GetDureeTotalTrajectoire());
        wxString heure = m_frame->DecouperTexteDebut(duree, 2);
        m_textCtrlDureeHeureModifierTrajectoires->AppendText(heure);

        wxString temp = m_frame->DecouperTexteDebut(duree, 5);
        wxString minute = m_frame->DecouperTexteFin(temp, 3);
        m_textCtrlDureeMinutesModifierTrajectoires->AppendText(minute);

        wxString seconde = m_frame->DecouperTexteFin(duree, 6);
        m_textCtrlDureeSecondeModifierTrajectoires->AppendText(seconde);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereDepartTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString depart = m_frame->ConversionEnWxString(m_donnees_IHM->GetDepartTrajectoire());
        m_textCtrlBainDeDepartModifier->AppendText(depart);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereAriveeTrajectoire(m_frame->ConversionEnString(id_selection)))
    {
        wxString arivee = m_frame->ConversionEnWxString(m_donnees_IHM->GetArriveeTrajectoire());
        m_textCtrlBainDarriveeModifier->AppendText(arivee);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}
//
// Creer une trajectoire
//
void EvtPanelRegleur::OnListBoxSelectionMouvementsCreationTrajectoire(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxSelectionMouvementsCreationTrajectoire
}

void EvtPanelRegleur::OnSaveButtonCreerTrajectoiresClick(wxCommandEvent& event)
{
    bool erreur = false;
    char* car = ";";
    string donnee_depart;
    string donnee_arrive;
    vector<string> ordre_separe;
    string donnee_ordre;
    string nom_trajectoire;
    string duree_total;
    wxUniChar caractere(*car);
    wxString message;

    if(!m_textCtrlNomCreerTrajectoires->IsEmpty())
    {
        nom_trajectoire = m_frame->ConversionEnString(m_textCtrlNomCreerTrajectoires->GetValue());
    }
    else
    {
        erreur = true;
        message << "le champs \"Nom de la trajectoire\" est vide.\n";
    }

    if(!m_textCtrlDepartTrajectoireCreation->IsEmpty())
    {
        donnee_depart = m_frame->ConversionEnString(m_textCtrlDepartTrajectoireCreation->GetValue());
    }
    else
    {
        erreur = true;
        message << "Le bain de départ n'est pas donné.\n";
    }

    if(!m_textCtrlAriveeTrajectoireCreation->IsEmpty())
    {
        donnee_arrive = m_frame->ConversionEnString(m_textCtrlAriveeTrajectoireCreation->GetValue());
    }
    else
    {
        erreur = true;
        message << "Le bain de d'arrivé n'est pas donné .\n";
    }

    if(!m_textCtrlOrganisationTrajectoires->IsEmpty())
    {
        wxString ordrewx = m_textCtrlOrganisationTrajectoires->GetValue();

        if(ordrewx.EndsWith(";"))
        {
            ordrewx.RemoveLast();
        }

        donnee_ordre = m_frame->ConversionEnString(ordrewx);

        unsigned int nb_point_virgule = ordrewx.Freq(caractere);
        unsigned int position;
        wxString temp;

        for(unsigned int i = 0; i < nb_point_virgule + 1; i++)
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
                    ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteFin(ordrewx, position + 1)));
                }
                else
                {
                    position = ordrewx.find(";");
                    temp.clear();
                    temp = m_frame->DecouperTexteFin(ordrewx, position + 1);
                    position = temp.find(";");
                    ordre_separe.push_back(m_frame->ConversionEnString(m_frame->DecouperTexteDebut(temp, position)));
                    ordrewx.clear();
                    ordrewx = (m_frame->DecouperTexteFin(temp, position));
                }
            }
        }

        for(unsigned int i = 0; i < ordre_separe.size(); i++)
        {
            cout << ordre_separe[i] << endl;
        }
    }
    else
    {
        erreur = true;
        message << "L'organisation des mouvements n'est pas donné.\n";
    }

    if(!m_textCtrlDureeHeureCreerTrajectoires->IsEmpty() && !m_textCtrlDureeMinutesCreerTrajectoires->IsEmpty()
       && !m_textCtrlDureeSecondeCreerTrajectoires->IsEmpty())
    {
        duree_total = m_frame->ConversionEnString(m_textCtrlDureeHeureCreerTrajectoires->GetValue()) + ":"
                      + m_frame->ConversionEnString(m_textCtrlDureeMinutesCreerTrajectoires->GetValue()) + ":"
                      + m_frame->ConversionEnString(m_textCtrlDureeSecondeCreerTrajectoires->GetValue());
    }
    else
    {
        erreur = true;
        message << "Les champs concernant la durée d'éxcution dde la trajectoire ne sont pas tous remplis.\n";
    }

    if(!erreur)
    {
        string requete = "INSERT INTO trajectoires (nom_trajectoire, duree_trajectoire) VALUES('" + nom_trajectoire
                       + "','" + duree_total + "')";
        
        if(!m_bdd_anodisation->ExecuteInsert(requete))
        {
            EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
        }
        else
        {
            requete = "SELECT id_trajectoire FROM trajectoires ORDER BY id_trajectoire DESC LIMIT 1 OFFSET 0";

            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                vector<string> resultat = m_bdd_anodisation->GetLastResult();
                string id_trajectoire = resultat[0];

                for(unsigned int i = 0; i < ordre_separe.size(); i++)
                {
                    requete
                        = "INSERT INTO intermediaire_mouvements_trajectoires (id_t, id_m, point_depart,point_arrive, "
                          "ordre_mouvements) VALUES ("
                          + resultat[0] + "," + ordre_separe[i] + ",'" + donnee_depart + "','" + donnee_arrive + "','"
                          + donnee_ordre + "')";
                    cout << requete << endl;

                    if(!m_bdd_anodisation->ExecuteInsert(requete))
                    {
                        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                    }
                }
            }
        }
    }
    else
    {
        wxLogError(message);
    }

    VideListBoxTrajectoires();
    RempliListBoxTrajectoires();
}
//
// Détruire une trajectoire
//
void EvtPanelRegleur::OnListBoxDetruireSelectionTrajectoires(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxDetruireSelectionTrajectoires
}

void EvtPanelRegleur::OnYesButtonDetruireTrajectoiresClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxDetruireTrajectoires->GetStringSelection();
    string id_selection = m_frame->ConversionEnString(m_frame->GardeIdSelection(selection));
    string requete = "SELECT id_p FROM intermediaire_processus_trajectoires WHERE id_t=" + id_selection;

    // suppresion hyerarchique des id ( on select pour pouvoir supprimé les id des tables intermidiaire sans risque de
    // segfault
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> resultat = m_bdd_anodisation->GetLastResult();
        requete = "DELETE FROM intermediaire_processus_trajectoires WHERE id_t=" + id_selection;

        if(m_bdd_anodisation->ExecuteDelete(requete))
        {
            requete = "DELETE FROM intermediaire_mouvements_trajectoires WHERE id_t=" + id_selection;

            if(!m_bdd_anodisation->ExecuteDelete(requete))
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            requete = "DELETE FROM trajectoires WHERE id_trajectoire=" + id_selection;

            if(!m_bdd_anodisation->ExecuteDelete(requete))
            {
                EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
            }

            for(unsigned int i; i < resultat.size(); i++)
            {
                requete = "DELETE FROM processus WHERE id_processus=" + resultat[i];

                if(!m_bdd_anodisation->ExecuteDelete(requete))
                {
                    EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_bdd_anodisation->GetLastError()));
                }
            }
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

    VideListBoxTrajectoires();
    RempliListBoxTrajectoires();
}
//
// Tester une trajectoire
//
void EvtPanelRegleur::OnListBoxTesterSelectionTrajectoires(wxCommandEvent& event)
{
    // TODO: Implement OnListBoxTesterSelectionTrajectoires
}

void EvtPanelRegleur::OnCancelButtonTestTrajectoireClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxTesterTrajectoires->GetStringSelection();
    wxString id_selection = m_frame->GardeIdSelection(selection);
    
    if(m_client_connecte)
    {
        m_client->StopTestTrajectoire(id_selection);
    }
    else
    {
        EnvoiMessage(wxT("Le serveur n'est pas connecté.\n"));
    }
}

void EvtPanelRegleur::OnInfoBrasTestTrajectoireClick(wxCommandEvent& event)
{
    if(m_client_connecte)
    {
        bool reponse;
        reponse = m_client->DemandeDisponibiliteBras();

        if(reponse)
        {
        }
    }
    else
    {
        EnvoiMessage(wxT("Le serveur n'est pas connecté.\n"));
    }
}

void EvtPanelRegleur::OnYesButtonTesterTrajectoiresClick(wxCommandEvent& event)
{
    wxString selection = m_listBoxTesterTrajectoires->GetStringSelection();
    wxString id_selection = m_frame->GardeIdSelection(selection);
    
    if(m_client_connecte)
    {
        m_client->TestTrajectoire(id_selection);
    }
    else
    {
        //EnvoiMessage(wxT("Le serveur n'est pas connecté\n"));
    }
}
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                            Méthode du programme                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//
// IHM
//
void EvtPanelRegleur::EnvoiMessage(wxString message)
{
    wxCommandEvent MyEventMsg(wxEVT_COMMAND_BUTTON_CLICKED, ID_REGLEUR);
    MyEventMsg.SetString(message);
    wxPostEvent(m_frame, MyEventMsg);
}

void EvtPanelRegleur::EnvoiErreurRemplissage(wxString message)
{
    wxCommandEvent MyEventMsg(wxEVT_COMMAND_BUTTON_CLICKED, ID_REGLEUR + 1);
    MyEventMsg.SetString(message);
    wxPostEvent(m_frame, MyEventMsg);
}
                               //////////////////
                               //              //
                               //  Mouvements  //
                               //              //
                               //////////////////
void EvtPanelRegleur::CacheNoteBookMouvement()
{
    m_notebookMouvements->Hide();
}

void EvtPanelRegleur::MontreNoteBookMouvement()
{
    m_notebookMouvements->Show();
}

void EvtPanelRegleur::RempliListBoxMouvements()
{
    if(m_donnees_IHM->RecupereListeToutMouvements())
    {
        vector<string> liste_mouvement = m_donnees_IHM->GetListeToutMouvements();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_mouvement.size(); taille++)
        {
            if(taille % 2 == 0)
            {
                rempli.clear();
                rempli << liste_mouvement[taille] << wxT(" - ");
            }
            else
            {
                nom.clear();
                nom << liste_mouvement[taille];

                int separateur = nom.find("   ");
                rempli << m_frame->DecouperTexteDebut(nom, separateur);

                m_listBoxAffichageMouvements->Append(rempli);
                m_listBoxDetruireMouvements->Append(rempli);
                m_listBoxTesterMouvements->Append(rempli);
                m_listBoxModifierMouvements->Append(rempli);
            }
        }
        
        m_listBoxAffichageMouvements->SetSelection(0);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
}

void EvtPanelRegleur::VideListBoxMouvements()
{
    m_listBoxAffichageMouvements->Clear();
    m_listBoxDetruireMouvements->Clear();
    m_listBoxTesterMouvements->Clear();
    m_listBoxModifierMouvements->Clear();
}
                               //////////////////
                               //              //
                               // Trajectoires //
                               //              //
                               //////////////////
void EvtPanelRegleur::CacheNoteBookTrajectoire()
{
    m_notebookTrajectoires->Hide();
}

void EvtPanelRegleur::MontreNoteBookTrajectoire()
{
    m_notebookTrajectoires->Show();
}

void EvtPanelRegleur::RempliListBoxTrajectoires()
{
    if(m_donnees_IHM->RecupereListeTouteTrajectoires())
    {
        vector<string> liste_trajectoires = m_donnees_IHM->GetListeTouteTrajectoires();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_trajectoires.size(); taille++)
        {
            if(taille % 2 == 0)
            {
                rempli.clear();
                rempli << liste_trajectoires[taille] << wxT(" - ");
            }
            else
            {
                nom.clear();
                nom << liste_trajectoires[taille];

                int separateur = nom.find("   ");
                rempli << m_frame->DecouperTexteDebut(nom, separateur);

                m_listBoxAffichageTrajectoires->Append(rempli);
                m_listBoxDetruireTrajectoires->Append(rempli);
                m_listBoxTesterTrajectoires->Append(rempli);
                m_listBoxModifierTrajectoires->Append(rempli);
            }
        }
        
        m_listBoxAffichageTrajectoires->SetSelection(0);
    }
    else
    {
        EnvoiErreurRemplissage(m_frame->ConversionEnWxString(m_donnees_IHM->GetDerniereErreur()));
    }
    
    
    
    if(m_donnees_IHM->RecupereListeToutMouvements())
    {
        vector<string> liste_mouvement = m_donnees_IHM->GetListeToutMouvements();

        wxString rempli;
        wxString nom;

        for(unsigned int taille = 0; taille < liste_mouvement.size(); taille++)
        {
            if(taille % 2 == 0)
            {
                rempli.clear();
                rempli << liste_mouvement[taille] << wxT(" - ");
            }
            else
            {
                nom.clear();
                nom << liste_mouvement[taille];

                int separateur = nom.find("   ");
                rempli << m_frame->DecouperTexteDebut(nom, separateur);

                m_listBoxModifierCompositionTrajectoire->Append(rempli);
                m_listBoxCreerTrajectoires->Append(rempli);
            }
        }
    }
}

void EvtPanelRegleur::VideListBoxTrajectoires()
{
    m_listBoxAffichageTrajectoires->Clear();
    m_listBoxDetruireTrajectoires->Clear();
    m_listBoxTesterTrajectoires->Clear();
    m_listBoxModifierTrajectoires->Clear();
    m_listBoxModifierCompositionTrajectoire->Clear();
    m_listBoxCreerTrajectoires->Clear();
}

