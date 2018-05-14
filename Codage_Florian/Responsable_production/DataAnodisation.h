/*******************************************************************************
  *  Fichier:  DataAnnodiastion.h
  *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
  *  Crée le:  29/04/2018
  *  Utilité:  Permet l'accès à la BdD Anodisation_test
  *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef DATAANODISATION_H
#define DATAANODISATION_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/Session.h>
using namespace Poco::Data::ODBC;
using namespace Poco::Data;
#include <Poco/Data/RecordSet.h>
#include <Poco/Exception.h>
#include "Poco/Data/ODBC/ODBCException.h"


class DataAnodisation
{
    public:
        DataAnodisation(string dsn);
        ~DataAnodisation();
        
        // Éxecution des différentes requêtes
        bool ExecuteDelete(string requete);
        bool ExecuteInsert(string requete);
        bool ExecuteSelect(string requete);
        bool ExecuteUpdate(string requete);
        
        // Assesseur
        bool IsConnexionOK(){return m_connexionOK;};
        string GetLastError(){return m_last_error;};
        string GetDureeTotal(){return m_dureeTotal;};
        string GetNombreBain(){return m_nombreBain;};
        string GetNomProcessus(){return m_nomProcessus;};
        string GetOrdreTrajectoires(){return m_ordreTrajectoires;};
        unsigned int GetNombreColonnes(){return m_nb_colones;};
        vector<string> GetLastResult(){return m_last_result;};
        vector<string> GetListeTouteTrajectoires(){return m_listeTouteTrajectoires;};
        vector<string> GetListeTrajectoiresProcessus(){return m_listeTrajectoiresProcessus;};
        vector<string> GetListeProcessus(){return m_listeProcessus;};
        
        // Recupération de données pour l'IHM
        bool RecupereDureeTotal(string id_processus);
        bool RecupereListeProcessus();
        bool RecupereListeTrajectoiresProcessus(string id_processus);
        bool RecupereListeTouteTrajectoires();
        bool RecupereNombreBain(string id_processus);
        bool RecupereNomProcessus(string id_processus);
        bool RecupereOrdreTrajectoires(string id_processus);
        
    protected:
    private:
        Session *m_session;
        
        bool m_connexionOK;
        string m_dureeTotal;
        string m_last_error;
        string m_nomProcessus;
        string m_nombreBain;
        string m_ordreTrajectoires;
        unsigned int m_nb_colones;
        vector<string> m_listeTouteTrajectoires;
        vector<string> m_listeTrajectoiresProcessus;
        vector<string> m_listeProcessus;
        vector<string> m_last_result;
};

#endif // DATAANODISATION_H
