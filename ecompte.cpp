#include "ecompte.h"

ecompte::ecompte(string eml ,string nt ,double tm,double t)
{
    email=eml;
    numTel=nt;
    taux3Mois=tm;
    taux=t;
    cout << "création ecompte";
}
ecompte::ecompte(const ecompte & E)
{
    email=E.email;
    numTel=E.numTel;
    taux3Mois=E.taux3Mois;
    taux=E.taux;
}
ecompte &ecompte::CreerCompte()
{
cout<<endl<<"Saisir votre adresse email: ";
cin >>this->email;
cout<<endl<<"Saisir votre numero de telephone: ";
cin >>this->numTel;
return *this;
}
ecompte :: ~ecompte() {}
