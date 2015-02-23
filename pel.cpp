
/***************************************************/
/****          Plan Epargne Logement            ****/
/****              Marc Abeille                 ****/
/***************************************************/

#include "pel.h"

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
bool Pel::Ajouter(double mtt)
{
time_t nbAnneesMax=126227704;
time_t dateDuJour=time(NULL);
time_t dateVersementMax;

dateVersementMax=this->dateJ+nbAnneesMax;

if (dateDuJour>dateVersementMax)
    {
    cout<<"Vous ne pouvez plus effectuer de versement Exceptionnel"<<endl;
    return false;
    }
else
    {
    this->soldePel=this->soldePel+mtt;
    return true;
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
time_t Ouverture=0;
int years=0;
int days=0;

Ouverture=time(NULL)-this->dateJ;
cout<<"____________________________________________________________"<<endl;
ConversionStoAJ(Ouverture,years,days);
out<<"Client n°: "<<this->indice<<" Compte ouvert depuis "<<years<<" an(s)"<<" et "<<days<<" jour(s)"<<endl<<endl;
out<<"Solde du  PEL _ _ _ _ _: "<<this->soldePel<<endl;
out<<"Versement mensuel _ _ _: "<<this->versementMensuel<<endl;
out<<"Taux d'interet Annuel _: "<<this->tauxEmprunt<<endl;
out<<"Coeff d'emprunt fixé à : 2,5"<<endl;
out<<"Date de Creation_ _ _ _: ";
date::AfficherDate(this->dateJ);
this->TempsRestantEmprunt();
this->MontantEmpruntable();
cout<<"____________________________________________________________"<<endl;
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
time_t tempsRestantMin;
time_t dateDuJour=time(NULL);
time_t dateDeblocageMin;
time_t nbAnneesMin=126227704;

dateDeblocageMin=this->dateJ+nbAnneesMin;
tempsRestantMin=dateDeblocageMin-dateDuJour;

do
    {
    cout<<"Saisissez le nouveau montant de vos versements mensuels: ";
    cin >>this->versementMensuel;
    if (versementMensuel==0&&tempsRestantMin>0)
        {
        cout<<"Vous ne pouvez pas passer le montant des versements à 0 avant le ";
        date::AfficherDate(dateDeblocageMin);
        }
    }
while (versementMensuel==0&&tempsRestantMin>0);

}

void Pel::TempsRestantEmprunt()
{
time_t dateDuJour=time(NULL);
time_t tempsRestantMin;
time_t tempsRestantMax;
time_t dateDeblocageMin;
time_t dateDeblocageMax;
time_t nbAnneesMin=126227704;
time_t nbAnneesMax=220898482;
int days;
int years;

dateDeblocageMin=this->dateJ+nbAnneesMin;
dateDeblocageMax=this->dateJ+nbAnneesMax;
tempsRestantMin=dateDeblocageMin-dateDuJour;
tempsRestantMax=dateDeblocageMax-dateDuJour;

ConversionStoAJ(tempsRestantMin,years,days);

cout<<"----------------------------------------------------"<<endl;
if (dateDeblocageMin<dateDuJour)
    cout<<"Vous pouvez emprunter dès aujourd'hui"<<endl;
else
    cout<<"Vous pourrez emprunter dans "<<years<<" annee(s) "<<days<<" jour(s)"<<endl;
cout<<"----------------------------------------------------"<<endl;
cout<<"Date Minimum: ";
date::AfficherDate(dateDeblocageMin);
cout<<"Date Cloture: ";
date::AfficherDate(dateDeblocageMax);
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

/*Fonction de calcul du montant empruntable a terme min et max*/
void Pel::MontantEmpruntable()
{
double coeff=2.5;
double montantEmpruntable=0;
time_t dateDeblocageMin;
time_t nbAnneesMin=126227704;
time_t tempsRestantMin;
time_t tempsRestantMax;
time_t dateDeblocageMax;
time_t nbAnneesMax=220898482;
time_t dateDuJour=time(NULL);
double soldeADate=0;
double interets=0;
int years;
int days;

dateDeblocageMin=this->dateJ+nbAnneesMin;
dateDeblocageMax=this->dateJ+nbAnneesMax;
tempsRestantMin=dateDeblocageMin-dateDuJour;
tempsRestantMax=dateDeblocageMax-dateDuJour;
cout<<"--------------------------------------------------------"<<endl;
cout<<"Calcul du montant empruntable (interets annuels inclus):"<<endl;
cout<<"--------------------------------------------------------"<<endl;
if (this->dateJ>=dateDeblocageMin)
    {
    montantEmpruntable=this->soldePel*coeff;
    cout<<"Vous pouvez emprunter des maintenant la somme de "<<(double)montantEmpruntable<<" euros"<<endl;

    ConversionStoAJ(tempsRestantMax,years,days);
    soldeADate=(soldePel+(years*12+(days/30.4167))*this->versementMensuel);
    this->CalculInteret(soldeADate,interets,years);
    montantEmpruntable=(soldeADate+interets)*coeff;
    cout<<"A date de cloture: "<<montantEmpruntable<<" euros";
    }
else
    {
    ConversionStoAJ(tempsRestantMin,years,days);
    soldeADate=(soldePel+(years*12+(days/30.4167))*this->versementMensuel);
    this->CalculInteret(soldeADate,interets,years);
    montantEmpruntable=(soldeADate+interets)*coeff;
    cout<<"A date de déblocage min: "<<montantEmpruntable<<" euros"<<endl;

    ConversionStoAJ(tempsRestantMax,years,days);
    soldeADate=(soldePel+(years*12+(days/30.4167))*this->versementMensuel);
    this->CalculInteret(soldeADate,interets,years);
    montantEmpruntable=(soldeADate+interets)*coeff;
    cout<<"A la date de cloture_ _: "<<montantEmpruntable<<" euros"<<endl;
    }
}

/*Fonction de calcul du montant des interets*/
void Pel::CalculInteret(double mttTotal, double &mttInterets,int nbAnnees)
{
mttInterets=mttTotal*(((double)this->tauxEmprunt/100)*(double)nbAnnees);
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
