#include <iostream>
#include <string>
#include <vector>
using namespace std;
class GestionEquipe {
    string nomEquipe;
    int nombreMembres;
    vector<Employe*> membres;
public:
    GestionEquipe(string nom = "", int nb = 1);
    GestionEquipe(const GestionEquipe& equipe);
    ~GestionEquipe();

    string getNomEquipe();
    void setNomEquipe(string n);
    int getNombreMembres();
    void setNombreMembres(int n);
    void ajouterEmploye(Employe* employe);
    void supprimerEmploye(int idEmploye);
    void afficherEquipe();
};
