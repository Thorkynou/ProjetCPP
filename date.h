//creation du fichier date.h
//realise par benedicte, repris par Clement L

#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

#ifndef DATE_H
#define DATE_H

class date
{
private:
	/*struct tm t;
    int jour;
    int mois;
    int an;*/

protected:
    time_t dateJ;


public:

	date();
    date(time_t date);
    date(const date & copie);
	/*date (int j,int m,int an);//constructeur par parametres par defaut-->ok testé
	date(const date & acopier);//constructeur par copie
    void Saisir(istream &in);//saisie de la date du jour
    void Afficher(ostream &out) const;//affiche la date du jour*/

    virtual ~date(){};//detsructeur par defaut

    void MiseAJour();

    /*date &operator=(const date &D);

    friend ostream & operator<<(ostream &out, const date &D);

    friend istream & operator>>(istream &in, date &D);

    time_t Conversion();*/
};


#endif // DATE_H
