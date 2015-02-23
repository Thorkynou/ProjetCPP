/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: client.h                              *
 * @author: Benedicte, reprit par Clément L       *
 **************************************************/

#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

#ifndef DATE_H
#define DATE_H

class date
{
public:
    int jour;
    int mois;
    int an;
    time_t dateJ;


	date();

    date(time_t date);

    date(const date & copie);
	
    virtual ~date(){};//detsructeur par defaut

    void MiseAJour();

    void AfficherDate(const time_t &dateJ);

    void Conversion(int &jour, int &mois, int &an);
};


#endif // DATE_H
