#ifndef TACHE_H
#define TACHE_H
#include <iostream>
#include <string>
using namespace std;
class Tache {
    string description;
    string statut;
public:
    Tache(string = "", string = "");
    Tache(const Tache&);
    ~Tache();

    string getDescription();
    void setDescription(string desc);
    string getStatut();
    void setStatut(string stat);
    void marquerCommeTerminee();
};
#endif
