#include "projet.h"
#include <stdio.h>
#include <stdlib.h>



void creation(liste* l){
    int rep;
    do {

        insere_queue_tel(l);

        do{

            printf("Voulez vous ajouter un autre telephone O/N :");

            scanf("%d",&rep);
        }while(!(rep==1 || rep==0));
    }while(rep);
}
int main(){
    liste l;
    creer_liste(&l);
    int menu_general,menu_maj,menu_ajouter,menu_recherche,menu_suppression,pos,menu_modification,menu_enregistrement;
    long  int tlf;
    char ville[10];

    do{
        printf("\n\n\n\n\n\n");
        printf("\t\t\tMENU GENERAL\n1-Creation du repertoire telephonique\n2-Mise a jour des telephones\n3-Recherche , affichage et Tri \n4-Enregistrement et chargement dans un fichier \n5-Quitter \n\t\t\tDonner votre choix SVP :");
        scanf("%d",&menu_general);
        if (menu_general==1){

            creation(&l);
        }
        else if(menu_general==2){
            do{
            printf("\n\n\t\t\tMENU MAJ\n\n1-Ajouter un nouvel telephone\n2-Supprimer un telephone\n3-Modifier les donnees d'un telephone \n4-Retour Menu generale\n\t\t\tDonner votre choix SVP :");
            scanf("%d",&menu_maj);
                if (menu_maj==1){
                    do {
                        printf("\n\n\t\t\tMenu Ajouter\n1-Ajout en tete\n2-Ajout en queue\n3-Ajout dans une position\n4-Retour au menu MAJ\n\t\t\tDonner votre choix SVP : ");
                        scanf("%d",&menu_ajouter);
                        if (menu_ajouter==1)
                            insere_tete_tel(&l);
                        else if (menu_ajouter==2)
                            insere_queue_tel(&l);
                        else if (menu_ajouter==3)
                        insere_pos_tel(&l);


                    }while(menu_ajouter!=4);
                }
                else if (menu_maj==2){
                    do {
                        printf("\n\n\t\t\tMenu Suppression\n1-Suppression en tete\n2-Suppression en queue\n3-Suppression a partir d'une position\n4-Suppression d'un telephone donne\n5-Suppression des telephones d'une ville donnee\n6-Suppression des telephones d'un indicatif donne\n7-Retour au menu MAJ\n\t\t\tDonner votre choix SVP : ");
                        scanf("%d",&menu_suppression);
                        if (menu_suppression==1)
                            supprimer_tete_tel(&l);
                        else if (menu_suppression==2)
                            supprimer_queue_tel(&l);
                        else if (menu_suppression==3){
                            do
                            {
                            printf("donner la position(le taille est %d) : ",taille_liste_rep(&l));scanf("%d",&pos);
                            } while ((pos>=taille_liste_rep(&l)+1)||(pos<=1));
                            supp_apres_pos(pos,&l);
                        }
                        else if (menu_suppression==4){
                            printf("donner le numero de telephone a supprimer: ");scanf("%ld",&tlf);
                            suppression_tel_donne(tlf,&l);
                        }
                        else if (menu_suppression==5){
                            printf("Entrez le nom de la ville : ");
                            fflush(stdin);
                            fgets(ville, sizeof(ville), stdin);
                            ville[strcspn(ville, "\n")] = '\0';
                            suppression_ville_tel(ville, &l);
                        }
                        else if (menu_suppression==6){
                            suppression_indicatif_tel(&l);
                        }


                    }while(menu_suppression!=7);
                }
                else if (menu_maj==3){
                    do{
                        printf("\n\n\t\t\tMenu Modification\n1-Adresse\n2-Telephone\n3-Retour au menu MAJ\n\t\t\tDonner votre choix SVP : ");scanf("%d",&menu_modification);
                        if (menu_modification==1){
                            modifier_adresse(&l);
                        }
                        else if (menu_modification==2){
                            modifier_telephone(&l);
                        }
                    }while(menu_modification!=3);
                }
            }while (menu_maj!=4);
        }
        else if (menu_general==3){
            do{
            printf("\n\n\t\t\tMENU Recherche et affichage\n\n1-Contenu de la liste des telephones\n2-Recherche par numero telephone\n3-Recherche par nom  \n4-Recherche par indicatif telephone\n5-Recherche par ville\n6-Tri\n7-Retour au menu general\n\t\t\tDonner votre choix SVP :");
            scanf("%d",&menu_recherche);
                if (menu_recherche==1)
                    afficher(&l);
                else if (menu_recherche==2)
                    afficher_num(&l);
                else if (menu_recherche==3)
                    afficher_nom(&l);
                else if (menu_recherche==4)
                    afficher_ind(&l);
                else if (menu_recherche==5)
                    afficher_ville(&l);
                else if (menu_recherche==6)
                    tri(&l);
            }while (menu_recherche!=7);
        }
        else if (menu_general==4)
        {do{
        printf("\n\n\t\t\tMENU Enregistrement et chargement\n\n1-Enregistrement\n2-Chargement\n3-Retour au menu generale\n\t\t\tDonner votre choix SVP :");
        scanf("%d",&menu_enregistrement);
        if (menu_enregistrement==1)
            enregistrer(&l);
        else if (menu_enregistrement==2)
            chargement(&l);
        }while(menu_enregistrement!=3);
        }
    }while(menu_general!=5);
    return 0;
}

