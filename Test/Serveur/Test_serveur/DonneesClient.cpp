/*******************************************************************************
 *  Fichier:  DonneesClient.cpp
 *  Projet:   Chaîne d'anodisation - Test du client pour le PC responsable 
              de production avec un serveur
 *  Crée le:  14/04/2018
 *  Utilité:  Contient les données des clients connectés
 *  Auteur:   Florian Provost
*******************************************************************************/
#include "DonneesClient.h"

DonneesClient::DonneesClient(int num)
{
    m_num = num;
    m_etat = 0;
}

/*DonneesClient::~DonneesClient()
{
    
}
*/
