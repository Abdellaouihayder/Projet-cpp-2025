#include <typeinfo>
#include "Tache.h"  
#include "AssistantSocial.h"
#include "client.h"
#include "AssistantSpecialiste.h"
#include "Employe.h"
#include "GestionEquipe.h"
#include "Receptionniste.h"
#include "Specialisation.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include "GestionNationalite.h"
#include <set>
#include <map>
#include <algorithm> 
#include <sstream>  
#include <list>

using namespace std;

//gestion des nationalites implementation
template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::ajouterNationalite(const IDType &idClient, const NationaliteType &nationalite)
{
    ClientNationalite[idClient].insert(nationalite);
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::ajouterNationalites(const IDType &idClient, const vector<NationaliteType> &nationalites)
{
    for (typename vector<NationaliteType>::const_iterator it = nationalites.begin(); it != nationalites.end(); ++it)
    {
        ClientNationalite[idClient].insert(*it);
    }
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::supprimerNationalite(const IDType &idClient, const NationaliteType &nationalite)
{
    typename map<IDType, set<NationaliteType> >::iterator it = ClientNationalite.find(idClient);
    if (it != ClientNationalite.end())
    {
        it->second.erase(nationalite);
        if (it->second.empty())
        {
            ClientNationalite.erase(it);
        }
    }
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::modifierNationalites(const IDType &idClient, const vector<NationaliteType> &nouvellesNationalites)
{
    set<NationaliteType> nouvellesSet(nouvellesNationalites.begin(), nouvellesNationalites.end());
    ClientNationalite[idClient] = nouvellesSet;
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::afficherNationalites(const IDType &idClient)
{
	//algorithme find 
    typename map<IDType, set<NationaliteType> >::iterator it = ClientNationalite.find(idClient);
    if (it != ClientNationalite.end())
    {
        cout << "Client " << idClient << " a les nationalitï¿½s : ";
        for (typename set<NationaliteType>::const_iterator nat = it->second.begin(); nat != it->second.end(); ++nat)
        {
            cout << *nat << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Aucune nationalitï¿½ trouvï¿½e pour le client " << idClient << endl;
    }
}

template <typename IDType, typename NationaliteType>
struct CompareByID
{
    bool operator()(const pair<IDType, set<NationaliteType> >& a, const pair<IDType, set<NationaliteType> >& b) const
    {
        return a.first < b.first;
    }
};

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::afficherTous()
{
    vector< pair<IDType, set<NationaliteType> > > elements(ClientNationalite.begin(), ClientNationalite.end());
    //Algorithe de Trier
    sort(elements.begin(), elements.end(),CompareByID<IDType, NationaliteType>());
    for (typename vector< pair<IDType, set<NationaliteType> > >::iterator it = elements.begin(); it != elements.end(); ++it)
    {
        cout << "Client " << it->first << " : ";
        for (typename set<NationaliteType>::const_iterator nat = it->second.begin(); nat != it->second.end(); ++nat)
        {
            cout << *nat << " ";
        }
        cout << endl;
    }
}


template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::enregistrerNationaliteDansFichier(const string &nomFichier)
{
    ofstream fichier(nomFichier.c_str(), ios::out | ios::app);  

    if (!fichier.is_open())
    {
        cerr << "Erreur : impossible d'ouvrir le fichier \"" << nomFichier << "\" pour l'écriture." << endl;
        return;
    }

    typename map<IDType, set<NationaliteType> >::iterator it;
    for (it = ClientNationalite.begin(); it != ClientNationalite.end(); ++it)
    {
        fichier << it->first << ":";
        typename set<NationaliteType>::const_iterator natIt;
        for (natIt = it->second.begin(); natIt != it->second.end(); ++natIt)
        {
            fichier << " " << *natIt;
        }
        fichier << endl;
    }

    fichier.close();
}

template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::afficherIDs() {
    // Créer une liste pour stocker les IDs
    list<IDType> ids;

    // Parcours de la map pour ajouter les IDs dans la liste
    for (typename map<IDType, set<NationaliteType> >::iterator it = ClientNationalite.begin(); it != ClientNationalite.end(); ++it) {
        ids.push_back(it->first);  // Ajouter l'ID à la liste
    }

    // Afficher les IDs stockés dans la liste
    cout << "Liste des IDs des clients : " << endl;
    for (typename list<IDType>::iterator it = ids.begin(); it != ids.end(); ++it) {
        cout << *it << " ";  // Affiche l'ID
    }
    cout << endl;
}

// Charger les taches depuis un fichier
template <typename IDType, typename NationaliteType>
void GestionDesNationalites<IDType, NationaliteType>::chargerNationaliteDepuisFichier(const string &nomFichier)
{
    ifstream fichier(nomFichier.c_str());
    if (!fichier.is_open()) { exit(-4); }
    if (fichier)
    {
        string ligne;
        while (getline(fichier, ligne))
        {
            istringstream iss(ligne);
            IDType idClient;
            string deuxPoints;

            // Lire l'ID et ignorer le ':'
            if (!(iss >> idClient >> deuxPoints) || deuxPoints != ":")
                continue;

            set<NationaliteType> nationalites;
            NationaliteType nat;
            while (iss >> nat)
            {
                nationalites.insert(nat);
            }

            ClientNationalite[idClient] = nationalites;
        }
        fichier.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier pour la lecture." << endl;
    }
}

// Lien entre la déclaration du template et la définition du template
template class GestionDesNationalites<int, string>;


