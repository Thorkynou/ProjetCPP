#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef PEL_H
#define PEL_H

class Pel//: public Client
{
private:
    double versementMensuel;
    int tauxEmprunt;
    double soldePel;

public:

    Pel(double vm=0,int te=0);
    Pel(const Pel & monPel);

    ~Pel(){};

    void AfficherPEL(ostream & out)const;

    void CreerPel();

    void Ajouter(double mtt);
    void ModifMontantMensuel();
    void TempsRestant();
    void MontantEmpruntable();
    void EcritureFichier()const;

    friend ostream &operator<<(ostream &out, const Pel &P);
};



#endif

