struct adresse{
    char rue[20];
    char ville[10];
    int code_postale;
};
typedef struct noeud{
    long int num;
    char nom[20];
    char prenom[20];
    struct adresse adresse;
    char date_de_naissance[11];
    char e_mail[25];
    struct noeud * suivant;
}noeud;

typedef struct liste{
         noeud * premier;
         noeud * dernier;
}liste;
void creer_liste(liste*);
unsigned liste_vide(liste *);
unsigned recherche_tel(long int , noeud *);
int taille_liste_rep(liste*);
void insere_queue_tel(liste * );
void insere_tete_tel(liste * );
void insere_pos_tel(liste*);
void inserer(liste* l,noeud p);

void supprimer_tete_tel(liste*);
void supprimer_queue_tel(liste*);
void suppression_pos_tel(int,liste*);
void suppression_tel_donne(long int,liste*);
void supprimer( noeud *);
void supp_apres_pos(int ,liste *);
void suppression_ville_tel(char* , liste *);
void suppression_indicatif_tel(liste *);

void modifier_adresse(liste*);
void modifier_telephone(liste *);

void afficher(liste*);
void afficher_num( liste *);
void afficher_ind( liste *);
void afficher_nom( liste *);
void afficher_ville( liste *);
void tri( liste *l) ;

void enregistrer(liste *);
void chargement(liste *);
