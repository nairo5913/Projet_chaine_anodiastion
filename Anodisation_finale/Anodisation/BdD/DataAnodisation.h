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

   protected:
   private:
        Session *m_session;
    
        bool m_connexionOK;
        string m_last_error;
    
        vector<string> m_last_result;
};

#endif  // DATAANODISATION_H
