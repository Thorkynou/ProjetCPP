/*creation du fichier oprations.h fichier realise par benedicte le 01 fevrier 2015*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;


#ifndef OPERATION_H
#define OPERATION_H

class operationbancaire//est un objet operation bancaire
    {
    private:
        string operation;//nom de l'action realise sur le compte(ajout ou retrait)
        double montant;//montant de l'operation
        string description;//description de l'operation avec des details

    public:
        int indice;//indice de la classe

        operationbancaire(string operation=" ",double montant=0,string description= " ");//constructeur par parametres

        operationbancaire(const operationbancaire& op);//constructeur par copie

        void AfficherO_B();//affichage de l'operation

        string TypeO_B();//affichage du nom de l'operation (retrait, ajout, versement)

        double Montant_O_B();//affichage du montant de l'operation

        ~operationbancaire();//destruteur
    };

ostream &operator<<(ostream &out,operationbancaire & op);// surcharge de l'operateur

#endif
