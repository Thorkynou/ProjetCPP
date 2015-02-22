#include "gestion_menu.h"


void GestionMenu::AjoutCompte(Client &C)
{
	int i = 0;
	int valid;
	cout << "Voulez-vous ajouter un compte ? (0 pour non, 1 pour oui)" << endl;
	cin >> valid;
	if(valid)
		i=MenuChoixCompte();
	switch(i)
	{   case 0: return;
				break;
		case 1: C.CreationPEL();
				break;
		case 2: C.CreationEC();
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
	while(i<0 && i>4);
	return i;
}

void GestionMenu::AffichageComptes(Client &C)//affiche les generalites de chaque compte
{
	int i=0;
	cout << "Quel compte voulez-vous afficher ?" << endl;
	i = MenuChoixCompte();
	switch(i)
    {
        case 0: return ;
                break;
		case 1: if(C.PEL)
					C.comptePEL.AfficherPEL(cout);
					//Pel.AfficherPEL(cout);
				else
					cout << "Ce client n'a pas encore de PEL" << endl;
				break;
		case 2: if(C.EC)
					C.compteEC.AfficherCompte();// ecompte.AfficherCompte()
				else
					cout << "Ce client n'a pas encore d'e-compte" << endl;
				break;
		case 3: if(C.LE)
					C.compteLE.Afficher();//LivretEpargne.Afficher();
				else
					cout << "Ce client n'a pas encore de Livret d'Epargne" << endl;
				break;
		case 4: if(C.CB)
					C.compteCB.Afficher();//CompteBloque.Afficher();
				else
					cout << "Ce client n'a pas encore de Compte Bloque" << endl;
				break;
		default:
                break;
	}
}
void GestionMenu::ConsulterComptes(Client &C)
{
	int i=0;
	cout << "Souhaitez vous consulter un compte et ses operations associees?"<<endl;
	cout<<"Quel compte voulez-vous consulter ?" << endl;
	i = MenuChoixCompte();
        switch(i)
        {
            case 0: return;
                    break;
            case 1: GestionMenu::OperationPEL(PE);
                    break;
            case 2: GestionMenu::OperationEcompte(EC);
                    break;
            case 3: GestionMenu::OperationLivretepargne(LE);
                    break;
            case 4: GestionMenu::OperationCompteBloque(CB);
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
		cout<<endl;
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
    int sousmenu=0;

    do
    {
    cout<<"Souhaitez vous faire une operation sur ce compte?"<<endl;
    cout<<endl;
    cout<<"1) Ajouter de l'argent"<<endl;
    cout<<"2) Retirer de l'argent"<<endl;
    cout<<"3) Afficher les 10 dernieres operations sur le comptes"<<endl;
    cout<<"4) Sauvegarder les donnees dans un fichier auxiliaire"<<endl;
    cout<<"0) Quitter le sous programme"<<endl;
    cout<<"Saisir votre choix\n";
    cin>>choix;
    if(i<0 && i>4)
			cout << "Mauvais choix, recommencez" << endl;
    }
    while(i<0 && i>4);

    switch(choix)
        {
            case 0: return;
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

            case 3: cout<<"voici les 10 dernière operations faite sur le compte\n";
                    CC.Afficher10Actions();
                    break;
            case 4: cout<<"souhaitez vous exportez vos donnees ou supprimer le fichier?\n";
                    cout<<"1 pour exportez ou 2 pour supprimer le fichier\n";
                    cin>>sousmenu;
                        if (sousmenu==1)
                            {
                                //ExtractionFichier(vector<comptecourant>&moncomptecourant)
                            }
                        else
                        {
                            //ReecritureFichier(const vector<comptecourant>&moncomptecourant)
                        }
                    break;
            default:
                    break;
            }
}

 void GestionMenu::OperationCompteBloque(CompteBloque &CB)
{
    int choix=0;
    int sousmenu=0;
    double interets=0;
    double ajout=0;
 do
    {
    cout<<"souhaitez vous faire une operation sur ce Compte Bloque?"<<endl;
    cout<<endl;
    cout<<"1) Afficher les donnees et le solde du compte"<<endl;
    cout<<"2) Ajouter de l'argent sur le compte bloque"<<endl;
    cout<<"3) Calculer les interets"<<endl;
    cout<<"4) Afficher la duree restante pour utiliser le compte"<<endl;
    cout<<"5) Afficher la duree pendant laquelle le compte est bloque"<<endl;
    cout<<"6) Sauvegarder les donnees dans un fichier auxiliaire"<<endl;
    cout<<"0) Quitter le sous programme"<<endl;
    cout<<"Saisir votre choix\n";
    cin>>choix;
    if(i<0 && i>6)
			cout << "Mauvais choix, recommencez" << endl;
    }
    while(i<0 && i>6);

    switch(choix)
        {
            case 0: return;
                    break;

            case 1: cout<<"voici les donnees associees a votre compte bloque"<<endl;//donnees, solde et date ouverture
                    CB.Afficher();
                    CB.AfficherIndice();
                    break;

            case 2: cout<<"vous souhaitez ajouter de l'argent sur votre compte courant"<<endl;
                    cout<<"quelle somme souhaitez-vous ajouter"<<endl;
                    cin>>ajout;
                    CB.Ajouter(ajout);
                    break;
             case 3: interets=CB.CalculInterets();
                    cout<<"vos interets annuels sont de "<<interets<<endl;
                    break;

            case 4: cout<<"la duree restante pour utiliser le compte est de "<<endl;
                    break;

            case 5: cout<<"le compte est bloque pendant "<<endl;
                    break;

            case 6: cout<<"souhaitez vous exportez vos donnees ou supprimer le fichier?\n";
                    cout<<"1 pour exportez ou 2 pour supprimer le fichier\n";
                    cin>>sousmenu;
                        if (sousmenu==1)
                            {CB.EcritureFichier()}
                        else
                        { //ReecritureFichier(const vector<comptecourant>&moncomptecourant)
                        }
                    break;
            default:
                    break;
            }
}


 void GestionMenu::OperationPEL(Pel &PE)
 {
  int choix=0;
  double ajout=0;
    int sousmenu=0;
    double interets=0;
 do
    {
    cout<<"Souhaitez vous faire une operation sur ce PEL?"<<endl;
    cout<<endl;
    cout<<"1) Afficher les donnees et le solde du PEL"<<endl;
    cout<<"2) Faire un versement exceptionnel"<<endl;
    cout<<"3) Modifier le montant des versements"<<endl;
    cout<<"4) Afficher le temps restant pour utiliser le PEL"<<endl;
    cout<<"5) Sauvegarder les donnees sur un fichier auxiliaire csv"<<endl;
    cout<<"6) Supprimer le fichier et en creer un nouveau"<<endl;
   // cout<<"7) Rechercher par indice"<<endl;
   // cout<<"8) Ecrire dans le fichier"<<endl;
    cout<<"0) Quitter le sous programme"<<endl;
    cout<<"Saisir votre choix\n";
    cin>>choix;
    if(i<0 && i>6)
			cout << "Mauvais choix, recommencez" << endl;
    }
    while(i<0 && i>6);

    switch(choix)
        {
            case 0: return;
                    break;
            case 1: cout<<"voici les donnees associees a votre PEL"<<endl;//donnees, solde et date ouverture
                    Pel.AfficherPEL(cout);
                    Pel.AfficherIndice();
                    break;

            case 2: cout<<"vous souhaitez faire un versement exceptionnel sur votre PEL"<<endl;
                    cout<<"quelle somme souhaitez-vous ajouter"<<endl;
                    cin>>ajout;
                    Pel.Ajouter(ajout);
                    break;
             case 3: Pel.ModifMontantMensuel();
                    break;

            case 4: Pel.TempsRestantEmprunt();
                    break;

            case 5: Pel.ExtractionFichier(vector<Pel>&mesPel);
                    break;

            case 6: Pel.ReecritureFichier(const vector<Pel>&mesPel);
                    break;
            case 7: Pel.RechercheParIndice(vector<Pel>&mesPel,int indice);
                    break;
            case 8: Pel.EcritureFichier();
                    break;
            default:
                    break;
            }

 }

  void GestionMenu::OperationEcompte(ecompte &EC)
  {

  }
   void GestionMenu::OperationLivretEpargne(LivretEpargne & LE)
   {

   }

