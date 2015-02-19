//projet3
//classe Livret Epargne realisee pas Alain


#include <iostream>
#include <string>

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
LivretEpargne operator+(double N);
~LivretEpargne();//destructeur
void Ajouter(double Somme);//ajouter de l'argent dans le livret épargne
void CalculInterets();
void MiseAJour();//cad nouveau solde avec les interets rajoutes
void Afficher();//affiche le livret epargne

};

#endif
