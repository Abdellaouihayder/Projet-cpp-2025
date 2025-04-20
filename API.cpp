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
int Tache::getId(){ return id;}
void Tache::setId(int i){id=i;}


// Employe implementation
Employe::Employe(int id, string n, string p, float s,int nbr) : idEmploye(id), nom(n), poste(p), salaire(s),nbrTache(nbr){}
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
// Sauvegarde les tâches dans un fichier
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
// Charge les tâches depuis un fichier
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
        Tache* t = new Tache(desc, statut);
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
			// Réécriture du fichier mis à jour
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



//Receptionniste implementation
Receptionniste::Receptionniste(int id, string n, string p, float s,int nbr, string sh) : Employe(id, n, p, s,nbr), shift(sh) {}
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
// Surcharge de <<

ostream& operator<<(ostream& os, Receptionniste& r) {
    os << "ID Employé: " << r.getIdEmploye() << endl;
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


//AssistantSocial implementation
AssistantSocial::AssistantSocial(int id, string nom, string poste, float salaire,int nbr, string* domaineExpertise)
    : Employe(id, nom, poste, salaire,nbr) {
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
AssistantSocial AssistantSocial::operator+(AssistantSocial& other) {
    string fusionDomaine = this->getDomaineExpertise() + " & " + other.getDomaineExpertise();
    return AssistantSocial(
        this->idEmploye, 
        this->nom, 
        this->poste, 
        this->salaire + other.salaire, 
        this->nbrTache + other.nbrTache, 
        new string(fusionDomaine)
    );
}





//Specialisation implementation
Specialisation::Specialisation(string nom, string desc): nomSpecialisation(nom), description(desc) {}
Specialisation::Specialisation(const Specialisation& spec): nomSpecialisation(spec.nomSpecialisation), description(spec.description) {}
Specialisation::~Specialisation() {}
string Specialisation::getNomSpecialisation() {return nomSpecialisation;}
void Specialisation::setNomSpecialisation(string n) {nomSpecialisation = n;}
string Specialisation::getDescription() {return description;}
void Specialisation::setDescription(string d) {description = d;}




//AssistantSpecialiste implementation

AssistantSpecialiste::AssistantSpecialiste(int id, string *nom, string poste, float salaire, int nbr, 
                                           string *certif, string nomSpec, string descSpec, string *domaineExpertise)
: AssistantSocial(id, *nom, poste, salaire, nbr, domaineExpertise), 
  Specialisation(nomSpec, descSpec) {
    certification = new string(*certif);
}


AssistantSpecialiste::AssistantSpecialiste(const AssistantSpecialiste& aspec): AssistantSocial(aspec), Specialisation(aspec) {
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
    cout << "Taches: " << getnbrTache() << endl;
    cout << "Certification: " << getCertification() << endl;
    cout << "Specialisation: " << getNomSpecialisation() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Domaine Expertise: " << getDomaineExpertise() << endl;
}

AssistantSpecialiste AssistantSpecialiste::operator-(AssistantSpecialiste& other) {
    // Réduire uniquement le salaire
    float newSalaire = this->salaire - other.salaire;

    return AssistantSpecialiste(
        this->idEmploye,  
        &this->nom, 
        this->poste,
        newSalaire,
		this->nbrTache,  
        this->certification,  
        this->getNomSpecialisation(),
        this->getDescription(),
        this->domaineExpertise
    );
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
Employe* GestionEquipe::rechercherEmploye(int idEmploye) {
    for (unsigned int i = 0; i < membres.size(); ++i) {
        if (membres[i]->getIdEmploye() == idEmploye) {
            return membres[i];  
        }
    }
    return NULL;  
}
void GestionEquipe::afficherEquipe() {
    cout << "Team Name: " << nomEquipe << endl;
    cout << "Number of Members: " << nombreMembres << endl;
    for (unsigned int i = 0; i < membres.size(); i++) {
        cout << "Employee ID: " << membres[i]->getIdEmploye() << ", Name: " << membres[i]->getNom() << endl;
        if (AssistantSpecialiste* assistant = dynamic_cast<AssistantSpecialiste*>(membres[i])) {
            cout << "Certification: " << assistant->getCertification() << endl;  
        }
        else if (Receptionniste* receptionniste = dynamic_cast<Receptionniste*>(membres[i])) {
            cout << "Shift: " << receptionniste->getShift() << endl; 
        }
    }
}

bool GestionEquipe::modifierEmploye(int idEmploye, const string& nom, const string& poste, float salaire, int nbrTache) {
    for (unsigned int i = 0; i < membres.size(); i++) {
        if (membres[i]->getIdEmploye() == idEmploye) {
            membres[i]->setNom(nom);
            membres[i]->setPoste(poste);
            membres[i]->setSalaire(salaire);
            membres[i]->setnbrTache(nbrTache);

            enregistrerEmployesDansFichier("employes.txt");

            return true; 
        }
    }

    return false; 
}



GestionEquipe& GestionEquipe::operator=(const GestionEquipe& equipe) {
    if (this != &equipe) {  
    
    nomEquipe = equipe.nomEquipe;
    nombreMembres = equipe.nombreMembres;
    for (unsigned int i = 0; i < membres.size(); i++) {
        delete membres[i];  
    }
    membres.clear();  
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
    return *this;  
}
void GestionEquipe::enregistrerEmployesDansFichier(const string& nomFichier) {
    ofstream fichier(nomFichier.c_str());  // Utilisation de c_str() si nécessaire
    if (!fichier.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier pour sauvegarder les employés !" << endl;
        return;
    }

    for (unsigned int i = 0; i < membres.size(); i++) {
        fichier << membres[i]->getIdEmploye() << ";" 
                << membres[i]->getNom() << ";" 
                << membres[i]->getPoste() << ";" 
                << membres[i]->getSalaire() << ";" 
                << membres[i]->getnbrTache() << endl;  
    }

    fichier.close();  
}

