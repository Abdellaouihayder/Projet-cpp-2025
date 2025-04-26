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
Tache::Tache(int i,string desc, string stat) :id(i),description(desc), statut(stat) {}
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
Employe::Employe(int id, string n, string p, float s,int nbr) : idEmploye(id), nom(n), poste(p), salaire(s),nbrTache(nbr){
try {
        if (nbrTache < 0) {
            throw invalid_argument("Le nombre de t�ches ne peut pas �tre n�gatif.");
        }
        this->nbrTache = nbrTache;
    } catch (const invalid_argument& e) {
        cerr << "Erreur lors de la cr�ation de l'employ� : " << e.what() << endl;
        this->nbrTache = 0;  // Valeur par d�faut ou traitement sp�cifique
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
			// R�criture du fichier mis a jour
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
cout << "Client " << c.getNom() << " " << c.getPrenom() << " enregistr�." << endl;}
void Receptionniste::attribuerChambre(client c, int chambre) {
cout << "Chambre " << chambre << " attribu�e au client " << c.getNom() << " " << c.getPrenom() << endl;}
void Receptionniste::afficherEmploye(){
cout << "Nom: " << getNom() << ", Poste: " << getPoste() << ", Salaire: " << getSalaire() << ", Shift: " << shift << endl;}
// Surcharge de <<

ostream& operator<<(ostream& os, Receptionniste& r) {
    os << "ID Employ�: " << r.getIdEmploye() << endl;
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

AssistantSpecialiste::AssistantSpecialiste(int id, string nom, string poste, float salaire, int nbrTache)
    : AssistantSocial(id, nom, poste, salaire, nbrTache), Specialisation() {
    // initialisation sp�cifique si n�cessaire
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
    // R�duire uniquement le salaire
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
// enregistrerEmployesDansFichier
void GestionEquipe::enregistrerEmployesDansFichier(const string& nomFichier) {
    ofstream fichier(nomFichier.c_str(), ios::out | ios::app);  
    if (!fichier.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier pour sauvegarder les employ�s !" << endl;
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
void GestionEquipe::chargerEmployesDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier.c_str());
    if (!fichier.is_open()) { exit(-2); }

    string ligne;
    while (getline(fichier, ligne)) {
        int pos1 = ligne.find(';');
        int pos2 = ligne.find(';', pos1 + 1);
        int pos3 = ligne.find(';', pos2 + 1);
        int pos4 = ligne.find(';', pos3 + 1);

        int id = atoi(ligne.substr(0, pos1).c_str());
        string nom = ligne.substr(pos1 + 1, pos2 - pos1 - 1);
        string poste = ligne.substr(pos2 + 1, pos3 - pos2 - 1);
        float salaire = atof(ligne.substr(pos3 + 1, pos4 - pos3 - 1).c_str());
        int nbrTache = atoi(ligne.substr(pos4 + 1).c_str());

        Employe* e = NULL;

        if (poste == "Receptionniste") {
            e = new Receptionniste(id, nom, poste, salaire, nbrTache);
        } else if (poste == "AssistantSocial") {
            e = new AssistantSocial(id, nom, poste, salaire, nbrTache);
        } else if (poste == "AssistantSpecialiste") {
            e = new AssistantSpecialiste(id, nom, poste, salaire, nbrTache);
        }

        if (e != NULL) {
            membres.push_back(e);
        }
    }

    fichier.close();
}

//gestion des nationalites implementation
template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::ajouterNationalite(const IDType &idClient, const NationaliteType &nationalite)
{
    ClientNationalite[idClient].insert(nationalite);
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::ajouterNationalites(const IDType &idClient, const vector<NationaliteType> &nationalites)
{
    for (typename vector<NationaliteType>::const_iterator it = nationalites.begin(); it != nationalites.end(); ++it)
    {
        ClientNationalite[idClient].insert(*it);
    }
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::supprimerNationalite(const IDType &idClient, const NationaliteType &nationalite)
{
    typename map<IDType, set<NationaliteType> >::iterator it = ClientNationalite.find(idClient);
    if (it != ClientNationalite.end())
    {
        it->second.erase(nationalite);
        if (it->second.empty())
        {
            ClientNationalite.erase(it);
        }
    }
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::modifierNationalites(const IDType &idClient, const vector<NationaliteType> &nouvellesNationalites)
{
    set<NationaliteType> nouvellesSet(nouvellesNationalites.begin(), nouvellesNationalites.end());
    ClientNationalite[idClient] = nouvellesSet;
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::afficherNationalites(const IDType &idClient)
{
    typename map<IDType, set<NationaliteType> >::iterator it = ClientNationalite.find(idClient);
    if (it != ClientNationalite.end())
    {
        cout << "Client " << idClient << " a les nationalit�s : ";
        for (typename set<NationaliteType>::const_iterator nat = it->second.begin(); nat != it->second.end(); ++nat)
        {
            cout << *nat << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Aucune nationalit� trouv�e pour le client " << idClient << endl;
    }
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::afficherTous()
{
    for (typename map<IDType, set<NationaliteType> >::iterator it = ClientNationalite.begin(); it != ClientNationalite.end(); ++it)
    {
        cout << "Client " << it->first << " : ";
        for (typename set<NationaliteType>::const_iterator nat = it->second.begin(); nat != it->second.end(); ++nat)
        {
            cout << *nat << " ";
        }
        cout << endl;
    }
}
template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::enregistrerNationaliteDansFichier(const string &nomFichier)
{
    ofstream fichier(nomFichier.c_str(), ios::out | ios::app);  // Changed to ensure file is cleared and written properly

    if (!fichier.is_open())
    {
        cerr << "Erreur : impossible d'ouvrir le fichier \"" << nomFichier << "\" pour l'écriture." << endl;
        return;
    }

    typename map<IDType, set<NationaliteType> >::iterator it;
    for (it = ClientNationalite.begin(); it != ClientNationalite.end(); ++it)
    {
        fichier << it->first << ":";
        typename set<NationaliteType>::const_iterator natIt;
        for (natIt = it->second.begin(); natIt != it->second.end(); ++natIt)
        {
            fichier << " " << *natIt;
        }
        fichier << endl;
    }

    fichier.close();
}

// Charger les t�ches depuis un fichier
template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::chargerNationaliteDepuisFichier(const string &nomFichier)
{
    ifstream fichier(nomFichier.c_str());
    if (!fichier.is_open()) { exit(-4); }
    if (fichier)
    {
        string ligne;
        while (getline(fichier, ligne))
        {
            istringstream iss(ligne);
            IDType idClient;
            string deuxPoints;

            // Lire l'ID et ignorer le ':'
            if (!(iss >> idClient >> deuxPoints) || deuxPoints != ":")
                continue;

            set<NationaliteType> nationalites;
            NationaliteType nat;
            while (iss >> nat)
            {
                nationalites.insert(nat);
            }

            ClientNationalite[idClient] = nationalites;
        }
        fichier.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier pour la lecture." << endl;
    }
}

// Lien entre la d�claration du template et la d�finition du template
template class GestionDesNationalites<int, string>;


