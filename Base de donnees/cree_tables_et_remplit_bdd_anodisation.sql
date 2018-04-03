CREATE TABLE "Processus" (
    id_processus SERIAL,
    PRIMARY KEY (id_processus),
    nom_processus char(255) NOT NULL,
    processus_valide boolean DEFAULT FALSE,
    duree_mouvement time without time zone NOT NULL,
    numero_bain integer NOT NULL,
    duree_bain time without time zone NOT NULL
) WITHOUT OIDS;

/*COMMENT ON TABLE "Processus" IS "Contient les details d'un processus";*/
/*\COPY "Processus" FROM './donnees_processus.csv' WITH DELIMITER ',';*/

CREATE TABLE "Trajectoires" (
    id_trajectoire SERIAL,
    PRIMARY KEY (id_trajectoire),
    nom_trajectoire char(255) NOT NULL,
    id_processus integer,
    id_mouvements integer,
    contenu_trajectoire text,
    axe char
) WITHOUT OIDS;

/*COMMENT ON TABLE "Processus" IS 'Contient les details d\'une trajectoire';*/
\COPY "Trajectoires" FROM './donnees_trajectoires.csv' WITH DELIMITER ',';

CREATE TABLE "Mouvements" (
    id_mouvements SERIAL,
    PRIMARY KEY (id_mouvements),
    nom_mouvement char(255) NOT NULL,
    id_processus integer,
    contenu_mouvement text,
    nb_processus_utilise integer,
    axe char,
/*    partie_bras integer ou text ou char,*/
    vitesse char,
    temps_attente time without time zone

) WITHOUT OIDS;

/*COMMENT ON TABLE "Processus" IS 'Contient les details d\'un mouvement';
COPY "Mouvements" FROM './donnees_mouvements.csv' WITH DELIMITER ',';*/

CREATE TABLE "Intermediaire_processus_trajectoires" (
    /*nom_champ char,*/
    id_p integer,
    id_t integer,
    PRIMARY KEY (id_p, id_t),
    ordre_trajectoires text
);

/*COMMENT ON TABLE "Processus" IS 'Table intermediaire pour faire la liaison entre la table "Processus" et "Trajectoires"';
COPY "Intermediaire_processus_trajectoires" FROM './donnees_intermediaire_processus_trajectoires.csv' WITH DELIMITER ',';*/

CREATE TABLE "Intermediaire_mouvements_trajectoires" (
    /*nom_champ char,*/
    id_t integer,
    id_m integer,
    PRIMARY KEY (id_m, id_t),

    ordre_mouvements text,
    point_depart char,
    point_arrive char
);

/*COMMENT ON TABLE "Processus" IS 'Table intermediaire pour faire la liaison entre la table "Mouvements" et "Trajectoires"';
COPY "Intermediaire_mouvements_trajectoires" FROM './donnees_intermediaire_mouvements_trajectoires.csv' WITH DELIMITER ',';*/
