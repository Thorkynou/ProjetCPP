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


comptecourant::comptecourant(int numerodecompte,double solde,double decouvert,double taux):evenement()//constructeur par parametres par defaut--> ok testé
    {
        evenement.Saisir();
        evenement.Afficher();
        cout<<"+++++++++++++Voici le constructeur par parametres du compte courant\n";
        cout<<endl;
        cout<<"\nLe numero de compte courant est le\t"<<numerodecompte<<endl;
        cout<<endl;
        cout<<"\nLe solde de ce compte courant est de \t"<<solde<<" euros"<<endl;
        cout<<endl;
        cout<<"\nLe decouvert autorise par la banque est de \t"<<decouvert<<" euros"<<endl;
        cout<<endl;
        cout<<"\nCe compte courant a un taux d'interêt de\t"<<taux<<" %"<<endl;

    }

comptecourant::comptecourant(const comptecourant & CC):evenement(CC.evenement)//constructeur par copie
    {
        cout<<"+++++++++++++Voici le constructeur par copie du compte courant\n";
        cout<<endl;
        evenement.Afficher();
        //a verifier (je n'ai pas encore tester
       /* numerodecompte=CC.numerodecompte;
        cout<<numerodecompte;
        cout<<endl;
        solde=CC.solde;
        cout<<solde;
        cout<<endl;
        decouvert=CC.decouvert;
        taux=CC.taux;
        debiteur=CC.debiteur;*/

    }
    /*
void comptecourant ::Retirer()//retrait d'argent sur le compte
    {

        cout<<"le nouveau solde du compte est "<<solde<<endl;

    }


void comptecourant::Ajouter()//ajout d'argent sur le compte
    {
        cout<<"le nouveau solde du compte est "<<solde<<endl;

    }*/
    //testé -->ok
comptecourant & comptecourant::operator+(int N)//on aura solde2=solde1.operator+(100)              (solde2=solde1+100)
    {
        comptecourant CC= *this;
        CC.solde=CC.solde+N;
        return CC;
    }

    //testé -->ok
comptecourant & comptecourant::operator-(int N)//on aura solde2=solde1.operator-(100)              (solde2=solde1-100)
{
        comptecourant CC= *this;
        CC.solde=CC.solde-N;
        return CC;
    }


void comptecourant::AfficherSolde(ostream & out)//affiche le solde du compte
    {
        out<<solde<<endl;
    }
//void comptecourant::AffichageAlerte(ostream & out)//affichage d'un message d'alerte quand le solde =le decouvert autorise

//int comptecourant::CalculAgios(int solde,bool debiteur)//
   /* {
        int nbjoursdebiteur=0;
        double tauxinteretdecouvert=0.12;
    }
*/
//void comptecourant::AffichageAgios()const//affichage des agios que le client doit payer

//void comptecourant::Afficher10Actions()const//affichage des 10 dernieres actions faite sur le compte



// a l'exterieur de la classe
/*comptecourant operator+(int N,const comptecourant & CC)//pour l'ajout d'argent on aura solde3=operator+(100,solde2)  (solde3=100+solde2)
    {
        return CC+N;
    }


comptecourant operator-(intN,const comptecourant &CC);//pour le retrait d'argent on aura solde3=operator-(100,solde2)  (solde3=100-solde2)
    {
        return CC-N;
    }
  */

istream & operator >>(istream & in,const comptecourant & CC)
    {
        //C.Saisir(in);
        return in;
    }


ostream & operator<<(ostream & out,comptecourant & CC)
 {
        CC.AfficherSolde(out);
        return out;
    }



