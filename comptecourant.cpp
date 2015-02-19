/*creation du fichier compte courant.h
fihcier realise par benedicte le */

#include "comptecourant.h"

/*comptecourant::comptecourant()//constructeur par defaut
    {
        cout<<"+++++++++++++Voici le constructeur par defaut du compte courant\n ";
        cout<<endl;
    }
*/
comptecourant::~comptecourant()//destructeur par defaut-->teste ok
    {
        cout<<"--------------Destruction du compte courant\n ";
        cout<<endl;
    }


comptecourant::comptecourant(int numerodecompte,double solde,double decouvert,double taux)//constructeur par parametres par defaut--> ok testé
    {
       // evenement.Saisir();
       // evenement.Afficher();
        cout<<"+++++++++++++Voici le constructeur par parametres du compte courant \n";
        cout<<endl;
        cout<<"\nLe numero de compte courant est le \t"<<numerodecompte<<endl;
        cout<<endl;
        cout<<"\nLe solde de ce compte courant est de \t"<<solde<<" euros"<<endl;
        cout<<endl;
        cout<<"\nLe decouvert autorise par la banque est de \t"<<decouvert<<" euros"<<endl;
        cout<<endl;
        cout<<"\nCe compte courant a un taux d'interêt de \t"<<taux<<" %"<<endl;

    }

comptecourant::comptecourant(const comptecourant & CC)//constructeur par copie
    {
        cout<<"+++++++++++++Voici le constructeur par copie du compte courant\n";
        cout<<endl;
        //evenement.Afficher();
        //a verifier (je n'ai pas encore tester
        this->numerodecompte=CC.numerodecompte;
        cout<<"le numerodecompte par copie est \t"<<numerodecompte;
        cout<<endl;
        solde=CC.solde;
        cout<<solde;
        cout<<endl;
        decouvert=CC.decouvert;
        taux=CC.taux;
        debiteur=CC.debiteur;
        montantdebiteur=CC.montantdebiteur;
        agios=CC.agios;
        nbagios=CC.nbagios;
    }

 comptecourant& comptecourant ::operator=(const comptecourant & CC)//--> je ne l'ai pas encore tester je le fais dans l'aprem, mais ca fonctionne
 //dans le fonction Calculer agios
 {  this->numerodecompte=CC.numerodecompte;
    this->solde=CC.solde;
    this->decouvert=CC.decouvert;
    this->taux=CC.taux;
    this->debiteur=CC.debiteur;
    this->montantdebiteur=CC.montantdebiteur;
    this->agios=CC.agios;
    this->nbagios=CC.nbagios;

    return *this;
 }

void comptecourant ::Retirer()//retrait d'argent sur le compte -->ok testé
    {
        int N;
        cout<<"saisir la somme a retirer sur le compte en banque\n";
        cin>>N;

        solde=solde-N;
        cout<<"le nouveau solde du compte est \t"<<solde<<endl;

    }

//pb ca n'ajoute pas d'argent(je dois verifier quel solde il prend), il ne prend pas en compte mon solde par defaut de 1500.
//je travaille dessus cet aprem
comptecourant & comptecourant::Ajouter()//ajout d'argent sur le compte -->pb
    {
        int N;
        cout<<"\nsaisir la somme a ajouter sur le compte en banque\n";
        cin>>N;

       this->solde=this->solde+N;
        cout<<"le nouveau solde du compte est \t"<<(this->solde)<<endl;
        return *this;
    }

    //testé -->ok
comptecourant & comptecourant::operator+(int N)//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
    {
        this->solde=this->solde+N;
        return *this;
    }

    //testé -->ok
comptecourant & comptecourant::operator-(int N)//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)
    {
        this->solde=this->solde-N;
        return *this;
    }


void comptecourant::AfficherSolde(ostream &out)//affiche le solde du compte  -->ok testé
    {
        out<<solde<<endl;
    }

//
/*pb dans l'eaglite je regarde ca
void comptecourant::AffichageAlerte(ostream &out)//affichage d'un message d'alerte quand le solde =le decouvert autorise
    {
        if((this->solde)==(this->decouvert))
            {
                cout<<"attention vous allez être à decouvert\n";
                cout<<endl;
            }
        else
            {
                cout<<"tout va bien sur votre compte en banque\n";
            }
    }
*/
//pb à la fin du calcul pour ajouter la taxe sinon ca calcule le nombre d'agios au oins pour un jour
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
                montantdebiteur=(this->solde)*1;
                cout<<"le montantdebiteur est \t"<<montantdebiteur;
                sommedebiteur=somme+montantdebiteur;
                cout<<"la somme debiteur est\t"<<sommedebiteur;
            }

        (this->agios)=(sommedebiteur*tauxinteretdecouvert)/365;
        cout<<"le nombre d'agios est\t"<<agios;//-->ok
        (this->nbagios)=(this->agios)+5.90;//5.90€ de taxe de commissions-->ya un souci dans l'operation

    return (this->nbagios);

       // compte debiteur du 5 au 22 janvier de 500 euros et du 2 au 28 mars de 450.
       // montantdebiteur=(17*500)+(26*450)=20200
      //  agios=(20200*12)/36500//tx d'interet de 12%
       // agios=11.07euros +5.90€ de taxe de commissions

    }

void comptecourant::AffichageAgios(const double &nbagios)const//affichage des agios que le client doit payer
    {
        cout<<"votre compte est a decouvert, vous devez payer\t"<<nbagios<<"euros\n"<<endl;
    }

//void comptecourant::Afficher10Actions()const//affichage des 10 dernieres actions faite sur le compte



// a l'exterieur de la classe
/*comptecourant operator+(int N,const comptecourant & CC)//pour l'ajout d'argent on aura solde3=operator+(100,solde2)  (solde3=100+solde2)
    {
        return CC+N;
    }


comptecourant operator-(int N,const comptecourant &CC);//pour le retrait d'argent on aura solde3=operator-(100,solde2)  (solde3=100-solde2)
    {
        return CC-N;
    }
  */

istream &operator>>(istream &in,const comptecourant & CC)
    {

        return in;
    }


ostream &operator<<(ostream &out,comptecourant & CC)
 {
       // CC.AfficherSolde(out);
        //CC.AffichageAlerte(out);
        return out;
    }



