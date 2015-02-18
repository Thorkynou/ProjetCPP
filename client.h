/**************************************************
 *                  Projet C++                    *           
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: client.h                              *
 * @author: Clément L                             *
 **************************************************/

#include <iostream>
#include <string>
//#include "comptecourant.h"

#ifndef CLIENT_H
#define CLIENT_H
using namespace std;

class Client
{
private:
	//CompteCourant compteC;
	string nom;
	string prenom;
	string adresse;
	bool CC;
	bool LE;
	bool CB;
	bool PEL;
	bool EC;
public: 
	// Constructeur par paramètres
	Client(string nom = "vide", string prenom = "vide", string adresse = "vide", bool CC = false, bool LE = false, bool CB = false, bool PEL = false, bool EC = false);

	// Constructeur par copie
	Client(const Client &C);

	//Destructeur
	virtual ~Client(){};

	virtual void Afficher(ostream &out) const;

	virtual void ModifierAdresse(string adresse);

	Client &operator=(const Client &C);
};


#endif