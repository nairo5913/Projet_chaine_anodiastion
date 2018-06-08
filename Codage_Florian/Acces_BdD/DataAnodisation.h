/*******************************************************************************
  *  Fichier:  DataAnnodiastion.h
  *  Projet:   Chaîne d'anodisation - Gestion du client BdD pour le PC du
               responsable de production
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
        bool ExecuteDelete(string requete); // À coder
        bool ExecuteInsert(string requete); // À coder
        bool ExecuteSelect(string requete); // À coder
        bool ExecuteUpdate(string requete); // À coder
        
        bool IsConnexionOK(){return m_connexionOK;};
        string GetLastError(){return m_last_error;};
        vector<string> GetLastResult(){return m_last_result;};
        unsigned int GetNombreColonnes(){return m_nb_colones;};
        
    protected:
    private:
        Session *m_session;
        bool m_connexionOK;
        unsigned int m_nb_colones;
        string m_last_error;
        vector<string> m_last_result;
};

#endif  // DATAANODISATION_H
