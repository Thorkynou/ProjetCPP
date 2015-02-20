#include "ecompte.h"

ecompte::ecompte(string eml ,string nt ,double s,double tm,double t)
{
	email=eml;
	numTel=nt;
	solde=s;
	taux3Mois=tm;
	taux=t;
	cout <<endl<<"*******************"<<endl<< "création ecompte"<<endl<<"*******************";
}
ecompte::ecompte(const ecompte & E)
{
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
