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
    */

    /*
    Receptionniste r;
        cin >> r;
        cout << "\nInformations du r�ceptionniste :\n";
        cout << r;

    cout << "test fichier" << endl;*/
    /*
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



   Receptionniste* r = new Receptionniste(1, "John Doe", "Receptionniste", 2500.0, 5, "Matin");

    // Cr�er des t�ches
    Tache* tache1 = new Tache(1, "R�pondre au t�l�phone", "En cours");
    Tache* tache2 = new Tache(2, "Accueillir un client", "Termin�");

    // Ajouter des t�ches � l'employ�
    r->ajouterTache(tache1);
    r->ajouterTache(tache2);


    // Sauvegarder les t�ches dans un fichier
    r->enregistrerTachesDansFichier("Taches.txt");

    // Charger les t�ches depuis le fichier
    Receptionniste* r2 = new Receptionniste(0, "", "", 0.0, 0, "");
    r2->chargerTachesDepuisFichier("Taches.txt");



    // Lib�rer la m�moire
    delete r;
    delete r2;
    */

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
	
	    GestionDesNationalites gestion;

    // Ajouter des nationalit�s (simples) pour le client 1
    gestion.ajouterNationalite(1, "Fran�aise");
    gestion.ajouterNationalite(1, "Italienne");
    gestion.ajouterNationalite(1, "Fran�aise"); // Doublon ignor� gr�ce au set

    // Afficher les nationalit�s du client 1
    gestion.afficherNationalites(1);

    // Ajouter plusieurs nationalit�s � un autre client (client 2)
    set<string> natClient2;
    natClient2.insert("Espagnole");
    natClient2.insert("Allemande");
    natClient2.insert("Japonaise");

    // Convertir le set en vector pour passer � la m�thode (car elle prend vector)
    vector<string> vecNatClient2(natClient2.begin(), natClient2.end());
    gestion.ajouterNationalites(2, vecNatClient2);

    // Affichage global
    cout << "\n--- Tous les clients ---" << endl;
    gestion.afficherTous();

    // Modifier les nationalit�s du client 1
    set<string> nouvellesNat;
    nouvellesNat.insert("Tunisienne");
    nouvellesNat.insert("Alg�rienne");

    vector<string> vecNouvellesNat(nouvellesNat.begin(), nouvellesNat.end());
    gestion.modifierNationalites(1, vecNouvellesNat);

    // Supprimer une nationalit�
    gestion.supprimerNationalite(2, "Allemande");

    // Affichage final
    cout << "\n--- Apr�s modifications ---" << endl;
    gestion.afficherTous();
	system("pause");
    return 0;
}
