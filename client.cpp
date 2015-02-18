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
}

void Client::ModifierAdresse(string adresse)
{
	this->adresse = adresse;
}
