#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef PEL_H
#define PEL_H

class Pel
{
private:
    double versementMensuel;
    int tauxEmprunt;
    double soldePel;

public:

    int indice;

    Pel(double vm=0,int te=0, int indice=0);
    Pel(const Pel & monPel);

    ~Pel(){};

    void AfficherPEL(ostream & out)const;

    void CreerPel();

    void Ajouter(double mtt);
    void ModifMontantMensuel();
    void TempsRestant();
    void MontantEmpruntable();
    void EcritureFichier()const;
    void AfficherIndice()const;

    friend ostream &operator<<(ostream &out, const Pel &P);
};



#endif

