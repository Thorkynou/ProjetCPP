//creation du fichier date.cpp
//realise par benedicte

#include "date.h"

date::date()// constructeur par defaut
    {
        cout<<"voici le constructeur par defaut de la date\n";
        cout<<endl;
    }


void date::Saisir()//saisie de la date du jour
    {
        cout<<"Saisir le jour, puis le mois et enfin l'annee\n";//saisie de la date d'operation
        cin>>jour>>mois>>an;
        cout<<endl;
    }

void date::Afficher()//affiche la date du jour
    {
        cout<<"nous sommes le"<<jour<<"/"<<mois<<"/"<<an;
        cout<<endl;
    }

date::~date()//detsructeur par defaut
    {
        cout<<"destruction de la classe date\n";
        cout<<endl;
    }


