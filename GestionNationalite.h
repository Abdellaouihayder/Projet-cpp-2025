#ifndef GESTION_NATIONALITES_H
#define GESTION_NATIONALITES_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class GestionDesNationalites
{
private:
    map<int, vector<string> > ClientNationalite; 

public:
    void ajouterNationalites(const int &idClient, const vector<string> &nationalites);
    void ajouterNationalite(const int &idClient, const string &nationalite);
    void supprimerNationalite(const int &idClient, const string &nationalite);
    void modifierNationalites(const int &idClient, const vector<string> &nouvellesNationalites);
    void afficherNationalites(const int &idClient);
    void afficherTous();
};

#endif
