/*******************************************************************************
 *  Fichier:  DataAnnodiastion.h
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  29/04/2018
 *  Utilité:  Permet l'accès à la BdD Anodisation_test
 *  Auteur:   Florian Provost
              Nassim Boubziz
*******************************************************************************/
#ifndef DATAANODISATION_H
#define DATAANODISATION_H

//#include <list>
//using std::list;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
// Librairies POCO
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Exception.h>
#include "Poco/Data/ODBC/ODBCException.h"
//#include "Poco/Util/HelpFormatter.h"
//#include "Poco/DateTimeFormatter.h"
//#include "Poco/DateTimeFormat.h"
using namespace Poco::Data::ODBC;
using namespace Poco::Data;
//using Poco::Data::Keywords::use;

class DataAnodisation
{
   public:
        DataAnodisation(string dsn);
        ~DataAnodisation();
    
        // Éxecution des différentes requêtes
        bool ExecuteDelete(string requete);
        bool ExecuteInsert(string donnees);
        bool ExecuteSelect(string requete);
        bool ExecuteUpdate(string requete);
        string DernierIdProcessus();
    
        // Assesseur
        bool IsConnexionOK(){return m_connexionOK;};
        string GetLastError(){return m_last_error;};
        vector<string> GetLastResult(){return m_last_result;};
        
        // Regleur
        string GetDureeTotalMouvement(){return m_dureeTotalMouvement;};
        string GetDureeTotalTrajectoire(){return m_dureeTotalTrajectoire;};
        string GetNomMouvement(){return m_nomMouvement;};
        string GetNomTrajectoire(){return m_nomTrajectoire;};
        string GetOrdreMouvements(){return m_ordreMouvements;};
        string GetAxeXMouvement(){return m_AxeXMouvement;};
        string GetAxeYMouvement(){return m_AxeYMouvement;};
        string GetAxeZMouvement(){return m_AxeZMouvement;};
        string GetDepartTrajectoire(){return m_DepartTrajectoire;};
        string GetArriveeTrajectoire(){return m_ArriveeTrajectoire;};
        unsigned int GetNombreColonnes(){return m_nb_colones;};
        vector<string> GetListeToutMouvements(){return m_listeToutMouvements;};
        vector<string> GetListeTouteTrajectoires(){return m_listeTouteTrajectoires;};
        vector<string> GetListeMouvementsCreationTrajectoires(){return m_listeMouvementsCreationTrajectoires;};
        vector<string> GetListeTrajectoires(){return m_listeTrajectoires;};
        
        // Recupération de données pour l'IHM régleur
        bool RecupereDureeTotalMouvement(string id_mouvement);
        
        bool RecupereAxeXMouvement(string id_mouvement);
        bool RecupereAxeYMouvement(string id_mouvement);
        bool RecupereAxeZMouvement(string id_mouvement);
        bool RecupereDepartTrajectoire(string id_trajectoire);
        bool RecupereAriveeTrajectoire(string id_trajectoire);
        bool RecupereDureeTotalTrajectoire(string id_trajectoire);
        bool RecupereListeToutMouvements();
        bool RecupereListeTouteTrajectoires();
        bool RecupereListeMouvementsCreationTrajectoires();
        bool RecupereNomMouvement(string mouvement);
        bool RecupereNomTrajectoire(string id_trajectoire);
        bool RecupereOrdreMouvements(string id_processus);

   protected:
   private:
        Session *m_session;
    
        bool m_connexionOK;
        string m_last_error;
    
        vector<string> m_last_result;
        
        // Régleur
        string m_dureeTotalMouvement;
        string m_dureeTotalTrajectoire;
        string m_nomMouvement;
        string m_nomTrajectoire;
        string m_ordreMouvements;
        string m_AxeXMouvement;
        string m_AxeYMouvement;
        string m_AxeZMouvement;
        string m_DepartTrajectoire;
        string m_ArriveeTrajectoire;
        unsigned int m_nb_colones;
        vector<string> m_listeTouteTrajectoires;
        vector<string> m_listeToutMouvements;
        vector<string> m_listeMouvementsCreationTrajectoires;
        vector<string> m_listeMouvement;
        vector<string> m_listeTrajectoires;
};

#endif  // DATAANODISATION_H
