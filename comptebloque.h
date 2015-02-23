/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: comptebloque.h                        *
 * @author: Clément L                             *
 **************************************************/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstddef>
#include <cstdlib>
#include "date.h"

#ifndef COMPTEBLOQUE_H
#define COMPTEBLOQUE_H

using namespace std;

class CompteBloque: public date
{
public:
	double taux; // Le taux du compte

	double solde; // Son solde

	int indice; // Son indice

	double annees; // Années passées (pour application du taux)


	// Constructeur par paramètres
	CompteBloque(time_t dateCB=time(NULL), int indice = 0, double taux = 0, double solde = 0, double annees = 0);

	// Constructeur par copie
	CompteBloque(const CompteBloque &CB);

	// Destructeur
	~CompteBloque(){cout << "Destru Compte Bloque";};

	// Fonction de création de compte
	void CreerCompte();

	// Fonction d'affichage
	void Afficher(ostream & out);

	// Fonction ajoutant 'n' au solde
	void Ajouter(double n);

	// Fonction retirant 'n' au solde (si RetraitPossible)
	void Retirer(double n);

	// Fonction d'écriture dans un fichier
	void EcritureFichier();

	// Fonction d'affichage de l'indice (pour test)
    void AfficherIndice()const;

    // Fonction de recherche par indice
    void RechercheParIndice(vector<CompteBloque>&mesCB, int indice);

    // Fonction d'affichage (surcharge de '<<')
    friend ostream &operator<<(ostream &out, CompteBloque &CB);

    // Autorise le retrait
    bool RetraitPossible();

    // Fonction de conversion du temps restant
    void ConversionStoAJ(int nbSecondes,int &years,int &days);

    // Fonction d'affichage du temps restant
    void TempsRestant();

    // Calcul des interets
    double CalculTaux();

    // Applique les interets
    void AppliquerTaux();
};

void ExtractionFichier(vector<CompteBloque>&mesCB);

void ReecritureFichier(const vector<CompteBloque>&mesCB);

#endif