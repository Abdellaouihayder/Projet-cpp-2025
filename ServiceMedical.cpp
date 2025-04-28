#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream> 
#include "ServiceMedical.h"
using namespace std;
ServiceMedical::ServiceMedical(string desc, int nb): Service(desc) { 
    nombreConsultations=nb;
  }

void ServiceMedical::afficherServiceMedical() {
        cout << "Service medical: " << description << ", Consultations: " << nombreConsultations << endl;
    }
