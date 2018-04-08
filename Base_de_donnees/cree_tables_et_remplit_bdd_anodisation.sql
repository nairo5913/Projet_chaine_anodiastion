CREATE TABLE "processus" (
    id_processus SERIAL,
    nom_processus char(255) NOT NULL,
    processus_valide boolean DEFAULT FALSE,
    duree_processus time without time zone NOT NULL,
    numero_bain integer NOT NULL,
    duree_bain time without time zone NOT NULL,
    PRIMARY KEY (id_processus)
) WITHOUT OIDS;

COMMENT ON TABLE "processus" IS 'Contient les details des processus';
\COPY "processus" FROM './donnees_processus.csv' WITH DELIMITER ',';

CREATE TABLE "trajectoires" (
    id_trajectoire SERIAL,
    nom_trajectoire char(255) NOT NULL,
    contenu_trajectoire text,
    duree_trajectoire time without time zone,
    PRIMARY KEY (id_trajectoire)
) WITHOUT OIDS;

COMMENT ON TABLE "trajectoires" IS 'Contient les details des trajectoire';
\COPY "trajectoires" FROM './donnees_trajectoires.csv' WITH DELIMITER ',';

CREATE TABLE "mouvements" (
    id_mouvements SERIAL,
    nom_mouvement char(255) NOT NULL,
    contenu_mouvement text,
    axe char,
/*    partie_bras integer ou text ou char,*/
    vitesse char,
    temps_attente time without time zone,
    duree_mouvement time without time zone,
    PRIMARY KEY (id_mouvements)
) WITHOUT OIDS;

COMMENT ON TABLE "mouvements" IS 'Contient les details des mouvement';
\COPY "mouvements" FROM './donnees_mouvements.csv' WITH DELIMITER ',';

CREATE TABLE "intermediaire_processus_trajectoires" (
    /*nom_champ char,*/
    id_p integer,
    id_t integer,
    ordre_trajectoires text,
    PRIMARY KEY (id_p, id_t)
);

COMMENT ON TABLE "intermediaire_processus_trajectoires" IS 'Table intermediaire pour faire la liaison entre la table "processus" et "trajectoires"';
\COPY "intermediaire_processus_trajectoires" FROM './donnees_intermediaire_processus_trajectoires.csv' WITH DELIMITER ',';

CREATE TABLE "intermediaire_mouvements_trajectoires" (
    /*nom_champ char,*/
    id_t integer,
    id_m integer,
    ordre_mouvements text,
    point_depart char,
    point_arrive char,
    PRIMARY KEY (id_m, id_t)
);

COMMENT ON TABLE "intermediaire_mouvements_trajectoires" IS 'Table intermediaire pour faire la liaison entre la table "mouvements" et "trajectoires"';
\COPY "intermediaire_mouvements_trajectoires" FROM './donnees_intermediaire_mouvements_trajectoires.csv' WITH DELIMITER ',';
