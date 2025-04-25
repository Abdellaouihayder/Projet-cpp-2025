#include <iostream>
#include <string>
#include <vector>
#include "AssistantSpecialiste.h"
#include "Receptionniste.h"
#include "client.h"
#include "tache.h"
#include "employe.h"
#include "assistantsocial.h"
#include "specialisation.h"
#include "gestionEquipe.h"
#include "Tache.h"
#include <stdexcept>
#include "GestionNationalite.h"
#include <set>
#include <map>
//#include "API.cpp"

using namespace std;
int main()
{
    /*	 string domaineExpertise1 = "Psychologie";
        string domaineExpertise2 = "Sociologie";
        string certif1 = "Certificat A";
        string certif2 = "Certificat B";

        AssistantSpecialiste as1(1, new string("Alice"), "Assistante Sociale", 2500.0f, new string(certif1), "Spï¿½cialisation A", "Description A", new string(domaineExpertise1));
        AssistantSpecialiste as2(2, new string("Bob"), "Assistante Sociale", 2200.0f, new string(certif2), "Spï¿½cialisation B", "Description B", new string(domaineExpertise2));

        // Affichage des informations avant soustraction
        std::cout << "Avant soustraction : " << std::endl;
        as1.afficherEmploye();
        std::cout << std::endl;
        as2.afficherEmploye();
        std::cout << std::endl;

        // Utilisation de l'opï¿½rateur -
        AssistantSpecialiste as3 = as1 - as2;

        // Affichage des informations aprï¿½s soustraction
        std::cout << "Aprï¿½s soustraction : " << std::endl;
        as3.afficherEmploye();
    */

    /*
    Receptionniste r;
        cin >> r;
        cout << "\nInformations du rï¿½ceptionniste :\n";
        cout << r;

    cout << "test fichier" << endl;*/
    /*
    GestionEquipe gestionEquipe;  // Crï¿½ation de l'objet de gestion d'ï¿½quipe

    // Test 1: Ajouter des employï¿½s
    cout << "Ajout de nouveaux employï¿½s:\n";

    // Ajout d'un rï¿½ceptionniste
    gestionEquipe.ajouterEmploye(new Receptionniste(1, "John Doe", "Receptionniste", 2500.0, 5, "Matin"));

    // Ajout d'un assistant social
    string domaineExpertise = "Psychologie";
    gestionEquipe.ajouterEmploye(new AssistantSocial(2, "Doe Jane", "AssistantSocial", 2800.0, 3, &domaineExpertise));

    // Ajout d'un assistant spï¿½cialiste
    string certification = "Diplï¿½me en Psychologie";
    Specialisation spec("Sociologie", "Etudes de la sociï¿½tï¿½");
    gestionEquipe.ajouterEmploye(new AssistantSpecialiste(3, new string("Charlie"), "AssistantSpecialiste", 3000.0, 4, &certification, spec.getNomSpecialisation(), spec.getDescription(), &domaineExpertise));

    // Test 2: Afficher tous les employï¿½s
    cout << "\nListe des employï¿½s:\n";
    gestionEquipe.afficherEquipe();

    // Afficher les employï¿½s aprï¿½s suppression
    cout << "\nListe des employï¿½s aprï¿½s suppression:\n";
    gestionEquipe.afficherEquipe();

    // Test 5: Sauvegarder dans un fichier
    cout << "\nSauvegarde de l'ï¿½quipe dans un fichier...\n";
    gestionEquipe.enregistrerEmployesDansFichier("Employer.txt");

    // Test 6: Charger depuis un fichier
    cout << "\nChargement des employï¿½s depuis le fichier...\n";
    gestionEquipe.chargerEmployesDepuisFichier("Employer.txt");

    // Afficher les employï¿½s aprï¿½s chargement depuis fichier
    cout << "\nListe des employï¿½s aprï¿½s chargement depuis fichier:\n";
    gestionEquipe.afficherEquipe();



   Receptionniste* r = new Receptionniste(1, "John Doe", "Receptionniste", 2500.0, 5, "Matin");

    // Crï¿½er des tï¿½ches
    Tache* tache1 = new Tache(1, "Rï¿½pondre au tï¿½lï¿½phone", "En cours");
    Tache* tache2 = new Tache(2, "Accueillir un client", "Terminï¿½");

    // Ajouter des tï¿½ches ï¿½ l'employï¿½
    r->ajouterTache(tache1);
    r->ajouterTache(tache2);


    // Sauvegarder les tï¿½ches dans un fichier
    r->enregistrerTachesDansFichier("Taches.txt");

    // Charger les tï¿½ches depuis le fichier
    Receptionniste* r2 = new Receptionniste(0, "", "", 0.0, 0, "");
    r2->chargerTachesDepuisFichier("Taches.txt");



    // Libï¿½rer la mï¿½moire
    delete r;
    delete r2;
    */

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
	
	    GestionDesNationalites gestion;

    // Ajouter des nationalités (simples) pour le client 1
    gestion.ajouterNationalite(1, "Française");
    gestion.ajouterNationalite(1, "Italienne");
    gestion.ajouterNationalite(1, "Française"); // Doublon ignoré grâce au set

    // Afficher les nationalités du client 1
    gestion.afficherNationalites(1);

    // Ajouter plusieurs nationalités à un autre client (client 2)
    set<string> natClient2;
    natClient2.insert("Espagnole");
    natClient2.insert("Allemande");
    natClient2.insert("Japonaise");

    // Convertir le set en vector pour passer à la méthode (car elle prend vector)
    vector<string> vecNatClient2(natClient2.begin(), natClient2.end());
    gestion.ajouterNationalites(2, vecNatClient2);

    // Affichage global
    cout << "\n--- Tous les clients ---" << endl;
    gestion.afficherTous();

    // Modifier les nationalités du client 1
    set<string> nouvellesNat;
    nouvellesNat.insert("Tunisienne");
    nouvellesNat.insert("Algérienne");

    vector<string> vecNouvellesNat(nouvellesNat.begin(), nouvellesNat.end());
    gestion.modifierNationalites(1, vecNouvellesNat);

    // Supprimer une nationalité
    gestion.supprimerNationalite(2, "Allemande");

    // Affichage final
    cout << "\n--- Après modifications ---" << endl;
    gestion.afficherTous();
	system("pause");
    return 0;
}
