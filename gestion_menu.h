/*creation du fichier gestion_menu.h fichier realise par benedicte le 21 fevrier 2015*/

#include <iostream>

#ifndef GESTION_MENU_H
#define GESTION_MENU_H

#include "date.h"
#include "client.h"
#include "comptebloque.h"
#include "comptecourant.h"
#include "operation.h"
#include "pel.h"
#include "ecompte.h"
#include"livretepargne.h"
#include "client.h"

class GestionMenu
{
public:
    static void AjoutCompte(Client &C);
    static void SupprimerCompte(Client &C);
    static int  MenuChoixCompte();

    static void AffichageComptes(Client &C);

    static void RepetitionAffichageCompte(Client &C);
    static void ConsulterComptes(Client &C);

    static void OperationCompteCourant(comptecourant &CC);
    static void OperationCompteBloque(CompteBloque &CB);
    static void OperationPEL(Pel &PEL);
    static void OperationEcompte(ecompte &EC);
    static void OperationLivretEpargne(LivretEpargne &LE);
};

#endif
