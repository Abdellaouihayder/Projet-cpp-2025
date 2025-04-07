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



//Receptionniste implementation
Receptionniste::Receptionniste(int id, string n, string p, float s, string sh) : Employe(id, n, p, s), shift(sh) {}
Receptionniste::Receptionniste(const Receptionniste& r) : Employe(r), shift(r.shift) {}
Receptionniste::~Receptionniste() {}
string Receptionniste::getShift() {return shift;}
void Receptionniste::setShift(string s) {shift = s;}
void Receptionniste::enregistrerClient(client c) {
cout << "Client " << c.getNom() << " " << c.getPrenom() << " enregistré." << endl;}
void Receptionniste::attribuerChambre(client c, int chambre) {
cout << "Chambre " << chambre << " attribuée au client " << c.getNom() << " " << c.getPrenom() << endl;}
void Receptionniste::afficherEmploye(){
cout << "Nom: " << getNom() << ", Poste: " << getPoste() << ", Salaire: " << getSalaire() << ", Shift: " << shift << endl;}


//AssistantSocial implementation
AssistantSocial::AssistantSocial(int id, string nom, string poste, float salaire, string* domaineExpertise)
    : Employe(id, nom, poste, salaire) {
    this->domaineExpertise = new string(*domaineExpertise);  
}
AssistantSocial::AssistantSocial(const AssistantSocial& assistant)
    : Employe(assistant) {
    domaineExpertise = new string(*assistant.domaineExpertise);  
}
AssistantSocial::~AssistantSocial() {
    if (domaineExpertise != NULL) {delete domaineExpertise;  }
}
string AssistantSocial::getDomaineExpertise() {
    if (domaineExpertise != NULL) {
        return *domaineExpertise;
    } else {return "No expertise assigned";}
}
void AssistantSocial::setDomaineExpertise(string d) {
    if (domaineExpertise != NULL) {
        *domaineExpertise = d;
    } else {domaineExpertise = new string(d);}
}
void AssistantSocial::aiderClient(client c) {
    cout << "L'assistant social " << getNom() << " aide le client " << c.getNom() << " " << c.getPrenom() << endl;
}
void AssistantSocial::afficherEmploye() {
    cout << "Nom: " << getNom() << ", Poste: " << getPoste() << ", Salaire: " << getSalaire() << ", Domaine d'expertise: " 
         << getDomaineExpertise() << endl;
}




//Specialisation implementation
Specialisation::Specialisation(string nom, string desc)
    : nomSpecialisation(nom), description(desc) {}
Specialisation::Specialisation(const Specialisation& spec)
    : nomSpecialisation(spec.nomSpecialisation), description(spec.description) {}
Specialisation::~Specialisation() {}
string Specialisation::getNomSpecialisation() {return nomSpecialisation;}
void Specialisation::setNomSpecialisation(string n) {nomSpecialisation = n;}
string Specialisation::getDescription() {return description;}
void Specialisation::setDescription(string d) {description = d;}




//AssistantSpecialiste implementation
AssistantSpecialiste::AssistantSpecialiste(int id, string *nom, string poste, float salaire, string *certif, string nomSpec, string descSpec,string *domaineExpertise)
: AssistantSocial(id, *nom, poste, salaire, domaineExpertise), 
      Specialisation(nomSpec, descSpec) {
        certification = new string(*certif);
}

AssistantSpecialiste::AssistantSpecialiste(const AssistantSpecialiste& aspec)
    : AssistantSocial(aspec), Specialisation(aspec) {
    if (aspec.certification != NULL) {
        certification = new string(*aspec.certification);
    } else {
        certification = NULL;
    }
}
AssistantSpecialiste::~AssistantSpecialiste() {
    if (certification != NULL) {
        delete certification;  
    }
}
string AssistantSpecialiste::getCertification() {
    return (certification != NULL) ? *certification : "No certification available";
}
void AssistantSpecialiste::setCertification(string c) {
    if (certification == NULL) {
        certification = new string(c);
    } else {
        *certification = c;
    }
}
void AssistantSpecialiste::organiserAtelier(string sujet) {
    cout << "Organizing workshop on: " << sujet << endl;
}
void AssistantSpecialiste::afficherEmploye() {
    cout << "Assistant Specialiste Details:" << endl;
    cout << "Nom: " << getNom() << endl;
    cout << "Poste: " << getPoste() << endl;
    cout << "Salaire: " << getSalaire() << endl;
    cout << "Certification: " << getCertification() << endl;
    cout << "Specialisation: " << getNomSpecialisation() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Domaine Expertise: " << getDomaineExpertise() << endl;
}




//GestionEquipe implementation
GestionEquipe::GestionEquipe(string nom, int nb) : nomEquipe(nom), nombreMembres(nb) {}
GestionEquipe::GestionEquipe(const GestionEquipe& equipe) {
    nomEquipe = equipe.nomEquipe;
    nombreMembres = equipe.nombreMembres;
    Employe *p;
    for (unsigned int i = 0; i < equipe.membres.size(); i++) {
        if (typeid(*equipe.membres[i]) == typeid(AssistantSpecialiste)) {
        	p=new AssistantSpecialiste(static_cast<const AssistantSpecialiste&>(*equipe.membres[i]));
            membres.push_back(p);
        }
        else if (typeid(*equipe.membres[i]) == typeid(Receptionniste)) {
        	p=new Receptionniste(static_cast<const Receptionniste&>(*equipe.membres[i]));
            membres.push_back(p);
        }
    }
}

GestionEquipe::~GestionEquipe() {
    for (unsigned int i = 0; i < membres.size(); i++) {
        delete membres[i];  
    }
    membres.clear();  
}
string GestionEquipe::getNomEquipe() {return nomEquipe;}
void GestionEquipe::setNomEquipe(string n) {nomEquipe = n;}
int GestionEquipe::getNombreMembres() {return nombreMembres;}
void GestionEquipe::setNombreMembres(int n) {nombreMembres = n;}

void GestionEquipe::ajouterEmploye(Employe* employe) {
    Employe* nonConstEmploye = const_cast<Employe*>(employe);

    if (typeid(*nonConstEmploye) == typeid(AssistantSpecialiste)) {
        nonConstEmploye = new AssistantSpecialiste(static_cast<const AssistantSpecialiste&>(*employe));
    }
    else if (typeid(*nonConstEmploye) == typeid(Receptionniste)) {
        nonConstEmploye = new Receptionniste(static_cast<const Receptionniste&>(*employe));
    }
        membres.push_back(nonConstEmploye);
        nombreMembres = membres.size();
}

void GestionEquipe::supprimerEmploye(int idEmploye) {
    for (unsigned int i = 0; i < membres.size(); i++) {
        if (membres[i]->getIdEmploye() == idEmploye) {
            delete membres[i];  
            membres.erase(membres.begin() + i);  
            nombreMembres = membres.size();
            break;
        }
    }
}
void GestionEquipe::afficherEquipe() {
    cout << "Team Name: " << nomEquipe << endl;
    cout << "Number of Members: " << nombreMembres << endl;
    for (unsigned int i = 0; i < membres.size(); i++) {
        cout << "Employee ID: " << membres[i]->getIdEmploye() << ", Name: " << membres[i]->getNom() << endl;
    }
}


