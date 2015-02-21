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

void AjoutCompte(Client &C, int indice);

int MenuChoixCompte();

void Affichagecomptes(Client &C);

void RepetitionAffichageCompte(Client &C);

main()
{
	int i=0;
	
}

void AjoutCompte(Client &C, int indice)
{
	int i = 0;
	int valid;
	cout << "Voulez-vous lui ajouter un compte ? (0 pour non, 1 pour oui)" << endl;
	cin >> valid;
	if(valid)
	{
		do
		{
			i=MenuChoixCompte();
			switch(i)
			{
				case 1: C.comptePEL.indice = indice;
						C.CreationPEL();
						break;
				case 2: //C.compteEC.indice = indice;
						C.CreationEC();
						break;
				case 3: //C.compteLE.indice = indice;
						C.CreationLE();
						break;
				case 4: C.compteCB.indice = indice;
						C.CreationCB();
						break;
				default:;
			}
			cout << "Voulez-vous lui ajouter un autre compte ? (0 pour non, 1 pour oui)" << endl;
			cin >> valid;
		}while(valid);
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
		cout << "4)  Compte Bloque" << endl;
		cin >> i;
		if(i<1 && i>4)
			cout << "Mauvais choix, recommencez" << endl;
	}
	while(i<1 && i>4);
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
				{
					C.comptePEL.AfficherPEL(cout);
					C.comptePEL.AfficherIndice();
				}
				else
					cout << "Ce client n'a pas encore de PEL" << endl;
				break;
		case 2: if(C.EC)
				{
					C.compteEC.AfficherCompte();
					//C.compteEC.AfficherIndice();
				}
				else
					cout << "Ce client n'a pas encore d'e-compte" << endl;
				break;
		case 3: if(C.LE)
				{
					C.compteLE.Afficher();
					//C.compteLE.AfficherIndice();
				}
				else
					cout << "Ce client n'a pas encore de Livret d'Epargne" << endl;
				break;
		case 4: if(C.CB)
				{
					C.compteCB.Afficher();
					C.compteCB.AfficherIndice();
				}
				else
					cout << "Ce client n'a pas encore de Compte Bloque" << endl;
				
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
