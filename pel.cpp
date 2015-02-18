#include "pel.h"

Pel::Pel(double vm,int te)
{
versementMensuel=vm;
tauxEmprunt=te;
}

Pel::Pel(const Pel & monPel)
{
versementMensuel=monPel.versementMensuel;
tauxEmprunt=monPel.tauxEmprunt;
}

Pel Pel::CreerCompte()
{
cout<<"Saisir le montant mensuel de versement: ";
cin >>this->versementMensuel;
cout<<"Saisir le taux d'emprunt initial: ";
cin >>this->tauxEmprunt;
return *this;
}

void Pel::VersementExept(Pel & monPel)
{
double mtt=0;

cout<<"Quel montant voulez vous verser? ";
cin >>mtt;

monPel.soldePel=monPel.soldePel+mtt;
/**** METTRE A JOUR LE SOLDE COMPTE COURANT!! ****/
}


