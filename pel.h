#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstddef>
#include <cstdlib>
#include "date.h"

using namespace std;

#ifndef PEL_H
#define PEL_H

class Pel: public date
{
public:
    double versementMensuel;
    int tauxEmprunt;
    double soldePel;
    int indice;

    Pel(double vm=0,int te=0, int i=0, double sp=0,time_t datePel=time(NULL));
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
    void RechercheParIndice(vector<Pel>&mesPel,int indice);

    friend ostream &operator<<(ostream &out, const Pel &P);

};

void ExtractionFichier(vector<Pel>&mesPel);
void ReecritureFichier(const vector<Pel>&mesPel);


#endif

