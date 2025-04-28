#include "Tache.h"

// Initialisation de la variable statique
int Tache::compteur = 0;

// Constructeurs
Tache::Tache(int i, string desc, string stat) : id(i), description(desc), statut(stat) {
    compteur++; // Incr�menter � chaque cr�ation d'objet
}

Tache::Tache(const Tache& T) {
    description = T.description;
    statut = T.statut;
    id = T.id;
    compteur++; // Incr�menter aussi dans le constructeur de copie
}

// Destructeur
Tache::~Tache() {
    compteur--; // D�cr�menter quand un objet est d�truit
}

// Getters & Setters
string Tache::getDescription() { return description; }
void Tache::setDescription(string desc) { description = desc; }
string Tache::getStatut() { return statut; }
void Tache::setStatut(string stat) { statut = stat; }
int Tache::getId() { return id; }
void Tache::setId(int i) { id = i; }
void Tache::marquerCommeTerminee() { statut = "Terminee"; }

// M�thode statique
void Tache::afficherCompteur() {
    cout << "Nombre Total des Taches sont : " << compteur << endl;
}

