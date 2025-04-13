#include <iostream>
#include <string>
#include "Employe.h"
class Receptionniste : public Employe {
    string shift;
public:
    Receptionniste(int id = 0, string nom = "", string poste = "", float salaire = 0.0,int nbr=0, string shift = "");
    Receptionniste(const Receptionniste& R);
    ~Receptionniste();

    string getShift();
    void setShift(string s);
    void enregistrerClient(client client);
    void attribuerChambre(client client, int chambre);
    virtual void afficherEmploye();
    
    friend ostream& operator<<(ostream& os, Receptionniste& r);
    friend istream& operator>>(istream& is, Receptionniste& r);
};
