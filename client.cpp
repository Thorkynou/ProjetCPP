/**************************************************
 *                  Projet C++                    *
 * Bénédicte, Marc, Alain, Clément S et Clément L *
 *                                                *
 * Fichier: client.cpp                            *
 * @author: Clément L                             *
 **************************************************/


#include <iostream>
#include <string>
#include "client.h"
using namespace std;

Client::Client(int indice, string nom, string prenom, string adresse, bool LE, bool CB, bool PEL, bool EC)
{
	this->indice = indice;
	this->nom = nom;
	this->prenom = prenom;
	this->adresse = adresse;
	this->LE = LE;
	this->CB = CB;
	this->PEL = PEL;
	this->EC = EC;
}

Client::Client(const Client &C)
{
	indice = C.indice;
	nom = C.nom;
	prenom = C.prenom;
	adresse = C.adresse;
	LE = C.LE;
	CB = C.CB;
	PEL = C.PEL;
	EC = C.EC;
	compteC = C.compteC;
}

void Client::Saisir(istream &in, int indice)
{
	this->indice = indice;
    cout << endl << "Entrez le nom du client" << endl;
    in >> nom;
    cout << "Son prenom" << endl;
    in >> prenom;
    cout << "Son adresse(pitie, sans espaces, underscore a la place)" << endl;
    in.ignore();
    getline(in, adresse); // Dans le cas d'une saisie avec espaces
    EcritureFichier();
}

void Client::Afficher(ostream &out) const
{
	out << "Nom : " << nom << endl;
	out << "Prenom : " << prenom << endl;
	out << "Adresse : " << adresse << endl;
	out << endl;
	if(LE)
		out << "a un livret d'epargne" << endl;
	if(CB)
		out << "a un compte bloque" << endl;
	if(PEL)
		out << "a un PEL" << endl;
	if(EC)
		out << "a un e-compte" << endl;
}

void Client::ModifierAdresse(string adresse)
{
	this->adresse = adresse;
}

Client & Client::operator=(const Client &C)
{
	cout << "utilisation d'operator=" << endl;
	nom = C.nom;
	prenom = C.prenom;
	adresse = C.adresse;
	LE = C.LE;
	CB = C.CB;
	PEL = C.PEL;
	EC = C.EC;
	return (*this);
}

Client::~Client()
{
	cout<<"destructeur du client" << endl;
}

ostream & operator<<(ostream &out, const Client &C)
{
	C.Afficher(out);
	return out;
}

istream & operator>>(istream &in, Client &C)
{
	C.Saisir(in);
	return in;
}

void Client::CreationPEL()
{
	this->PEL = true;
	this->comptePEL.CreerPel();
}

void Client::DestructionPEL()
{
	this->PEL = false;
}

void Client::CreationLE()
{
	this->LE = true;
	this->compteLE.CreerCompte();
}

void Client::DestructionLE()
{
	this->LE = false;
}

void Client::CreationCB()
{
	this->CB = true;
	this->compteCB.CreerCompte();
}

void Client::DestructionCB()
{
	this->CB = false;
}

void Client::CreationEC()
{
	this->EC = true;
	this->compteEC.CreerCompte();
}

void Client::DestructionEC()
{
	this->EC = false;
}

void Client::AjoutPEL(double N)
{
	if(comptePEL.Ajouter(N))
		this->compteC.Retirer(N);
}

void Client::AjoutLE(double N)
{
	this->compteC.Retirer(N);
//	this->compteLE.Ajouter(N);
}

void Client::AjoutCB(double N)
{
	this->compteC.Retirer(N);
	this->compteCB.Ajouter(N);
}

void Client::RetirerLE(double N)
{
	this->compteLE.Retirer(N);
	this->compteC.Ajouter(N);
}

void Client::RetirerCB(double N)
{
	this->compteCB.Retirer(N);
	this->compteC.Ajouter(N);
}

void Client::EcritureFichier()const
{
	ofstream monFichier;
	monFichier.open("clients.txt",ofstream::app);
	monFichier << this->indice << ";" << this->nom << ";" << this->prenom << ";" << this->adresse << ";" << this->LE << ";" << this->CB << ";" << this->PEL << ";" << this->EC << ";" << endl;
	monFichier.close();
}

void ExtractionFichier(vector<Client>&mesClients)
{
	Client monClient(0);
	int k=0;
	int j=0;
	int taille=0;

	vector <string> ligneFichier;
	string maLigne;
	string mot;
	string maLigneCSV;

	fstream monFichier;

	monFichier.open("clients.txt",ofstream::in);
	if (monFichier.fail())
    	cerr<<"Le fichier n'existe pas"<<endl;
	else
    {
    	while (monFichier.eof()!=true)
        {
        	monFichier >> maLigneCSV;
        	ligneFichier.push_back(maLigneCSV);
        	maLigneCSV.clear();
        }
    	ligneFichier.pop_back();
    	taille=ligneFichier.size();
    }
	monFichier.close();

	mesClients.resize(taille);

	for (k=0;k<taille;k++)
    {
    	maLigne=ligneFichier[k];
    	istringstream iss(maLigne);

    	j=0;
    	while (getline(iss,mot,';'))
        {
        	switch(j)
            {
            	case 0:mesClients[k].indice=atoi(mot.c_str());
                	break;
            	case 1:mesClients[k].nom=mot.c_str();
                	break;
            	case 2:mesClients[k].prenom=mot.c_str();
                	break;
            	case 3:mesClients[k].adresse=mot.c_str();
                	break;
            	case 4:mesClients[k].LE=atoi(mot.c_str());
                	break;
            	case 5:mesClients[k].CB=atoi(mot.c_str());
                	break;
            	case 6:mesClients[k].PEL=atoi(mot.c_str());
                	break;
            	case 7:mesClients[k].EC=atoi(mot.c_str());
                	break;
            }
        	j++;
        }
    }
}

/*Fonction de suppression et écriture d'un nouveau fichier apres modif de vector*/
void ReecritureFichier(const vector<Client>&mesClients)
{
	ofstream monFichier;
	ofstream tempFichier;
	int taille=0;

	tempFichier.open("tempClients.txt",ofstream::app);
	taille=mesClients.size();

	for(int i=0;i<taille;i++)
	{
   		tempFichier << mesClients[i].nom << ";" << mesClients[i].prenom << ";" << mesClients[i].adresse << ";" << mesClients[i].LE << ";" << mesClients[i].CB << ";" << mesClients[i].PEL << ";" << mesClients[i].EC << ";" << endl;
	}
	tempFichier.close();

	remove("clients.txt");
	rename("tempClients.txt","clients.txt");
}

/*Fonction de recherche par indice dans un vector*/
void Client::RechercheParIndice(vector<Client>&mesClients,int indice)
{
	int taille=0;

	taille=mesClients.size();

	for (int i=0;i<taille;i++)
    {
   		if (mesClients[i].indice==indice)
        	*this=mesClients[i];
    }
}
