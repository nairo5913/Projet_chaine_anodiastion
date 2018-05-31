CREATE TABLE "processus" (
    id_processus SERIAL,
    nom_processus char(100) NOT NULL,
    processus_valide boolean DEFAULT FALSE,
    duree_processus time without time zone NOT NULL,
    nombre_bain integer,
    PRIMARY KEY (id_processus)
) WITHOUT OIDS;

COMMENT ON TABLE "processus" IS 'Contient les détails des processus';
\COPY processus (nom_processus, processus_valide, duree_processus) FROM './Donnees/donnees_processus.csv' WITH DELIMITER ',';

CREATE TABLE "trajectoires" (
    id_trajectoire SERIAL,
    nom_trajectoire char(100) NOT NULL,
    trajectoire_valide boolean DEFAULT FALSE,
    contenu_trajectoire text,
    duree_trajectoire time without time zone,
    PRIMARY KEY (id_trajectoire)
) WITHOUT OIDS;

COMMENT ON TABLE "trajectoires" IS 'Contient les détails des trajectoire';
\COPY trajectoires (nom_trajectoire, contenu_trajectoire, duree_trajectoire) FROM './Donnees/donnees_trajectoires.csv' WITH DELIMITER ',';

CREATE TABLE "mouvements" (
    id_mouvement SERIAL,
    nom_mouvement char(100) NOT NULL,
    mouvement_valide boolean DEFAULT FALSE,
    contenu_mouvement text,
    axe_x integer,
    axe_y integer,
    axe_z integer,
    --partie_bras char(6),
    vitesse char,
    temps_attente time without time zone,
    duree_mouvement time without time zone,
    PRIMARY KEY (id_mouvement)
) WITHOUT OIDS;

COMMENT ON TABLE "mouvements" IS 'Contient les détails des mouvement';
\COPY mouvements (nom_mouvement, contenu_mouvement, axe_x, axe_y, axe_z, vitesse, temps_attente, duree_mouvement) FROM './Donnees/donnees_mouvements.csv' WITH DELIMITER ',';

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
\COPY "intermediaire_processus_trajectoires" FROM './Donnees/donnees_intermediaire_processus_trajectoires.csv' WITH DELIMITER ',';

CREATE TABLE "intermediaire_mouvements_trajectoires" (
    /*nom_champ char,*/
    id_t integer REFERENCES trajectoires (id_trajectoire),
    id_m integer REFERENCES mouvements (id_mouvement),
    ordre_mouvements text NOT NULL,
    point_depart char(6),
    point_arrive char(6)
    /*PRIMARY KEY (id_m, id_t)*/
);

COMMENT ON TABLE "intermediaire_mouvements_trajectoires" IS 'Table intermediaire pour faire la liaison entre la table "mouvements" et "trajectoires"';
\COPY "intermediaire_mouvements_trajectoires" FROM './Donnees/donnees_intermediaire_mouvements_trajectoires.csv' WITH DELIMITER ',';
