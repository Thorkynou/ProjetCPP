//creation du fichier compte courant.h

#include <iostream>
#include <string>

#include GeneraliteCompte.h

#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

class CompteCourant:public GeneraliteCompte
{

private:
        int decouvert;//variable autorisant un decouvert au client
public:
        int agios;//calcul des agios si on depasse le decouvert

        CompteCourant();//constructeur par defaut
        CompteCourant(decouvert=0);//constructeur par parametres
        //constructeur par copie

        void Afficher10Actions()const;
        void Retirer();
        void Ajouter();
        void AffichageAlerte();
        int CalculAgios();
        void AffichageAgios()const;

};

#endif
