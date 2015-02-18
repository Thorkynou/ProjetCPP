/* client */

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "comptecourant.h"

using namespace std;

class Client
{
private:
	nom;
	prenom;
	adresse;
	bool CC;
	bool LE;
	bool CB;
	bool PEL;
	bool EC;
public: 
	Client(string nom, string prenom, string adresse, bool CC = true, bool LE = false, bool CB = false, bool PEL = false, bool EC = false);

	Client(const Client &C);

	~Client(){};
};


#endif