#include "pel.h"

/***************************************************/
/****          Plan Epargne Logement            ****/
/***************************************************/

/*Constructeur par paramètre*/
Pel::Pel(double vm,int te, int i, double sp, time_t datePel): date(datePel)
{
versementMensuel=vm;
tauxEmprunt=te;
indice=i;
soldePel=sp;
}

/*Constructeur par copie*/
Pel::Pel(const Pel & monPel)
{
versementMensuel=monPel.versementMensuel;
tauxEmprunt=monPel.tauxEmprunt;
indice=monPel.indice;
}

/*Création Saisie du PEL*/
void Pel::CreerPel()
{
int ouverture=0;
int ecriture=0;

cout<<"Saisir le montant mensuel de versement: ";
cin >>this->versementMensuel;
cout<<"Saisir le taux d'emprunt initial: ";
cin >>this->tauxEmprunt;
this->soldePel=0;

this->EcritureFichier();
}

/*Versement Exceptionnel*/
void Pel::Ajouter(double mtt)
{
this->soldePel=this->soldePel+mtt;
}

/*Ecriture des données dans le fichier*/
void Pel::EcritureFichier()const
{
ofstream monFichier;
monFichier.open("Pel.txt",ofstream::app);
monFichier<<this->indice<<";"<<this->versementMensuel<<";"<<this->tauxEmprunt<<";"<<this->soldePel<<";"<<dateJ<<";"<<endl;
monFichier.close();
}

/*Surcharge d'operateur Afficher*/
void Pel::AfficherPEL(ostream & out)const
{
out<<"Indice: "<<this->indice<<" Solde du  PEL: "<<this->soldePel<<" Versement mensuel: "<<this->versementMensuel<<" Taux d'emprunt: "<<this->tauxEmprunt<<" Date: "<<this->dateJ<<endl;
}

/*Operateur d'affichage << */
ostream & operator<<(ostream &out, const Pel &P)
{
P.AfficherPEL(out);
return out;
}

/*Affichage de l'indice*/
void Pel::AfficherIndice()const
{
cout<<"L'indice PEL est: "<<this->indice<<endl;
}

/*Modification du montant des versements*/
void Pel::ModifMontantMensuel()
{
cout<<"Saisissez le nouveau montant de vos versements mensuels: ";
cin >>this->versementMensuel;
}

void Pel::TempsRestantEmprunt()
{
time_t tempsRestant;



}

/***************************************************/
/****      Gestion des fichiers / Vectors       ****/
/****               Classe PEL                  ****/
/***************************************************/

/*Conversion CSV en vector de class*/
void ExtractionFichier(vector<Pel>&mesPel)
{
Pel monPel(0);
int k=0;
int j=0;
int taille=0;

vector <string> ligneFichier;
string maLigne;
string mot;
string maLigneCSV;

fstream monFichier;

monFichier.open("Pel.txt",ofstream::in);
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

mesPel.resize(taille);

for (k=0;k<taille;k++)
    {
    maLigne=ligneFichier[k];
    istringstream iss(maLigne);

    j=0;
    while (getline(iss,mot,';'))
        {
        switch(j)
            {
            case 0:mesPel[k].indice=atoi(mot.c_str());
                break;
            case 1:mesPel[k].versementMensuel=atof(mot.c_str());
                break;
            case 2:mesPel[k].tauxEmprunt=atoi(mot.c_str());
                break;
            case 3:mesPel[k].soldePel=atof(mot.c_str());
                break;
            case 4:mesPel[k].dateJ=atoi(mot.c_str());
                break;
            }
        j++;
        }
    }
}

/*Fonction de suppression et écriture d'un nouveau fichier apres modif de vector*/
void ReecritureFichier(const vector<Pel>&mesPel)
{
ofstream monFichier;
ofstream tempFichier;
int taille=0;

tempFichier.open("tempPel.txt",ofstream::app);
taille=mesPel.size();

for(int i=0;i<taille;i++)
    {
    tempFichier<<mesPel[i].indice<<";"<<mesPel[i].versementMensuel<<";"<<mesPel[i].tauxEmprunt<<";"<<mesPel[i].soldePel<<";"<<mesPel[i].dateJ<<";"<<endl;
    }
tempFichier.close();

remove("Pel.txt");
rename("tempPel.txt","Pel.txt");
}

/*Fonction de recherche par indice dans un vector*/
void Pel::RechercheParIndice(vector<Pel>&mesPel,int indice)
{
int taille=0;

taille=mesPel.size();

for (int i=0;i<taille;i++)
    {
    if (mesPel[i].indice==indice)
        *this=mesPel[i];
    }
}
