/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: main.cpp                              *
 * @author: Clément L                             *
 **************************************************/

#include "date.h"
#include "client.h"
#include <vector>
#include <map>

void AjoutCompte(Client &C);

int MenuChoixCompte();

void Affichagecomptes(Client &C);

void RepetitionAffichageCompte(Client &C);

main()
{

	/*Client C;
	C.Afficher(cout);
	cin >> C;
	cout << C;
    C.compteC.AfficherSolde(cout);

    C.CreationPEL();
    C.AjoutPEL(100);
    C.compteC.AfficherSolde(cout);
    C.comptePEL.AfficherPEL();

    C.CreationEC();
    C.AjoutEC(150);
    C.compteC.AfficherSolde(cout);
    C.compteEC.AfficherCompte();

    C.CreationLE();
    C.AjoutLE(200);
    C.compteC.AfficherSolde(cout);
    C.compteLE.Afficher();*/


	vector <Client> Banque(5);
	//vector <Client>::iterator it;
	for(int i=0; i<2; i++)
	{
		Banque[i].Saisir(cin);
		AjoutCompte(Banque[i]);
	}
	for(int i=0; i<2; i++)
	{
		cout << "Affichage des comptes du client " << Banque[i].nom << endl;
		RepetitionAffichageCompte(Banque[i]);
	}




	/*date D;
	D.Afficher();
	date D2(8, 12, 2015);
	D2.Afficher();
	date D3;
	D3.Saisir();
	D3.Afficher();
	date D4 = D3;
	D4.Afficher();

	cin.ignore();*/

	/*Client C;
	Client C1("machin", "bidule", "22 rue de marsoulas", true);
	Client C2=C1;
	cout << "*****************" << endl;
	cout << "        C" << endl;
	cout << "*****************" << endl;
	C.Afficher(cout);
	cout << "*****************" << endl;
	cout << "        C1" << endl;
	cout << "*****************" << endl;
	C1.Afficher(cout);
	cout << "*****************" << endl;
	cout << "        C2" << endl;
	cout << "*****************" << endl;
	C2.Afficher(cout);
	string S;
	cout << "Entrez une nouvelle adresse" << endl;
	getline(cin, S);
	C.ModifierAdresse(S);
	cout << "*****************" << endl;
	cout << "        C" << endl;
	cout << "*****************" << endl;
	C.Afficher(cout);
	C2 = C;
	cout << "*****************" << endl;
	cout << "        C2" << endl;
	cout << "*****************" << endl;
	C2.Afficher(cout);
	Client C3("hello", "coucou", "truc bidule", true, false, true, false, true);
	cout << "*****************" << endl;
	cout << "        C3" << endl;
	cout << "*****************" << endl;
	C3.Afficher(cout);*/
}


void AjoutCompte(Client &C)
{
	int i = 0;
	int valid;
	cout << "Voulez-vous lui ajouter un compte ? (0 pour non, 1 pour oui)" << endl;
	cin >> valid;
	if(valid)
		i=MenuChoixCompte();
	switch(i)
	{
		case 1: C.CreationPEL();
				break;
		case 2: C.CreationEC();
				break;
		case 3: C.CreationLE();
				break;
		default:;
	}
}

int MenuChoixCompte()
{
	int i;
	do
	{
		cout << "1)  PEL" << endl;
		cout << "2)  E-compte" << endl;
		cout << "3)  Livret d'Epargne" << endl;
		cin >> i;
		if(i<1 && i>3)
			cout << "Mauvais choix, recommencez" << endl;
	}
	while(i<1 && i<3);
	return i;
}

void AffichageComptes(Client &C)
{
	int i;
	cout << "Quel compte voulez-vous afficher ?" << endl;
	i = MenuChoixCompte();
	switch(i)
	{
		case 1: if(C.PEL)
					C.comptePEL.AfficherPEL();
				else
					cout << "Ce client n'a pas encore de PEL" << endl;
				break;
		case 2: if(C.EC)
					C.compteEC.AfficherCompte();
				else
					cout << "Ce client n'a pas encore d'e-compte" << endl;
				break;
		case 3: if(C.LE)
					C.compteLE.Afficher();
				else
					cout << "Ce client n'a pas encore de Livret d'Epargne" << endl;
				break;
		default:;
	}
}

void RepetitionAffichageCompte(Client &C)
{
	int valid;
	do
	{
		AffichageComptes(C);
		cout << "Voulez-vous afficher un autre compte de ce client ? (1 oui, 0 non)" << endl;
		cin >> valid;
	}while (valid == 1);
}