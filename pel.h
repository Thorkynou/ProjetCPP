
/***************************************************/
/****          Plan Epargne Logement            ****/
/****              Marc Abeille                 ****/
/***************************************************/

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

    void AfficherPEL(ostream & out);

    void CreerPel();

    bool Ajouter(double mtt);
    void ModifMontantMensuel();
    void TempsRestantEmprunt();
    void MontantEmpruntable();
    void EcritureFichier()const;
    void AfficherIndice()const;
    void RechercheParIndice(vector<Pel>&mesPel,int indice);
    void CalculInteret(double mttTotal, double &mttInterets,int nbAnnees);

    friend ostream &operator<<(ostream &out, Pel &P);

};

void ExtractionFichier(vector<Pel>&mesPel);
void ReecritureFichier(const vector<Pel>&mesPel);
void ConversionStoAJ(int nbSecondes,int &years,int &days);

#endif

