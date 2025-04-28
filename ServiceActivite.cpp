#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream> 
#include <string>
#include "ServiceActivite.h"
using namespace std;


ServiceActivite::ServiceActivite(string desc, int anim):Service(desc) {
      animateurID=anim;
}

void ServiceActivite::organiserEvenement(string date) {
        cout << "Avancement organise le " << date << " par animateur numero : " << animateurID << endl;
}
