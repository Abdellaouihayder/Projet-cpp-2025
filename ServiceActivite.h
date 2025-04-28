#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
#include"Service.h"
#include "assistantsocial.h"

using namespace std;

class ServiceActivite : public Service {
private:
    int animateurID;
public:
    ServiceActivite(string="", int=0);
    void organiserEvenement(string date);
    void ajouterActivite(string activite);
    void afficherServiceActivite();
};
