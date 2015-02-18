/* client.cpp */

#include "client.h"

Client::Client(string nom, string prenom, string adresse, bool CC, bool LE, bool CB, bool PEL, bool EC);
{
	this->nom = nom; 
	this->prenom = prenom;
	this->adresse = adresse;
}

Client::Client(const Client &C)
{
	nom = C.nom;
	prenom = C.prenom;
	adresse = C.adresse;
	CC = C.CC;
	LE = C.LE;
	CB = C.CB;
	PEL = C.PEL;
	EC = C.EC;
}