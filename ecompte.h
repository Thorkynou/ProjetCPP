/*
00888880080000008888800880880088888008800008008888888000008888800 
00800000080000008000000808080080000008080008000008000000008000000 
00800000080000008880000800080088880008008008000008000000008888800 
00800000080000008000000800080080000008000808000008000000000000800 
00888880088888008888800800080088888008000088000008000008008888800 

Ctrl+f , 8 , enter                 
*/
#include <iostream>
#include <string>
using namespace std;

#ifndef ECOMPTE_H
#define ECOMPTE_H

class ecompte //, public GeneraliteCompte
{
private:
	string email; //si temps vérif @ présent et (dot) présent aussi
	string numTel; //penser a vérifier que le l'utilisateur a saisit 10 chiffres pas plus/moins (voire si temps commence 0)
	double solde;
	double taux3Mois;//taux pour les 3 premiers mois du compte
	double taux;//taux pour les mois suivant les 3 premiers mois

public :
	ecompte(string eml = "vide" ,string nt = "vide" ,double s=50, double tm =4.5,double t =1.5);//constructeur par parametre par defaut
	ecompte(const ecompte & E);//constructeur par copie


	~ecompte();//destructeur
	void AfficherSolde(ostream & out);
	void AfficherCompte();
	void Retrait();
	void Ajouter(ecompte & E);
	ecompte &CreerCompte();
};

#endif
