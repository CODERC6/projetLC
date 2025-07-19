#include <stdio.h>
#include "bibliotheque.h"
#include<string.h>
#define MAX 100
int generer_isbn()
{
    static int isbn_courant = 10000;
    isbn_courant++;
    return isbn_courant;
}
void emprunterLivre(Livre livres[], Emprunt emprunts[], int nb, int nbEmprunts)
{
    int isbn;
    if (nb == 0)
    {
        printf("Aucun livre n'est disponible dans la bibliotheque.\n");
        return 0;
    }
    printf("Entrez l'ISBN du livre a emprunter : ");
    scanf("%d", &isbn);
    getchar();
    int trouve = 0;
    for (int i = 0; i < nb; i++)
    {
        if (livres[i].isbn == isbn && livres[i].estEmprunte == 0)
        {
            livres[i].estEmprunte = 1;
            emprunts[nbEmprunts].isbn = isbn;
            printf("Nom de l'etudiant emprunteur : ");
            gets(emprunts[nbEmprunts].nom_emprunteur);
            printf("Date d'emprunt (jj/mm/aaaa) : ");
            gets(emprunts[nbEmprunts].date);
            printf("Date de retour prevue (jj/mm/aaaa) : ");
            gets(emprunts[nbEmprunts].date_retour);
            nbEmprunts++;
            trouve = 1;
            printf("Livre emprunte avec succes.\n");
            break;
        }
    }
    if (trouve == 0)
    {
        printf("Livre non disponible ou ISBN incorrect ou deja emprunter.\n");
    }
}

void afficherEmprunts(Emprunt emprunts[], int nbEmprunts)
{
    if (nbEmprunts == 0)
    {
        printf("Aucun emprunt enregistre.\n");
    }
    else
    {
        printf("\nListe des emprunts en cours :\n");
        for (int i = 0; i < nbEmprunts; i++)
        {
            printf("Emprunt %d :\n", i + 1);
            printf("ISBN             : %d\n", emprunts[i].isbn);
            printf("Emprunteur       : %s\n", emprunts[i].nom_emprunteur);
            printf("Date d'emprunt   : %s\n", emprunts[i].date);
            printf("Date de retour   : %s\n\n", emprunts[i].date_retour);
        }
    }
}

void retournerLivre(Livre livres[], int nb)
{
    int isbn;
    int jours_retard;
    printf("Saisir l'ISBN du livre a retourner : ");
    scanf("%d", &isbn);
    int trouve = 0;
    for (int i = 0; i < nb; i++)
    {
        if (livres[i].isbn == isbn)
        {
            trouve = 1;
            if (livres[i].estEmprunte == 1)
            {
                livres[i].estEmprunte = 0;
                printf("Combien de jours de retard ? ");
                scanf("%d", &jours_retard);
                if (jours_retard > 0)
                {
                    int amende = jours_retard * 500;
                    printf("Vous devez payer une amende de %d pour %d jour(s) de retard.\n", amende, jours_retard);

                }
                else
                {
                    printf("Retour fait dans les temps. Aucune amende.\n");
                }

                printf("Livre retourner avec succes !\n");
            }
            else
            {
                printf("Ce livre n'etait pas emprunte.\n");
            }
        }
    }

    if (!trouve)
    {
        printf("Livre non trouve.\n");
    }
}


void menu()
{
    printf("\033[1;36m**************** BIENVENUE DANS LE GESTIONNAIRE DE BIBLIOTHEQUE ********************\033[0m\n");
    printf("1. Ajouter un livre\n");
    printf("2. Afficher les livres\n");
    printf("3. Rechercher un livre par son titre\n");
    printf("4. Supression d'un livre par son ISBN\n");
    printf("5. Emprunt d'un livre par son ISBN\n");
    printf("6. Retourner le livre  emprunter par son ISBN\n");
    printf("7. Afficher les emprunts en cours\n");
    printf("8. Affichage des statistiques du bibliotheque\n");
    printf("0. Quitter\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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
        menu();
        printf("Saisir votre choix: ");
        scanf(" %d", &choix);
        getchar(); // absorbe le \n après le choix
        switch(choix)
        {

        case 5:
            emprunterLivre(livres, emprunts, nb, nbEmprunts);
            nbEmprunts++;
            break;
        case 6:
            retournerLivre(livres, nb);
            break;
        case 7:
            afficherEmprunts(emprunts, nbEmprunts);
            break;

        case 0:
            printf("Au revoir !\n");
            return;

        default:
            printf("Choix invalide , veuillez reessayer.\n");
        }
    }
}
