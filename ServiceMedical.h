#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
#include "Service.h"
using namespace std;
class ServiceMedical : public Service {
protected:
    int nombreConsultations;
public:
    ServiceMedical(string desc, int nb) ;
    void afficherServiceMedical();
};
