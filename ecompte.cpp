#include "ecompte.h"

ecompte::ecompte(time_t dc=time(NULL),string eml ,string nt ,double s,double tm,double t):date (dc)
{
	dateCreation=dc;
	email=eml;
	numTel=nt;
	solde=s;
	taux3Mois=tm;
	taux=t;
	cout <<endl<<"*******************"<<endl<< "création ecompte"<<endl<<"*******************";
}
ecompte::ecompte(const ecompte & E)
{
	dateCreation=E.dateCreation;
	email=E.email;
	numTel=E.numTel;
	solde=E.solde;
	taux3Mois=E.taux3Mois;
	taux=E.taux;
}

ecompte &ecompte::CreerCompte()
{
	cout<<endl<<"Saisir votre adresse email: ";
	cin >>this->email;
	cout<<endl<<"Saisir votre numero de telephone: ";
	cin >>this->numTel;
	dateCreation=time(NULL);
	cout<<dateCreation;
	return *this;
}
ecompte :: ~ecompte() {}

void ecompte::AfficherSolde(ostream & out)
{
	out<<endl<<"votre solde est actellement de :"<<solde<<"€"<<endl;
}

void ecompte::Retrait()
{
	int x=0;
	while (x<10)
	{
		cout<<endl<<"Saisir la somme a retirer du ecompte :";
		cin>>x;
		if (x<10)
			cout<<endl<<"somme minimale pour un retrait : 10 €";
	}
	solde=solde-x;
	AfficherSolde(cout);

}


void ecompte::Ajouter(ecompte & E)
{
	double x=0;
	cout<<endl<<"Saisir somme a verser sur le compte : ";
	cin >>x;
	E.solde=E.solde+x;
	AfficherSolde(cout);
}
void ecompte::AjouterSA(ecompte & E,double n)
{
	E.solde=E.solde+n;
}

void ecompte::AfficherCompte()
{
	cout<<endl<<"___________________________________________"<<endl;
	cout<<"*********Récapitualatif du compte *********"<<endl;
	cout<<"adresse email :"<<email<<endl;
	cout<<"numéro de téléphone :"<<numTel;
	AfficherSolde(cout);
	cout<<"___________________________________________"<<endl;
}
/*
void CalculInterets(double n)
{
	int x;//va représenter le nombre de quinzaine pris en compte dans le mois en cours
	double y;//va representer le nombre de quinzaines dans l'année en cours
	double interets;//somme des interets
	if(date::jour==1)
		x=2;
	else if(date::jour>1 && date::jour<16)
    		x=1;
	else
		x=0;
	y=(12-date::mois)*2+x;
	interets=n*taux/100*y/24;
	cout<< "le montant des interets de cette somme s'eleveront à "<<interets<<"euros"<<endl;
}

*/

void ecompte::EcritureFichier()const
{
ofstream monFichier;
monFichier.open("ecompte.txt",ofstream::app);
monFichier<<this->indice<<";"<<this->solde<<";"<<this->taux<<";"<<this->email<<";"<<this->numTel<<";"<<dateJ<<";"<<endl;
monFichier.close();
}





