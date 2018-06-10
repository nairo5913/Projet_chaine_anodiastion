/*******************************************************************************
 *  Fichier:  DataAnnodiastion.cpp
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  29/04/2018
 *  Utilité:  Permet l'accès à la BdD Anodisation_test
 *  Auteur:   Florian Provost
              Nassim Boubziz
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
        m_last_error = ce.displayText();
        m_connexionOK = false;
    }
}

DataAnodisation::~DataAnodisation()
{
    // Destructeur
}
//
// SQL
//
bool DataAnodisation::ExecuteDelete(string requete)
{
    bool retour = true;

    if(m_session != NULL)
    {
        Statement* supression;

        try
        {
            supression = new Statement(*m_session);
            *supression << requete;

            supression->execute();
        }
        catch(ODBC::StatementException& se)
        {
            m_last_error = se.toString();
            retour = false;
        }
    }
    else
    {
        m_last_error = "Non connecté à la BdD";
        retour = false;
    }

    return retour;
}

bool DataAnodisation::ExecuteInsert(string requete)
{
    bool retour = true;

    if(m_session != NULL)
    {
        Statement* insert;

        try
        {
            insert = new Statement(*m_session);
            *insert << requete;
            insert->execute();
        }
        catch(ODBC::StatementException& se)
        {
            m_last_error = se.toString();
            retour = false;
        }
    }
    else
    {
        m_last_error = "Non connecté à la BdD";
        retour = false;
    }

    return retour;
}

bool DataAnodisation::ExecuteSelect(string requete)
{
    bool retour = true;

    if(m_session != NULL)
    {
        Statement* select;
        RecordSet* rs;

        try
        {
            select = new Statement(*m_session);
            *select << requete;
            rs = new RecordSet(*select);

            while(!select->done())
            {
                select->execute();
                bool more = rs->moveFirst();
                m_last_result.clear();

                // m_nb_colones = rs->columnCount();
                // std::cout << "Nombre de colonnes : " << m_nb_colones << std::endl;

                while(more)
                {
                    for(std::size_t col = 0; col < rs->columnCount(); ++col)
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
    else
    {
        m_last_error = "Non connecté à la BdD";
        retour = false;
    }

    return retour;
}

bool DataAnodisation::ExecuteUpdate(string requete)
{
    bool retour = true;

    if(m_session != NULL)
    {
        Statement* update;

        try
        {
            update = new Statement(*m_session);
            *update << requete;
            update->execute();
        }
        catch(ODBC::StatementException& se)
        {
            m_last_error = se.toString();
            retour = false;
        }
    }
    else
    {
        m_last_error = "Non connecté à la BdD";
        retour = false;
    }

    return retour;
}

string DataAnodisation::DernierIdProcessus()
{
    string requete = "SELECT id_processus FROM processus ORDER BY id_processus DESC LIMIT 1 OFFSET 0";
    string retour = "";
    
    if(ExecuteSelect(requete))
    {
        cout << "dernier id : " << m_last_result[0] << endl;
        retour = m_last_result[0];
    }
    else
    {
        cout << "erreur requete" << endl;
    }
    
    return retour;
}

