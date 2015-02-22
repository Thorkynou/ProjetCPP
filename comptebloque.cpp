/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: comptebloque.cpp                      *
 * @author: Clément L                             *
 **************************************************/

#include "comptebloque.h"

CompteBloque::CompteBloque(time_t dateCB, int indice, double taux, double solde): date(dateCB)
{
	this->indice = indice;
	this->taux = taux;
	this->solde = solde;
}

CompteBloque::CompteBloque(const CompteBloque &CB)
{
	indice = CB.indice;
	taux = CB.taux;
	solde = CB.solde;
}

void CompteBloque::CreerCompte()
{
	cout << "Creation d'un compte bloque" << endl;
	cout << "Saisir un taux: " << endl;
	cin >> this->taux;
	EcritureFichier();
}

double CompteBloque::CalculInterets()
{
	return(this->solde = (this->solde) * (this->taux) / 100);
}

void CompteBloque::Afficher()
{
	cout << endl << "Affichage du compte bloque" << endl;
	cout << "Taux : " << taux << endl;
	cout << "Solde : " << solde << endl << endl;
}

void CompteBloque::AfficherIndice()
{
	cout<<"L'indice CB est: "<<this->indice<<endl;
}

void CompteBloque::Ajouter(double n)
{
	this->solde = this->solde + n;
}

void CompteBloque::EcritureFichier()
{
	ofstream monFichier;
	monFichier.open("CB.txt",ofstream::app);
	MiseAJour();
	monFichier << this->indice << ";" << this->taux << ";" << this->solde << ";" << dateJ << endl;
	monFichier.close();
}