#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream> 
#include "Dossier.h"
#include "client.h"

using namespace std;


Dossier::Dossier(int id, string cl, string statut) {
      idDossier=id;
      client=cl;
      statutActuel=statut;
    }
Dossier::~Dossier() {
        for (size_t i = 0; i < services.size(); ++i) {
            delete services[i]; 
        }
        services.clear();
    }
    
Dossier::Dossier(const Dossier& other) {
        idDossier = other.idDossier;
        client = other.client;
        statutActuel = other.statutActuel;
        
        for (size_t i = 0; i < other.services.size(); ++i) { 
            services.push_back(other.services[i]); 
        }
    }
void Dossier::afficherServices() {
      for (size_t i = 0; i < services.size(); ++i) {
          cout << "Service " << i + 1 << " : " << typeid(*services[i]).name() << endl;
      }
  }
void Dossier::ajouterService(Service* service) {
        services.push_back(service);
    }

void Dossier::supprimerService() {
        if (!services.empty()) {
            services.pop_back();
        }
    }
    void Dossier::sauvegarderDossier(const string& filename) {
        ofstream fichier;
        fichier.open(filename.c_str(), ios::out | ios::app ); 
        if (fichier.is_open()) {
            fichier << "Dossier ID: " << idDossier << "\n";
            fichier << "Client: " << client.getNom() << "\n";
            fichier << "Statut: " << statutActuel << "\n";
            fichier << "Services: " << services.size() << "\n";
            fichier.close();
            cout << "Dossier sauvegardé dans " << filename << endl;
        } else {
            cout << "Erreur lors de l'ouverture du fichier." << endl;
        }
    }
    
    void Dossier::chargerDossier(const string& filename) {
        ifstream fichier(filename.c_str(), ios::in);
        if (fichier.is_open()) {
            string ligne;
            while (getline(fichier, ligne)) {
                cout << ligne << endl;
            }
            fichier.close();
        } else {
            cout << "Erreur lors de l'ouverture du fichier." << endl;
        }
    }
    ostream& operator<<(ostream& os, const Dossier& d) {
        os << "Dossier ID: " << d.idDossier << ", Client: " << d.client.nom << ", Statut: " << d.statutActuel << ", Nombre de services: " << d.services.size();
        return os;
    }
    bool operator==(const Dossier& d1, const Dossier& d2) {
        return (d1.idDossier == d2.idDossier) &&
               (d1.client.nom == d2.client.nom) &&
               (d1.statutActuel == d2.statutActuel);
    }
