//projet3
//classe Livret Epargne realisee pas Alain


#include <iostream>
#include <string>

using namespace std;

#include "livretepargne.h"

LivretEpargne::LivretEpargne() //constructeur par defaut
{
cout<<"je suis dans le constructeur par defaut de livret epargne"<<endl;
indice =0;
solde=0;
taux =1.5;
plafondDepot = 7700;
}

LivretEpargne::LivretEpargne(time_t dateLE,int indice,double solde ,double taux , double plafond ):date(dateLE)//constructeur par parametre
{
cout<< "je suis dans le constructeur par parametres de livret epargne"<<endl;
this -> indice=indice;
this -> solde = solde;
this -> taux =taux;
plafondDepot=plafond;
}

LivretEpargne::LivretEpargne(const LivretEpargne & LE)//constructeur par copie
{
cout<< "je suis dans le constructeur par copie de livret epargne"<< endl;
indice = LE.indice;
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

void LivretEpargne::CreerCompte()
{
    cout << "Creation d'un Livret Epargne" << endl;
    cout<<endl<<"Saisir un taux: ";
    cin >>this->taux;
    cout<<endl<<"Saisir un plafond de depot: ";
    cin >>this->plafondDepot;
    EcritureFichier();
}

void LivretEpargne::Afficher()
{
cout<<endl;
cout<<"---------AFFICHAGE DU LIVRET EPARGNE---------"<<endl;
cout << "le sodle de ce livret epargne est de "<<solde<<"euros"<<endl;
cout << "son taux d'interets est de "<< taux<<"%"<< endl;
cout << "et son plafond de depot est de " << plafondDepot<< "euros"<<endl;
cout<<"---------------------------------------------"<<endl;


}


LivretEpargne LivretEpargne:: operator+(double N)
{
this->solde=this->solde+N;
return *this;
}

void LivretEpargne::CalculInterets(double N)//calcule le montant des interets de l'année d'une somme donnée
{
//le calcule des interets d'un livret epargne se fait par rapport aux quinzaines
//il y à donc 24 quinzaines dans un année

int x;//va représenter le nombre de quinzaine pris en compte dans le mois en cours
double y;//va representer le nombre de quinzaines dans l'année en cours
double interets;//somme des interets

if(date::jour==1)
    x=2;//si un virement est effectué le 1er du mois, alors les 2 quinzaines de ce mois seront prises en compte
else if(date::jour>1 && date::jour<16)
    x=1;//si le virement est effectué pendant la premiere quinzaine du mois en cours (cad entre le 2 et le 15 inlus) alors seulement la 2eme quinzaines du mois sera prise en compte
else
    x=0;//si le virement est effectué pendant la deuxieme quinzaine du mois (cad apres le 15) alors celui ci ne sera pas pris en compte
        //et on commencera a partir de la 1ere quinzaine du moi suivant

y=(12-date::mois)*2+x;

interets=N*taux/100*y/24;

cout<< "le montant des interets de cette somme s'eleveront à "<<interets<<"euros"<<endl;



}


void LivretEpargne:: Ajouter()//ajouter de l'argent dans le livret épargne
{

//declaration
double montant;//represente le montant que le client souhaite ajouter au livret epargne
double montanttotal=0;//si le client ajoute plusieurs fois de l'argent d'affilé
int rep;

//premiere partie, on demande au client combien il veut ajouter dans son livret
cout << "BIENVENUE DANS LA FONCTION AJOUTER DE L'ARGENT DANS LE LIVRET EPARGNE"<<endl;
do
{
    do
    {
        //date::Afficher();

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
    cout<< "Voulez-vous encore ajouter de l'argent dans votre livret?? 1-oui   0-non"<<endl;
    cin>>rep;

}
while(rep==1);
cout << "le montant total du virement s'élève à "<< montanttotal<<"euros"<<endl;

//deuxieme parties, on modifie le solde du compte courant puisque le montant vient de celui-ci

//troisieme ârties :calcul des interets perçus avec le rajout des cette somme

CalculInterets(montanttotal);

}


void LivretEpargne::EcritureFichier()const
{
ofstream monFichier;
monFichier.open("LE.txt",ofstream::app);
monFichier<<this->solde<<";"<<this->taux<<";"<<this->plafondDepot<<";"<<this->indice<<";"<<dateJ<<";"<<endl;
monFichier.close();
}


/*Affichage de l'indice*/
void LivretEpargne::AfficherIndice()const
{
cout<<"L'indice LE est: "<<this->indice<<endl;
}

/*Conversion CSV en vector de class*/
void ExtractionFichier(vector<LivretEpargne>&mesLE)
{
LivretEpargne monLE(0);
int k=0;
int j=0;
int taille=0;

vector <string> ligneFichier;
string maLigne;
string mot;
string maLigneCSV;

fstream monFichier;

monFichier.open("LE.txt",ofstream::in);
if (monFichier.fail())
    cerr<<"Le fichier n'existe pas"<<endl;
else
    {
    while (monFichier.eof()!=true)
        {
        monFichier>>maLigneCSV;
        ligneFichier.push_back(maLigneCSV);
        maLigneCSV.clear();
        }
    ligneFichier.pop_back();
    taille=ligneFichier.size();
    }
monFichier.close();

mesLE.resize(taille);

for (k=0;k<taille;k++)
    {
    maLigne=ligneFichier[k];
    istringstream iss(maLigne);

    j=0;
    while (getline(iss,mot,';'))
        {
        switch(j)
            {
                break;
            case 1:mesLE[k].solde=atof(mot.c_str());
                break;
            case 2:mesLE[k].taux=atoi(mot.c_str());
                break;
            case 3:mesLE[k].plafondDepot=atof(mot.c_str());
                break;
            case 4:mesLE[k].dateJ=atoi(mot.c_str());
                break;
            }
        j++;
        }
    }
}

/*Fonction de suppression et écriture d'un nouveau fichier apres modif de vector*/
void ReecritureFichier(const vector<LivretEpargne>&mesLE)
{
ofstream monFichier;
ofstream tempFichier;
int taille=0;

tempFichier.open("tempLE.txt",ofstream::app);
taille=mesLE.size();

for(int i=0;i<taille;i++)
    {
    tempFichier<<mesLE[i].indice<<";"<<mesLE[i].solde<<";"<<mesLE[i].taux<<";"<<mesLE[i].plafondDepot<<";"<<endl;
    }
tempFichier.close();

remove("LE.txt");
rename("tempLE.txt","LE.txt");
}

/*Fonction de recherche par indice dans un vector*/
void LivretEpargne::RechercheParIndice(vector<LivretEpargne>&mesLE,int indice)
{
int taille=0;

taille=mesLE.size();

for (int i=0;i<taille;i++)
    {
    if (mesLE[i].indice==indice)
        *this=mesLE[i];
    }
}
/*
void CalculInterets();
void MiseAJour();//cad nouveau solde avec les interets rajoutes
*/



