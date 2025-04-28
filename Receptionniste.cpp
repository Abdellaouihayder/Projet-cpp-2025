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


//Receptionniste implementation
Receptionniste::Receptionniste(int id, string n, string p, float s,int nbr, string sh) : Employe(id, n, "Receptionniste", s,nbr), shift(sh) {}
Receptionniste::Receptionniste(const Receptionniste& r) : Employe(r), shift(r.shift) {}
Receptionniste::~Receptionniste() {}
string Receptionniste::getShift() {return shift;}
void Receptionniste::setShift(string s) {shift = s;}
void Receptionniste::enregistrerClient(client c) {
cout << "Client " << c.getNom() << " " << c.getPrenom() << " enregistré." << endl;}
void Receptionniste::attribuerChambre(client c, int chambre) {
cout << "Chambre " << chambre << " attribué au client " << c.getNom() << " " << c.getPrenom() << endl;}
void Receptionniste::afficherEmploye(){
cout << "Nom: " << getNom() << ", Poste: " << getPoste() << ", Salaire: " << getSalaire() << ", Shift: " << shift << endl;}
// Surcharge de <<

ostream& operator<<(ostream& os, Receptionniste& r) {
    os << "ID Employï¿½: " << r.getIdEmploye() << endl;
    os << "Nom: " << r.getNom() << endl;
    os << "Poste: " << r.getPoste() << endl;
    os << "Salaire: " << r.getSalaire() << " DT" << endl;
    os << "Nombre de tache: " << r.getnbrTache() << endl;
    os << "Shift: " << r.shift << endl;
    return os;
}

// Surcharge de >>
istream& operator>>(istream& is, Receptionniste& r) {
    string nom, poste, shift;
    int id,nbrTache;
    float salaire;

    cout << "Saisir l'ID : ";
    is >> id;
    r.setIdEmploye(id);

    cout << "Saisir le nom : ";
    is >> nom;
    r.setNom(nom);

    cout << "Saisir le poste : ";
    is >> poste;
    r.setPoste(poste);

    cout << "Saisir le salaire : ";
    is >> salaire;
    r.setSalaire(salaire);
    
    cout << "Saisir nombre de tache : ";
    is >> nbrTache;
    r.setnbrTache(nbrTache);

    cout << "Saisir le shift : ";
    is >> shift;
    r.setShift(shift);

    return is;
}




