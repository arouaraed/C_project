#include "projet.h"
#include<assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void creer_liste(struct liste* l){
    l->premier=NULL;
    l->dernier=NULL;
}
unsigned liste_vide(struct liste*l){
    return(l->premier==NULL);

}
unsigned recherche_tel(long int nu, noeud * p) {
     while (p != NULL ){
            if (p->num==nu)
                    return 1;
            p = p->suivant;
    }
     return 0; }
void insere_queue_tel(liste * l){
    long int tel;
    noeud *q;
    q=( noeud*)malloc(sizeof(noeud));
    do
    {
        printf("donner le numero de telephone : ");scanf("%ld",&tel);

    }while(recherche_tel(tel,l->premier)==1);
    q->num=tel;

    printf("Entrez le nom : ");
    fflush(stdin);
    fgets(q->nom, sizeof(q->nom), stdin);
    q->nom[strcspn(q->nom, "\n")] = '\0';
    fflush(stdin);

    printf("Entrez le prenom : ");
    fgets(q->prenom, sizeof(q->prenom), stdin);
    q->prenom[strcspn(q->prenom, "\n")] = '\0';
    fflush(stdin);

    printf("Entrez la rue : ");
    fgets(q->adresse.rue, sizeof(q->adresse.rue), stdin);
    q->adresse.rue[strcspn(q->adresse.rue, "\n")] = '\0';
    fflush(stdin);

    printf("Entrez la ville : ");
    fgets(q->adresse.ville, sizeof(q->adresse.ville), stdin);
    q->adresse.ville[strcspn(q->adresse.ville, "\n")] = '\0';
    fflush(stdin);

    printf("Entrez le code postal : ");
    scanf("%d", &q->adresse.code_postale);
    fflush(stdin);
    printf("Entrez la date de naissance (format jj/mm/aaaa) : ");
    scanf("%s", q->date_de_naissance);
    fflush(stdin);
    printf("Entrez l'e-mail : ");
    scanf("%s", q->e_mail);
    fflush(stdin);
    q->suivant=NULL;
    if(l->premier==NULL){
        l->premier=q;
    }
    else
        l->dernier->suivant=q;
    l->dernier=q;
}
void insere_tete_tel(struct liste*l){
    long int tel;
    noeud *q;
    q=( noeud*)malloc(sizeof(noeud));

    do
    {
        printf("donner le numero de telephone : ");scanf("%ld",&tel);

    }while(recherche_tel(tel,l->premier)==1);

    q->num=tel;
    printf("Entrez le nom : ");
    fflush(stdin);
    fgets(q->nom, sizeof(q->nom), stdin);
    q->nom[strcspn(q->nom, "\n")] = '\0';

    printf("Entrez le prenom : ");
    fgets(q->prenom, sizeof(q->prenom), stdin);
    q->prenom[strcspn(q->prenom, "\n")] = '\0';

    printf("Entrez la rue : ");
    fgets(q->adresse.rue, sizeof(q->adresse.rue), stdin);
    q->adresse.rue[strcspn(q->adresse.rue, "\n")] = '\0';
    printf("Entrez la ville : ");

    fgets(q->adresse.ville, sizeof(q->adresse.ville), stdin);
    q->adresse.ville[strcspn(q->adresse.ville, "\n")] = '\0';

    printf("Entrez le code postal : ");
    scanf("%d", &q->adresse.code_postale);

    printf("Entrez la date de naissance (format jj/mm/aaaa) : ");
    fflush(stdin);
    scanf("%s", q->date_de_naissance);

    printf("Entrez l'e-mail : ");
    scanf("%s", q->e_mail);
    q->suivant=l->premier;

    if (liste_vide(l))
        l->dernier=q;
    l->premier=q;
}
void insere_pos_tel(liste* l){
    noeud *q,*p;
    long int tel;
    int pos;
    p=l->premier;

    do
    {
     printf("donner la position a ajouter(le taille est %d) : ",taille_liste_rep(l));scanf("%d",&pos);
    } while ((pos>=taille_liste_rep(l)+1)||(pos<=1));

    do
    {
        printf("donner le numero de telephone : ");scanf("%ld",&tel);

    }while(recherche_tel(tel,l->premier)==1);
    q=(struct noeud*)malloc(sizeof(struct noeud));
    q->num=tel;
    printf("Entrez le nom : ");
    fflush(stdin);
    fgets(q->nom, sizeof(q->nom), stdin);
    q->nom[strcspn(q->nom, "\n")] = '\0';

    printf("Entrez le prenom : ");
    fgets(q->prenom, sizeof(q->prenom), stdin);
    q->prenom[strcspn(q->prenom, "\n")] = '\0';

    printf("Entrez la rue : ");
    fgets(q->adresse.rue, sizeof(q->adresse.rue), stdin);
    q->adresse.rue[strcspn(q->adresse.rue, "\n")] = '\0';
    printf("Entrez la ville : ");

    fgets(q->adresse.ville, sizeof(q->adresse.ville), stdin);
    q->adresse.ville[strcspn(q->adresse.ville, "\n")] = '\0';

    printf("Entrez le code postal : ");
    scanf("%d", &q->adresse.code_postale);

    printf("Entrez la date de naissance (format jj/mm/aaaa) : ");
    fflush(stdin);
    scanf("%s", q->date_de_naissance);

    printf("Entrez l'e-mail : ");
    scanf("%s", q->e_mail);
    for (int i=1;i<pos;i++)
        p=p->suivant;
    q->suivant=p->suivant;
    p->suivant=q;

}
int taille_liste_rep(liste * l){
    noeud* p=l->premier;
    int taille=0;
    if (liste_vide(l))
        return 0;

    while(p)  {

        taille++;
        p = p->suivant; }
    return taille;
}
void inserer_avant(int info,struct noeud *p){
    struct noeud *q;
    q=(struct noeud*)malloc(sizeof(struct noeud));
    *q=*p;

    p->suivant=q;
}


void afficher(struct liste *l){
    struct noeud *q;
    if (liste_vide(l))
        printf("Liste est vide");
    else{
        q=l->premier;
        while(q!=NULL){
            printf("\nNumero de telephone : %ld",q->num);
            printf("\nNom : %s",q->nom);
            printf("\nPrenom : %s",q->prenom);
            printf("\nRue : %s",q->adresse.rue);
            printf("\nVille : %s",q->adresse.ville);
            printf("\nCode postal : %d",q->adresse.code_postale);
            printf("\nDate de naissance : %s",q->date_de_naissance);
            printf("\nE-mail : %s",q->e_mail);
            printf("\n\n");
            q=q->suivant;
        }
    }
}
void parcours(struct noeud *p, void(*oper)(struct noeud*)){
               while(p)  {

                    (*oper)(p);
               p = p->suivant; } }

void supprimer(struct noeud *p){
    struct noeud *q;
    q=p->suivant;
    p->num=q->num;
    p->suivant=q->suivant;
    free(q);
}
void supprimer_tete_tel(liste * l){
    if (liste_vide(l))
        printf("la liste est vide");
    else if ((taille_liste_rep(l))==1){

        noeud *q;
        q=l->premier;
        l->premier=NULL;
        free(q);
        l->dernier=NULL;
        }
    else{
        noeud *q;
        q=l->premier;
        l->premier=l->premier->suivant;
        free(q);
    }
}
void supprimer_queue_tel(liste* l){
    if (liste_vide(l))
        printf("la liste est vide");
    else if ((taille_liste_rep(l))==1){

        noeud *q;
        q=l->premier;
        l->premier=NULL;
        free(q);
        l->dernier=NULL;
        }
    else{
        noeud *q,*p;
        p=l->premier;
        while (p->suivant!=l->dernier)
            p=p->suivant;
        q=l->dernier;
        p->suivant=NULL;
        l->dernier=p;
        free(q);
    }
}
void supp_apres_pos(int w,struct liste *l){
    struct noeud *p,*q,*au;
    p=l->premier;
    for(int i=1;i<w;i++)
        p=p->suivant;
    q=p->suivant;
    while(q!=l->dernier){
        au=q;
        q=q->suivant;
        free(au);
    }
    p->suivant=NULL;
    l->dernier=p;
    free(q);

}
void suppression_tel_donne(long int num, liste *l){
    noeud *q,*p;
    if (liste_vide(l))
        printf("la liste est vide");
    else{
        p=NULL;
        q=l->premier;
        while (q!=NULL){
            if (q->num==num){
                if (p==NULL){
                    l->premier=q->suivant;
                    if (q->suivant==NULL)
                        l->dernier=NULL;
                }
                else{
                    p->suivant=q->suivant;
                    if (q->suivant==NULL)
                        l->dernier=p;
                }
                free(q);
                return;
            }
            p=q;
            q=q->suivant;
        }
        printf("le numero %ld n'a pas ete trouvee",num);
    }
}
void suppression_indicatif_tel(liste *l){
    noeud *q,*p,*prec;
    int ind;
    printf("donner un indicatif a supprimmer");scanf("%d",&ind);
    if (liste_vide(l))
        printf("la liste est vide");
    else{
        p=NULL;
        prec=NULL;
        q=l->premier;
        while (q!=NULL){
            if ((q->num/100000000)==ind){
                if (prec==NULL){
                    l->premier=q->suivant;
                    if (q->suivant==NULL)
                        l->dernier=NULL;
                        return;
                }
                else{
                    prec->suivant=q->suivant;
                    if (q->suivant==NULL)
                        l->dernier=prec;
                }
                free(q);
                noeud*q;
                q=prec;
            }
            else{
                prec=q;
            }
            q=q->suivant;
        }
    }
}
void suppression_ville_tel(char* ville, liste *l){
    noeud *q, *p, *prec;
    if (liste_vide(l))
        printf("la liste est vide");
    else{
        p=NULL;
        prec = NULL;
        q=l->premier;
        while (q!=NULL){
            if (strcmp(q->adresse.ville, ville) == 0){
                if (p == NULL){
                    l->premier=q->suivant;
                    if (q->suivant==NULL)
                        l->dernier=NULL;
                }
                else{
                    prec->suivant=q->suivant;
                    if (q->suivant==NULL)
                        l->dernier=prec;
                }
                free(q);
                noeud*q=prec;
            }
            else{
                prec = q;
                p = q;
            }
            q=q->suivant;
        }
    }
}
void tri( liste *l) {
    if (l->premier == NULL) {
        return;
    }

    struct noeud  *q, *r;
    q = l->premier;
    while (q->suivant != NULL) {

        r = q->suivant;
        while (r != NULL) {
            if (r->num > q->num) {
                long int temp_num = q->num;
                char temp_nom[50] = {0};
                strcpy(temp_nom, q->nom);
                char temp_prenom[50] = {0};
                strcpy(temp_prenom, q->prenom);
                char temp_rue[50] = {0};
                strcpy(temp_rue, q->adresse.rue);
                char temp_ville[50] = {0};
                strcpy(temp_ville, q->adresse.ville);
                unsigned int temp_code_postal = q->adresse.code_postale;
                char temp_date_de_naissance[20] = {0};
                strcpy(temp_date_de_naissance, q->date_de_naissance);
                char temp_email[50] = {0};
                strcpy(temp_email, q->e_mail);

                q->num = r->num;
                strcpy(q->nom, r->nom);
                strcpy(q->prenom, r->prenom);
                strcpy(q->adresse.rue, r->adresse.rue);
                strcpy(q->adresse.ville, r->adresse.ville);
                q->adresse.code_postale = r->adresse.code_postale;
                strcpy(q->date_de_naissance, r->date_de_naissance);
                strcpy(q->e_mail, r->e_mail);

                r->num = temp_num;
                strcpy(r->nom, temp_nom);
                strcpy(r->prenom, temp_prenom);
                strcpy(r->adresse.rue, temp_rue);
                strcpy(r->adresse.ville, temp_ville);
                r->adresse.code_postale = temp_code_postal;
                strcpy(r->date_de_naissance, temp_date_de_naissance);
                strcpy(r->e_mail, temp_email);
            }
            r = r->suivant;
        }
        q = q->suivant;
    }
}
void modifier_adresse(liste*l){
    noeud *q=l->premier;
    long int num;
    struct adresse nouvelle_adresse;


    printf("Entrez le numero de telephone que tu veut changer son adresse: ");
    scanf("%ld",&num);
    if (recherche_tel(num,l->premier)==0){
        printf("le numero n'existe pas");
        return;
    }

    while (q!=NULL){
        if (q->num==num){
                printf("Entrez la nouvelle rue : ");
                fflush(stdin);
                fgets(nouvelle_adresse.rue, sizeof(nouvelle_adresse.rue), stdin);
                nouvelle_adresse.rue[strcspn(nouvelle_adresse.rue, "\n")] = '\0';

                printf("Entrez la nouvelle ville : ");
                fgets(nouvelle_adresse.ville, sizeof(nouvelle_adresse.ville), stdin);
                nouvelle_adresse.ville[strcspn(nouvelle_adresse.ville, "\n")] = '\0';

                printf("Entrez le nouveau code postal : ");
                scanf("%d", &nouvelle_adresse.code_postale);

                q->adresse = nouvelle_adresse;

            }
            q=q->suivant;
        }
}
void modifier_telephone(liste *l){
    noeud *q=l->premier;
    long int num;
    printf("Entrez le numero de telephone que tu veut changer : ");scanf("%ld",&num);
    if (recherche_tel(num,l->premier)==0){
        printf("le numero n'existe pas");
        return;
    }

    while (q!=NULL){
        if (q->num==num){
            do{
            printf("donner le nouveau numero de telephone : ");scanf("%ld",&num);
            }while(recherche_tel(num,l->premier)==1);
            q->num=num;
            return;
        }
        q=q->suivant;
    }
}
void afficher_num( liste *l){
     noeud *q;
    long int num;
    printf("Entrez le numero de telephone que tu veut afficher ses informations : ");scanf("%ld",&num);
    if (recherche_tel(num,l->premier)==0){
        printf("le numero n'existe pas");
        return;
    }
    if (liste_vide(l))
        printf("Liste est vide");
    else{
        q=l->premier;
        while(q!=NULL){
            if (q->num==num){
            printf("\nNom : %s",q->nom);
            printf("\nPrenom : %s",q->prenom);
            printf("\nRue : %s",q->adresse.rue);
            printf("\nVille : %s",q->adresse.ville);
            printf("\nCode postal : %d",q->adresse.code_postale);
            printf("\nDate de naissance : %s",q->date_de_naissance);
            printf("\nE-mail : %s",q->e_mail);
            printf("\n\n");
            return;
            }
            q=q->suivant;
        }
    }
}
void afficher_nom( liste *l){
    noeud *q;
    char nom[20];
    printf("Entrez le nom : ");
    fflush(stdin);
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';
    if (liste_vide(l))
        printf("Liste est vide");
    else{
        q=l->premier;
        while(q!=NULL){
            if (strcmp(nom,q->nom)==0){
            printf("\nNumero de telephone : %ld",q->num);
            printf("\nNom : %s",q->nom);
            printf("\nPrenom : %s",q->prenom);
            printf("\nRue : %s",q->adresse.rue);
            printf("\nVille : %s",q->adresse.ville);
            printf("\nCode postal : %d",q->adresse.code_postale);
            printf("\nDate de naissance : %s",q->date_de_naissance);
            printf("\nE-mail : %s",q->e_mail);
            printf("\n\n");
            }
            q=q->suivant;
        }
    }
}
void afficher_ind( liste *l){
    noeud *q;
    int ind;
    printf("donner un indicatif");scanf("%d",&ind);
    if (liste_vide(l))
        printf("Liste est vide");
    else{
        q=l->premier;
        while(q!=NULL){
            if ((q->num/100000000)==ind){
            printf("\nNumero de telephone : %ld",q->num);
            printf("\nNom : %s",q->nom);
            printf("\nPrenom : %s",q->prenom);
            printf("\nRue : %s",q->adresse.rue);
            printf("\nVille : %s",q->adresse.ville);
            printf("\nCode postal : %d",q->adresse.code_postale);
            printf("\nDate de naissance : %s",q->date_de_naissance);
            printf("\nE-mail : %s",q->e_mail);
            printf("\n\n");
            }
            q=q->suivant;
        }
    }
}
void afficher_ville( liste *l){
    struct noeud *q;
    char ville[20];
    printf("Entrez la ville : ");
    fflush(stdin);
    fgets(ville, sizeof(ville), stdin);
    ville[strcspn(ville, "\n")] = '\0';
    if (liste_vide(l))
        printf("Liste est vide");
    else{
        q=l->premier;
        while(q!=NULL){
            if (strcmp(ville,q->adresse.ville)==0){
            printf("\nNumero de telephone : %ld",q->num);
            printf("\nNom : %s",q->nom);
            printf("\nPrenom : %s",q->prenom);
            printf("\nRue : %s",q->adresse.rue);
            printf("\nVille : %s",q->adresse.ville);
            printf("\nCode postal : %d",q->adresse.code_postale);
            printf("\nDate de naissance : %s",q->date_de_naissance);
            printf("\nE-mail : %s",q->e_mail);
            printf("\n\n");
            }
            q=q->suivant;
        }
    }
}

void enregistrer(liste *l)
{   char fichier[100]="repertoire.txt";
    noeud *q=l->premier;
    FILE *f=fopen(fichier,"w");
    while(q!=NULL)
    {fprintf(f,"%ld %s %s %s %s %u %s %s\n",q->num,q->nom, q->prenom,q->adresse.rue, q->adresse.ville, q->adresse.code_postale,q->date_de_naissance,q->e_mail);
        q=q->suivant;}
    printf("\Enregistrement Avec Success ! \n");
    fclose(f);
}
void inserer(liste* l,noeud p){
    struct noeud *q;
    q=(struct noeud*)malloc(sizeof(struct noeud));

    *q=p;

    q->suivant=NULL;
    if(l->premier==NULL){
        l->premier=q;
    }
    else
    l->dernier->suivant=q;
    l->dernier=q;
}
void chargement(liste *l) {
    noeud p;
    FILE *f = fopen("repertoire.txt", "r");
    if (f == NULL) {
        printf("\nLe fichier n'existe pas\n");
    } else {
        while (fscanf(f, "%ld %s %s %s %s %u %s %s\n", &p.num, p.nom, p.prenom, p.adresse.rue, p.adresse.ville, &p.adresse.code_postale, p.date_de_naissance, p.e_mail) != EOF && fscanf(f, "\n") != EOF) {
            inserer(l, p);
        }
        printf("Chargement Avec Success ! \n");
        fclose(f);
    }
}
