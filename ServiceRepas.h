#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
#include"Service.h"
#include"Plat.h"
using namespace std;

class ServiceRepas : public Service {
protected:
    vector<Plat> plats;

public:
    ServiceRepas(string);
    void ajouterPlat(Plat& plat);
    void supprimerPlat(string nom);
    void afficherMenu();
};

