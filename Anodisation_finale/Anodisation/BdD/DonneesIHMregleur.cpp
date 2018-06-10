/*******************************************************************************
 *  Fichier:  DonneesIHMregleur.cpp
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  09/06/2018
 *  Utilité:  Récuperer les données pour l'IHM régleur depuis la Base de 
              données et stockage dans des variables
 *  Auteur:   Florian Provost
              Nassim Boubziz
*******************************************************************************/
#include "DonneesIHMregleur.h"

DonneesIHMregleur::DonneesIHMregleur(DataAnodisation *bdd)
{
    m_bdd_anodisation = bdd;
}

DonneesIHMregleur::~DonneesIHMregleur()
{
    // Destructeur
}

bool DonneesIHMregleur::RecupereDureeTotalMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT duree_mouvement FROM mouvements WHERE id_mouvement=" + id_mouvement;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_dureeTotalMouvement = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de durée total pour ce mouvement.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHMregleur::RecupereDureeTotalTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT duree_trajectoire FROM trajectoires WHERE id_trajectoire=" + id_trajectoire;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_dureeTotalTrajectoire = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de durée total pour cette trajectoire.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHMregleur::RecupereListeToutMouvements()
{
    bool retour = false;
    string requete = "SELECT id_mouvement, nom_mouvement FROM mouvements ORDER BY id_mouvement";
    
    m_listeToutMouvements.clear();
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            for(unsigned int taille = 0; taille < dernier_resultat.size(); taille++)
            {
                m_listeToutMouvements.push_back(dernier_resultat[taille]);
            }
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a aucun mouvement.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHMregleur::RecupereListeTouteTrajectoires()
{
    bool retour = false;
    
    string requete = "SELECT id_trajectoire, nom_trajectoire FROM trajectoires ORDER BY id_trajectoire";
    
    m_listeTouteTrajectoires.clear();
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            for(unsigned int taille = 0; taille < dernier_resultat.size(); taille++)
            {
                m_listeTouteTrajectoires.push_back(dernier_resultat[taille]);
            }
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a aucune trajectoire.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }

    return retour;
}

bool DonneesIHMregleur::RecupereListeMouvementsCreationTrajectoires()
{
    bool retour = false;
    string requete = "SELECT id_mouvement, nom_mouvement, contenu_mouvement FROM mouvements ORDER BY id_mouvement";
    
    m_listeMouvementsCreationTrajectoires.clear();
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            for(unsigned int taille = 0; taille < dernier_resultat.size(); taille++)
            {
                m_listeMouvementsCreationTrajectoires.push_back(dernier_resultat[taille]);
            }
        }
        else
        {
            m_derniere_erreur = "Il n'y a aucun mouvement.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}


bool DonneesIHMregleur::RecupereNomMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT nom_mouvement FROM mouvements WHERE id_mouvement=" + id_mouvement;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat= m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_nomMouvement = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de nom pour ce mouvement.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }

    return retour;
}

bool DonneesIHMregleur::RecupereNomTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT nom_trajectoire FROM trajectoires WHERE id_trajectoire=" + id_trajectoire;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat= m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_nomTrajectoire = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de nom pour cette trajectoire.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }

    return retour;
}

bool DonneesIHMregleur::RecupereOrdreMouvements(string id_trajectoire)
{
    bool retour = false;
    string requete = "SELECT ordre_mouvements FROM intermediaire_mouvements_trajectoires WHERE id_t=" + id_trajectoire;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_ordreMouvements = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas d'ordre de mouvement pour cette trajectoire.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }

    return retour;
}

bool DonneesIHMregleur::RecupereAxeXMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT axe_x FROM mouvements WHERE id_mouvement=" +id_mouvement;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_AxeXMouvement = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas d'axe x pour ce mouvement.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHMregleur::RecupereAxeYMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT axe_y FROM mouvements WHERE id_mouvement=" +id_mouvement;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_AxeYMouvement = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas d'axe y pour ce mouvement.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHMregleur::RecupereAxeZMouvement(string id_mouvement)
{
    
    bool retour = false;
    
    string requete = "SELECT axe_z FROM mouvements WHERE id_mouvement=" +id_mouvement;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_AxeZMouvement = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas d'axe z pour ce mouvement.";
        }
        
        retour = true;
        
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}
bool DonneesIHMregleur::RecupereDepartTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT point_depart FROM intermediaire_mouvements_trajectoires WHERE id_t=" +id_trajectoire;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {   
        vector<string> dernier_resultat=m_bdd_anodisation->GetLastResult();
        //for(unsigned int i; i<dernier_resultat.size();i++)
        //{
        //    cout<<dernier_resultat[i]<<endl;
        //}
        
        if(!dernier_resultat.empty())
        {
            m_DepartTrajectoire = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de point de départ pour cette trajectoire.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHMregleur::RecupereAriveeTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT point_arrive FROM intermediaire_mouvements_trajectoires WHERE id_t=" +id_trajectoire;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_ArriveeTrajectoire = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de point de d'arrivé pour cette trajectoire.";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour; 
}
