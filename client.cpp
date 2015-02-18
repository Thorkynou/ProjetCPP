/**************************************************
 *                  Projet C++                    *           
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: client.cpp                            *
 * @author: Clément L                             *
 **************************************************/


#include <iostream>
#include <string>
#include "client.h"
using namespace std;

Client::Client(string nom, string prenom, string adresse, bool CC, bool LE, bool CB, bool PEL, bool EC)
{
	cout << "constructeur par paramètres" << endl;
	this->nom = nom; 
	this->prenom = prenom;
	this->adresse = adresse;
	this->CC = CC;
	this->LE = LE;
	this->CB = CB;
	this->PEL = PEL;
	this->EC = EC;
}

Client::Client(const Client &C)
{
	cout << "constructeur par copie" << endl;
	nom = C.nom;
	prenom = C.prenom;
	adresse = C.adresse;
	CC = C.CC;
	LE = C.LE;
	CB = C.CB;
	PEL = C.PEL;
	EC = C.EC;
}

void Client::Afficher(ostream &out) const
{
	out << "Nom : " << nom << endl;
	out << "Prenom : " << prenom << endl;
	out << "Adresse : " << adresse << endl;
	out << endl;
	if(CC)
		out << "a un compte courant" << endl;
	if(LE)
		out << "a un livret d'epargne" << endl;
	if(CB)
		out << "a un compte bloque" << endl;
	if(PEL)
		out << "a un PEL" << endl;
	if(EC)
		out << "a un e-compte" << endl;
}

void Client::ModifierAdresse(string adresse)
{
	this->adresse = adresse;
}

Client & Client::operator=(const Client &C)
{
	cout << "utilisation d'operator=" << endl;
	nom = C.nom;
	prenom = C.prenom;
	adresse = C.adresse;
	CC = C.CC;
	LE = C.LE;
	CB = C.CB;
	PEL = C.PEL;
	EC = C.EC;
	return (*this);
}