/*creation du fichier compte courant.h
fihcier realise par benedicte le */

#include "comptecourant.h"


       // int agios;//calcul des agios si on depasse le decouvert

comptecourant::comptecourant()//constructeur par defaut
    {
        cout<<"voici le constructeur par defaut du compte courant\n ";
        cout<<endl;
    }

comptecourant::~comptecourant()//destructeur par defaut
    {
        cout<<"destructeur du compte courant\n ";
        cout<<endl;
    }


comptecourant::comptecourant(long numerodecompte,int solde=0,int decouvert=0,double taux=0.30);//constructeur par parametres par defaut
    {
        cout<<"saisir le numero de compte\n";
        cin>>numerodecompte;



    }

      /*  comptecourant(const comptecourant &C);//constructeur par copie

        void Retirer();//retrait d'argent sur le compte
        void Ajouter();//ajout d'argent sur le compte
        comptecourant operator+(int N)const;//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
        comptecourant operator-(int N)const;//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)

        void AfficherSolde(ostream & out);//affiche le solde du compte
        void AffichageAlerte(ostream & out);//affichage d'un message d'alerte quand le solde =le decouvert autorise

        int CalculAgios(int solde,bool debiteur,);//
        {
            int nbjoursdebiteur,double txinteretdecouvert
        }
        void AffichageAgios()const;//affichage des agios que le client doit payer

       void Afficher10Actions()const;//affichage des 10 dernieres actions faite sur le compte

        ~CompteCourant();// destructeur du compte courant


comptecourant operator+(intN,const comptecourant &C);//pour l'ajout d'argent on aura solde3=operator+(100,solde2)  (solde3=100+solde2)
comptecourant operator-(intN,const comptecourant &C);//pour le retrait d'argent on aura solde3=operator-(100,solde2)  (solde3=100-solde2)

istream & operator >>(istream &in,const comptecourant &C);
ostream & operator<<(ostream &out,const comptecourant &C);
*/

