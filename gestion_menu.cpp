#include "gestion_menu.h"


void GestionMenu::AjoutCompte(Client &C)
{
	int i = 0;
	int valid;
	cout << "Voulez-vous lui ajouter un compte ? (0 pour non, 1 pour oui)" << endl;
	cin >> valid;
	if(valid)
		i=MenuChoixCompte();
	switch(i)
	{   case 0: return ;
				break;
		case 1:
                C.CreationPEL();
				break;
		case 2: C.CreationEC();
                return ;
				break;
		case 3: C.CreationLE();
				break;
		case 4: C.CreationCB();
				break;
		default:
                break;
	}
}

void GestionMenu::SupprimerCompte(Client &C)
{
	int i = 0;
	int valid;
	cout << "Voulez-vous lui supprimer un compte ? (0 pour non, 1 pour oui)" << endl;
	cin >> valid;
	if(valid)
		i=MenuChoixCompte();
	switch(i)
	{
        case 0: return ;
				break;
		case 1: C.DestructionPEL();
				break;
		case 2: C.DestructionEC();
				break;
		case 3: C.DestructionLE();
				break;
		case 4: C.DestructionCB();
				break;
		default:
                break;
	}
}

int GestionMenu::MenuChoixCompte()
{
	int i=0;
	do
	{
        cout << "0)  Retour au programme" << endl;
		cout << "1)  PEL" << endl;
		cout << "2)  E-compte" << endl;
		cout << "3)  Livret d'Epargne" << endl;
		cout << "4)  Compte Bloque" << endl;
        cin >> i;
		if(i<0 && i>4)
			cout << "Mauvais choix, recommencez" << endl;
	}
	while(i<1 && i>4);
	return i;
}

void GestionMenu::AffichageComptes(Client &C)
{
	int i=0;
	cout << "Quel compte voulez-vous afficher ?" << endl;
	i = MenuChoixCompte();
	switch(i)
	{
        case 0: return ;
                break;
		case 1: if(C.PEL)
					C.comptePEL.AfficherPEL(cout);//rajout du cout
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
		case 4: if(C.CB)
					C.compteCB.Afficher();
				else
					cout << "Ce client n'a pas encore de Compte Bloque" << endl;
				break;
		default:
                break;
	}
}

void GestionMenu::RepetitionAffichageCompte(Client &C)
{
	int valid=0;
	do
	{
		AffichageComptes(C);
		cout << "Voulez-vous afficher un autre compte de ce client ? (1 oui, 0 non)" << endl;
		cin >> valid;
	}while (valid == 1);
}

void GestionMenu::OperationCompteCourant(comptecourant &CC)
{ int choix=0;
    int solde_ajout=0;
    int solde_retrait=0;
    double ajout=0;
    double retrait=0;

    cout<<"souhaitez vous faire une operation sur ce compte?\n"<<endl;
    cout<<endl;
    cout<<"1) pour ajouter de l'argent"<<endl;
    cout<<"2) pour retirer de l'argent"<<endl;
    cout<<"3) afficher les 10 dernieres operations sur le comptes"<<endl;
    cout<<"0) pour quitter le sous programme";
    cout<<"saisir votre choix\n";
    cin>>choix;

    switch(choix)
        {
            case 0: cout<<"mauvaise touche, recommencez"<<endl;
                    return;
                    break;

            case 1: cout<<"vous souhaitez ajouter de l'argent sur votre compte courant"<<endl;
                    cout<<"quelle somme souhaitez-vous ajouter"<<endl;
                    cin>>ajout;
                    solde_ajout=CC.Ajouter(ajout);
                    //CC.AfficherSolde(cout);
                    CC.Afficher();
                    break;

            case 2: cout<<"vous souhaitez retirer de l'argent sur votre compte courant"<<endl;
                    cout<<"quelle somme souhaitez-vous retirer"<<endl;
                    cin>>retrait;
                    solde_retrait=CC.Retirer(retrait);
                   // CC.AfficherSolde(cout);
                    CC.Afficher();
                    break;

            case 3: CC.Afficher10Actions();
                    break;
            }
}


