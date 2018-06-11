#!/bin/bash
# Florian provost SN2IR
# Creation_bdd.sh

### Style de texte ###
NORMAL="\\033[00m"

# Couleurs
NOIR="\\033[30m"
ROUGE="\\033[31m"
VERT="\\033[32m"
JAUNE="\\033[33m"
BLEU="\\033[34m"
ROSE="\\033[35m"
CYAN="\\033[36m"
BLANC="\\033[37m"

# Gras
GRAS="\\033[01m"

# Italique
ITALIQUE="\\033[03m"

# Souligné
SOULIGNE="\\033[04m"

#Fond
FOND_NOIR="\\033[40m"
FOND_ROUGE="\\033[41m"
FOND_VERT="\\033[42m"
FOND_JAUNE="\\033[43m"
FOND_BLEU="\\033[44m"
FOND_ROSE="\\033[45m"
FOND_CYAN="\\033[46m"
FOND_BLANC="\\033[47m"

### Test si un seul parametre ###
if [ $# -ne 0 ]
then
   echo -e "Usage : $0 $ROUGE aucun paramètre $NORMAL"
   exit 1
fi

### Déclaration variable ###
#
nom_bdd='Anodisation_test'

### Demande login pour générer la BdD sur le serveur ###

read -p "Entrez votre identifiant pour l'accès à la base de données : " identifiant
#echo "login : $identifiant"

### Choix du serveur ###
#
echo -e "Choix du serveur :\n 1 : serveursn\n 2 : localhost"
read -p 'Entrez votre choix (1 seul caractere) : ' -n 1 choix_serveur
echo -e "\n"
#echo "Choix du serveur : $choix_serveur"

if [ $choix_serveur = "1" ]
then
    serveur='serveursn'
elif [ $choix_serveur = "2" ]
then
    serveur='localhost'
else
    echo -e "$GRAS$ROUGE Le choix du serveur est éronné !$NORMAL\n"
    exit 1
fi

### Récapitulatif ###
#
echo -e " $SOULIGNE$GRAS$JAUNE""Nom de la Base de données :$NORMAL $nom_bdd"
echo -e " $SOULIGNE$GRAS$JAUNE""Nom du serveur :$NORMAL $serveur"
echo -e " $SOULIGNE$GRAS$JAUNE""Login de l'utilisateur :$NORMAL $identifiant\n"

### Création ###
#
echo -e " Suppression de la base de données si existante. Si non existante PostgreSQL peut afficher un message d’erreur, ne pas s’en soucier."
dropdb -h $serveur -U $identifiant $nom_bdd

echo -e " Création de la base de données."
createdb -h $serveur -U $identifiant $nom_bdd

echo -e " Remplissage de la base de données."
psql -h $serveur -U $identifiant -d $nom_bdd < ./cree_tables_et_remplit_bdd_anodisation.sql
