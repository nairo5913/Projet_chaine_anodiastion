/*******************************************************************************
 *  Fichier:  Serveur.cpp
 *  Projet:   Chaîne d'anodisation - Test du client pour le PC responsable
              de production avec un serveur
 *  Crée le:  14/04/2018
 *  Utilité:  Gestion de la partie serveur réseau
 *  Auteur:   Florian Provost
*******************************************************************************/
#include "Serveur.h"

Serveur::Serveur(EvtFramePrincipal *frame, long port, int maxclients)
{
    m_nombreMaxClients = maxclients;
    m_frame = frame;
    m_port = port;
    m_bras_dispo = true;

    wxIPV4address addr;
    addr.Service(m_port);
    m_serveur = new wxSocketServer(addr);

    // wxString message="Serveur à l'écoute sur le port ");
    wxString message = "";

    // on vérifie que le serveur est bien à l'écoute
    if(!m_serveur->Ok())
    {
        m_serveur_running = false;
    }
    else
    // le serveur fonctionne
    {
        m_serveur_running = true;

        // on demande à l'IHM d'afficher le message
        message.Printf("Serveur à l'écoute sur le port %ld ...", m_port);
        wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR);
        MyEvent.SetString(message);
        wxPostEvent(m_frame, MyEvent);

        // On connecte les gestionnaires d'événement au événements
        Connect(SERVER_ID, wxEVT_SOCKET, wxSocketEventHandler(Serveur::OnServerEvent));
        Connect(SOCKET_ID, wxEVT_SOCKET, wxSocketEventHandler(Serveur::OnSocketEvent));

        // On indique quel gestionnaire d'événement utiliser
        m_serveur->SetEventHandler(*this, SERVER_ID);

        // sur un événement 'connexion au socket'
        m_serveur->SetNotify(wxSOCKET_CONNECTION_FLAG);

        // on active les événements sur le socket
        m_serveur->Notify(true);

        // au départ pas de client connecté
        m_nombreClients = 0;
    }
}

Serveur::~Serveur()
{
    // Destructeur
}

void Serveur::Close()
{
    m_serveur_running = false;
    m_serveur->Destroy();
}

int Serveur::RetireClient(wxSocketBase *sock)
{
    m_nombreClients--;

    DonneesClient *mes_donnees = (DonneesClient *)(sock->GetClientData());

    // on détruit le socket
    sock->Destroy();

    // on récupère le numéro de client
    int num_client = mes_donnees->GetNumClient();

    // on détruit ses données
    delete m_donnees_client_map[num_client];

    // on supprime la référence dans la map
    m_donnees_client_map.erase(m_donnees_client_map.find(num_client));

    return num_client;
}

int Serveur::TrouveNumeroClientLibre()
{
    // on recherche dans le conteneur le premier n° libre de producteur
    int num_libre = 1;

    while(m_donnees_client_map.find(num_libre) != m_donnees_client_map.end())
    {
        num_libre++;
    }

    return num_libre;
}

void Serveur::OnServerEvent(wxSocketEvent &event)  // gestionnaire d'événement pour le serveur
{
    wxSocketBase *sock;

    // si l'événement est une nouvelle connexion sur le socket
    if(event.GetSocketEvent() == wxSOCKET_CONNECTION)
    {
        // alors on accepte cette nouvelle connexion en créant un
        // nouveau socket et ceci de façon non bloquante.
        // Ce n'est pas génant car si nous sommes arrivés ici
        // c'est qu'il y a de toute façon une connexion entrante
        sock = m_serveur->Accept(false);

        // si le socket existe
        if(sock)
        {
            // on indique quel gestionnaire d'événement utiliser (pour ce nouveau socket)
            sock->SetEventHandler(*this, SOCKET_ID);

            // sur un événement 'entrée sur le socket' ou 'socket perdu'
            sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);

            // on active les événements sur ce socket
            sock->Notify(true);

            // il y a un client de plus
            m_nombreClients++;
            int num_client = TrouveNumeroClientLibre();
            m_donnees_client_map.insert(DONNEES_CLIENT_MAP::value_type(num_client, new DonneesClient(num_client)));
            sock->SetClientData(m_donnees_client_map[num_client]);

            if(m_nombreClients != (m_nombreMaxClients + 1))
            {
                wxString message("Connexion du client numéro ");
                message << num_client << "\n";

                // on envoie la réponse '101-' au client
                EcritReponse(sock, CONNEXION_OK);
                AfficheMessage(message);
                AfficheNombreClients();
            }
            else if(m_nombreClients == (m_nombreMaxClients + 1))
            {
                EcritReponse(sock, NOMBRE_MAX_UTILISATEURS);
                RetireClient(sock);
                AfficheMessage("Nombre maximum de clients atteints\n");
                AfficheNombreClients();
            }
            else
            {
                EcritReponse(sock, CONNEXION_PAS_OK);
                RetireClient(sock);
                AfficheMessage("Erreur de connexion\n");
                AfficheNombreClients();
            }
        }
        else
        {
            wxLogWarning("Problème: le serveur n'a pas pu créer de socket pour le client...");
        }
    }
    else  // à priori, il ne peut pas y avoir d'autre événement qu'une nouvelle connexion sur le socket
    {
        AfficheMessage("Événement inattendu sur OnServerEvent...");
    }
}

void Serveur::OnSocketEvent(wxSocketEvent &event)  // gestionnaire d'événements pour un socket
{
    // on récupère le socket ayant généré l'événement
    wxSocketBase *sock = event.GetSocket();

    // on traite l'événement sur ce socket
    switch(event.GetSocketEvent())
    {
        // entrée sur le socket
        case wxSOCKET_INPUT:
        {
            // On déactive l'événement d'entrée sur le socket
            // de façon à ne pas réentrer dans le gestionnaire d'événement
            // pendant le traitement.
            sock->SetNotify(wxSOCKET_LOST_FLAG);

            // on récupère les données pour ce client
            DonneesClient *mes_donnees = (DonneesClient *)(sock->GetClientData());

            // on récupère le message du client
            wxString message = LitMessage(sock);

            // on affiche le message du client sur l'ihm
            wxString s("");
            s.Printf("message du client %i reçu: %s \n", mes_donnees->GetNumClient(), message.c_str());
            AfficheMessage(s);

            // on décode le message du client et on lui répond
            DecodeMessage(message, sock, mes_donnees);

            // on rétablit l'événement d'entrée sur le socket
            sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);

            break;
        }
        case wxSOCKET_LOST:  // le client s'est déconnecté
        {
            int num_client = RetireClient(sock);
            wxString message("Déconnexion du client numéro ");
            message << num_client << "\n";
            AfficheMessage(message);
            AfficheNombreClients();

            break;
        }
        default:
            AfficheMessage("événement inattendu sur OnSocketEvent...");

            break;
    }
}

void Serveur::DecodeMessage(wxString message, wxSocketBase *sock, DonneesClient *donnees)
{
    wxString texte = "";

    switch(donnees->GetEtat())
    {
        case 0:  // Dans notre cas, il n'y a que l'état 0
            if(message.StartsWith(DEMANDE_IDENTIFICATION, &texte))
            {
                wxString reponse(IDENTIFICATION_OK);
                EcritReponse(sock, reponse.ToStdString());
            }
            else if(message.StartsWith(DEMANDE_TEST_PROCESSUS, &texte))
            {
                bool test = true;

                wxString message;
                message << "Le texte reçu est : " << texte << wxT("\n");

                wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
                MyEvent.SetString(message);
                wxPostEvent(m_frame, MyEvent);

                if(!test)
                {
                    wxString reponse(EXECUTION_IMPOSSIBLE);
                    EcritReponse(sock, reponse.ToStdString());
                }
            }
            else if(message.StartsWith(DEMANDE_TEST_TRAJECTOIRE, &texte))
            {
                bool test = true;

                wxString message;
                message << "Le texte reçu est : " << texte << wxT("\n");

                wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
                MyEvent.SetString(message);
                wxPostEvent(m_frame, MyEvent);

                if(!test)
                {
                    wxString reponse(EXECUTION_IMPOSSIBLE);
                    EcritReponse(sock, reponse.ToStdString());
                }
            }
            else if(message.StartsWith(DEMANDE_TEST_MOUVEMENT, &texte))
            {
                bool test = true;

                wxString message;
                message << "Le texte reçu est : " << texte << wxT("\n");

                wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
                MyEvent.SetString(message);
                wxPostEvent(m_frame, MyEvent);

                if(!test)
                {
                    wxString reponse(EXECUTION_IMPOSSIBLE);
                    EcritReponse(sock, reponse.ToStdString());
                }
            }
            else if(message.StartsWith(DEMANDE_EXECUTION_PROCESSUS, &texte))
            {
                bool test = true;

                wxString message;
                message << "Le texte reçu est : " << texte << wxT("\n");

                wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
                MyEvent.SetString(message);
                wxPostEvent(m_frame, MyEvent);

                if(!test)
                {
                    wxString reponse(EXECUTION_IMPOSSIBLE);
                    EcritReponse(sock, reponse.ToStdString());
                }
            }
            else if(message.IsSameAs(STOP_TEST_PROCESSUS))
            {
                bool test = true;

                wxString message;
                message << "Le texte reçu est : " << wxT("\n");

                wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
                MyEvent.SetString(message);
                wxPostEvent(m_frame, MyEvent);
            }
            else if(message.IsSameAs(STOP_TEST_TRAJECTOIRE))
            {
                bool test = true;

                wxString message;
                message << "Le texte reçu est : " << wxT("\n");

                wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
                MyEvent.SetString(message);
                wxPostEvent(m_frame, MyEvent);
            }
            else if(message.IsSameAs(STOP_TEST_MOUVEMENT))
            {
                bool test = true;

                wxString message;
                message << "Le texte reçu est : " << wxT("\n");

                wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
                MyEvent.SetString(message);
                wxPostEvent(m_frame, MyEvent);
            }
            else if(message.IsSameAs(DISPONIBILITE_BRAS))
            {
                if(m_bras_dispo)
                {
                    wxString reponse(BRAS_DISPONIBLE);
                    EcritReponse(sock, reponse.ToStdString());
                }
                else
                {
                    wxString reponse(BRAS_INDISPONIBLE);
                    EcritReponse(sock, reponse.ToStdString());
                }
            }
            else if(message.IsSameAs(DEMANDE_TACHE_EN_COURS))
            {
                bool tache_cours = true;

                if(!m_bras_dispo)
                {
                    if(tache_cours)
                    {
                        wxString reponse;
                        reponse << wxT(TACHE_EN_COURS) << m_tache << "-1";
                        EcritReponse(sock, reponse.ToStdString());
                    }
                    else
                    {
                        wxString reponse(PAS_TACHE_EN_COURS);
                        EcritReponse(sock, reponse.ToStdString());
                    }
                }
                else
                {
                    wxString reponse(PAS_TACHE_EN_COURS);
                    EcritReponse(sock, reponse.ToStdString());
                }
            }
            else if(message.IsSameAs(DEMANDE_CONNEXION))
            // le client demande à se déconnecter
            {
                int num_client = RetireClient(sock);
                wxString message("Déconnexion du client numéro ");
                message << num_client << "\n";
                AfficheMessage(message);
                AfficheNombreClients();
            }
            else if(message.IsSameAs(ERREUR_RESEAUX))  // Erreur réseau
            {
                AfficheMessage("Erreur réseau: il faut redémarrer le serveur !");
                Close();
            }
            else  // commande inconnue du protocole...
            {
                EcritReponse(sock, COMMANDE_INCONNUE);
            }

            break;
        default:  // on ne devrait pas arriver ici...
            wxLogWarning("État inconnu du client...");

            break;
    }
}

void Serveur::EcritReponse(wxSocketBase *sock, string reponse)
{
    // la réponse est limitée à 128 caractères...
    char buffer[128] = "";
    strcpy(buffer, reponse.c_str());
    buffer[strlen(buffer) + 2] = 0x00;
    buffer[strlen(buffer) + 1] = 0x0A;
    buffer[strlen(buffer)] = 0x0D;
    sock->Write(&buffer, strlen(buffer));

    if(sock->Error())
    {
        AfficheMessage("Erreur réseau: il faut redémarrer le serveur !");
        Close();
    }
    else
    {
        AfficheReponse(wxT("Reponse du serveur : ") + reponse + wxT("\n"));
    }
}

void Serveur::AfficheNombreClients()
{
    wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR);
    wxString message("");

    if(m_nombreClients <= 1)
    {
        message.Printf("Serveur à l'écoute sur le port %ld, %i client connecté", m_port, m_nombreClients);
    }
    else
    {
        message.Printf("Serveur à l'écoute sur le port %ld, %i clients connectés", m_port, m_nombreClients);
    }

    MyEvent.SetString(message);
    wxPostEvent(m_frame, MyEvent);
}

void Serveur::AfficheMessage(wxString message)
{
    wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 1);
    MyEvent.SetString(message);
    wxPostEvent(m_frame, MyEvent);
}

void Serveur::AfficheReponse(wxString reponse)
{
    wxCommandEvent MyEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SERVEUR + 2);
    MyEvent.SetString(reponse);
    wxPostEvent(m_frame, MyEvent);
}

wxString Serveur::LitMessage(wxSocketBase *sock)
{
    // à mettre absolument de façon à éviter de rester bloqué dans le gestionnaire d'événement
    // et donc de réentrer dans le code.
    sock->SetFlags(wxSOCKET_NOWAIT);

    // on sera limité à des messages de 2Ko...
    char *buffer = new char[2048];
    int i = 0;
    bool erreur = false;

    do
    {
        sock->Read(&buffer[i], 1);
        i++;
        // on teste s'il n'y a pas eu d'erreur d'E/S
        erreur = sock->Error();
    } while((buffer[i - 1] != 0x0A) || erreur);  // jusqu'à le 'LF' ou une erreur détectée

    // on supprime le CR LF
    if(!erreur)
    {
        buffer[i - 2] = 0x00;
        wxString message(buffer, wxConvUTF8);
        delete buffer;
        return message;
    }
    else
    {
        return ("402-");
    }
}