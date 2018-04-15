/*******************************************************************************
  *  Fichier:  Protocoles.h
  *  Projet:   Chaîne d'anodisation - Gestion du client pour le PC responsable 
               de production
  *  Crée le:  11/04/2018
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
// Partie 200, Envoi/Réception
////////////////////////////////////////////////////////////////////////////////
//
#define ENVOI "200-"
#define RECEPTION_OK "201-"
#define RECEPTION_PAS_OK "202-"

////////////////////////////////////////////////////////////////////////////////
// Partie 300, Exécution
////////////////////////////////////////////////////////////////////////////////
//
#define EXECUTION_IMPOSSIBLE "302-"

////////////////////////////////////////////////////////////////////////////////
// Partie 400, Erreurs
////////////////////////////////////////////////////////////////////////////////
//
#define ERREUR_RESEAUX "402-"
#define ERREUR_CONNEXION_BDD "403-"
#define COMMANDE_INCONNUE "404-"

////////////////////////////////////////////////////////////////////////////////
// Partie 500, Informations
////////////////////////////////////////////////////////////////////////////////
//
#define DISPONIBILITE_BRAS "500-"
#define BRAS_DISPONIBLE "501-"
#define BRAS_INDISPONIBLE "502-"
#define DEMANDE_TACHE_EN_COURS "503-"
/*
 * #define  "504-" // Reception de la taches en cours 
 * Type (Trajectoire, mouvement ou processus) + id
 * A faire dans le code
*/
#define PAS_TACHE_EN_COURS "505-"

////////////////////////////////////////////////////////////////////////////////
// Partie 600, Déconnexion
////////////////////////////////////////////////////////////////////////////////
//
#define DEMANDE_DECONNEXION "600-"
#define DECONNEXION_OK "601-"
#define DECONNEXION_PAS_OK "602-"