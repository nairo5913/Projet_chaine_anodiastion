/*******************************************************************************
 *  Fichier:  Protocoles.h
 *  Projet:   Chaîne d'anodisation
 *  Crée le:  29/04/2018
 *  Utilité:  Défini le protocole utilisé entre le client et le serveur
 *  Auteur:   Florian Provost
              Nassim Boubziz
*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Partie 100, Connexion
////////////////////////////////////////////////////////////////////////////////
// Connexion
#define DEMANDE_CONNEXION "100-"
#define CONNEXION_OK "101-"
#define CONNEXION_PAS_OK "102-"
#define NOMBRE_MAX_UTILISATEURS "103-"

// Identification
#define DEMANDE_IDENTIFICATION "110-"
#define IDENTIFICATION_OK "111-"
#define IDENTIFICATION_PAS_OK "112-"

////////////////////////////////////////////////////////////////////////////////
// Partie 200, Exécution
////////////////////////////////////////////////////////////////////////////////
//
// Exécution
#define DEMANDE_TEST_PROCESSUS "200-"
#define DEMANDE_TEST_TRAJECTOIRE "201-"
#define DEMANDE_TEST_MOUVEMENT "202-"
#define DEMANDE_EXECUTION_PROCESSUS "203-"
#define EXECUTION_OK "204-"
#define EXECUTION_IMPOSSIBLE "205-"

// Interuption
#define STOP_TEST_PROCESSUS "210-"
#define STOP_TEST_TRAJECTOIRE "211-"
#define STOP_TEST_MOUVEMENT "212-"
#define STOP_OK "213-"
#define PAS_PROPRIETAIRE "214-"

////////////////////////////////////////////////////////////////////////////////
// Partie 300, Informations
////////////////////////////////////////////////////////////////////////////////
//
#define DISPONIBILITE_BRAS "300-"
#define BRAS_DISPONIBLE "301-"
#define BRAS_INDISPONIBLE "302-"
#define DEMANDE_TACHE_EN_COURS "303-"
#define TACHE_EN_COURS "304-"
#define PAS_TACHE_EN_COURS "305-"

////////////////////////////////////////////////////////////////////////////////
// Partie 400, Erreurs
////////////////////////////////////////////////////////////////////////////////
//
#define ERREUR_RESEAUX "402-"
#define ERREUR_CONNEXION_BDD "403-"
#define COMMANDE_INCONNUE "404-"

////////////////////////////////////////////////////////////////////////////////
// Partie 500, Déconnexion
////////////////////////////////////////////////////////////////////////////////
//
#define DEMANDE_DECONNEXION "500-"
#define DECONNEXION_OK "501-"
#define DECONNEXION_PAS_OK "502-"