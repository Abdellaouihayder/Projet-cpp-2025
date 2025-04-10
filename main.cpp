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
    
    AssistantSpecialiste as1(1, new string("Alice"), "Assistante Sociale", 2500.0f, new string(certif1), "Sp�cialisation A", "Description A", new string(domaineExpertise1));
    AssistantSpecialiste as2(2, new string("Bob"), "Assistante Sociale", 2200.0f, new string(certif2), "Sp�cialisation B", "Description B", new string(domaineExpertise2));

    // Affichage des informations avant soustraction
    std::cout << "Avant soustraction : " << std::endl;
    as1.afficherEmploye();
    std::cout << std::endl;
    as2.afficherEmploye();
    std::cout << std::endl;

    // Utilisation de l'op�rateur -
    AssistantSpecialiste as3 = as1 - as2;

    // Affichage des informations apr�s soustraction
    std::cout << "Apr�s soustraction : " << std::endl;
    as3.afficherEmploye();

}
