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
int ouverture=0;
int ecriture=0;

cout<<"Saisir le montant mensuel de versement: ";
cin >>this->versementMensuel;
cout<<"Saisir le taux d'emprunt initial: ";
cin >>this->tauxEmprunt;
this->soldePel=0;

Client::PEL=true;//???

this->EcritureFichier();
return *this;
}

void Pel::VersementExept(Pel & monPel)
{
double mtt=0;

cout<<"Quel montant voulez vous verser? ";
cin >>mtt;

monPel.soldePel=monPel.soldePel+mtt;

}


void Pel::EcritureFichier()const
{
ofstream monFichier;
monFichier.open("Pel.txt",ofstream::app);
monFichier<<this->versementMensuel<<";"<<this->tauxEmprunt<<";"<<this->soldePel<<";"<<endl;
monFichier.close();
}




