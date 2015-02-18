#include "ECompte.h"

ECompte::ECompte(string eml,int nt[10],double tm,double t)
{
    email=eml;
    numTel[10]=nt[10];
    taux3Mois=tm;
    taux=t;
    cout << "création ecompte";
}
ECompte::ECompte(const ECompte & E)
{
    email=E.email;
    numTel[10]=E.numTel[10];
    taux3Mois=E.taux3Mois;
    taux=E.taux;
}
ECompte ECompte::CreerCompte()
{
cout<<endl<<"Saisir votre adresse email: ";
cin >>this->email;
cout<<endl<<"Saisir votre numero de telephone: ";
cin >>this->numTel;
return *this;
}
