#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
using namespace std;

class Plat {
private:
    string nom;
    double prix;
    string desc;

public:
    Plat(string n = "", double p = 0.0, string d = "")
        : nom(n), prix(p), desc(d) {}
    string getNom() { return nom; }
    double getPrix() { return prix; }
    string getDescription()  { return desc; }
    void setNom(const string& n) { nom = n; }
    void setPrix(double p) { prix = p; }
    void setDescription(const string& d) { desc= d; }
    void afficher() {cout << "Plat: " << nom << " | Prix: " << prix << "DT | " << desc << endl;}
};
