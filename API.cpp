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
using namespace std;

// client implementation 
client::client(string n, string p, int c) : nom(n), prenom(p), cin(c) {}
client::client(const client& c) : nom(c.nom), prenom(c.prenom), cin(c.cin) {}
client::~client() {}
void client::afficherinfo() {
    cout << "Nom: " << nom << ", Prenom: " << prenom << ", CIN: " << cin << endl;
}
string client::getNom() { return nom; } 
void client::setNom(string n) { nom = n; } 
string client::getPrenom() { return prenom; }
void client::setPrenom(string p) { prenom = p; }
int client::getCin() { return cin; }
void client::setCin(int c) { cin = c; }

// Tache implementation
Tache::Tache(string desc, string stat) : description(desc), statut(stat) {}
Tache::Tache(const Tache& T){
	description = T.description;  
    statut = T.statut;
}
Tache::~Tache() {}
string Tache::getDescription() { return description; }
void Tache::setDescription(string desc) { description = desc; }
string Tache::getStatut() { return statut; }
void Tache::setStatut(string stat) { statut = stat; }
void Tache::marquerCommeTerminee() { statut = "Terminee"; }


// Employe implementation
Employe::Employe(int id, string n, string p, float s) : idEmploye(id), nom(n), poste(p), salaire(s) {}
Employe::Employe(const Employe& e)
    : idEmploye(e.idEmploye), nom(e.nom), poste(e.poste), salaire(e.salaire) {
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

