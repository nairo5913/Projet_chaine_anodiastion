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
}

bool DataAnodisation::RecupereDureeTotalMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT duree_mouvement FROM mouvements WHERE id_mouvement=" + id_mouvement;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = GetLastResult();
        
        m_dureeTotalMouvement = dernier_resultat[0];
        
        retour = true;
    }
    else
    {
        retour = false;
    }
    
    return retour;
}

bool DataAnodisation::RecupereDureeTotalTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT duree_trajectoire FROM trajectoires WHERE id_trajectoire=" + id_trajectoire;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat = GetLastResult();
        
        m_dureeTotalTrajectoire = dernier_resultat[0];
        
        retour = true;
    }
    else
    {
        retour = false;
    }
    
    return retour;
}

bool DataAnodisation::RecupereListeToutMouvements()
{
    bool retour;
    string requete = "SELECT id_mouvement, nom_mouvement FROM mouvements ORDER BY id_mouvement";
    
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
    
    string requete = "SELECT id_trajectoire, nom_trajectoire FROM trajectoires ORDER BY id_trajectoire";
    
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

bool DataAnodisation::RecupereListeMouvementsCreationTrajectoires() // À coder
{
    bool retour;
    string requete = "SELECT id_mouvement, nom_mouvement, contenu_mouvement FROM mouvements ORDER BY id_mouvement";
    
    m_listeMouvementsCreationTrajectoires.clear();
    
    if(ExecuteSelect(requete))
    {
        retour = true;
        
        for(unsigned int taille = 0; taille < m_last_result.size(); taille++)
        {
            m_listeMouvementsCreationTrajectoires.push_back(m_last_result[taille]);
        }
    }
    else
    {
        retour = false;
    }
    
    return retour;
}


bool DataAnodisation::RecupereNomMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT nom_mouvement FROM mouvements WHERE id_mouvement=" + id_mouvement;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat= GetLastResult();
        
        m_nomMouvement= dernier_resultat[0];
        
        retour=true;
    }
    else
    {
        retour=false;
    }

    return retour;
}

bool DataAnodisation::RecupereNomTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT nom_trajectoire FROM trajectoires WHERE id_trajectoire=" + id_trajectoire;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat= GetLastResult();
        
        m_nomTrajectoire= dernier_resultat[0];
        
        retour=true;
    }
    else
    {
        retour=false;
    }

    return retour;
}

bool DataAnodisation::RecupereOrdreMouvements(string id_trajectoire) // À coder
{
    bool retour = false;
    string requete = "SELECT ordre_mouvements FROM intermediaire_mouvements_trajectoires WHERE id_t=" +id_trajectoire;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=GetLastResult();
        
        m_ordreMouvements= dernier_resultat[0];
        
        retour=true;
    }

    return retour;
}

bool DataAnodisation::RecupereAxeXMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT axe_x FROM mouvements WHERE id_mouvement=" +id_mouvement;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=GetLastResult();
        
        m_AxeXMouvement= dernier_resultat[0];
    
        retour = true;
    }
    
    return retour;
}

bool DataAnodisation::RecupereAxeYMouvement(string id_mouvement)
{
    bool retour = false;
    
    string requete = "SELECT axe_y FROM mouvements WHERE id_mouvement=" +id_mouvement;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=GetLastResult();
        
        m_AxeYMouvement= dernier_resultat[0];
        
        retour = true;
    }
    
    return retour;
}

bool DataAnodisation::RecupereAxeZMouvement(string id_mouvement)
{
    
    bool retour = false;
    
    string requete = "SELECT axe_z FROM mouvements WHERE id_mouvement=" +id_mouvement;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=GetLastResult();
        
        m_AxeZMouvement = dernier_resultat[0];
        
        retour = true;
        
    }
    return retour;
}
bool DataAnodisation::RecupereDepartTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT point_depart FROM intermediaire_mouvements_trajectoires WHERE id_t=" +id_trajectoire;
    
    if(ExecuteSelect(requete))
    {   
        vector<string> dernier_resultat=GetLastResult();
        //for(unsigned int i; i<dernier_resultat.size();i++)
        //{
        //    cout<<dernier_resultat[i]<<endl;
        //}
        
        m_DepartTrajectoire = dernier_resultat[0];
        
        retour = true;
    }
    return retour;
}

bool DataAnodisation::RecupereAriveeTrajectoire(string id_trajectoire)
{
    bool retour = false;
    
    string requete = "SELECT point_arrive FROM intermediaire_mouvements_trajectoires WHERE id_t=" +id_trajectoire;
    
    if(ExecuteSelect(requete))
    {
        vector<string> dernier_resultat=GetLastResult();
        
        m_ArriveeTrajectoire = dernier_resultat[0];
        
        retour = true;
    }
    return retour; 
}
