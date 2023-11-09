#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fiche_donneur.h"

int main()
{
    fiche_donneur fd1= {"Taleb","Mansour",11418459,23310165,24,"Bizerte",1,"A+","sang",1,0,"non"},fd2= {"hamzaoui","Aziz",12225548,50310165,22,"Tunis",1,"O+","sang",0,0,"oui"};
 
 int x=ajouter("fiche_donneur.txt", fd1);
    if(x==1)
        printf("\najout de donneur avec succés");
    else printf("\nechec ajout");

/////////////////////////////////////////////////////////////
 /*int y=modifier("fiche_donneur.txt",11418459,fd2 );
    if(y==1)
        printf("\nModification de la fiche donneur avec succés");
    else printf("\nechec Modification");
////////////////////////////////////////////////////////////
 */  int z=supprimer("fiche_donneur.txt",11418459 );
    if(z==1)
        printf("\nSuppression de la fiche donneur avec succés");
    else printf("\nechec Suppression");
////////////////////////////////////////////////////////////
   fiche_donneur fd3=chercher("fiche_donneur.txt",11418459 );
    if(fd3.cin==-1)
        printf("introuvable");
else printf("exist");
    return 0;
}
