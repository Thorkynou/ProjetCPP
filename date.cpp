//creation du fichier date.cpp
//realise par benedicte

#include "date.h"

date::date()// constructeur par defaut
{
    memset(&t, 0, sizeof(t));
    cout<<"+++++++++++++Voici le constructeur par defaut de la date\n";
    time_t now = time(NULL);
    t=*localtime(&now);
    jour = t.tm_mday;
    mois = t.tm_mon+1;
    an = t.tm_year+1900;
    cout<<endl;
}

date::date(int j,int m,int an)
    {
        this->jour = j;
        this->mois = m;
        this->an = an;
    }

void date::Saisir()
{
    cout << "Entrez la date de création sous la forme: jj mm aaaa" << endl;
    cin >> jour >> mois >> an;
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


