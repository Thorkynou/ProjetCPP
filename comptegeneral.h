#include <iostream>

#ifndef COMPTEGENERAL_H
#define COMPTEGENERAL_H

class CompteGeneral
{
    protected:
        string nom; //nom generique du compte de type Compte General de la banque ...

    public:
    CompteGeneral (string name="");//constructeur par defaut et parametre
    CompteGeneral (const CompteGeneral &CG);//constructeur par copie

    virtual~CompteGeneral();
    virtual void Afficher()=0;//fonction virtuelle pure

}

#endif
