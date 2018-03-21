#!/bin/sh
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
   echo "Usage : $0 $ROUGE aucun paramètre $NORMAL"
   exit 1
fi

### Demande login pour générer la BdD sur le serveur ###

read -p "Entrez votre identifiant pour l'accès à la base de données : " identifiant
read -s -p "Entrez votre mot de passe pour l'accès à la base de données : " mot_passe
