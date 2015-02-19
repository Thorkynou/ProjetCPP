//creation du fichier date.cpp
//realise par benedicte

#include "date.h"

date::date()// constructeur par defaut
    {
        cout<<"+++++++++++++Voici le constructeur par defaut de la date\n";
        jour=18;
        mois=02;
        an=2015;
        cout<<endl;
    }
/*
date::date(int j,int m,int an)
    {
        cout<<"+++++++++++++Voici le constructeur par parametres de la date\n";
       jour=j;
        mois=m;
       this->an=an;
        cout<<endl;
    }
*/
void date::Saisir()//saisie de la date du jour
    {
        cout<<"\nSaisir le jour, puis le mois et enfin l'annee\n";//saisie de la date d'operation
        cin>>jour>>mois>>an;
        cout<<endl;
    }

void date::Afficher()//affiche la date du jour
    {
        cout<<"\nNous sommes le\t"<<jour<<"/"<<mois<<"/"<<an<<"\n";
        cout<<endl;
    }

date::date(const date & acopier)
    {
        cout<<"+++++++++++++Voici le constructeur par copie de la date\n";
        jour=acopier.jour;
        mois=acopier.mois;
        an=acopier.an;

    }

date::~date()//detsructeur par defaut
    {
        cout<<"--------------Destruction de la classe date\n";
        cout<<endl;
    }


