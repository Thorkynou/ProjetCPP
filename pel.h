#include <iostream>
#include <string>

using namespace std;

#ifndef PEL_H
#define PEL_H

class Pel//: public GeneraliteCompte
{
private:
    double versementMensuel;
    int tauxEmprunt;

public:

    Pel(double vm=0,int te=0);
    Pel(const Pel & monPel);

    virtual ~Pel(){};

    virtual void Afficher();

    Pel CreerCompte();

    void VersementExept();
    void ModifMontantMensuel();
    void TempsRestant();
    void MontantEmpruntable();

};

#endif

