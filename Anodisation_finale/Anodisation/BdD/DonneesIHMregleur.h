/*******************************************************************************
 *  Fichier:  DonneesIHMregleur.cpp
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  09/06/2018
 *  Utilité:  Récuperer les données pour l'IHM régleur depuis la Base de 
              données et stockage dans des variables
 *  Auteur:   Florian Provost
              Nassim Boubziz
*******************************************************************************/
#ifndef DONNEESIHMREGLEUR_H
#define DONNEESIHMREGLEUR_H

#include <list>
using std::list;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include "DataAnodisation.h"

class DonneesIHMregleur
{
    public:
        DonneesIHMregleur(DataAnodisation *bdd);
        ~DonneesIHMregleur();
        
        string GetDureeTotalMouvement(){return m_dureeTotalMouvement;};
        string GetNomMouvement(){return m_nomMouvement;};
        string GetOrdreMouvements(){return m_ordreMouvements;};
        string GetAxeXMouvement(){return m_AxeXMouvement;};
        string GetAxeYMouvement(){return m_AxeYMouvement;};
        string GetAxeZMouvement(){return m_AxeZMouvement;};
        vector<string> GetListeToutMouvements(){return m_listeToutMouvements;};
        vector<string> GetListeMouvementsCreationTrajectoires(){return m_listeMouvementsCreationTrajectoires;};
        
        string GetDureeTotalTrajectoire(){return m_dureeTotalTrajectoire;};
        string GetDepartTrajectoire(){return m_DepartTrajectoire;};
        string GetArriveeTrajectoire(){return m_ArriveeTrajectoire;};
        string GetNomTrajectoire(){return m_nomTrajectoire;};
        vector<string> GetListeTouteTrajectoires(){return m_listeTouteTrajectoires;};
        vector<string> GetListeTrajectoires(){return m_listeTrajectoires;};
        
        string GetDerniereErreur(){return m_derniere_erreur;};
        unsigned int GetNombreColonnes(){return m_nb_colones;};

        // Recupération de données pour l'IHM
        bool RecupereDureeTotalMouvement(string id_mouvement);
        bool RecupereAxeXMouvement(string id_mouvement);
        bool RecupereAxeYMouvement(string id_mouvement);
        bool RecupereAxeZMouvement(string id_mouvement);
        bool RecupereListeToutMouvements();
        bool RecupereNomMouvement(string mouvement);
        bool RecupereListeMouvementsCreationTrajectoires();
        
        bool RecupereDepartTrajectoire(string id_trajectoire);
        bool RecupereAriveeTrajectoire(string id_trajectoire);
        bool RecupereDureeTotalTrajectoire(string id_trajectoire);
        bool RecupereListeTouteTrajectoires();
        bool RecupereNomTrajectoire(string id_trajectoire);
        bool RecupereOrdreMouvements(string id_trajectoire);

    private:
        DataAnodisation *m_bdd_anodisation;
        
        string m_dureeTotalMouvement;
        string m_nomMouvement;
        string m_ordreMouvements;
        string m_AxeXMouvement;
        string m_AxeYMouvement;
        string m_AxeZMouvement;
        vector<string> m_listeToutMouvements;
        vector<string> m_listeMouvementsCreationTrajectoires;
        vector<string> m_listeMouvement;
        
        string m_dureeTotalTrajectoire;
        string m_DepartTrajectoire;
        string m_nomTrajectoire;
        string m_ArriveeTrajectoire;
        vector<string> m_listeTrajectoires;
        vector<string> m_listeTouteTrajectoires;
        
        string m_derniere_erreur;
        unsigned int m_nb_colones;
};

#endif // DONNEESIHMREGLEUR_H
