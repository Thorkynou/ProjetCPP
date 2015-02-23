/*creation du fichier oprations.cpp fichier realise par benedicte le 20 fevrier 2015*/

#include "operation.h"


operationbancaire::operationbancaire(const operationbancaire& op)
    {//cout<<"+++++++++++++Voici le constructeur par copie de la classe operation\n "<<endl;
        this->operation=op.operation;
        this->montant=op.montant;
        this->description=op.description;
    }

operationbancaire::operationbancaire(string operation,double montant,string description)//constructeur par parametres
    {//cout<<"+++++++++++++Voici le constructeur par defaut de la classe operation\n "<<endl;
        this->operation=operation;
        this->montant=montant;
        this->description=description;
    }

void operationbancaire::AfficherO_B()//affichage de l'operation
    {
        cout<<"operation de "<<(this->operation)<<" d'un montant de "<<(this->montant)<<"euros"<<endl;
        cout<<description<<endl;
    }

string operationbancaire::TypeO_B()//retourne le nom de l'action
    {    return (this->operation);    }

double operationbancaire::Montant_O_B()//retourne le montant de l'operation
    {    return (this->montant);    }

ostream &operator<<(ostream &out,operationbancaire & op)
    {        return out;    }

operationbancaire::~operationbancaire()//destruteur de la classe operationbancaire
    { }  //cout<<"--------------Destruction du compte courantde la classe operation\n "<<endl;


