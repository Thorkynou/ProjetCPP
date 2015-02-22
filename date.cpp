//creation du fichier date.cpp
//realise par benedicte, repris par Clement L.

#include "date.h"

date::date()// constructeur par defaut
{
    /*memset(&t, 0, sizeof(t));
    cout<<"+++++++++++++Voici le constructeur par defaut de la date\n";
    time_t now = time(NULL);
    t=*localtime(&now);
    jour = t.tm_mday;
    mois = t.tm_mon+1;
    an = t.tm_year+1900;
    cout<<endl;*/
    cout << "----------------------------------" << endl;
    cout << "    constructeur defaut date" << endl;
    cout << "----------------------------------" << endl;
    this->dateJ = time(NULL);
}

/*date::date(int j,int m,int an)
{
    this->jour = j;
    this->mois = m;
    this->an = an;
}*/

date::date(time_t date)
{
    cout << "----------------------------------" << endl;
    cout << "    constructeur param date" << endl;
    cout << "----------------------------------" << endl;
    this->dateJ = date;
}

date::date(const date & copie)
{
    dateJ = copie.dateJ;
}

void date::MiseAJour()
{
    dateJ = time(NULL);
}

void date::AfficherDate(const time_t &dateJ)
{
    struct tm *t;
    memset(&t, 0, sizeof(&t));
    t = localtime(&dateJ);
    cout << t->tm_mday << "/" << (t->tm_mon)+1 << "/" << (t->tm_year)+1900 << endl;
}

/*void date::Saisir(istream &in)
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

time_t date::Conversion()
{
    time_t dateD;
    dateD = mktime(&this->t);
    return dateD;
}*/