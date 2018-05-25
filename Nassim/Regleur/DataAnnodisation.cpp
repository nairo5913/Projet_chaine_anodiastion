#include "DataAnnodisation.h"

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

bool DataAnodisation::ExecuteDelete(string requete)  //À coder
{
    bool retour = false;

    return retour;
}

bool DataAnodisation::ExecuteInsert(string requete)  //À coder
{
    bool retour = false;

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

    return retour;
}

bool DataAnodisation::ExecuteUpdate(string requete)  //À coder
{
    bool retour = false;

    return retour;
}

bool DataAnodisation::RecupereDureeTotal(string id_processus) // À coder
{
    bool retour = false;

    return retour;
}


bool DataAnodisation::RecupereListeToutMouvements()
{
    bool retour;
    string requete = "SELECT * FROM mouvements ORDER BY id_mouvement";
    
    m_listeToutMouvements.clear();
    
    if(ExecuteSelect(requete))
    {
        retour = true;
        
        for(unsigned int taille = 0; taille < m_last_result.size(); taille++)
        {
            m_listeToutMouvements.push_back(m_last_result[taille]);
        }
    }
    else
    {
        retour = false;
    }
    
    return retour;
}

bool DataAnodisation::RecupereListeTouteTrajectoires()
{
    bool retour;
    
    string requete = "SELECT * FROM trajectoires ORDER BY id_trajectoire";
    
    m_listeTouteTrajectoires.clear();
    
    if(ExecuteSelect(requete))
    {
        retour = true;
        
        for(unsigned int taille = 0; taille < m_last_result.size(); taille++)
        {
            m_listeTouteTrajectoires.push_back(m_last_result[taille]);
        }
    }
    else
    {
        retour = false;
    }

    return retour;
}

bool DataAnodisation::RecupereListeMouvementsTrajectoires(string id_mouvement) // À coder
{
    bool retour = false;

    return retour;
}


bool DataAnodisation::RecupereNomMouvement(string id_mouvement) // À coder
{
    bool retour = false;

    return retour;
}

bool DataAnodisation::RecupereNomTrajectoire(string id_trajectoire) // À coder
{
    bool retour = false;

    return retour;
}

bool DataAnodisation::RecupereOrdreMouvements(string id_trajectoire) // À coder
{
    bool retour = false;

    return retour;
}
