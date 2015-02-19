//projet3
//classe Livret Epargne realisee pas Alain


#include <iostream>
#include <string>

using namespace std;

#include "livretepargne.h"

LivretEpargne::LivretEpargne() //constructeur par defaut
{
cout<<"je suis dans le constructeur par defaut de livret epargne"<<endl;
solde=0;
taux =1.5;
plafondDepot = 7700;
}

LivretEpargne::LivretEpargne(double solde ,double taux , double plafond )//constructeur par parametre
{
cout<< "je suis dans le constructeur par parametres de livret epargne"<<endl;
this -> solde = solde;
this -> taux =taux;
plafondDepot=plafond;
}

LivretEpargne::LivretEpargne(const LivretEpargne & LE)//constructeur par copie
{
cout<< "je suis dans le constructeur par copie de livret epargne"<< endl;
solde = LE.solde;
taux = LE.taux;
plafondDepot= LE.plafondDepot;
}


LivretEpargne::~LivretEpargne()//destructeur
{
cout << "je suis dans le destructeur de livret epargne"<< endl;
};//destructeur


void LivretEpargne::Afficher()
{
cout << "le sodle de ce livret epargne est de "<<solde<<endl;
cout << "son taux d'interets est de "<< taux<< endl;
cout << "et son plafond de depot est de " << plafondDepot<< "euros"<<endl;
}


LivretEpargne LivretEpargne:: operator+(double N)
{
LivretEpargne LE= *this;
LivretEpargne.solde= LE.solde+N;
return LE;
}




/*
Ajouter();//ajouter de l'argent dans le livret épargne
void CalculInterets();
void MiseAJour();//cad nouveau solde avec les interets rajoutes
*/



