#ifndef GESTION_NATIONALITES_H
#define GESTION_NATIONALITES_H
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <typename IDType, typename NationaliteType>
class GestionDesNationalites
{
private:
    map<IDType, set<NationaliteType> > ClientNationalite;

public:
    // Ajouter une nationalit� pour un client
    void ajouterNationalite(const IDType &idClient, const NationaliteType &nationalite);
    // Ajouter plusieurs nationalit�s pour un client
    void ajouterNationalites(const IDType &idClient, const vector<NationaliteType> &nationalites);
    // Supprimer une nationalit� pour un client
    void supprimerNationalite(const IDType &idClient, const NationaliteType &nationalite);
    // Modifier toutes les nationalit�s pour un client
    void modifierNationalites(const IDType &idClient, const vector<NationaliteType> &nouvellesNationalites);
    // Afficher les nationalit��s d'un client
    void afficherNationalites(const IDType &idClient);
    // Afficher toutes les nationalit�s
    void afficherTous();
    void enregistrerNationaliteDansFichier(const string &nomFichier);
    void chargerNationaliteDepuisFichier(const string &nomFichier);
};

#endif

