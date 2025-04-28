#include "Tache.h"

// Initialisation de la variable statique
int Tache::compteur = 0;

// Constructeurs
Tache::Tache(int i, string desc, string stat) : id(i), description(desc), statut(stat) {
    compteur++; // Incrémenter à chaque création d'objet
}

Tache::Tache(const Tache& T) {
    description = T.description;
    statut = T.statut;
    id = T.id;
    compteur++; // Incrémenter aussi dans le constructeur de copie
}

// Destructeur
Tache::~Tache() {
    compteur--; // Décrémenter quand un objet est détruit
}

// Getters & Setters
string Tache::getDescription() { return description; }
void Tache::setDescription(string desc) { description = desc; }
string Tache::getStatut() { return statut; }
void Tache::setStatut(string stat) { statut = stat; }
int Tache::getId() { return id; }
void Tache::setId(int i) { id = i; }
void Tache::marquerCommeTerminee() { statut = "Terminee"; }

// Méthode statique
void Tache::afficherCompteur() {
    cout << "Nombre Total des Taches sont : " << compteur << endl;
}

