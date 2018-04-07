/*******************************************************************************
  *  Fichier:  DataAnnodiastion.cpp
  *  Projet:   Chaîne d'anodisation - Test des requetes SQL en C++ afin de voir 
               la structure de la BdD
  *  Crée le:  07/04/2018
  *  Utilité:  Permet l'accès à la BdD Annodisation_test
  *  Auteur:   Florian Provost
*******************************************************************************/
#include "DataAnnodiastion.h"

DataAnnodiastion::DataAnnodiastion(string dsn)
{
    m_session = NULL;
    m_connexionOK = true;
    
    ODBC::Connector::registerConnector();
    
    // On essaye de se connecteur à la bdd avec les info contenues dans le dsn
    try
    {
        m_session = new Session("ODBC", "DSN=" + dsn);
    }
    catch (ConnectionFailedException& ce)
    {
        m_last_error= ce.displayText();
        m_connexionOK=false;
    }
}

DataAnnodiastion::~DataAnnodiastion()
{
    // Destructeur
}

bool DataAnnodiastion::ExecuteSelect(string requete)
{
    bool retour = true;
    
    return retour;
}