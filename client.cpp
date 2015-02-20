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

Client::Client(string nom, string prenom, string adresse, bool CC, bool LE, bool CB, bool PEL, bool EC): compteC(), D()
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
	compteC = C.compteC;
}

void Client::Saisir(istream &in)
{
    cout << "Entrez le nom du client" << endl;
    in >> nom;
    cout << "Son prenom" << endl;
    in >> prenom;
    cout << "Son adresse" << endl;
    in.ignore();
    getline(in, adresse);
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

Client::~Client()
{
	cout<<"destructeur du client" << endl;
}

ostream & operator<<(ostream &out, const Client &C)
{
	C.Afficher(out);
	return out;
}

istream & operator>>(istream &in, Client &C)
{
	C.Saisir(in);
	return in;
}

void Client::CreationPEL()
{
	this->PEL = true;
	this->comptePEL.CreerPel();
}

void Client::DestructionPEL()
{
	this->PEL = false;
}

void Client::CreationLE()
{
	this->LE = true;
	this->compteLE.CreerCompte();
}

void Client::DestructionLE()
{
	this->LE = false;
}

/*void Client::CreationCB()
{
	this->CB = true;
	this->compteCB.Creer();
}*/

void Client::DestructionCB()
{
	this->CB = false;
}

void Client::CreationEC()
{
	this->EC = true;
	this->compteEC.CreerCompte();
}

void Client::DestructionEC()
{
	this->EC = false;
}

void Client::AjoutPEL(double N)
{
	this->compteC.Retirer(N);
	this->comptePEL.Ajouter(N);
}

void Client::AjoutLE(double N)
{
	this->compteC.Retirer(N);
	this->compteLE.Ajouter(N);
}

/*void Client::AjoutCB(double N)
{
	this->compteC.Retirer(N);
	this->compteCB.Ajouter(N);
}*/

void Client::AjoutEC(double N)
{
	this->compteC.Retirer(N);
	this->compteEC.Ajout(N);
}