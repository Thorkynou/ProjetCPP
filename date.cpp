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

void date::Saisir(istream &in)
{
    cout << "Entrez la date de création sous la forme: jj mm aaaa" << endl;
    in >> jour >> mois >> an;
}

void date::Afficher(ostream &out) const//affiche la date du jour
{
    out<<"\nNous sommes le\t"<<jour<<"/"<<mois<<"/"<<an<<"\n";
    out<<endl;
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

date &date::operator=(const date &D)
{
    jour = D.jour;
    mois = D.mois;
    an = D.an;
    return (*this);
}

ostream &operator<<(ostream &out, const date &D)
{
    D.Afficher(out);
    return out;
}

istream & operator>>(istream &in, date &D)
{
    D.Saisir(in);
    return in;
}

