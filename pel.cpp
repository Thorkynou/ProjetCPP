#include "pel.h"

/*Constructeur par paramètre*/
Pel::Pel(double vm,int te, int indice)
{
versementMensuel=vm;
tauxEmprunt=te;
}

/*Constructeur par copie*/
Pel::Pel(const Pel & monPel)
{
versementMensuel=monPel.versementMensuel;
tauxEmprunt=monPel.tauxEmprunt;
indice=monPel.indice;
}

/*Création Saisie du PEL*/
void Pel::CreerPel()
{
int ouverture=0;
int ecriture=0;

cout<<"Saisir le montant mensuel de versement: ";
cin >>this->versementMensuel;
cout<<"Saisir le taux d'emprunt initial: ";
cin >>this->tauxEmprunt;
this->soldePel=0;

this->EcritureFichier();
}

/*Versement Exceptionnel*/
void Pel::Ajouter(double mtt)
{
this->soldePel=this->soldePel+mtt;
}

/*Ecriture des données dans le fichier*/
void Pel::EcritureFichier()const
{
ofstream monFichier;
monFichier.open("Pel.txt",ofstream::app);
monFichier<<this->indice<<";"<<this->versementMensuel<<";"<<this->tauxEmprunt<<";"<<this->soldePel<<";"<<endl;
monFichier.close();
}

/*Surcharge d'operateur Afficher*/
void Pel::AfficherPEL(ostream & out)const
{
out<<"Solde du  PEL: "<<this->soldePel<<"  Montant versement mensuel: "<<this->versementMensuel<<"  Montant taux d'emprunt: "<<this->tauxEmprunt<<endl;
}

ostream & operator<<(ostream &out, const Pel &P)
{
	P.AfficherPEL(out);
	return out;
}

void Pel::AfficherIndice()const
{
cout<<"L'indice PEL est: "<<this->indice<<endl;
}


