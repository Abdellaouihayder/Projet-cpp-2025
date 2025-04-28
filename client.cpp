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
// client implementation 
client::client(string n, string p, int c) : nom(n), prenom(p), cin(c) {}
client::client(const client& c) : nom(c.nom), prenom(c.prenom), cin(c.cin) {}
client::~client() {}
void client::afficherinfo() {
    cout << "Nom: " << nom << ", Prenom: " << prenom << ", CIN: " << cin << endl;
}
string client::getNom() { return nom; } 
void client::setNom(string n) { nom = n; } 
string client::getPrenom() { return prenom; }
void client::setPrenom(string p) { prenom = p; }
int client::getCin() { return cin; }
void client::setCin(int c) { cin = c; }
