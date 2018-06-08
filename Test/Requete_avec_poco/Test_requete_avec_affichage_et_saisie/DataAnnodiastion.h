/*******************************************************************************
  *  Fichier:  DataAnnodiastion.h
  *  Projet:   Chaîne d'anodisation - Test des requêtess SQL en C++ afin de voir 
               la structure de la BdD
  *  Crée le:  07/04/2018
  *  Utilité:  Permet l'accès à la BdD Anodisation_test
  *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef DATAANNODIASTION_H
#define DATAANNODIASTION_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <Poco/Data/Session.h>
#include <Poco/Data/ODBC/Connector.h>
using namespace Poco::Data::ODBC;
using namespace Poco::Data;
#include <Poco/Exception.h>
#include "Poco/Data/ODBC/ODBCException.h"
#include <Poco/Data/RecordSet.h>

class DataAnnodiastion
{
    public:
        DataAnnodiastion(string dsn);
        ~DataAnnodiastion();
        bool ExecuteSelect(string requete);
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

#endif // DATAANNODIASTION_H
