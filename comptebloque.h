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
	double taux;
	double solde;

public:
	int indice;

	CompteBloque(time_t dateCB=time(NULL), int indice = 0, double taux = 0, double solde = 0);

	CompteBloque(const CompteBloque &CB);

	~CompteBloque(){cout << "Destru Compte Bloque";};

	void CreerCompte();

	double CalculInterets();

	void Afficher(ostream & out);

	void Ajouter(double n);

	void Retirer(double n);

	void EcritureFichier();

    void AfficherIndice()const;

    void RechercheParIndice(vector<CompteBloque>&mesCB, int indice);

    friend ostream &operator<<(ostream &out, CompteBloque &CB);

    bool RetraitPossible();

    void AffichageTempsRestant();

    void ConversionStoAJ(int nbSecondes,int &years,int &days);
};

void ExtractionFichier(vector<CompteBloque>&mesCB);

void ReecritureFichier(const vector<CompteBloque>&mesCB);

#endif