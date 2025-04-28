#include <iostream>
#include <string>
#include <vector>
#include "AssistantSpecialiste.h"
#include "Receptionniste.h"
#include "client.h"
#include "employe.h"
#include "assistantsocial.h"
#include "specialisation.h"
#include "gestionEquipe.h"
#include "Tache.h"
#include <stdexcept>
#include "GestionNationalite.h"
#include <set>
#include <map>

using namespace std;
int main()
{
    
    cout << "test fichier" << endl;
    
    GestionEquipe gestionEquipe;  // Création de l'objet de gestion d'équipe

    // Test 1: Ajouter des employés
    cout << "Ajout de nouveaux employés:\n";

    // Ajout d'un réceptionniste
    gestionEquipe.ajouterEmploye(new Receptionniste(1, "John Doe", "Receptionniste", 2500.0, 5, "Matin"));

    // Ajout d'un assistant social
    string domaineExpertise = "Psychologie";
    gestionEquipe.ajouterEmploye(new AssistantSocial(2, "Doe Jane", "AssistantSocial", 2800.0, 3, &domaineExpertise));

    // Ajout d'un assistant spécialiste
    string certification = "Dipléme en Psychologie";
    Specialisation spec("Sociologie", "Etudes de la sociï¿½tï¿½");
    gestionEquipe.ajouterEmploye(new AssistantSpecialiste(3, new string("Charlie"), "AssistantSpecialiste", 3000.0, 4, &certification, spec.getNomSpecialisation(), spec.getDescription(), &domaineExpertise));

    // Test 2: Afficher tous les employés
    cout << "\nListe des employï¿½s:\n";
    gestionEquipe.afficherEquipe();

    // Afficher les employés aprés suppression
    cout << "\nListe des employés aprés suppression:\n";
    gestionEquipe.afficherEquipe();

    // Test 5: Sauvegarder dans un fichier
    cout << "\nSauvegarde de l'équipe dans un fichier...\n";
    gestionEquipe.enregistrerEmployesDansFichier("Employer.txt");

    // Test 6: Charger depuis un fichier
    cout << "\nChargement des employés depuis le fichier...\n";
    gestionEquipe.chargerEmployesDepuisFichier("Employer.txt");

    // Afficher les employés aprï¿½s chargement depuis fichier
    cout << "\nListe des employés aprés chargement depuis fichier:\n";
    gestionEquipe.afficherEquipe();

    cout << "test exception" << endl;
    /*
    try {
       // Tentative de crï¿½ation avec un nombre de tï¿½ches nï¿½gatif
       Receptionniste* r = new Receptionniste(1, "John Doe", "Receptionniste", 2500.0, -2, "Matin");

       // Si aucune exception n'est lancï¿½e, afficher l'objet
       r->afficherEmploye();
       delete r;
   }
   catch (const invalid_argument& e) {
       cout << "Exception attrapï¿½e : " << e.what() << endl;
   }

 */
	

    
     GestionDesNationalites<int, string> gestion;

    // Ajouter des nationalités pour plusieurs clients
    gestion.ajouterNationalite(17, "Franï¿½aise");
    gestion.ajouterNationalite(17, "Tunisienne");

    gestion.ajouterNationalite(12, "Italienne");
    gestion.ajouterNationalite(12, "Portugaise");

    gestion.ajouterNationalite(29, "Japonaise");
    gestion.ajouterNationalite(29, "Chinoise");
    gestion.ajouterNationalite(29, "Corï¿½enne");

    // Afficher les nationalités avant enregistrement
    cout << "Avant enregistrement dans le fichier :\n";
    gestion.afficherTous();

    // Enregistrer dans le fichier
    gestion.enregistrerNationaliteDansFichier("nationalites.txt");

    // Modifier les nationalités du client 17
    vector<string> nouvellesNationalites;
    nouvellesNationalites.push_back("Marocaine");
    nouvellesNationalites.push_back("Libanaise");
    gestion.modifierNationalites(17, nouvellesNationalites);

    // Supprimer une nationalité pour client 29
    gestion.supprimerNationalite(29, "Chinoise");

    // Afficher aprés modification
    cout << "\nAprés modification (avant rechargement du fichier) :\n";
    gestion.afficherTous();

    // Charger les données originales depuis le fichier
    gestion.chargerNationaliteDepuisFichier("nationalites.txt");

    // Affichage final
    cout << "\nAprés chargement depuis le fichier :\n";
    gestion.afficherTous();
    
    
	//system("pause");
    return 0;
}
