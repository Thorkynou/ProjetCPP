#include <iostream>
#include <string>

using namespace std;

#ifndef PEL_H
#define PEL_H

class Pel: public GeneraliteCompte
{
private:
    double versementMensuel;
    int tauxEmprunt;

public:

    Pel(double vm=0,int te=0);
    virtual ~Pel();

    virtual void Afficher();

    void VersementExept();
    void ModifMontantMensuel();
    void TempsRestant();
    void MontantEmpruntable();

};

#endif

