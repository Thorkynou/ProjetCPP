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
       date  evenement;
        int numerodecompte;//numero du compte courant
        double solde;//solde du compte
        double decouvert;//variable autorisant un decouvert au client
        double taux;//taux du compte courant=0.30%
        bool debiteur;//verification du solde<0 pour calculer les agios

public:
        double montantdebiteur;//calcule le montantdebietur a chaque fois que le bool debiteur est true on incremente apres a chaque passage
        double agios;//calcul des agios si on depasse le decouvert
        double nbagios;

        /***********ok***********/
      // comptecourant();//constructeur par defaut--->ok testé

        comptecourant(int numerodecompte=256352,double solde=1500.0,double decouvert=-500.0,double taux=0.30);//constructeur par parametres par defaut -->pb
        /***********ok***********/

        comptecourant(const comptecourant &CC);//constructeur par copie

       comptecourant &operator=(const comptecourant & CC);

        void Retirer();//retrait d'argent sur le compte
        /***********ok***********/

        comptecourant& Ajouter();//ajout d'argent sur le compte-->pb

        /***********ok***********/
        comptecourant & operator+(int N);//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
        /***********ok***********/
        comptecourant & operator-(int N);//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)

        void AfficherSolde(ostream & out);//affiche le solde du compte
        void AffichageAlerte(ostream & out);//affichage d'un message d'alerte quand le solde =le decouvert autorise

        double CalculAgios();//calcul des agios

       void AffichageAgios(const double &nbagios)const;//affichage des agios que le client doit payer

     //  void Afficher10Actions()const;//affichage des 10 dernieres actions faite sur le compte
       //ouvrir un fichier et le fermer apres;
       //recuperer avec un vector <comptecourant>les 10 dernieres lignes du fichiers , faire une boucle avec begin et end.

        virtual ~comptecourant();// destructeur du compte courant-->ok testé

};

comptecourant operator+(int N,const comptecourant & CC);//pour l'ajout d'argent on aura solde3=operator+(100,solde2)  (solde3=100+solde2)
/***********ok***********/
comptecourant operator-(int N,const comptecourant & CC);//pour le retrait d'argent on aura solde3=operator-(100,solde2)  (solde3=100-solde2)
/***********ok***********/

/***********ok***********/
istream & operator >>(istream &in,const comptecourant & CC);
/***********ok***********/
ostream & operator<<(ostream &out,comptecourant & CC);


#endif
