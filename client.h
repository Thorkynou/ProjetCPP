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
#include "pel.h"
#include "ecompte.h"
#include "livretepargne.h"
#include "comptebloque.h"



#ifndef CLIENT_H
#define CLIENT_H
using namespace std;

class Client
{
public:
	int indice; // indice du client
	string nom;  // son nom
	string prenom; // son prénom
	string adresse; // son adresse
	comptecourant compteC; // son compte courant
	Pel comptePEL; // son compte PEL
	ecompte compteEC; // son e-compte
	LivretEpargne compteLE; // son livret epargne
	CompteBloque compteCB; // son compte bloqué
	bool LE; // booléen vérifiant l'état du compte sur livret
	bool CB; // booléen vérifiant l'état du compte bloqué
	bool PEL; // booléen vérifiant l'état du PEL
	bool EC; // booléen vérifiant l'état de l'e-compte


	// Constructeur par paramètres
	Client(int indice = 0, string nom = "vide", string prenom = "vide", string adresse = "vide", bool LE = false, bool CB = false, bool PEL = false, bool EC = false);

	// Constructeur par copie
	Client(const Client &C);

	// Fonction de saisie
	void Saisir(istream &in);

	// Destructeur
	~Client();

	// Fonction d'affichage
	void Afficher(ostream &out) const;

	//Fonction de modification de l'adresse
	void ModifierAdresse(string adresse);

	// Surcharge de l'operator '='
	Client &operator=(const Client &C);

	// Surcharge de l'operator '<<'
	friend ostream &operator<<(ostream &out, const Client &C);

	// Surcharge de l'operator '>>'
	friend istream &operator>>(istream &in, Client &C);

	// Fonction pour la création de PEL
	void CreationPEL();

	// Fonction pour la destruction de PEL
	void DestructionPEL();

	// Fonction pour la création de LE
	void CreationLE();

	// Fonction pour la destruction de LE
	void DestructionLE();

	// Fonction pour la création de CB
	void CreationCB();

	// Fonction pour la destruction de CB
	void DestructionCB();

	// Fonction pour la création de EC
	void CreationEC();

	// Fonction pour la destruction de EC
	void DestructionEC();

	// Fonction pour ajouter N au solde du PEL
	void AjoutPEL(double N);

	// Fonction pour ajouter N au solde du LE
	void AjoutLE(double N);

	// Fonction pour ajouter N au solde du CB
	void AjoutCB(double N);

	void RetirerLE(double N);
	void RetirerCB(double N);
	// Fonction pour l'écriture dans un fichier
	void EcritureFichier()const;

	// Fonction pour rechercher un client par son indice
	void RechercheParIndice(vector<Client>&mesClients,int indice);
};

// Fonction qui récupère les données dans le fichier pour les mettre dans une classe
void ExtractionFichier(vector<Client>&mesClients);

// Fonction réécrivant les modifications en créant un autre fichier
void ReecritureFichier(const vector<Client>&mesClients);


#endif
