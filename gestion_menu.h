#ifndef GESTION_MENU_H
#define GESTION_MENU_H

#include "client.h"

class GestionMenu
{
public:
    static void AjoutCompte(Client &C);
    static void SupprimerCompte(Client &C);
    static int  MenuChoixCompte();

    static void AffichageComptes(Client &C);

    static void RepetitionAffichageCompte(Client &C);

    static void OperationCompteCourant(comptecourant &CC);
};

#endif
