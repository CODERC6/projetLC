#include <stdio.h>
#include "bibliotheque.h"
#include<string.h>
#define MAX 100


void afficherLivre(Livre livres[], int nb)
{
    if (nb == 0)
    {
        printf("Aucun livre enregistre pour le moment.\n");
        return;
    }

    printf("\nListe des livres enregistres :\n\n");
    printf("Y'a %d Enregistre !!!",nb);
    for (int i = 0; i < nb; i++)
    {
        printf("\nLivre %d\n", i + 1);
        printf("Titre  : %s\n", livres[i].titre);
        printf("Auteur : %s\n", livres[i].auteur);
        printf("Annee  : %d\n",livres[i].annee);
        printf("ISBN   : %d\n", livres[i].isbn);
        if (livres[i].estEmprunte == 1)
        {
            printf("Etat   : Emprunte\n");
        }
        else
        {
            printf("Etat   : Disponible\n");
        }
    }
}

void principal()
{
    Livre livres[MAX];
    int nb = 0, choix;

    while(1)
    {
        system("pause");
        system("cls");
        printf("Saisir votre choix: ");
        scanf(" %d", &choix);
        getchar();
        switch(choix)
        {
        case 2:
           afficherLivre(livres,nb);
            break;

}
}
}
