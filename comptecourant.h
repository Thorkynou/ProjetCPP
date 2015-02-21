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

class operationbancaire
    {
    private:
        string operation;//nom de l'action realise sur le compte(ajout ou retrait)
        double montant;//montant de l'operation
        string description;//description de l'operation avec des details

    public:
        operationbancaire();//constructeur par defaut
        operationbancaire(string operation,double montant,string description);//constructeur par parametres
        operationbancaire(const operationbancaire& op);
        void AfficherO_B();//affichage de l'operation
        string TypeO_B();
        double Montant_O_B();
        ~operationbancaire();//destruteur
    };

ostream &operator<<(ostream &out,operationbancaire & op);

class comptecourant
    {

    private:

        int numerodecompte;//numero du compte courant
        double solde;//solde du compte
        double decouvert;//variable autorisant un decouvert au client
        double taux;//taux du compte courant=0.30%
        bool debiteur;//verification du solde<0 pour calculer les agios
        int index;//compteur de boucle
        vector<operationbancaire>Tab_MesActions;

    public:
        double montantdebiteur;//calcule le montantdebietur a chaque fois que le bool debiteur est true on incremente apres a chaque passage
        double agios;//calcul des agios si on depasse le decouvert
        double sommeagios;
        double nbagios;

      // comptecourant();//constructeur par defaut

        comptecourant(int numerodecompte=256352,double solde=1500.0,double decouvert=-500.0,double taux=0.30,bool debiteur=true,
                        double montantdebiteur=0.0,double agios=0.0,double sommeagios=0.0,double nbagios=0.0,int index=0);//constructeur par parametres par defaut

        comptecourant(const comptecourant &CC);//constructeur par copie

        comptecourant &operator=(const comptecourant & CC);//operation d'affectation

        comptecourant & operator+(int N);//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
        double Ajouter(double N);//ajout d'argent sur le compte
        void AfficherOperation();

        comptecourant & operator-(int N);//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)
        double Retirer(double N);//retrait d'argent sur le compte
        void AfficherRetrait()const;

        void AfficherSolde(ostream & out);//affiche le solde du compte

        void AffichageAlerte(ostream & out);//affichage d'un message d'alerte quand le solde =le decouvert autorise

        double CalculAgiosJournaliers();//calcul des agios

        void AffichageAgios();//affichage des agios que le client doit payer

        void Afficher10Actions();//affichage des 10 dernieres actions faite sur le compte

        void EcritureFichier();//ecriture dans un fichier
        void LectureFichier();// lecture d'un fichier
        //comptecourant& operator!=(const comptecourant & CC);

        virtual ~comptecourant();// destructeur du compte courant

    };

istream &operator>>(istream &in,const comptecourant & CC);

ostream &operator<<(ostream &out,comptecourant & CC);



#endif //COMPTECOURANT
