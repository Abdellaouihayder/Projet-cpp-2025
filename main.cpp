#include <iostream>
#include <string>
#include <vector>
#include "AssistantSpecialiste.h"
using namespace std;
main() {
	 string domaineExpertise1 = "Psychologie";
    string domaineExpertise2 = "Sociologie";
    string certif1 = "Certificat A";
    string certif2 = "Certificat B";
    
    AssistantSpecialiste as1(1, new string("Alice"), "Assistante Sociale", 2500.0f, new string(certif1), "Spécialisation A", "Description A", new string(domaineExpertise1));
    AssistantSpecialiste as2(2, new string("Bob"), "Assistante Sociale", 2200.0f, new string(certif2), "Spécialisation B", "Description B", new string(domaineExpertise2));

    // Affichage des informations avant soustraction
    std::cout << "Avant soustraction : " << std::endl;
    as1.afficherEmploye();
    std::cout << std::endl;
    as2.afficherEmploye();
    std::cout << std::endl;

    // Utilisation de l'opérateur -
    AssistantSpecialiste as3 = as1 - as2;

    // Affichage des informations après soustraction
    std::cout << "Après soustraction : " << std::endl;
    as3.afficherEmploye();

}
