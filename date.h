//creation du fichier date.h
//realise par benedicte

#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class date
{
private:
    int jour;
    int mois;
    int an;

public:

   date();// constructeur par defaut-->ok testé
   //date (int j=18,int m=02,int an=2015);//constructeur par parametres par defaut-->ok testé
   date(const date & acopier);//constructeur par copie
    void Saisir();//saisie de la date du jour
    void Afficher();//affiche la date du jour

    ~date();//detsructeur par defaut

};
#endif // DATE_H
