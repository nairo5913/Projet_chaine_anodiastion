/*******************************************************************************
  *  Fichier:  DataAnnodiastion.h
  *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
  *  Crée le:  29/04/2018
  *  Utilité:  Permet l'accès à la BdD Anodisation_test
  *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef DATAANODISATION_H
#define DATAANODISATION_H

#include <list>
using std::list;
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
        vector<string> GetLastResult(){return m_last_result;};
        
        
    protected:
    private:
        Session *m_session;
        
        bool m_connexionOK;
        string m_last_error;
        
        vector<string> m_last_result;
};

#endif // DATAANODISATION_H
