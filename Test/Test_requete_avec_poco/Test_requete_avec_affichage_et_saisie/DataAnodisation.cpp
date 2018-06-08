/*******************************************************************************
  *  Fichier:  DataAnnodiastion.cpp
  *  Projet:   Chaîne d'anodisation - Gestion du client BdD pour le PC du 
               responsable de production
  *  Crée le:  25/05/2018
  *  Utilité:  Permet l'accès à la BdD Anodisation_test
  *  Auteur:   Nassim Boubziz
*******************************************************************************/
#include "DataAnodisation.h"

DataAnodisation::DataAnodisation(string dsn)
{
    m_session = NULL;
    m_connexionOK = true;
    
    ODBC::Connector::registerConnector();
    
    // On essaye de se connecteur à la bdd avec les info contenues dans le dsn
    try
    {
        m_session = new Session("ODBC", "DSN=" + dsn);
    }
    catch(ConnectionFailedException& ce)
    {
        m_last_error= ce.displayText();
        m_connexionOK=false;
    }
}

DataAnodisation::~DataAnodisation()
{
    // Destructeur
}

bool DataAnodisation::ExecuteDelete(string requete) //À coder
{
    bool retour = false;
    
    return retour;
}

bool DataAnodisation::ExecuteInsert(string requete) //À coder
{
    bool retour = false;
    
    return retour;
}

bool DataAnodisation::ExecuteSelect(string requete) //À coder
{
    bool retour = false;
    
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

bool DataAnodisation::ExecuteUpdate(string requete) //À coder
{
    bool retour = false;
    
    return retour;
}

/*bool DataAnodisation::ExecuteUpdate(string requete) //A coder
{
    bool retour = false;
    
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
                
            
            }
        }
        catch(ODBC::StatementExeption& se)
        {
            m_last-error = se.totString();
            retour = false;
        }
    }
        
    return retour;
     
