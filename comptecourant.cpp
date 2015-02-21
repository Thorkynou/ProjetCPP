/*creation du fichier compte courant.h
fihcier realise par benedicte le */

#include "comptecourant.h"


operationbancaire::operationbancaire()//constructeur par defaut
    {//cout<<"+++++++++++++Voici le constructeur par defaut de la classe operation\n "<<endl;
    }

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
    {   //cout<<"--------------Destruction du compte courantde la classe operation\n "<<endl;
    }

/*comptecourant::comptecourant()//constructeur par defaut
    {
        cout<<"+++++++++++++Voici le constructeur par defaut du compte courant\n ";
        cout<<endl;
    }
*/

comptecourant::~comptecourant()//destructeur par defaut
    { //  cout<<"--------------Destruction du compte courant\n "<<endl;
    }

comptecourant::comptecourant(int numerodecompte,double solde,double decouvert,double taux,bool debiteur,
double montantdebiteur,double agios,double sommeagios,double nbagios,int index)//constructeur par parametres par defaut
    {
       // cout<<"+++++++++++++Voici le constructeur par parametres du compte courant"<<endl;
        this->numerodecompte=numerodecompte;
        cout<<"Le numero de compte courant est le \t"<<numerodecompte<<"\n";

        this->solde=solde;
        cout<<"Le solde de ce compte courant est de \t"<<solde<<" euros\n";

         this->decouvert=decouvert;
        cout<<"Le decouvert autorise par la banque est de \t"<<decouvert<<" euros\n";

         this->taux=taux;
        cout<<"Ce compte courant a un taux d'interêt de \t"<<taux<<" % (c'est peu,mais c'est déjà ca)\n";

        this->debiteur=debiteur;
        cout<<"Ce compte peut etre debiteur mais crediteur c'est mieux\n";

        this->montantdebiteur=montantdebiteur;
        cout<<"Le montant debiteur de ce compte est de \t"<<montantdebiteur<<" euros\n";

        this->agios=agios;
        cout<<"Le montant des agios de ce compte est de \t"<<agios<<" euros\n";

        this->sommeagios=sommeagios;
        cout<<"Lasomme des agios pour plusieurs jour de ce compte est de \t"<<sommeagios<<" euros\n";

        this->nbagios=nbagios;
        cout<<"Le montant total des agios de ce compte est de \t"<<nbagios<<" euros\n";

        this->index=index;
    }

comptecourant::comptecourant(const comptecourant & CC)//constructeur par copie
    {
       // cout<<"+++++++++++++Voici le constructeur par copie du compte courant"<<endl;
        this->numerodecompte=CC.numerodecompte;
        cout<<"le numerodecompte par copie est \t"<<numerodecompte<<endl;

        solde=CC.solde;
        cout<<"le solde initial par copie est de \t"<<solde<<" euros"<<endl;

        decouvert=CC.decouvert;
        cout<<"le decouvert autorise par copie est \t"<<decouvert<<" euros"<<endl;

        taux=CC.taux;
        cout<<"le taux de ce compte par copie est \t"<<taux<<"%"<<endl;

        debiteur=CC.debiteur;
        cout<<"ce compte est debiteur ou non par copie : \t"<<debiteur<<endl;

        montantdebiteur=CC.montantdebiteur;
        cout<<"le montant debiteur est \t"<<montantdebiteur<<" euros"<<endl;

        agios=CC.agios;
        cout<<"les agios sont de \t"<<agios<<" euros"<<endl;

        sommeagios=CC.sommeagios;
        cout<<"Le montant des agios de ce compte est de \t"<<sommeagios<<" euros\n";

        nbagios=CC.nbagios;
        cout<<"la somme totale des agios est de  \t"<<nbagios<<" euros"<<endl;

        index=CC.index;
    }


 comptecourant& comptecourant ::operator=(const comptecourant & CC)
 {
    this->numerodecompte=CC.numerodecompte;
    this->solde=CC.solde;
    this->decouvert=CC.decouvert;
    this->taux=CC.taux;
    this->debiteur=CC.debiteur;
    this->montantdebiteur=CC.montantdebiteur;
    this->agios=CC.agios;
    this->sommeagios=CC.sommeagios;
    this->nbagios=CC.nbagios;
    this->index=CC.index;

    return *this;
 }

double comptecourant ::Retirer(double N)//retrait d'argent sur le compte -->modification pour Clement L
    {
        this->Tab_MesActions.push_back(operationbancaire("retrait",N,"vide (non utilisé par le programme)"));
        EcritureFichier();

        solde=solde-N;
        return solde;
    }

double comptecourant ::Ajouter(double N)//ajout d'argent sur le compte
    {
        //operationbancaire nouvelleoperation("Ajout",N,"vide (non utilisé par le programme)");
        this->Tab_MesActions.push_back(operationbancaire("ajout",N,"vide (non utilisé par le programme)"));
        EcritureFichier();//ecriture dans le fichier

        solde=solde+N;
        return (solde);
    }

void comptecourant ::AfficherOperation()//affichage de l'ajout ou du retrait d'argent sur le compte
{
    double paiement=0;
    //LectureFichier();//sert a rien
    cout<<"le nouveau solde du compte courant est de "<<(this->solde)<<" euros\n"<<endl;
    paiement=CalculAgiosJournaliers();
    cout<<"le nombre d'agios  est de \t"<<paiement<<" euros\n";
}


comptecourant & comptecourant::operator+(int N)//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
    {
        this->solde=this->solde+N;
        return *this;
    }


comptecourant & comptecourant::operator-(int N)//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)
    {
        this->solde=this->solde-N;
        return *this;
    }


void comptecourant::AfficherSolde(ostream &out)//affiche le solde du compte  -->ok testé
    {
        out<<solde<<endl;
    }



void comptecourant::AffichageAlerte(ostream &out)//affichage d'un message d'alerte quand le solde =le decouvert autorise
    {
        if((this->solde)<(this->decouvert))
            {
                out<<"!!!!!!!!!!!!!!!!!!!!!!!!!!attention attention !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                out<< "Vous êtes a DECOUVERT\n";
                out<<"Vous devez absolument remettre de l'argent sur votre compte\n";
                out<<"!!!!!!!!!!!!!!!!!!!!!!!!!!attention attention !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                out<<endl;
            }
        else
            {
                out<<"tout va bien sur votre compte en banque\n";
            }
    }

double comptecourant::CalculAgiosJournaliers()
    {
        int nbjoursdebiteur=0;
        double tauxinteretdecouvert=0.12;
        double sommedebiteur=0;
        double somme=0;
        //etape 1 : montantdebiteur=nbjdebiteur*debit //pour chaque montant faire le calcul
        //etape2: agios=(montantdebiteur*txinteretdecouvert)/(365*100)
        if ((this->solde)<(this->decouvert))
            {
                cout<<"votre compte est debiteur\n";
                cout<<endl;
                this->debiteur=true;
            }
        else
            {
                cout<<"votre compte n'est pas debiteur, il est crediteur\n";
                cout<<endl;
                this->debiteur=false;
            }

        if (debiteur) //(this->debiteur)==true
            {
                AffichageAlerte(cout);//affichage du message d'alerte si le compte est debiteur
                cout<<"saisir le nombre de jours debiteur pour le même montant debiteur\n";
                cin>>nbjoursdebiteur;

                montantdebiteur=(this->solde)*(-1)*nbjoursdebiteur;//faire la valeur absolue du solde a *nbjoursdecouvert;
                cout<<"le montant debiteur est de\t"<<montantdebiteur<<" euros\n";
                cout<<endl;
                cout<<endl;
                sommedebiteur=somme+montantdebiteur;
                cout<<"la somme debiteur est de\t"<<sommedebiteur<<" euros\n";
                cout<<endl;
            }

        (this->agios)=(sommedebiteur*tauxinteretdecouvert)/365;

        (this->sommeagios)=(this->sommeagios)+(this->agios);
        cout<<"la somme de vos agios a paye sans les taxes est de \t"<<(this->sommeagios)<<" euros\n";
        return (this->sommeagios);//(this->nbagios)

       // compte debiteur du 5 au 22 janvier de 500 euros et du 2 au 28 mars de 450.
       // montantdebiteur=(17*500)+(26*450)=20200
      //  agios=(20200*12)/36500//tx d'interet de 12%
       // agios=11.07euros +5.90€ de taxe de commissions

    }
//fonction teste ok
void comptecourant::AffichageAgios()//affichage des agios que le client doit payer-->testée ok//const double &agios
    {
            (this->nbagios)=(this->sommeagios)+5.90;//5.90€ de taxe de commissions
        //  AffichageAgios(nbagios);
        cout<<"\nvotre compte est a decouvert, vous devez payer\t"<<(this->nbagios)<<" euros\n"<<endl;
    }

istream &operator>>(istream &in,const comptecourant & CC)
    {
        return in;
    }

ostream &operator<<(ostream &out,comptecourant & CC)
    {
        return out;
    }

void comptecourant::EcritureFichier()
    {
        //creation du fichier comptecourant
        ofstream fichier_compte_courant;
        fichier_compte_courant.open("comptecourant.txt",ofstream::app);// eriture à la fin du fichier avec app

        //verification que le l'ouverture du fichier s'est bien passee
         /*   if(fichier_compte_courant.is_open())
                {   cout<<"le fichier est ouvert\n";    }
            else  // sinon
                {   cerr << "Erreur à l'ouverture !" << endl;   }
        */
        //affichage dans le fichier txt
        operationbancaire nouvelleoperation(this->Tab_MesActions.back());//constructeur par copie appelé
        fichier_compte_courant<<(this->index)+1<<"action"<<";"<<nouvelleoperation.TypeO_B()<<";"<<this->solde<<";"<<(this->nbagios)<<";"<<endl;
        (this->index)++;

        //fermeture du fichier
        fichier_compte_courant.close();
        // cout<<"le fichier est ferme\n";
    }


void comptecourant::Afficher10Actions()//affichage des 10 dernieres actions faite sur le compte
    {
        int i=0;//compteur de boucles
        vector<operationbancaire> ::reverse_iterator it;
        for (it=Tab_MesActions.rbegin();it!=Tab_MesActions.rend();it++)
            {
                if(i<10)
                    {
                        cout <<"L'action numero "<<10-i<<" est une action de \t"<<it->TypeO_B()<<"\td'un montant de \t"<<it->Montant_O_B()<<"euros"<<endl;
                    }
                i++;

            }
    }


void comptecourant::LectureFichier()//ne sert a rien
    {
        fstream fichier_compte_courant;
        fichier_compte_courant.open("comptecourant.txt",fstream::in);//ouverture du fichier en mode lecture avec in

        //verification que le l'ouverture du fichier s'est bien passee
          /*  if(fichier_compte_courant.is_open())
                {   cout<<"les donnees lues sont\n";    }
            else  // sinon
                {   cerr << "Erreur à la lecture !" << endl;    }
        */

          for(index=0;index<Tab_MesActions.size();index++)
            {   operationbancaire nouvelleoperation(this->Tab_MesActions.back());//appel du constructeur par copie
                cout<<"action numero "<<(this->index)+1<<nouvelleoperation.TypeO_B()<<"\t"<<"nouveau solde\t"<<(this->solde)<<endl;
            }

        fichier_compte_courant.close();//fermeture du fichier
}



