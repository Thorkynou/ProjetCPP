#include <iostream>
#include <string>

using namespace std;

#include "generalitecompte.h"
#ifndef LIVRETEPARGNE_H
#define LIVRETEPARGNE_H

class LivretEpargne : public GeneraliteCompte
{
private:
double taux;
double plafondDepot;

public:
Ajouter();
CalculInterets();
MiseAJour();

};
