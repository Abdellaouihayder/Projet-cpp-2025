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


//GestionEquipe implementation
GestionEquipe::GestionEquipe(string nom, int nb) : nomEquipe(nom), nombreMembres(nb) {}
GestionEquipe::GestionEquipe(const GestionEquipe& equipe) {
    nomEquipe = equipe.nomEquipe;
    nombreMembres = equipe.nombreMembres;
    Employe *p;
    for (unsigned int i = 0; i < equipe.membres.size(); i++) {
        if (typeid(*equipe.membres[i]) == typeid(AssistantSpecialiste)) {
        	p=new AssistantSpecialiste(static_cast<const AssistantSpecialiste&>(*equipe.membres[i]));//static_cast
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
    Employe* nonConstEmploye = const_cast<Employe*>(employe);//const cast

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
        if (AssistantSpecialiste* assistant = dynamic_cast<AssistantSpecialiste*>(membres[i])) {//dynamique cast
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
        cerr << "Erreur lors de l'ouverture du fichier pour sauvegarder les employï¿½s !" << endl;
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

  ifstream fichier(nomFichier.c_str());  // Ouverture du fichier
    if (!fichier) {
        cerr << "Erreur d'ouverture du fichier!" << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {  
        stringstream ss(ligne); 
        int id, nbrTache;
        string nom, poste;
        float salaire;

        ss >> id;  
        ss.ignore();  
        
        getline(ss, nom, ';');  
        getline(ss, poste, ';');  
        ss >> salaire;  
        ss.ignore();  
        
        ss >> nbrTache;  
        cout << "ID: " << id << ", Nom: " << nom
             << ", Poste: " << poste << ", Salaire: " << salaire
             << ", Nombre de Tâches: " << nbrTache << endl;
		if (poste == "Receptionniste") {
    		Receptionniste* e = new Receptionniste(id, nom, "Receptionniste", salaire, nbrTache, " ");
    			membres.push_back(e);
    			 delete e;
		} else if (poste == "AssistantSocial") {
    		AssistantSocial* e = new AssistantSocial(id, nom, "AssistantSocial", salaire, nbrTache, NULL);
    		membres.push_back(e);
    		 delete e;
		} else if (poste == "AssistantSpecialiste") {
    		AssistantSpecialiste* e = new AssistantSpecialiste(id, nom, "AssistantSpecialiste", salaire, nbrTache);
    		membres.push_back(e);
    		 delete e;
		}

        
    }

    fichier.close();
}
