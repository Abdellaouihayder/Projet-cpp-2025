#ifndef TACHE_H
#define TACHE_H

#include <iostream>
#include <string>
using namespace std;
class Tache {
	int id;
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
    int getId();
    void setId(int id);
    void marquerCommeTerminee();
};

#endif
