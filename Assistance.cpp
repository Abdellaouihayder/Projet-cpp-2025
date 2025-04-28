#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream> 
#include "Assistance.h"
#include <string>

using namespace std;
Assistance::Assistance( string type,string et, int id)
{
    typeAssistance=type;
    etat=et;
    IDintervenant=id;
}
void  Assistance::ajouterNotes(string notes) {
        cout << "Note ajoutee: " << notes << endl;
}
