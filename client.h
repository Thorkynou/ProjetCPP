/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: client.h                              *
 * @author: Clément L                             *
 **************************************************/

#include <iostream>
#include <string>
#include "comptecourant.h"
#include "date.h"
#include "pel.h"
#include "ecompte.h"
#include "livretepargne.h"



#ifndef CLIENT_H
#define CLIENT_H
using namespace std;

class Client
{
private:
	string nom;
	string prenom;
	string adresse;
public:
	date D;
	comptecourant compteC;
	Pel comptePEL;
	ecompte compteEC;
	LivretEpargne compteLE;
	bool CC;
	bool LE;
	bool CB;
	bool PEL;
	bool EC;
public:
	// Constructeur par paramètres
	Client(string nom = "vide", string prenom = "vide", string adresse = "vide", bool CC = true, bool LE = false, bool CB = false, bool PEL = false, bool EC = false);

	// Constructeur par copie
	Client(const Client &C);

	void Saisir(istream &in);

	//Destructeur
	virtual ~Client();

	virtual void Afficher(ostream &out) const;

	virtual void ModifierAdresse(string adresse);

	Client &operator=(const Client &C);

	friend ostream &operator<<(ostream &out, const Client &C);

	friend istream &operator>>(istream &in, Client &C);

	void CreationPEL();

	void DestructionPEL();

	void CreationLE();

	void DestructionLE();

	void CreationCB();

	void DestructionCB();

	void CreationEC();

	void DestructionEC();

	void AjoutPEL(double N);

	void AjoutLE(double N);

	//void AjoutCB(double N);

	void AjoutEC(double N);
;};


#endif
