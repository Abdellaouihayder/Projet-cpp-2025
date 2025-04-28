#include <typeinfo>
#include "Tache.h"  
#include "AssistantSocial.h"
#include "client.h"
#include "AssistantSpecialiste.h"
#include "Employe.h"
#include "GestionEquipe.h"
#include "Receptionniste.h"
#include "Specialisation.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include "GestionNationalite.h"
#include <set>
#include <map>
#include <algorithm> 
#include <sstream>  

using namespace std;

//Specialisation implementation
Specialisation::Specialisation(string nom, string desc): nomSpecialisation(nom), description(desc) {}
Specialisation::Specialisation(const Specialisation& spec): nomSpecialisation(spec.nomSpecialisation), description(spec.description) {}
Specialisation::~Specialisation() {}
string Specialisation::getNomSpecialisation() {return nomSpecialisation;}
void Specialisation::setNomSpecialisation(string n) {nomSpecialisation = n;}
string Specialisation::getDescription() {return description;}
void Specialisation::setDescription(string d) {description = d;}
