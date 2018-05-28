CREATE TABLE "processus" (
    id_processus SERIAL,
    nom_processus char(100) NOT NULL,
    processus_valide boolean DEFAULT FALSE,
    duree_processus time without time zone NOT NULL,
    PRIMARY KEY (id_processus)
) WITHOUT OIDS;

COMMENT ON TABLE "processus" IS 'Contient les détails des processus';
\COPY "processus" FROM './donnees_processus.csv' WITH DELIMITER ',';

CREATE TABLE "trajectoires" (
    id_trajectoire SERIAL,
    nom_trajectoire char(100) NOT NULL,
    contenu_trajectoire text,
    duree_trajectoire time without time zone,
    PRIMARY KEY (id_trajectoire)
) WITHOUT OIDS;

COMMENT ON TABLE "trajectoires" IS 'Contient les détails des trajectoire';
\COPY "trajectoires" FROM './donnees_trajectoires.csv' WITH DELIMITER ',';

CREATE TABLE "mouvements" (
    id_mouvement SERIAL,
    nom_mouvement char(100) NOT NULL,
    contenu_mouvement text,
    axe char,
    --partie_bras char(6),
    vitesse char,
    temps_attente time without time zone,
    duree_mouvement time without time zone,
    PRIMARY KEY (id_mouvement)
) WITHOUT OIDS;

COMMENT ON TABLE "mouvements" IS 'Contient les détails des mouvement';
\COPY "mouvements" FROM './donnees_mouvements.csv' WITH DELIMITER ',';

CREATE TABLE "intermediaire_processus_trajectoires" (
    /*nom_champ char,*/
    id_p integer REFERENCES processus (id_processus),
    id_t integer REFERENCES trajectoires (id_trajectoire),
    ordre_trajectoires text NOT NULL,
    numero_bain integer NOT NULL,
    duree_bain time without time zone NOT NULL
    /*PRIMARY KEY (id_p, id_t)*/
);

COMMENT ON TABLE "intermediaire_processus_trajectoires" IS 'Table intermediaire pour faire la liaison entre la table "processus" et "trajectoires"';
\COPY "intermediaire_processus_trajectoires" FROM './donnees_intermediaire_processus_trajectoires.csv' WITH DELIMITER ',';

CREATE TABLE "intermediaire_mouvements_trajectoires" (
    /*nom_champ char,*/
    id_t integer REFERENCES trajectoires (id_trajectoire),
    id_m integer REFERENCES mouvements (id_mouvement),
    ordre_mouvements text NOT NULL,
    point_depart char,
    point_arrive char
    /*PRIMARY KEY (id_m, id_t)*/
);

COMMENT ON TABLE "intermediaire_mouvements_trajectoires" IS 'Table intermediaire pour faire la liaison entre la table "mouvements" et "trajectoires"';
\COPY "intermediaire_mouvements_trajectoires" FROM './donnees_intermediaire_mouvements_trajectoires.csv' WITH DELIMITER ',';
