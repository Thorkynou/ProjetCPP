

#include "date.h"
#include "client.h"
#include <vector>
#include <map>

void AjoutCompte(Client &C);

int MenuChoixCreationCompte();

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
		cout << Banque[i];
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
		i=MenuChoixCreationCompte();
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

int MenuChoixCreationCompte()
{
	int i;
	do
	{
		cout << "1)  Creation PEL" << endl;
		cout << "2)  Creation E-compte" << endl;
		cout << "3)  Creation Livret d'Epargne" << endl;
		cin >> i;
		if(i<1 && i>3)
			cout << "Mauvais choix, recommencez" << endl;
	}
	while(i<1 && i<3);
	return i;
}

