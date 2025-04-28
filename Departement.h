#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
#include "Dossier.h"
using namespace std;

class Departement{
private:
    string nom;
    int Idresponsable;
    vector<Dossier> dossiers;
public:
    Departement(string="", int=0);
    virtual ~Departement();
    Departement(const Departement& other);
    void afficherDetails();
    void ajouterDossier(Dossier d);
    void supprimerDossier(int id);
    friend ostream& operator<<(ostream& os, const Departement& dept);
    friend bool operator==(const Departement& d1, const Departement& d2);
    void sauvegarderDepartement(const string& filename);
    void chargerDepartement(const string& filename);
};

ostream& operator<<(ostream& os, const Departement& dept);
bool operator==(const Departement& d1, const Departement& d2);
