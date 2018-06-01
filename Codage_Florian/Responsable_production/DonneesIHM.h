/*******************************************************************************
 *  Fichier:  DonneesIHM.h
 *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
 *  Crée le:  25/05/2018
 *  Utilité:  Récuperer les données pour l'IHM depuis la Base de données et 
              stockage dans des variables
 *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef DONNEESIHM_H
#define DONNEESIHM_H

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

class DonneesIHM
{
    public:
        DonneesIHM(DataAnodisation *bdd);
        ~DonneesIHM();

        string GetDureeTotal() {return m_dureeTotal;};
        string GetNombreBain() {return m_nombreBain;};
        string GetNomProcessus() {return m_nomProcessus;};
        string GetOrdreTrajectoires() {return m_ordreTrajectoires;};
        unsigned int GetNombreColonnes() {return m_nb_colones;};
        vector<string> GetListeTouteTrajectoires() {return m_listeTouteTrajectoires;};
        vector<string> GetListeTrajectoiresProcessus() {return m_listeTrajectoiresProcessus;};
        vector<string> GetListeProcessus() {return m_listeProcessus;};
        string GetDerniereErreur(){return m_derniere_erreur;};

        // Recupération de données pour l'IHM
        bool RecupereDureeTotal(string id_processus);
        bool RecupereListeProcessus();
        bool RecupereListeTouteTrajectoires();
        bool RecupereListeTrajectoiresProcessus(string id_processus);
        bool RecupereNombreBain(string id_processus);
        bool RecupereNomProcessus(string id_processus);
        bool RecupereOrdreTrajectoires(string id_processus);

    private:
        DataAnodisation *m_bdd_anodisation;

        string m_derniere_erreur;
        string m_dureeTotal;
        string m_nomProcessus;
        string m_nombreBain;
        string m_ordreTrajectoires;
        unsigned int m_nb_colones;
        vector<string> m_listeTouteTrajectoires;
        vector<string> m_listeTrajectoiresProcessus;
        vector<string> m_listeProcessus;
};

#endif // DONNEESIHM_H
