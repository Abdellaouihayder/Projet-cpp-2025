#ifndef TACHE_H  
#define TACHE_H
#include <iostream>
#include <string>
#include <vector>
#include "Tache.h"
class Tache;
using namespace std;
class Employe {
protected:
    int idEmploye;
    string nom;
    string poste;
    float salaire;
    vector<Tache*> taches;

public:
    Employe(int id = 0, string nom = "", string poste = "", float salaire = 0.0);
    Employe(const Employe& employe);
    virtual ~Employe();  
    
    int getIdEmploye();
    void setIdEmploye(int id);
    string getNom();
    void setNom(string n);
    string getPoste();
    void setPoste(string p);
    float getSalaire();
    void setSalaire(float s);
    virtual void afficherEmploye() = 0;
};
#endif
