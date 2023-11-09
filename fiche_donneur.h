
#ifndef FICHE_DONNEUR_H_INCLUDED
#define FICHE_DONNEUR_H_INCLUDED
#include <stdio.h>

typedef struct 
{

char nom[50];
char prenom[50];
int cin;
int telephone;
int age;
char lieu[50];
int sexe;
char type_sanguin[10];
char type_de_don[20];
int question1;
int question2;
char question3[100];
}fiche_donneur;

int ajouter(char *, fiche_donneur );
int modifier( char *, int, fiche_donneur );
int supprimer(char *, int );
fiche_donneur chercher(char *, int);

#endif // FICHE_DONNEUR_H_INCLUDED

