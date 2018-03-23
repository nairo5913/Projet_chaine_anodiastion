CREATE TABLE "Processus" (
    id integer,
    PRIMARY KEY (id),
    nom char(255) NOT NULL,
    processus_valide boolean DEFAULT FALSE,
    duree_mouvement time without time zone NOT NULL,
    numero_bain integer,
    duree_bain time without time zone NOT NULL
);

/*COMMENT ON TABLE "Processus" IS 'Contient les details d\'un processus';*/

CREATE TABLE "Mouvements" (
    id integer,
    PRIMARY KEY (id),
    nom char(255) NOT NULL,
    id_processus integer,
    nb_processus_utilise integer,
    axe char(1)
/*    partie_bras interger ou text ou char*/
);

/*COMMENT ON TABLE "Processus" IS 'Contient les details d\'un mouvement';*/

CREATE TABLE "Trajectoires" (
    id integer,
    PRIMARY KEY (id),
    nom char(255) NOT NULL,
    id_processus integer,
    id_mouvements integer,
    contenu_trajectoire text,
    axe char(1)
);

/*COMMENT ON TABLE "Processus" IS 'Contient les details d\'une trajectoire';*/

CREATE TABLE "Intermediaire_processus_mouvements" (
    nom_champ char
);

/*COMMENT ON TABLE "Processus" IS 'Table intermediaire pour faire la liaison entre la table "Processus" et "Mouvements"';*/

CREATE TABLE "Intermediaire_mouvements_trajectoires" (
    nom_champ char
);

/*COMMENT ON TABLE "Processus" IS 'Table intermediaire pour faire la liaison entre la table "Mouvements" et "Trajectoires"';*/
