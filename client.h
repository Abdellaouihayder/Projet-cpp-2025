#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
using namespace std;

class client {
    string nom;
    string prenom;
    int cin;
public:
    client(string = "", string = "", int = 0);
    client(const client&);
    ~client();
    void afficherinfo();
    string getNom();
    void setNom(string n);
    string getPrenom();
    void setPrenom(string p);
    int getCin();
    void setCin(int c);
};

#endif 

