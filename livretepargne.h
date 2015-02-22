//projet3
//classe Livret Epargne realisee pas Alain


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstddef>
#include <cstdlib>

using namespace std;

#ifndef LIVRETEPARGNE_H
#define LIVRETEPARGNE_H

class LivretEpargne
{
private:
double solde;
double taux;
double plafondDepot;

public:

LivretEpargne(); //constructeur par defaut
LivretEpargne(double solde ,double taux = 1.5, double plafond = 25000);//constructeur par parametre
LivretEpargne(const LivretEpargne & LE);//constructeur par copie
~LivretEpargne();//destructeur
LivretEpargne & operator=(const LivretEpargne & LE);
LivretEpargne operator+(double N);
LivretEpargne &CreerCompte();
void EcritureFichier()const;
void Ajouter();//ajouter de l'argent dans le livret épargne
void CalculInterets(double N);
void MiseAJour();//cad nouveau solde avec les interets rajoutes
void Afficher();//affiche le livret epargne

};

#endif
