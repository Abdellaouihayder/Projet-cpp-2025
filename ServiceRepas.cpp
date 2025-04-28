#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream> 
#include"ServiceRepas.h"
using namespace std;
ServiceRepas::ServiceRepas(string desc):Service(desc) {}

void ServiceRepas::ajouterPlat( Plat& plat) {
    plats.push_back(plat);
    cout << "Plat ajoute : " << plat.getNom() << endl;
}

void ServiceRepas::supprimerPlat(string nom) {
    for (unsigned int i = 0; i< plats.size(); i++) {
        if (plats[i].getNom() == nom) {
            cout << "Plat supprime : " << plats[i].getNom() << endl;
            plats.erase(plats.begin() + i);
            return;
        }
    }
    cout << "Plat non trouve : " << nom << endl;
}
    

void ServiceRepas::afficherMenu()  {
    if (plats.empty()) {
        cout << "Le menu est vide." << endl;
        return;
    }
    cout << "Menu :" << endl;
    for (size_t i = 0; i< plats.size(); i++){
        plats[i].afficher();
    }
}
