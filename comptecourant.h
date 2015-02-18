/*creation du fichier comptecourant.h
fihcier realise par benedicte le */

#include <iostream>
#include <string>
using namespace std;

#include "date.h"

#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

class comptecourant
{

private:
        long numerodecompte;//numero du compte courant
        double solde;//solde du compte
        double decouvert;//variable autorisant un decouvert au client
        double taux;//taux du compte courant=0.30%
        bool debiteur;//verification du solde<0 pour calculer les agios

public:
        double montantdebiteur;//calcule le montantdebietur a chaque fois que le bool debiteur est true on incremente apres a chaque passage
        double agios;//calcul des agios si on depasse le decouvert

        comptecourant();//constructeur par defaut

      /*  comptecourant(long numerodecompte,double solde=0,double decouvert=0,double taux=0.30);//constructeur par parametres par defaut
        comptecourant(const comptecourant &CC);//constructeur par copie

        void Retirer();//retrait d'argent sur le compte
        void Ajouter();//ajout d'argent sur le compte
        comptecourant operator+(int N)const;//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
        comptecourant operator-(int N)const;//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)

        void AfficherSolde(ostream & out);//affiche le solde du compte
        void AffichageAlerte(ostream & out);//affichage d'un message d'alerte quand le solde =le decouvert autorise

        int CalculAgios(double solde,bool debiteur);//calcul des agios
        //etape 1 : montantdebiteur=nbjdebiteur*debit //pour chaque montant faire le calcul
        //etape2: agios=(montantdebiteur*txinteretdecouvert)/(365*100)

        /*compte debiteur du 5 au 22 janvier de 500 euros et du 2 au 28 mars de 450.
        montantdebiteur=(17*500)+(26*450)=20200
        agios=(20200*12)/36500//tx d'interet de 12%
        agios=11.07euros +5.90€ de taxe de commissions
        */
      //  void AffichageAgios(const double agios)const;//affichage des agios que le client doit payer

     //  void Afficher10Actions()const;//affichage des 10 dernieres actions faite sur le compte
       //ouvrir un fichier et le fermer apres;
       //recuperer avec un vector <comptecourant>les 10 dernieres lignes du fichiers , faire une boucle avec begin et end.

        virtual ~ comptecourant();// destructeur du compte courant

};

comptecourant operator+(int N,const comptecourant & CC);//pour l'ajout d'argent on aura solde3=operator+(100,solde2)  (solde3=100+solde2)
comptecourant operator-(int N,const comptecourant & CC);//pour le retrait d'argent on aura solde3=operator-(100,solde2)  (solde3=100-solde2)

istream & operator >>(istream &in,const comptecourant & CC);
ostream & operator<<(ostream &out,const comptecourant & CC);

#endif
