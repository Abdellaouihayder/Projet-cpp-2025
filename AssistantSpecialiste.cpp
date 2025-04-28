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




//AssistantSpecialiste implementation

AssistantSpecialiste::AssistantSpecialiste(int id, string *nom, string poste, float salaire, int nbr, 
                                           string *certif, string nomSpec, string descSpec, string *domaineExpertise)
: AssistantSocial(id, *nom, "AssistantSpecialiste", salaire, nbr, domaineExpertise), 
  Specialisation(nomSpec, descSpec) {
    certification = new string(*certif);
}

AssistantSpecialiste::AssistantSpecialiste(int id, string nom, string poste, float salaire, int nbrTache)
    : AssistantSocial(id, nom, poste, salaire, nbrTache), Specialisation() {
    // initialisation spï¿½cifique si nï¿½cessaire
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
