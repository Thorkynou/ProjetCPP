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
    double taux3Mois;//taux pour les 3 premiers mois du compte
    double taux;//taux pour les mois suivant les 3 premiers mois
public :
    ecompte(string eml = "vide" ,string nt = "vide" ,double tm =0,double t =0);//constructeur par parametre par defaut
    ecompte(const ecompte & E);//constructeur par copie


    ~ecompte();//destructeur
    //virtual void Afficher();

    ecompte &CreerCompte();
};

#endif
