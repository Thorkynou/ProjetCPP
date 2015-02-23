/*creation du fichier comptecourant.h
fichier realise par benedicte le 21 fevrier 2015 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <cstddef>
#include <cstdlib>
using namespace std;

#include "operation.h"

#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

class comptecourant:public date
    {
    public:
        int numerodecompte;//numero du compte courant
        double solde;//solde du compte
        double decouvert;//variable autorisant un decouvert au client
        double taux;//taux du compte courant=0.30%
        bool debiteur;//verification du solde<0 pour calculer les agios
        vector<operationbancaire>Tab_MesActions;//vector d'operation bancaire pour creer un tableau d'operations bancaires

        double montantdebiteur;//calcule le montantdebietur a chaque fois que le bool debiteur est true on incremente apres a chaque passage
        double agios;//calcul des agios journaliers si on depasse le decouvert
        double sommeagios;//somme
        double nbagios;//
        int indice;//compteur de boucle indice dans la classe

      // comptecourant();//constructeur par defaut

        comptecourant(int numerodecompte=256352,double solde=1500.0,double decouvert=-500.0,double taux=0.30,bool debiteur=true,
                        double montantdebiteur=0.0,double agios=0.0,double sommeagios=0.0,double nbagios=0.0,int indice=0);//constructeur par parametres par defaut

        comptecourant(const comptecourant &CC);//constructeur par copie

        comptecourant &operator=(const comptecourant & CC);//operation d'affectation

        comptecourant & operator+(int N);//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)

        double Ajouter(double N);//ajout d'argent sur le compte

        virtual void Afficher();//void AfficherOperation();

        comptecourant & operator-(int N);//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)

        double Retirer(double N);//retrait d'argent sur le compte
       // void AfficherRetrait()const;

        void AfficherSolde(ostream & out);//affiche le solde du compte

        void Afficher10Actions();//affichage des 10 dernieres actions faite sur le compte

        void AffichageAlerte(ostream & out);//affichage d'un message d'alerte quand le solde =le decouvert autorise


        double CalculAgiosJournaliers();//calcul des agios

        void AffichageAgios();//affichage des agios que le client doit payer

        void EcritureFichier();//ecriture dans un fichier

        void LectureFichier();// lecture d'un fichier
        //comptecourant& operator!=(const comptecourant & CC);
        void RechercheParIndice(vector<comptecourant>&moncomptecourant,int indice);
        virtual ~comptecourant();// destructeur du compte courant

    };

istream &operator>>(istream &in,const comptecourant & CC);

ostream &operator<<(ostream &out,comptecourant & CC);

void ExtractionFichier(vector<comptecourant>&moncomptecourant);
void ReecritureFichier(const vector<comptecourant>&moncomptecourant);


#endif //COMPTECOURANT
