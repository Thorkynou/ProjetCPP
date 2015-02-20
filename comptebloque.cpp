/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: comptebloque.cpp                      *
 * @author: Clément L                             *
 **************************************************/

#include "comptebloque.h"

CompteBloque::CompteBloque(double taux, double plafondDepot, double solde)
{
	this->taux = taux;
	this->plafondDepot = plafondDepot;
	this->solde = solde;
}

CompteBloque::CompteBloque(const CompteBloque &CB)
{
	taux = CB.taux;
	plafondDepot = CB.plafondDepot;
	solde = CB.solde;
}

CompteBloque &CompteBloque::CreerCompte()
{
	cout << "Creation d'un compte bloque" << endl;
	cout << "Saisir un taux: " << endl;
	cin >> this->taux;
	cout << "Saisir le plafond de depot: " << endl;
	cin >> this->plafondDepot;
	return (*this);
}

void CompteBloque::Afficher()
{
	cout << endl << "Affichage du compte bloque" << endl;
	cout << "Taux : " << taux << endl;
	cout << "Plafond de depot :" << plafondDepot << endl;
	cout << "Solde : " << solde << endl << endl;
}

void CompteBloque::Ajouter(double n)
{
	this->solde = this->solde + n;
}