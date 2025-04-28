#ifndef TACHE_H
#define TACHE_H

#include <iostream>
#include <string>
using namespace std;

class Tache
{
    int id;
    string description;
    string statut;
    static int compteur; // D�claration de la variable statique

public:
    Tache(int = 0, string = "", string = "");
    Tache(const Tache &);
    ~Tache();

    string getDescription();
    void setDescription(string desc);
    string getStatut();
    void setStatut(string stat);
    int getId();
    void setId(int id);
    void marquerCommeTerminee();

    static void afficherCompteur(); // M�thode statique
};

#endif

