#ifndef ASSISTANTSPECIALISTE_H
#define ASSISTANTSPECIALISTE_H

#include <iostream>
#include <string>
#include "Specialisation.h"  
#include "AssistantSocial.h"  

class AssistantSpecialiste : public Specialisation, public AssistantSocial {
protected:
    string *certification;
public:
   AssistantSpecialiste(int id = 0, string *nom = NULL, string poste = "", float salaire = 0.0, int nbr = 0,
                     string *certif = NULL, string nomSpec = "", string descSpec = "", 
                     string *domaineExpertise = NULL);

    AssistantSpecialiste(const AssistantSpecialiste& aspec);
    AssistantSpecialiste operator-(AssistantSpecialiste& other);

    ~AssistantSpecialiste();

    string getCertification();
    void setCertification(string c);
    void organiserAtelier(string sujet);
    virtual void afficherEmploye();
};

#endif 

