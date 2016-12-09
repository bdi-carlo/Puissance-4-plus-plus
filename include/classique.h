#define N 6
#define M 7
#define L 7

/**
*\file classique.h
*\brief Prototypes des fonctions du puissance 4 classique utilisées
*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/

/**
*\struct t_piece
*\brief Structure pour définir un pion
*\enum t_type
*\brief type de la pièce
*/

/**
Pour le Puissance 4++, une pièce peut être soit creuse, pleine ou bloquante.
*/   
typedef enum{vide /**< Pas de pièce*/,creuse /**< Pièce creuse*/,pleine /**< Pièce pleine*/,bloquante /**< Pièce bloquante*/}t_type;

/**
Il peut y avoir 2 pièces dans la même case, on définit donc à quel joueur appartiennent les pièces ainsi que leur type.
*/
typedef struct{int valeur_pion1 ;/**< Numéro du joueur de la première pièce*/ t_type type1 ;/**< type de la première pièce*/int valeur_pion2 ;/**< Numéro du joueur de la deuxième pièce*/ t_type type2 ;/**< type de la deuxième pièce*/}t_piece;

typedef struct{int score ; char pseudo[L] ;}t_score;

int menu();
int IA (int grille[N][M], int tour) ;
void init_matrice(int matrice[N][M]);
void afficher_matrice(int matrice[N][M]);
int choix_ligne(int matrice[N][M], int colonne);
void placer_pions(int matrice[N][M], int colonne, int ligne, int num_joueur);
int gagne(int grille[N][M]);
int quitter();
void save_quit(int matrice[N][M], int tour, char pseudo1[L], char pseudo2[L]);
int begin();
int load_classique(int grille[N][M], int *tour, char pseudo1[L], char pseudo2[L]);
void affich_result(int grille[N][M], char joueur1[L], char joueur2[L], int tour);
void affich_score_classique();

void pseudo_classique(char pseudo1[L], char pseudo2[L], int party, int debut);
void enregistrement_score_classique(char joueur[L], int nb_coups);
void puissance_classique();
int fin_jeux();
