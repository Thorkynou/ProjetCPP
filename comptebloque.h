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
#include "date.h"

#ifndef COMPTEBLOQUE_H
#define COMPTEBLOQUE_H

using namespace std;

class CompteBloque: public date
{
private:
	double taux;
	double solde;

public:
	int indice;

	CompteBloque(time_t dateCB=time(NULL), int indice = 0, double taux = 0, double solde = 0);

	CompteBloque(const CompteBloque &CB);

	~CompteBloque(){cout << "Destru Compte Bloque";};

	void CreerCompte();

	double CalculInterets();

	void Afficher();

	void AfficherIndice();

	void Ajouter(double n);

	void EcritureFichier();
};

#endif