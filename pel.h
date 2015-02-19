#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "client.h"

#ifndef PEL_H
#define PEL_H

class Pel: public Client
{
private:
    double versementMensuel;
    int tauxEmprunt;
    double soldePel;

public:

    Pel(double vm=0,int te=0);
    Pel(const Pel & monPel);

    /*virtual*/ ~Pel(){};

    /*virtual*/ void Afficher();

    Pel CreerCompte();

    void VersementExept(Pel & monPel);
    void ModifMontantMensuel();
    void TempsRestant();
    void MontantEmpruntable();
    void EcritureFichier()const;

};

#endif

