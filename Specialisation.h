#ifndef SPECIALISATION_H
#define SPECIALISATION_H

#include <iostream>
#include <string>

class Specialisation {
protected:
    string nomSpecialisation;
    string description;
public:
    Specialisation(string nom = "", string desc = "");
    Specialisation(const Specialisation& spec);
    virtual ~Specialisation();

    string getNomSpecialisation();
    void setNomSpecialisation(string n);
    string getDescription();
    void setDescription(string d);
};

#endif // SPECIALISATION_H

