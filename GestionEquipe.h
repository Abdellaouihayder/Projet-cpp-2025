#include <iostream>
#include <string>
#include <vector>
using namespace std;
class GestionEquipe
{
    string nomEquipe;
    int nombreMembres;
    vector<Employe *> membres;

public:
    GestionEquipe(string nom = "NONE", int nb = 1);
    GestionEquipe(const GestionEquipe &equipe);
    ~GestionEquipe();
    GestionEquipe &operator=(const GestionEquipe &equipe);
    string getNomEquipe();
    void setNomEquipe(string n);
    int getNombreMembres();
    void setNombreMembres(int n);
    // crud
    void ajouterEmploye(Employe *employe);
    void supprimerEmploye(int idEmploye);
    void afficherEquipe();
    Employe *rechercherEmploye(int idEmploye);
    bool modifierEmploye(int idEmploye, const string &nom, const string &poste, float salaire, int nbrTache);
    // Sauvegarde et chargement des employ�s dans/depuis un fichier
    void enregistrerEmployesDansFichier(const string &nomFichier);
    void chargerEmployesDepuisFichier(const string &nomFichier);
};
