#include <iostream>
#include <string>
using namespace std;

#ifndef ECOMPTE_H
#define ECOMPTE_H

class ECompte //, public GeneraliteCompte
{
private:
    string email; //si temps vérif @ présent et (dot) présent aussi
    int numTel[10]; //penser a vérifier que le l'utilisateur a saisit 10 chiffres pas plus/moins (voire si temps commence 0)
    double taux3Mois;//taux pour les 3 premiers mois du compte
    double taux;//taux pour les mois suivant les 3 premiers mois
public :
    ECompte(string mail = "vide",int numTel[10]={} ,double tmois =0,double t =0);//constructeur par parametre par defaut
    ECompte(const ECompte & E);//constructeur par copie
    virtual ~ECompte(){};//destructeur

    ECompte CreerCompte();
};

#endif
