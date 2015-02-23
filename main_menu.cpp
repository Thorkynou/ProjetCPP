
#include"gestion_menu.h"

#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main()
{


cout<<"*****************************************************\n";
cout<<"*                                                   *\n";
cout<<"*                                                   *\n";
cout<<"*     Bienvenue a la banque des petits heros        *\n";
cout<<"*                                                   *\n";
cout<<"*                                                   *\n";
cout<<"*****************************************************\n";

int choix=0;
int i=0;
int sous_menu=0;
double N;//montant a ajouter sur les comptes


time_t dateJour=time(NULL);
date D;//date du jour
Client C;//client lamba
//comptecourant CC;
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
cout<<"Nous sommes aujourd'hui le\t";
D.AfficherDate(dateJour);
cout<<endl;

cout<<"Bonjour , etes vous client dans notre banque?\n";
        cout<<"1- pour oui et 2 pour non\n";
        cin>>choix;

        if(choix==1)
        {
            cout<<"quel est votre nom?\n";
            cin >> C;

            cout<<"Vous etes le client"<<C<<endl;
            C.Afficher(cout);//affichage des informations generales du client
            do
            {
            cout<<"quelle operation souhaitez vous faire aujourd'hui?"<<endl;
            cout<<"                    ********                      "<<endl;
            cout<<"1)\tAfficher les donnees du client"<<endl;
            cout<<"2)\tAfficher les donnees du compte courant"<<endl;
            cout<<"3)\tAfficher les informations generales du ou des comptes"<<endl;
            cout<<"4)\tModifier les coordonnees du titulaire"<<endl;
            cout<<"5)\tConsulter le compte et les diverses operations possible"<<endl;
            cout<<"6)\tAjouter un compte"<<endl;
            cout<<"7)\tAjouter de l'argent sur le compte"<<endl;
            cout<<"8)\tCloturer le compte"<<endl;
            cout<<"0-\tQuitter"<<endl;
            cout<<"Saisissez le numero de l'operation que vous souhaitez faire"<<endl;
            cin>>sous_menu;

                switch(sous_menu)
                    {
                            case 0:
                            {       cout<<"***********************************************"<<endl;
                                    cout<<"Au revoir et au plaisir de vous revoir tres prochainement dans notre banque !!!!!"<<endl;
                                    cout<<"***********************************************"<<endl;
                                    return 0;
                                    break;}

                            case 1: {cout<<"***********************************************"<<endl;
                                    cout<<"voici la liste de vos donnees personnelles"<<endl;
                                    cout<<"***********************************************"<<endl;
                                    cout<<endl;
                                    C.Afficher(cout);
                                    //C.compteC.AfficherSolde(cout);//afficher les donnees
                                    return 0;}
                                    break;

                            case 2: //compte courant
                                      {
                                      cout<<"***********************************************"<<endl;
                                      cout<<"voici votre compte courant"<<endl;
                                      cout<<"***********************************************"<<endl;
                                        cout<<endl;
                                        comptecourant CC;
                                        cout<<endl;
                                        GestionMenu::OperationCompteCourant(CC);
                                     //a supprimer   // comptecourant::comptecourant(int numerodecompte,double solde,double decouvert,double taux,bool debiteur,
                                            //double montantdebiteur,double agios,double sommeagios,double nbagios,int indice)
                                    break;}

                            case 3: //afficher les differents compte et leur solde
                                    {cout<<"***********************************************"<<endl;
                                    cout<<"voici les informations de vos differents comptes"<<endl;
                                    cout<<"***********************************************"<<endl;
                                   // cout<<endl;
                                    //GestionMenu::AffichageComptes(C);
                                    cout<<endl;
                                    GestionMenu::RepetitionAffichageCompte(C);
                                        for(int i=0; i<2; i++)
                                            {
                                                Banque[i].Saisir(cin);
                                                GestionMenu::AjoutCompte(Banque[i]);
                                            }
                                        for(int i=0; i<2; i++)
                                            {
                                                cout << "Affichage des comptes du client " << Banque[i].nom << endl;
                                                GestionMenu::RepetitionAffichageCompte(Banque[i]);
                                                }

                                    break;}
                             case 4:{cout<<"***********************************************"<<endl;
                                    cout<<"vous pouvez modifier votre adresse"<<endl;
                                    cout<<"***********************************************"<<endl;
                                    C.ModifierAdresse("blabla");
                                    break; }

                            case 5: {cout<<"***********************************************"<<endl;
                                    cout<<"consultation de vos comptes et des operations diverses"<<endl;
                                    cout<<"***********************************************"<<endl;
                                    //
                                    int i=0;
                                    cout << "Souhaitez vous consulter un compte et ses operations associees?"<<endl;
                                    cout<<"Quel compte voulez-vous consulter ?" << endl;
                                    i = GestionMenu::MenuChoixCompte();
                                        GestionMenu::ConsulterComptes(C);
                                    break; }

                            case 6: //ajouter un compter
                                    {cout<<"***********************************************"<<endl;
                                    cout<<"vous pouvez ajouter un compte a ceux deja existants"<<endl;
                                    cout<<"***********************************************"<<endl;
                                    GestionMenu::AjoutCompte(C);
                                    break;}

                            case 7: //ajouter de l'argent sur un des comptes
                                    {cout<<"***********************************************"<<endl;
                                    cout<<"vous pouvez ajouter de l'argent"<<endl;
                                    cout<<"***********************************************"<<endl;
                                    cout<<"Saisir le montant à ajouter"<<endl;
                                    cin>>N;
                                    i = GestionMenu::MenuChoixCompte();
                                    switch(i)
                                        {case 0: {return 0;
                                                    break;
                                                   }
                                        case 1: {C.AjoutPEL(N);
                                                break;}
                                        case 2: {C.AjoutEC(N);
                                                break;}
                                        case 3: {C.AjoutLE(N);
                                                break;}
                                        case 4: {C.AjoutCB(N);
                                                break;}
                                        default:
                                                break;
                                        }
                                    }

                            case 8: //cloturer le compte
                                    {cout<<"***********************************************"<<endl;
                                    cout<<"vous pouvez cloturer un compte"<<endl;
                                    cout<<"***********************************************"<<endl;
                                    GestionMenu::SupprimerCompte(C);
                                    break;}

                            default:cout<<"Entrez un chiffre entre 0 et 8"<<endl;
                                    break;
                    }
            }while(sous_menu!=0);
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


