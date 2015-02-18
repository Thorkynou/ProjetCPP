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

    date();// constructeur par defaut
    date (int jour, int mois, int an);//constructeur par parametres
    void Saisir();//saisie de la date du jour
    void Afficher();//affiche la date du jour

    ~date();//detsructeur par defaut

};
#endif // DATE_H
