#include <iostream>
#include <string>
#include <vector>
//#include "AssistantSpecialiste.h"
//#include "Receptionniste.h"
//#include "client.h"
//#include "tache.h"
//#include "employe.h"
//#include "assistantsocial.h"
//#include "specialisation.h"
//#include "gestionEquipe.h"
//#include "Tache.h"
#include <stdexcept>
//#include "GestionNationalite.h"
#include <set>
#include <map>
#include "API.cpp"

using namespace std;
int main()
{
    
    cout << "test fichier" << endl;
    
    GestionEquipe gestionEquipe;  // Cr�ation de l'objet de gestion d'�quipe

    // Test 1: Ajouter des employ�s
    cout << "Ajout de nouveaux employ�s:\n";

    // Ajout d'un r�ceptionniste
    gestionEquipe.ajouterEmploye(new Receptionniste(1, "John Doe", "Receptionniste", 2500.0, 5, "Matin"));

    // Ajout d'un assistant social
    string domaineExpertise = "Psychologie";
    gestionEquipe.ajouterEmploye(new AssistantSocial(2, "Doe Jane", "AssistantSocial", 2800.0, 3, &domaineExpertise));

    // Ajout d'un assistant sp�cialiste
    string certification = "Dipl�me en Psychologie";
    Specialisation spec("Sociologie", "Etudes de la soci�t�");
    gestionEquipe.ajouterEmploye(new AssistantSpecialiste(3, new string("Charlie"), "AssistantSpecialiste", 3000.0, 4, &certification, spec.getNomSpecialisation(), spec.getDescription(), &domaineExpertise));

    // Test 2: Afficher tous les employ�s
    cout << "\nListe des employ�s:\n";
    gestionEquipe.afficherEquipe();

    // Afficher les employ�s apr�s suppression
    cout << "\nListe des employ�s apr�s suppression:\n";
    gestionEquipe.afficherEquipe();

    // Test 5: Sauvegarder dans un fichier
    cout << "\nSauvegarde de l'�quipe dans un fichier...\n";
    gestionEquipe.enregistrerEmployesDansFichier("Employer.txt");

    // Test 6: Charger depuis un fichier
    cout << "\nChargement des employ�s depuis le fichier...\n";
    gestionEquipe.chargerEmployesDepuisFichier("Employer.txt");

    // Afficher les employ�s apr�s chargement depuis fichier
    cout << "\nListe des employ�s apr�s chargement depuis fichier:\n";
    gestionEquipe.afficherEquipe();

    cout << "test exception" << endl;
    /*
    try {
       // Tentative de cr�ation avec un nombre de t�ches n�gatif
       Receptionniste* r = new Receptionniste(1, "John Doe", "Receptionniste", 2500.0, -2, "Matin");

       // Si aucune exception n'est lanc�e, afficher l'objet
       r->afficherEmploye();
       delete r;
   }
   catch (const invalid_argument& e) {
       cout << "Exception attrap�e : " << e.what() << endl;
   }

 */
	

    
     GestionDesNationalites<int, string> gestion;

    // Ajouter des nationalit�s pour plusieurs clients
    gestion.ajouterNationalite(17, "Fran�aise");
    gestion.ajouterNationalite(17, "Tunisienne");

    gestion.ajouterNationalite(12, "Italienne");
    gestion.ajouterNationalite(12, "Portugaise");

    gestion.ajouterNationalite(29, "Japonaise");
    gestion.ajouterNationalite(29, "Chinoise");
    gestion.ajouterNationalite(29, "Cor�enne");

    // Afficher les nationalit�s avant enregistrement
    cout << "Avant enregistrement dans le fichier :\n";
    gestion.afficherTous();

    // Enregistrer dans le fichier
    gestion.enregistrerNationaliteDansFichier("nationalites.txt");

    // Modifier les nationalit�s du client 17
    vector<string> nouvellesNationalites;
    nouvellesNationalites.push_back("Marocaine");
    nouvellesNationalites.push_back("Libanaise");
    gestion.modifierNationalites(17, nouvellesNationalites);

    // Supprimer une nationalit� pour client 29
    gestion.supprimerNationalite(29, "Chinoise");

    // Afficher apr�s modification
    cout << "\nApr�s modification (avant rechargement du fichier) :\n";
    gestion.afficherTous();

    // Charger les donn�es originales depuis le fichier
    gestion.chargerNationaliteDepuisFichier("nationalites.txt");

    // Affichage final
    cout << "\nApr�s chargement depuis le fichier :\n";
    gestion.afficherTous();
    
    
	system("pause");
    return 0;
}
