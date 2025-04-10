#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <string>
#include <vector>
#include "Tache.h"
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
    Employe(const Employe& e);
    virtual ~Employe();
    
    int getIdEmploye();
    void setIdEmploye(int id);
    string getNom();
    void setNom(string n);
    string getPoste();
    void setPoste(string p);
    float getSalaire();
    void setSalaire(float s);
	Employe& operator=(const Employe& e);
    virtual void afficherEmploye() = 0;  
};

#endif

