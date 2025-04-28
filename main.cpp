#include <iostream>
#include <string>
#include <vector>
#include "AssistantSpecialiste.h"
#include "Receptionniste.h"
#include "client.h"
#include "employe.h"
#include "assistantsocial.h"
#include "specialisation.h"
#include "gestionEquipe.h"
#include "Tache.h"
#include <stdexcept>
#include "GestionNationalite.h"
#include <set>
#include <map>
#include"Service.h"

using namespace std;
void menuPrincipal() {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Gerer Receptionniste\n";
    cout << "2. Gerer Assistant Social\n";
    cout << "3. Gerer Assistant Specialiste\n";
    cout << "4. Gerer Equipe\n";
    cout << "5. Gerer Nationalites\n";
    cout << "6. Gerer Taches\n";
    cout << "7. Gerer Clients\n";
    cout << "0. Quitter\n";
    cout << "Votre choix: ";
}

// Sous-menus

void menuReceptionniste() {
    Receptionniste r;
    int choix;
    do {
        cout << "\n-- Menu Receptionniste --\n";
        cout << "1. Saisir receptionniste\n";
        cout << "2. Afficher receptionniste\n";
        cout << "0. Retour\n";
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1:
                cin >> r;
                break;
            case 2:
                cout << r;
                break;
        }
    } while (choix != 0);
}

void menuAssistantSocial() {
    AssistantSocial a;
    int choix;
    do {
        cout << "\n-- Menu Assistant Social --\n";
        cout << "1. Modifier domaine expertise\n";
        cout << "2. Afficher assistant social\n";
        cout << "0. Retour\n";
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1: {
                string domaine;
                cout << "Entrer domaine expertise: ";
                cin.ignore();
                getline(cin, domaine);
                a.setDomaineExpertise(domaine);
                break;
            }
            case 2:
                a.afficherEmploye();
                break;
        }
    } while (choix != 0);
}

void menuAssistantSpecialiste() {
    AssistantSpecialiste a(1, "Nom", "Poste", 1200, 0);
    int choix;
    do {
        cout << "\n-- Menu Assistant Specialiste --\n";
        cout << "1. Modifier certification\n";
        cout << "2. Afficher assistant specialiste\n";
        cout << "0. Retour\n";
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1: {
                string certif;
                cout << "Entrer certification: ";
                cin.ignore();
                getline(cin, certif);
                a.setCertification(certif);
                break;
            }
            case 2:
                a.afficherEmploye();
                break;
        }
    } while (choix != 0);
}

void menuGestionEquipe() {
    GestionEquipe equipe;
    int choix;
    do {
        cout << "\n-- Menu Gestion Equipe --\n";
        cout << "1. Ajouter receptionniste\n";
        cout << "2. Afficher equipe\n";
        cout << "0. Retour\n";
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1: {
                Receptionniste *r = new Receptionniste();
                cin >> *r;
                equipe.ajouterEmploye(r);
                break;
            }
            case 2:
                equipe.afficherEquipe();
                break;
        }
    } while (choix != 0);
}

void menuGestionNationalites() {
    GestionDesNationalites<int, string> gestion;
    int choix;
    do {
        cout << "\n-- Menu Gestion Nationalites --\n";
        cout << "1. Ajouter nationalite\n";
        cout << "2. Afficher nationalites d'un client\n";
        cout << "3. Afficher tous\n";
        cout << "0. Retour\n";
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1: {
                int id;
                string nat;
                cout << "ID client: ";
                cin >> id;
                cout << "Nationalite: ";
                cin.ignore();
                getline(cin, nat);
                gestion.ajouterNationalite(id, nat);
                break;
            }
            case 2: {
                int id;
                cout << "ID client: ";
                cin >> id;
                gestion.afficherNationalites(id);
                break;
            }
            case 3:
                gestion.afficherTous();
                break;
        }
    } while (choix != 0);
}

void menuGestionTaches() {
    vector<Tache> taches;
    int choix;
    do {
        cout << "\n-- Menu Gestion Taches --\n";
        cout << "1. Ajouter une tache\n";
        cout << "2. Afficher toutes les taches\n";
        cout << "0. Retour\n";
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1: {
                int id;
                string desc, statut;
                cout << "ID: ";
                cin >> id;
                cin.ignore();
                cout << "Description: ";
                getline(cin, desc);
                cout << "Statut: ";
                getline(cin, statut);
                taches.push_back(Tache(id, desc, statut));
                break;
            }
            case 2:
               for (unsigned int i = 0; i < taches.size(); ++i) {
    				cout << "ID: " << taches[i].getId()
         				<< ", Desc: " << taches[i].getDescription()
         				<< ", Statut: " << taches[i].getStatut() << endl;
				}

                break;
        }
    } while (choix != 0);
}

void menuGestionClients() {
    vector<client> clients;
    int choix;
    do {
        cout << "\n-- Menu Gestion Clients --\n";
        cout << "1. Ajouter un client\n";
        cout << "2. Afficher tous les clients\n";
        cout << "0. Retour\n";
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1: {
                string nom, prenom;
                int cinClient;
                cout << "Nom: ";
                cin.ignore();
                getline(cin, nom);
                cout << "Prenom: ";
                getline(cin, prenom);
                cout << "CIN: ";
                cin >> cinClient;
                clients.push_back(client(nom, prenom, cinClient));
                break;
            }
            case 2:
              for (size_t i = 0; i < clients.size(); ++i) {
    				clients[i].afficherinfo();
					}
                break;
        }
    } while (choix != 0);
}

// Main

int main() {
    int choix;
    do {
        menuPrincipal();
        cin >> choix;
        switch (choix) {
            case 1:
                menuReceptionniste();
                break;
            case 2:
                menuAssistantSocial();
                break;
            case 3:
                menuAssistantSpecialiste();
                break;
            case 4:
                menuGestionEquipe();
                break;
            case 5:
                menuGestionNationalites();
                break;
            case 6:
                menuGestionTaches();
                break;
            case 7:
                menuGestionClients();
                break;
            case 0:
                cout << "Au revoir!\n";
                break;
            default:
                cout << "Choix invalide.\n";
        }
    } while (choix != 0);

    return 0;
}
