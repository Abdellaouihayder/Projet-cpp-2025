#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
#include "Service.h"
#include "client.h"
using namespace std;


class Dossier {
protected:
    int idDossier;
    client client;
    string statutActuel;
    vector<Service*> services;
public:
    Dossier(int id, string cl, string statut);
    virtual ~Dossier();
    Dossier(const Dossier& other);
    int getId()  {return idDossier;}
    virtual void afficherServices();
    virtual void ajouterService(Service* service);
    virtual void supprimerService();
    friend ostream& operator<<(ostream& os, const Dossier& d);
    friend bool operator==(const Dossier& d1, const Dossier& d2);
    void sauvegarderDossier(const string& filename);
    void chargerDossier(const string& filename);

};
ostream& operator<<(ostream& os, const Dossier& d);
bool operator==(const Dossier& d1, const Dossier& d2);
