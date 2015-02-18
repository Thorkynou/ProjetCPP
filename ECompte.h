#include <iostream>
#include <string>
using namespace std;

#ifndef Ecompte_H
#define ECompte_H

class ECompte , public GeneraliteCompte
{
private:
    string email; //si temps vérif @ présent et (dot) présent aussi
    int numTel[10]; //penser a vérifier que le l'utilisateur a saisit 10 chiffres pas plus/moins (voire si temps commence 0)
    double taux3Mois;
    double taux;
};

