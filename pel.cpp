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
soldePel=monPel.soldePel;
dateJ=monPel.dateJ;
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
time_t nbAnneesMax=126227704;
time_t dateDuJour=time(NULL);
time_t dateVersementMax;

dateVersementMax=this->dateJ+nbAnneesMax;

if (dateDuJour>dateVersementMax)
    {
    cout<<"Vous ne pouvez plus effectuer de versement Exceptionnel"<<endl;
    }
else
    {
    this->soldePel=this->soldePel+mtt;
    }
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
void Pel::AfficherPEL(ostream & out)
{
cout<<"___________________________________________________"<<endl;
out<<"Client n°: "<<this->indice<<endl;
out<<"Solde du  PEL: "<<this->soldePel<<endl;
out<<"Versement mensuel: "<<this->versementMensuel<<endl;
out<<"Taux d'emprunt: "<<this->tauxEmprunt<<endl;
out<<"Date de Creation: ";
date::AfficherDate(this->dateJ);
this->TempsRestantEmprunt();
cout<<"___________________________________________________"<<endl;
}

/*Operateur d'affichage << */
ostream & operator<<(ostream &out, Pel &P)
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
time_t dateDuJour=time(NULL);
time_t tempsRestant;
time_t dateDeblocageMin;
time_t nbAnneesMin=126227704;
int days;
int years;

dateDeblocageMin=this->dateJ+nbAnneesMin;
tempsRestant=dateDeblocageMin-dateDuJour;

ConversionStoAJ(tempsRestant,years,days);

cout<<"Vous pourrez emprunter dans "<<years<<" annee(s) "<<days<<" jour(s)"<<endl<<"Date de deblocage ";
date::AfficherDate(dateDeblocageMin);
}

/*Fonction de conversion des secondes en Jours/Annees*/
void ConversionStoAJ(int nbSecondes,int &years,int &days)
{
int seconds;
int total_minutes;
int minutes;
int total_hours;
int hours;
int total_days;
int months;
int total_months;

seconds = nbSecondes % 60;
total_minutes = nbSecondes / 60;
minutes = total_minutes % 60;
total_hours = total_minutes / 60;
hours = total_hours % 24;
total_days = total_hours / 24;
days = total_days % 365;
years = total_days / 365;
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
