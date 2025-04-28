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
//AssistantSocial implementation
AssistantSocial::AssistantSocial(int id, string nom, string poste, float salaire,int nbr, string* domaineExpertise)
    : Employe(id, nom, "AssistantSocial", salaire,nbr) {
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

