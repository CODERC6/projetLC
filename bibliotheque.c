#include <stdio.h>
#include "bibliotheque.h"
#include<string.h>
#define MAX 100
void statistiques(Livre livres[], int nb)
{
    int nbEmpruntes = 0;
    int nbDisponibles = 0;
    for (int i = 0; i < nb; i++)
    {
        if (livres[i].estEmprunte == 1)
            nbEmpruntes++;
        else
            nbDisponibles++;
    }
    printf("\nStatistiques de la bibliotheque :\n");
    printf("Nombre total de livres        : %d\n", nb);
    printf("Nombre de livres empruntes    : %d\n", nbEmpruntes);
    printf("Nombre de livres disponibles  : %d\n", nbDisponibles);
}

void principal()
{
    Livre livres[MAX];
    int nb = 0, choix;
    Emprunt emprunts[MAX];
    int nbEmprunts = 0, nonEmprunt = 0;
    while(1)
    {
        system("pause");
        system("cls");
        printf("Saisir votre choix: ");
        scanf(" %d", &choix);
        getchar();
        switch(choix)

    }
}
