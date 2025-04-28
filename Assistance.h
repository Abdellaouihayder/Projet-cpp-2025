#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

using namespace std;
class Assistance {
protected:
    string typeAssistance;
    string etat;
    int IDintervenant;
public:
    Assistance(string="",string="", int=0) ;
     virtual ~Assistance(){}
     virtual void ajouterNotes(string notes) ;
};
