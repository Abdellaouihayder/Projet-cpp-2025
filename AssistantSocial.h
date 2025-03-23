#ifndef ASSISTANTSOCIAL_H
#define ASSISTANTSOCIAL_H

#include <iostream>
#include <string>
#include "Employe.h"  

class AssistantSocial : public Employe {
protected:
    string *domaineExpertise;
public:
    AssistantSocial(int id = 0, string nom = "", string poste = "", float salaire = 0.0, string *domaineExpertise = NULL);
    AssistantSocial(const AssistantSocial& assistant);
    ~AssistantSocial();
    
    string getDomaineExpertise();
    void setDomaineExpertise(string d);
    void aiderClient(client);
    void afficherAssistantSocial();
};

#endif // ASSISTANTSOCIAL_H

