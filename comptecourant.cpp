/*creation du fichier compte courant.h
fihcier realise par benedicte le */

#include "comptecourant.h"

/*comptecourant::comptecourant()//constructeur par defaut
    {
        cout<<"+++++++++++++Voici le constructeur par defaut du compte courant\n ";
        cout<<endl;
    }
*/
//fonction ok testé
comptecourant::~comptecourant()//destructeur par defaut
    {
        cout<<"--------------Destruction du compte courant\n ";
        cout<<endl;
    }

//fonction ok teste
comptecourant::comptecourant(string nomActions,int numerodecompte,double solde,double decouvert,double taux,bool debiteur,
double montantdebiteur,double agios,double sommeagios,double nbagios)//constructeur par parametres par defaut
    {
        cout<<"+++++++++++++Voici le constructeur par parametres du compte courant \n";
        cout<<endl;

        this->nomActions=nomActions;
        cout<<"Le nom de l'action realise est \t"<<nomActions<<"\n";

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
    }
//fonction ok teste
comptecourant::comptecourant(const comptecourant & CC)//constructeur par copie
    {
        cout<<"+++++++++++++Voici le constructeur par copie du compte courant\n";
        cout<<endl;

        this->nomActions=CC.nomActions;
        cout<<"Le nom de l'action realise est \t"<<nomActions<<"\n";

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
    }

    //fonction teste ok
 comptecourant& comptecourant ::operator=(const comptecourant & CC)
 {
    this->nomActions=CC.nomActions;
    this->numerodecompte=CC.numerodecompte;
    this->solde=CC.solde;
    this->decouvert=CC.decouvert;
    this->taux=CC.taux;
    this->debiteur=CC.debiteur;
    this->montantdebiteur=CC.montantdebiteur;
    this->agios=CC.agios;
    this->nbagios=CC.nbagios;

    return *this;
 }
//fonction teste ok
double comptecourant ::Retirer(double N)//retrait d'argent sur le compte -->modification pour Clement L
    {
        //cout<<"Saisir la somme a retirer sur le compte en banque\n";
        //cin>>N;
        solde=solde-N;
        return solde;
    }

void comptecourant ::AfficherRetrait()const//affichage du retrait d'argent sur le compte
    {
        cout<<"Le nouveau solde du compte courant est de\t"<<(this->solde)<<"euros\n"<<endl;

    }
//fonction ok -->testé
double comptecourant ::Ajouter(double N)//ajout d'argent sur le compte -->pb
    {
       // cout<<"\nSaisir la somme a ajouter sur le compte en banque\n";
       // cin>>N;
        solde=solde+N;
        return (solde);
    }

void comptecourant ::AfficherAjout()const//affichage de l'ajout d'argent sur le compte
{
   cout<<"le nouveau solde du compte courant est de \t"<<(this->solde)<<" euros\n"<<endl;
}


//fonction testé -->ok
comptecourant & comptecourant::operator+(int N)//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
    {
        this->solde=this->solde+N;
        return *this;
    }

//fonction testé -->ok
comptecourant & comptecourant::operator-(int N)//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)
    {
        this->solde=this->solde-N;
        return *this;
    }

//fonction teste ok
void comptecourant::AfficherSolde(ostream &out)//affiche le solde du compte  -->ok testé
    {
        out<<solde<<endl;
    }


//fonction teste ok
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

//fonction teste ok (a voir avec plusieurs actions si ca marche. pour un jour ca donne le bon resultat
double comptecourant::CalculAgios()
    {
        //int nbjoursdebiteur=0;
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
                //faire la valeur absolue du solde
                montantdebiteur=(this->solde)*(-1);
                cout<<"le montant debiteur est de\t"<<montantdebiteur<<" euros\n";
                cout<<endl;
                sommedebiteur=somme+montantdebiteur;
                cout<<"la somme debiteur est de\t"<<sommedebiteur<<" euros\n";
                cout<<endl;
            }

        (this->agios)=(sommedebiteur*tauxinteretdecouvert)/365;
        cout<<"le nombre d'agios pour ce jour est de \t"<<agios<<" euros\n";//-->ok
        cout<<endl;
        (this->sommeagios)=(this->sommeagios)+(this->agios);
        (this->nbagios)=(this->sommeagios)+5.90;//5.90€ de taxe de commissions
        AffichageAgios(nbagios);

    return (this->nbagios);

       // compte debiteur du 5 au 22 janvier de 500 euros et du 2 au 28 mars de 450.
       // montantdebiteur=(17*500)+(26*450)=20200
      //  agios=(20200*12)/36500//tx d'interet de 12%
       // agios=11.07euros +5.90€ de taxe de commissions

    }
//fonction teste ok
void comptecourant::AffichageAgios(const double &nbagios)const//affichage des agios que le client doit payer-->testée ok
    {
        cout<<"votre compte est a decouvert, vous devez payer\t"<<(this->nbagios)<<" euros\n"<<endl;
    }

    //fonction en cours
/*
void comptecourant::Afficher10Actions()const//affichage des 10 dernieres actions faite sur le compte
//ouvrir un fichier et le fermer apres;
       //recuperer avec un vector <comptecourant>les 10 dernieres lignes du fichiers , faire une boucle avec begin et end.
    {
        comptecourant * Tab_Actions[taille];
        int i;
        int nbMAxElem;//define 100



        for (i=0;i<nbMAxElem;i++)
            {   comptecourant *temporaire=new comptecourant(this->nomAction,this->solde);
                Tab_Actions[i]=*temporaire;
               // cin>>Tab_Actions[i]>>solde;
            }

        for (i=0;i<nbMAxElem;i++)
            {
                cout<<Tab_Actions[i];
            }

        delete[]Tab_Actions;

        vector<Tab_Actions> MesActions;//declarationsdu fichiers qui va repertorier les actions
        vector<Tab_Actions> ::iterator it;
        int idx;

        for (it=MesActions.rbegin();it!=MesActions.rend();it++)
            {
                cout<<"action numero ["<<idx--<<"]"="<<(*it)"<<endl;
            }

        for (idx=0;idx<10;idx++)
                {
                    cout<<"le solde suite a cette action est de "<<solde<<" euros\n";
                }*/


/*
comptecourant& comptecourant ::operator!=(const comptecourant & CC)
  {
    return *this;
        cout<<"surcharge de l'operateur != \n";

        this->numerodecompte!=CC.numerodecompte;
        this->solde!=CC.solde;
        this->decouvert!=CC.decouvert;
        this->taux!=CC.taux;
        this->debiteur!=CC.debiteur;
        this->montantdebiteur!=CC.montantdebiteur;
        this->agios!=CC.agios;
        this->sommeagios!=CC.sommeagios;
        this->nbagios!=CC.nbagios;

        return *this;
  }
*/

//fonction teste ok
istream &operator>>(istream &in,const comptecourant & CC)
    {

        return in;
    }

//fonction teste ok
ostream &operator<<(ostream &out,comptecourant & CC)
 {
       // CC.AfficherSolde(out);
        //CC.AffichageAlerte(out);
        return out;
    }


//creation d'un fichier
//fonction en cours
void comptecourant::EcritureFichier()const
    {
        //creation du fichier
        ofstream fichier_compte_courant;

        fichier_compte_courant.open("comptecourant.txt",ofstream::app);
        //verification que le l'ouverture du fichier s'est bien passee
            if(fichier_compte_courant.is_open())
                {
                    cout<<"le fichier est ouvert\n";
                }
            else  // sinon
                {
                    cerr << "Erreur à l'ouverture !" << endl;
                }

        fichier_compte_courant<<this->nomActions<<";"<<this->solde<<";"<<";"<<endl;

        //fermeture du fichier
        fichier_compte_courant.close();
        //verification que la fermeture du fichier s'est bien passee
            if (fichier_compte_courant.eof())
                cout<<"fin de fichier atteinte";

    }






