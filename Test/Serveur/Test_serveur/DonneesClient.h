/*******************************************************************************
  *  Fichier:  DonneesClient.h
  *  Projet:   Chaîne d'anodisation - Test du client pour le PC responsable 
               de production avec un serveur
  *  Crée le:  14/04/2018
  *  Utilité:  Contient les données des clients connectés
  *  Auteur:   Florian Provost
*******************************************************************************/
#ifndef DONNEESCLIENT_H
#define DONNEESCLIENT_H

class DonneesClient
{
    public:
        DonneesClient(int num);
        //~DonneesClient();
        int GetEtat(){return m_etat;};
        int GetNumClient(){return m_num;};
        void SetEtat(int etat){m_etat=etat;};
    protected:
    private:
        int m_num;
        int m_etat;
        
};

#endif // DONNEESCLIENT_H
