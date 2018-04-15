/*******************************************************************************
  *  Fichier:  DataAnnodiastion.cpp
  *  Projet:   Chaîne d'anodisation - Test des requêtes SQL en C++ afin de voir 
               la structure de la BdD
  *  Crée le:  07/04/2018
  *  Utilité:  Permet l'accès à la BdD Anodisation_test
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
    
    if(m_session != NULL)
    {
        Statement *select;
        RecordSet *rs;
        
        try
        {
            select = new Statement (*m_session);
            *select << requete;
            rs = new RecordSet(*select);
            
            while(!select->done())
            {
                select->execute();
                bool more = rs->moveFirst();
                m_last_result.clear();
                
                m_nb_colones = rs->columnCount();
                
                //std::cout << "Nombre de colonnes : " << m_nb_colones << std::endl;
                
                while(more)
                {
                    for(std::size_t col = 0; col < m_nb_colones; ++col)
                    {
                        m_last_result.push_back(rs->value(col).convert<string>());
                    }
                    more = rs->moveNext();
                }
            }
        }
        catch(ODBC::StatementException& se)
        {
            m_last_error = se.toString();
            retour = false;
        }
    }
    
    return retour;
}