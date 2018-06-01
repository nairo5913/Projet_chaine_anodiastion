/*******************************************************************************
 *  Fichier:  Protocoles.h
 *  Projet:   Chaîne d'anodisation - Gestion du PC responsable de production
 *  Crée le:  29/04/2018
 *  Utilité:  Défini le protocole utilisé entre le client et le serveur
 *  Auteur:   Florian Provost
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
#define DEMANDE_EXECUTION_PROCESSUS "200-"
#define DEMANDE_TEST_TRAJECTOIRE "201-"
#define DEMANDE_TEST_MOUVEMENT "202-"
#define EXECUTION_IMPOSSIBLE "203-"

////////////////////////////////////////////////////////////////////////////////
// Partie 300, Informations
////////////////////////////////////////////////////////////////////////////////
//
#define DISPONIBILITE_BRAS "300-"
#define BRAS_DISPONIBLE "301-"
#define BRAS_INDISPONIBLE "302-"
#define DEMANDE_TACHE_EN_COURS "303-"
#define TACHE_EN_COURS "304-" // Reception de la taches en cours 
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