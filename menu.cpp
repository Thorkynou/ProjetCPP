#include "date.h"
#include "client.h"
#include "comptebloque.h"
#include "comptecourant.h"
#include "operation.h"
#include "pel.h"
#include "ecompte.h"
#include"livretepargne.h"

#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main()
{
int choix=0;
int sous_menu=0;
Date D;//client du jour
Client C;//client lamba
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
cout<<D.Afficher(cout);
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
            cout<<"quelle operation souhaitez vous faire aujourd'hui?\n";
            cout<<"1-\tAfficher le solde de vos comptes\n";
            cout<<"2-\tAfficher les donnees \n";"
            cout<<"3-\tModifier les coordonnees du titulaire\n";
            cout<<"4-\tConsulter le compte\n";
            cout<<"5-\tCloturer le compte\n";
            cout<<"0-\tQuitter\n";
            cout<<"Saisissez le numero de l'operation que vous souhaitez faire\n";
            cin>>sous_menu;

                switch(sous_menu)
                    {
                            case 0: return 0;
                                    break;
                            case 1: C.compteC.AfficherSolde(cout);//afficher les differents compte et leur solde
                                    break;
                            case 2: //afficher les donnees
                                    {
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
                                    }
                                    break;
                            case 3: //modifier les donnees
                                    break;
                            case 4: //consulter le compte
                                    break;
                            case 5: //cloturer le compte
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
            //saisir les informations
            int choix=0;
            cout<<"quel compte souhaitez vous creer?\n";
            cout<<"1-\tCreer un compte courant\n";
            cout<<"2-\tCreer un livret d'epargne\n";
            cout<<"3-\tCreer un compte bloque\n";
            cout<<"4-\tCreer un Plan d'epargne logement\n";
            cout<<"5-\tCreer un ecompte\n";
            cout<<"0-\tQuitter le programme\n";
            cout<<"Saisissez votre choix\n";
            cin>>choix;

            Switch(choix)
            {
                case 0; return 0;
                        break;
                case 1://compte courant
                        break;
                case 2: //livret d'epargne
                        break;
                case 3: //compte bloque
                        break;
                case 4: //compte bloque
                        break;
                case 5: //ecompte
                        break;
                default:
                        break;
            }


        }

return 0;
}


