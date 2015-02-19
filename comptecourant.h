/*creation du fichier comptecourant.h
fichier realise par benedicte le */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#include "date.h"

#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

class comptecourant
{

private:
       //date  evenement;
        int numerodecompte;//numero du compte courant
        double solde;//solde du compte
        double decouvert;//variable autorisant un decouvert au client
        double taux;//taux du compte courant=0.30%
        bool debiteur;//verification du solde<0 pour calculer les agios

public:
        double montantdebiteur;//calcule le montantdebietur a chaque fois que le bool debiteur est true on incremente apres a chaque passage
        double agios;//calcul des agios si on depasse le decouvert
        double sommeagios;
        double nbagios;

      // comptecourant();//constructeur par defaut

        comptecourant(int numerodecompte=256352,double solde=1500.0,double decouvert=-500.0,double taux=0.30,bool debiteur=true,
                        double montantdebiteur=0.0,double agios=0.0,double sommeagios=0.0,double nbagios=0.0);//constructeur par parametres par defaut

        comptecourant(const comptecourant &CC);//constructeur par copie

       comptecourant &operator=(const comptecourant & CC);//operation d'affectation

        comptecourant & operator+(int N);//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
        comptecourant& Ajouter();//ajout d'argent sur le compte

        comptecourant & operator-(int N);//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)
        void Retirer();//retrait d'argent sur le compte

        void AfficherSolde(ostream & out);//affiche le solde du compte

        void AffichageAlerte(ostream & out);//affichage d'un message d'alerte quand le solde =le decouvert autorise

        double CalculAgios();//calcul des agios

        void AffichageAgios(const double &nbagios)const;//affichage des agios que le client doit payer

        void Afficher10Actions()const;//affichage des 10 dernieres actions faite sur le compte

        comptecourant & open();
       // comptecourant & close();
       virtual ~comptecourant();// destructeur du compte courant

       comptecourant& operator!=(const comptecourant & CC);


};

istream & operator >>(istream &in,const comptecourant & CC);

ostream & operator<<(ostream &out,comptecourant & CC);



#endif //COMPTECOURANT
