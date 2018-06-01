/*******************************************************************************
 *  Fichier:  DonneesIHM.cpp
 *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
 *  Crée le:  25/05/2018
 *  Utilité:  Récuperer les données pour l'IHM depuis la Base de données et 
              stockage dans des variables
 *  Auteur:   Florian Provost
*******************************************************************************/
#include "DonneesIHM.h"

DonneesIHM::DonneesIHM(DataAnodisation *bdd)
{
    m_bdd_anodisation = bdd;
}

DonneesIHM::~DonneesIHM()
{
    // Destructeur
}

bool DonneesIHM::RecupereDureeTotal(string id_processus)
{
    bool retour = false;
    
    string requete = "SELECT duree_processus FROM processus WHERE id_processus=" + id_processus;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_dureeTotal = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de durée total pour ce processus";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHM::RecupereListeProcessus()
{
    bool retour = false;
    
    string requete = "SELECT id_processus, nom_processus FROM processus ORDER BY id_processus";
    m_listeProcessus.clear();
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            for(unsigned int taille = 0; taille < dernier_resultat.size(); taille++)
            {
                m_listeProcessus.push_back(dernier_resultat[taille]);
            }
        }
        else
        {
            m_derniere_erreur = "Il n'y a aucun processus dans la base de données";
        }
        
        retour = true;
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }

    return retour;
}

bool DonneesIHM::RecupereListeTouteTrajectoires()
{
    bool retour = false;
    
    string requete = "SELECT id_trajectoire, nom_trajectoire, contenu_trajectoire, duree_trajectoire FROM trajectoires ORDER BY id_trajectoire";
    
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
            m_derniere_erreur = "Il n'y a aucune trajectoire dans la base de données";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }

    return retour;
}

bool DonneesIHM::RecupereListeTrajectoiresProcessus(string id_processus) // À finir
{
    bool retour;
    
    string requete = "SELECT id_t FROM intermediaire_processus_trajectoires WHERE id_p=" + id_processus;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        for(unsigned int taille = 0; taille < dernier_resultat.size(); taille++)
        {
            string requete = "SELECT id_trajectoire, nom_trajectoire, contenu_trajectoire, duree_trajectoire FROM trajectoires WHERE id_trajectoire=" + dernier_resultat[taille];
            
            if(m_bdd_anodisation->ExecuteSelect(requete))
            {
                retour = true;
                vector<string> resultat_traj = m_bdd_anodisation->GetLastResult();
                
                for(unsigned int nombre = 0; nombre < resultat_traj.size(); nombre++)
                {
                    
                    m_listeTrajectoiresProcessus.push_back(resultat_traj[nombre]);
                }
            }
            else
            {
                
                retour = false;
            }
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
        retour = false;
    }

    return retour;
}

bool DonneesIHM::RecupereNombreBain(string id_processus)
{
    bool retour = false;
    
    string requete = "SELECT nombre_bain FROM processus WHERE id_processus=" + id_processus;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_nombreBain = dernier_resultat[0];
            
            retour = true;
            
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de nombre de bain pour ce processus";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}

bool DonneesIHM::RecupereNomProcessus(string id_processus)
{
    bool retour = false;
    
    string requete = "SELECT nom_processus FROM processus WHERE id_processus=" + id_processus;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_nomProcessus = dernier_resultat[0];
            
            retour = true;
            
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas de nom pour ce processus";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }

    return retour;
}

bool DonneesIHM::RecupereOrdreTrajectoires(string id_processus)
{
    bool retour = false;
    
    string requete = "SELECT ordre_trajectoires FROM intermediaire_processus_trajectoires WHERE id_p=" + id_processus;
    
    if(m_bdd_anodisation->ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = m_bdd_anodisation->GetLastResult();
        
        if(!dernier_resultat.empty())
        {
            m_ordreTrajectoires = dernier_resultat[0];
            
            retour = true;
        }
        else
        {
            m_derniere_erreur = "Il n'y a pas d'ordre des trajectoires pour ce processus";
        }
    }
    else
    {
        m_derniere_erreur = m_bdd_anodisation->GetLastError();
    }
    
    return retour;
}
