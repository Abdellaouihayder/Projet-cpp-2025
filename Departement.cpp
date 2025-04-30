#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream> 
#include "Departement.h"
using namespace std;

Departement::Departement(string n, int resp){
  nom=n;
  Idresponsable=resp;
 }
Departement::~Departement() {
  dossiers.clear(); 
}

Departement::Departement(const Departement& other) {
  nom = other.nom;
  Idresponsable = other.Idresponsable;
  for (size_t i = 0; i < other.dossiers.size(); ++i) {
      dossiers.push_back(other.dossiers[i]); 
  }
}
void Departement::afficherDetails() {
cout << "Departement: " << nom << ",avec le Responsable numero : " << Idresponsable << endl;
cout<<"Les identifiant de  dossiers "<<endl;
for (size_t i = 0; i < dossiers.size(); ++i) {
  cout<<dossiers[i].getId()<<endl;
  }
}

void Departement::ajouterDossier(Dossier d) {
dossiers.push_back(d);
}

void Departement::supprimerDossier(int id) {
for (size_t i = 0; i < dossiers.size(); ++i) {
    if (dossiers[i].getId() == id) {
        dossiers[i].supprimerService();
        dossiers.erase(dossiers.begin() + i);
        cout << "Dossier avec ID " << id << " supprime." << endl;
        return;
    }
}
cout << "Aucun dossier trouve avec ID " << id << "." << endl;
}

void Departement::sauvegarderDepartement(const string& filename) {
  ofstream fichier(filename.c_str(), ios::app | ios::app);
  if (fichier.is_open()) {
      fichier << "Departement: " << nom << ", Responsable de numero: " << Idresponsable << "\n";
      fichier << "Nombre de dossiers: " << dossiers.size() << "\n";
      fichier.close();
      cout << "Departement sauvegarder dans " << filename << endl;
  } else {
      cout << "Erreur lors de l'ouverture du fichier." << endl;
  }
}

void Departement::chargerDepartement(const string& filename) {
  ifstream fichier(filename.c_str(), ios::in);
  if (fichier.is_open()) {
      string ligne;
      while (getline(fichier, ligne)) {
          cout << ligne << endl;
      }
      fichier.close();
  } else {
      cout << "Erreur lors de l'ouverture du fichier." << endl;
  }
}






ostream& operator<<(ostream& os, const Departement& dept) {
  os << "Departement: " << dept.nom << ", Responsable numero: " << dept.Idresponsable << ", Nombre de dossiers: " << dept.dossiers.size();
  return os;
}
bool operator==(const Departement& d1, const Departement& d2) {
  return (d1.nom == d2.nom) &&
         (d1.Idresponsable == d2.Idresponsable) &&
         (d1.dossiers.size() == d2.dossiers.size());
}
