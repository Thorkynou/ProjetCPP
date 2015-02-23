
#include "comptegeneral.h"

CompteGeneral::CompteGeneral (string name="")//constructeur par defaut et parametre
{
    nom=name;
}

CompteGeneral::CompteGeneral (const CompteGeneral &CG)//constructeur par copie
{
    nom=CG.nom;
}


 CompteGeneral::~CompteGeneral()
 {}
