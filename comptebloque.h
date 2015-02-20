/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: comptebloque.h                        *
 * @author: Clément L                             *
 **************************************************/


#include <iostream>
#include <string>

using namespace std;

class CompteBloque
{
private:
	double taux;
	double plafondDepot;
	double solde;

public:
	CompteBloque(double taux = 0, double plafondDepot = 10000, double solde = 0);

	CompteBloque(const CompteBloque &CB);

	~CompteBloque(){};

	CompteBloque &CreerCompte();

	void Ajouter(CompteBloque &CB);

	void CalculInterets();

	void Afficher();

	void Ajouter(double n);
};
