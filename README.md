# Projet chaîne d'annodisation

:exclamation: :collision: :bomb: :gun: 

[Liste des emoji](https://www.webpagefx.com/tools/emoji-cheat-sheet/)

## Description

Projet chaîne d'anodisation BTS SNIR Ozanam.

### Présentation des dossiers
- _**Anodisation**_ contient une version de l'intégration du projet avec peu de fichier et toutes les parties de l’IHM 

- _**Anodistion_finale**_ ontient une autre version de l’intégration du projet, où les différentes parties de l’IHM sont séparés. On a donc :
    - une partie principal (frame)
    - une partie régleur (panel)
    - et une partie responsable (panel). 
    - DataAnodisation permet l’accès à la BdD
    - Les données de remplissage de l’IHM sont situés dans DonneesIHMregleur et DonneesIHMresponsable pour simplifier le fichier DataAnodisation.

- _**Base_de_donnees**_ contient les scripts de génération pour la BdD ainsi que les données de remplissage et la structure de la BdD.

- _**Codage_Florian**_ contient la partie responsable d’avant l’intégration.

- _**Nassim**_ contient la partie régleur d’avant l’intégration.

- _**Test**_ contient :
    - un serveur de test pour la relation client – serveur
    - un test d’accès à la BdD avec POCO
    - Des tests d’IHM pour le projet
