#include "ECompte.h"

ECompte::ECompte(string eml ,string nt ,double tm,double t)
{
    email=eml;
    numTel=nt;
    taux3Mois=tm;
    taux=t;
    cout << "création ecompte";
}
ECompte::ECompte(const ECompte & E)
{
    email=E.email;
    numTel=E.numTel;
    taux3Mois=E.taux3Mois;
    taux=E.taux;
}
ECompte &ECompte::CreerCompte()
{
cout<<endl<<"Saisir votre adresse email: ";
cin >>this->email;
cout<<endl<<"Saisir votre numero de telephone: ";
cin >>this->numTel;
return *this;
}
