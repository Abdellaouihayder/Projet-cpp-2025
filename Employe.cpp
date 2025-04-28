#include <typeinfo>
#include "Tache.h"  
#include "AssistantSocial.h"
#include "client.h"
#include "AssistantSpecialiste.h"
#include "Employe.h"
#include "GestionEquipe.h"
#include "Receptionniste.h"
#include "Specialisation.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include "GestionNationalite.h"
#include <set>
#include <map>
#include <algorithm> 
#include <sstream>  

using namespace std;


// Employe implementation
Employe::Employe(int id, string n, string p, float s,int nbr) : idEmploye(id), nom(n), poste(p), salaire(s),nbrTache(nbr){
try {
        if (nbrTache < 0) {
            throw invalid_argument("Le nombre de tï¿½ches ne peut pas ï¿½tre nï¿½gatif.");
        }
        this->nbrTache = nbrTache;
    } catch (const invalid_argument& e) {
        cerr << "Erreur lors de la crï¿½ation de l'employï¿½ : " << e.what() << endl;
        this->nbrTache = 0;  // Valeur par dï¿½faut ou traitement spï¿½cifique
    }
}
Employe::Employe(const Employe& e)
    : idEmploye(e.idEmploye), nom(e.nom), poste(e.poste), salaire(e.salaire),nbrTache(e.nbrTache){
    Tache* T ;
    for (unsigned int i = 0; i < e.taches.size(); i++) {
    	T= new Tache(*e.taches[i]); 
        taches.push_back(T);
    }
}

Employe::~Employe() {
    for (unsigned int i = 0; i < taches.size(); i++) {
        delete taches[i];  
    }
    taches.clear();  
}
int Employe::getIdEmploye() { return idEmploye; }
void Employe::setIdEmploye(int id) { idEmploye = id; }
string Employe::getNom() { return nom; }
void Employe::setNom(string n) { nom = n; }
string Employe::getPoste() { return poste; }
void Employe::setPoste(string p) { poste = p; }
float Employe::getSalaire() { return salaire; }
void Employe::setSalaire(float s) { salaire = s; }
int Employe::getnbrTache(){ return nbrTache;}
void Employe::setnbrTache(int nbr) { nbrTache = nbr; }

Employe& Employe::operator=(const Employe& e) {
    if (this != &e) {  
    
    idEmploye = e.idEmploye;
    nom = e.nom;
    poste = e.poste;
    salaire = e.salaire;
    for (unsigned int i = 0; i < e.taches.size(); i++) {
        delete taches[i];
    }
    taches.clear();
    Tache* T ;
    for (unsigned int i = 0; i < e.taches.size(); i++) {
    	T= new Tache(*e.taches[i]); 
        taches.push_back(T);
    }
	}
    return *this;  
}
// Sauvegarde les taches dans un fichier
void Employe::enregistrerTachesDansFichier(const string& nomFichier)  {
    ofstream fichier(nomFichier.c_str());  
    if (!fichier.is_open()) { exit(-1); }

    for (unsigned int i = 0; i < taches.size(); i++) {
        fichier << taches[i]->getId() << ";" 
                << taches[i]->getDescription() << ";" 
                << taches[i]->getStatut() << endl;
    }

    fichier.close();
}
// Charge les taches depuis un fichier
void Employe::chargerTachesDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier.c_str());
    if (!fichier.is_open()) { exit(-2); }

    string ligne;
    while (getline(fichier, ligne)) {
        int pos1 = ligne.find(';');
        int pos2 = ligne.find(';', pos1 + 1);
		int id = atoi(ligne.substr(0, pos1).c_str());
        string desc = ligne.substr(pos1 + 1, pos2 - pos1 - 1);
        string statut = ligne.substr(pos2 + 1);
        Tache* t = new Tache(id,desc, statut);
        t->setId(id);
        taches.push_back(t);
    }

    fichier.close();
}
bool Employe::supprimerTacheParId(int id) {
    for (unsigned int i=0;i<taches.size();i++) {
        if (taches[i]->getId() == id) {        
            delete taches[i];                      
            taches.erase(taches.begin() + i);         
            nbrTache--;  
			// Récriture du fichier mis a jour
            enregistrerTachesDansFichier("taches.txt");              
            return true;               
        }
    }
    return false; 
}

void Employe::ajouterTache(Tache* t) {
    taches.push_back(t);
    nbrTache++;
    ofstream fichier("taches.txt", ios::app);
    if (fichier.is_open()) {
        fichier << t->getId() << ";"
                << t->getDescription() << ";"
                << t->getStatut() << endl;
        fichier.close();
    } else {
        cerr << "Erreur lors de l'ouverture du fichier pour ajout." << endl;
    }
}

bool Employe::rechercherTacheParId(int id) {
    for (unsigned int i = 0; i < taches.size(); i++) {
        if (taches[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

bool Employe::modifierTache(int id, const string& nouvelleDescription, const string& nouveauStatut) {
    if (!rechercherTacheParId(id)) {
        return false;
    }
    for (unsigned int i = 0; i < taches.size(); i++) {
        if (taches[i]->getId() == id) {
            taches[i]->setDescription(nouvelleDescription);
            taches[i]->setStatut(nouveauStatut);
            enregistrerTachesDansFichier("taches.txt");
            return true;
        }
    }
    return false;
}


