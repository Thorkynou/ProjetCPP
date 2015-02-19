//projet3
//classe Livret Epargne realisee pas Alain


#include <iostream>
#include <string>

using namespace std;

#include "livretepargne.h"

LivretEpargne::LivretEpargne() //constructeur par defaut
{
cout<<"je suis dans le constructeur par defaut de livret epargne"<<endl;
solde=0;
taux =1.5;
plafondDepot = 7700;
}

LivretEpargne::LivretEpargne(double solde ,double taux , double plafond )//constructeur par parametre
{
cout<< "je suis dans le constructeur par parametres de livret epargne"<<endl;
this -> solde = solde;
this -> taux =taux;
plafondDepot=plafond;
}

LivretEpargne::LivretEpargne(const LivretEpargne & LE)//constructeur par copie
{
cout<< "je suis dans le constructeur par copie de livret epargne"<< endl;
solde = LE.solde;
taux = LE.taux;
plafondDepot= LE.plafondDepot;
}


LivretEpargne::~LivretEpargne()//destructeur
{
cout << "je suis dans le destructeur de livret epargne"<< endl;
};//destructeur

LivretEpargne &  LivretEpargne::operator=(const LivretEpargne & LE)//opérateur d'affectation
{
solde=LE.solde;
taux=LE.taux;
plafondDepot=LE.plafondDepot;
return *this;


}


void LivretEpargne::Afficher()//affiche seulement les variables du livret epargne
{
cout << "le sodle de ce livret epargne est de "<<solde<<endl;
cout << "son taux d'interets est de "<< taux<<"%"<< endl;
cout << "et son plafond de depot est de " << plafondDepot<< "euros"<<endl;
}


LivretEpargne LivretEpargne:: operator+(double N)
{
this->solde=this->solde+N;
return *this;
}

void LivretEpargne:: Ajouter()//ajouter de l'argent dans le livret épargne
{

//declaration
double montant;//represente le montant que le client souhaite ajouter au livret epargne
double montanttotal=0;//si le client ajoute plusieurs fois de l'argent d'affilé
int rep;//savoir si le client souhaite continuer de rajouter de l'argent dans le livret

//premiere partie, on demande au client combien il veut ajouter dans son livret
cout << "BIENVENUE DANS LA FONCTION AJOUTER DE L'ARGENT DANS LE LIVRET EPARGNE"<<endl;
do
{
    do
    {
        cout << "Votre solde actuel est de "<< solde<<"euros"<<endl;
        cout<<endl;
        cout << "Combien voulez-vous rajouter d'argent dans le livret sachant que le plafond est fixé à:  "<< plafondDepot<< "euros"<<endl;
        cin>>montant;
        if(solde+montant>plafondDepot)
        {
        cout<<"Impossible d'ajouter ce montant car le plafond sera dépassé."<<endl;
        }
    }
    while(solde+montant>plafondDepot);



    cout<<"Vous avez décidé de rajouter "<<montant<<"euros dans le livret épargne qui seront donc déduits du compte courant"<<endl;
    solde=solde+montant;
    montanttotal=montanttotal+montant;
    cout<<"........................."<<endl;
    cout<<endl;
    cout << "OPERATION EFFECTUEE AVEC SUCCES!!"<<endl;
    cout<< "Voulez-vous ajouter de l'argent de nouveau dans votre livret?? 1-oui   0-non"<<endl;
    cin>>rep;

}
while(rep==1);
cout << "le montant total du virement s'élève à "<< montanttotal<<"euros"<<endl;//recapitulatif du montant total ajouté dans le livret

//deuxieme parties, on modifie le solde du compte courant puisque le montant vient de celui-ci
//on va donc deduire le montanttotal de cette opreation du compte courant


}



/*
void CalculInterets();
void MiseAJour();//cad nouveau solde avec les interets rajoutes
*/



