/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: comptebloque.cpp                      *
 * @author: Clément L                             *
 **************************************************/

#include "comptebloque.h"

CompteBloque::CompteBloque(time_t dateCB, int indice, double taux, double solde, double annees): date(dateCB)
{
	this->indice = indice;
	this->taux = taux;
	this->solde = solde;
	this->annees = annees;
}

CompteBloque::CompteBloque(const CompteBloque &CB)
{
	indice = CB.indice;
	taux = CB.taux;
	solde = CB.solde;
	annees = CB.annees;
}

void CompteBloque::CreerCompte()
{
	cout << "Creation d'un compte bloque" << endl;
	cout << "Saisir un taux: " << endl;
	cin >> this->taux;
	EcritureFichier();
}

void CompteBloque::Afficher(ostream & out)
{
	cout << "___________________________________________________"<<endl;
	out << "Client n°: " << this->indice << endl;
	out << "Taux: " << this->taux << endl;
	out << "Solde: " << this->solde << endl;
	out << "Date de Creation: ";
	date::AfficherDate(this->dateJ);
	this->TempsRestant();
	cout<<"___________________________________________________"<<endl;
}

void CompteBloque::Ajouter(double n)
{
	this->solde = this->solde + n;
}

void CompteBloque::Retirer(double n)
{
	if(RetraitPossible() && (solde-n)>0)
	{
		this->solde = this->solde-n;
		cout << "Virement effectue" << endl;
	}
	else
		cout << "Impossible de retirer" << endl;
}

void CompteBloque::EcritureFichier()
{
	ofstream monFichier;
	monFichier.open("CB.txt",ofstream::app);
	MiseAJour();
	monFichier << this->indice << ";" << this->taux << ";" << this->solde << ";" << this->dateJ << ";" << this->annees << ";" << endl;
	monFichier.close();
}

void CompteBloque::AfficherIndice()const
{
	cout<<"L'indice CB est: "<<this->indice<<endl;
}

ostream & operator<<(ostream &out, CompteBloque &CB)
{
	CB.Afficher(out);
	return out;
}

/*Conversion CSV en vector de class*/
void ExtractionFichier(vector<CompteBloque>&mesCB)
{
	CompteBloque monCB(0);
	int k=0;
	int j=0;
	int taille=0;

	vector <string> ligneFichier;
	string maLigne;
	string mot;
	string maLigneCSV;

	fstream monFichier;

	monFichier.open("CB.txt",ofstream::in);
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

	mesCB.resize(taille);

	for (k=0;k<taille;k++)
    {
	    maLigne=ligneFichier[k];
	    istringstream iss(maLigne);

	    j=0;
	    while (getline(iss,mot,';'))
        {
        	switch(j)
            {
          	  case 0:mesCB[k].indice=atoi(mot.c_str());
          	      break;
          	  case 1:mesCB[k].taux=atoi(mot.c_str());
          	      break;
          	  case 2:mesCB[k].solde=atof(mot.c_str());
          	      break;
          	  case 3:mesCB[k].dateJ=atoi(mot.c_str());
          	      break;
            }
        j++;
        }
    }
}

bool CompteBloque::RetraitPossible()
{
	time_t now = time(NULL);
	double diff;
	diff = difftime(now, this->dateJ);
	if((diff/3600/24/365.25) >= 4) // Si diff est supérieur à 4 ans
		return true;
	else
		return false;
}

void CompteBloque::ConversionStoAJ(int nbSecondes,int &years,int &days)
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

/*Fonction de suppression et écriture d'un nouveau fichier apres modif de vector*/
void ReecritureFichier(const vector<CompteBloque>&mesCB)
{
	ofstream monFichier;
	ofstream tempFichier;
	int taille=0;

	tempFichier.open("tempCB.txt",ofstream::app);
	taille=mesCB.size();

	for(int i=0;i<taille;i++)
   	{
    	tempFichier << mesCB[i].indice << ";" << mesCB[i].taux << ";" << mesCB[i].solde << ";" << mesCB[i].dateJ << ";" << mesCB[i].annees << ";" << endl;
    }
	tempFichier.close();

	remove("CB.txt");
	rename("tempCB.txt","CB.txt");
}

/*Fonction de recherche par indice dans un vector*/
void CompteBloque::RechercheParIndice(vector<CompteBloque>&mesCB,int indice)
{
	int taille=0;

	taille=mesCB.size();

	for (int i=0;i<taille;i++)
    {
    	if (mesCB[i].indice==indice)
        	*this=mesCB[i];
    }
}

void CompteBloque::TempsRestant()
{
	time_t dateDuJour=time(NULL);
	time_t tempsRestantMin;
	time_t dateDeblocageMin;
	time_t nbAnneesMin=126227704;
	int days;
	int years;

	dateDeblocageMin=this->dateJ+nbAnneesMin;
	tempsRestantMin=dateDeblocageMin-dateDuJour;
	ConversionStoAJ(tempsRestantMin,years,days);

	cout<<"----------------------------------------------------"<<endl;
	if (dateDeblocageMin<dateDuJour)
    	cout<<"Vous pouvez retirer des aujourd'hui"<<endl;
	else
    	cout<<"Vous pourrez retirer dans "<<years<<" annee(s) "<<days<<" jour(s)"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"Date Minimum: ";
	date::AfficherDate(dateDeblocageMin);
}

double CompteBloque::CalculTaux()
{
	return((this->solde) * (this->taux)/100); 
}

void CompteBloque::AppliquerTaux()
{
	time_t now = time(NULL);
	double diff;
	diff = difftime(now, dateJ);
	if((diff/365) >= (annees+1))
		solde = solde + CalculTaux();
}