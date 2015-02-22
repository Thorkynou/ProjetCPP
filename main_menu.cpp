
#include"gestion_menu.h"

#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main()
{
int choix=0;
int sous_menu=0;
date D;//client du jour
Client C;//client lamba
comptecourant CC;
vector <Client> Banque(5);//vector de banque avec 5 comptes
//vector <Client>::iterator it;

cout<<"*****************************************************\n";
cout<<"*                                                   *\n";
cout<<"*                                                   *\n";
cout<<"*     Bienvenue a la banque des petits heros        *\n";
cout<<"*                                                   *\n";
cout<<"*                                                   *\n";
cout<<"*****************************************************\n";

//affichage de la date du jour
D.Afficher(cout);
cout<<"Bonjour , etes vous client dans notre banque?\n";
        cout<<"1- pour oui et 2 pour non\n";
        cin>>choix;

        if(choix==1)
        {
            cout<<"quel est votre nom?\n";
            cin >> C;
            //cout << C;
            //recherche d'un nom --->C.RechercherNom;
            //if(rechercheclient)
            //si il existe afficher les informations du compte
            cout<<"vous etes le client"<<C<<endl;
            C.Afficher(cout);//affichage des informations generales du client
            cout<<"quelle operation souhaitez vous faire aujourd'hui?"<<endl;
            cout<<"1)\tAfficher les donnees du client"<<endl;
            cout<<"2)\tAfficher les donnees du compte courant"<<endl;
            cout<<"3)\tAfficher le solde de vos comptes"<<endl;
            cout<<"4)\tModifier les coordonnees du titulaire"<<endl;
            cout<<"5)\tConsulter le compte"<<endl;
            cout<<"6)\tAjouter un compte"<<endl;
            cout<<"7)\tCloturer le compte"<<endl;
            cout<<"0-\tQuitter"<<endl;
            cout<<"Saisissez le numero de l'operation que vous souhaitez faire"<<endl;
            cin>>sous_menu;

                switch(sous_menu)
                    {
                            case 0: {cout<<"Au revoir et au plaisir de vous revoir tres prochainement dans notre banque !!!!!"<<endl;
                                        return 0;
                                    }
                                    break;
                            case 1: {
                                        cout<<"voici la liste de vos donnees"<<endl;
                                        cout<<endl;
                                        C.compteC.AfficherSolde(cout);//afficher les donnees
                                        C.Afficher(cout);
                                    }
                                    break;
                            case 2: {//compte courant
                                        int choix=0;
                                        cout<<"voici votre compte courant"<<endl;
                                        cout<<endl;
                                        comptecourant CC;
                                        cout<<endl;
                                        GestionMenu::OperationCompteCourant(CC);
                                     //a supprimer   // comptecourant::comptecourant(int numerodecompte,double solde,double decouvert,double taux,bool debiteur,
                                            //double montantdebiteur,double agios,double sommeagios,double nbagios,int indice)
                                    }
                                    break;

                            case 3: //afficher les differents compte et leur solde
                                    {
                                           cout<<"voici les informations de vos differents comptes"<<endl;
                                           GestionMenu::RepetitionAffichageCompte(C);

                                    }
                                   /* {
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
                                    }*/

                                    break;

                            case 4: //modifier les donnees
                                    {
                                        cout<<"vous pouvez modifier votre adresse"<<endl;
                                        C.ModifierAdresse("blabla");
                                    }
                                    break;

                            case 5: //consulter le ou les comptes au choix avec un menu
                                        {   cout<<"consultation de vos comptes"<<endl;
                                            choix= GestionMenu::MenuChoixCompte();//le client a le choix d'afficher les 4 comptes
                                        }
                                    break;
                            case 6: //ajouter un compter
                                        {
                                                cout<<"vous pouvez ajouter un compte"<<endl;
                                                GestionMenu::AjoutCompte(C);

                                        }
                                    break;

                            case 7: //cloturer le compte
                                        {   cout<<"vous pouvez cloturer un compte"<<endl;
                                            GestionMenu::SupprimerCompte(C);
                                        }
                                    break;
                            default:
                                    break;
                    }
         }
        else
        {
            //creer un nouveau client
            cout<<"vous etes un nouveau client\n";
            cout<<"Bienvenue a vous\n";
            C.Saisir(cin);//saisir les informations
            GestionMenu::AjoutCompte(C);
        }

return 0;
}


