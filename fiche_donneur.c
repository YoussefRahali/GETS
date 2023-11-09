
#include "fiche_donneur.h"


int ajouter(char * filename, fiche_donneur fd )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %s %d %s %s %d %d %s \n",fd.nom,fd.prenom,fd.cin,fd.telephone,fd.age,fd.lieu,fd.sexe,fd.type_sanguin,fd.type_de_don,fd.question1,fd.question2,fd.question3);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int cin, fiche_donneur nouv )
{
    int tr=0;
    fiche_donneur fd;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %s %d %s %s %d %d %s",fd.nom,fd.prenom,&fd.cin,&fd.telephone,&fd.age,fd.lieu,&fd.sexe,fd.type_sanguin,fd.type_de_don,&fd.question1,&fd.question2,fd.question3)!=EOF)
        {
            if(fd.cin== cin)
            {
                       fprintf(f,"%s %s %d %d %d %s %d %s %s %d %d %s \n",nouv.nom,nouv.prenom,fd.cin,fd.telephone,fd.age,fd.lieu,fd.sexe,fd.type_sanguin,fd.type_de_don,fd.question1,fd.question2,fd.question3);
                tr=1;
            }
            else
                        fprintf(f2,"%s %s %d %d %d %s %d %s %s %d %d %s \n",fd.nom,fd.prenom,fd.cin,fd.telephone,fd.age,fd.lieu,fd.sexe,fd.type_sanguin,fd.type_de_don,fd.question1,fd.question2,fd.question3);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int cin)
{
    int tr=0;
    fiche_donneur fd;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %s %d %s %s %d %d %s \n",fd.nom,fd.prenom,&fd.cin,&fd.telephone,&fd.age,fd.lieu,&fd.sexe,fd.type_sanguin,fd.type_de_don,&fd.question1,&fd.question2,fd.question3)!=EOF)
        {
            if(fd.cin== cin)
                tr=1;
            else
                 fprintf(f2,"%s %s %d %d %d %s %d %s %s %d %d %s \n",fd.nom,fd.prenom,fd.cin,fd.telephone,fd.age,fd.lieu,fd.sexe,fd.type_sanguin,fd.type_de_don,fd.question1,fd.question2,fd.question3);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
fiche_donneur chercher(char * filename, int cin)
{
    fiche_donneur fd ;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %d %d %s %d %s %s %d %d %s \n",fd.nom,fd.prenom,&fd.cin,&fd.telephone,&fd.age,fd.lieu,&fd.sexe,fd.type_sanguin,fd.type_de_don,&fd.question1,&fd.question2,fd.question3)!=EOF)
        {
            if(fd.cin== cin)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        fd.cin=-1;
    return fd;

}







