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

typedef struct{int score ; char pseudo[L] ;}t_score;

int menu();

void init_matrice(int matrice[N][M]);
void afficher_matrice(int matrice[N][M]);
int choix_ligne(int matrice[N][M], int colonne);
void placer_pions(int matrice[N][M], int colonne, int ligne, int num_joueur);
int gagne(int grille[N][M]);
int quitter();
void save_quit_classique(int matrice[N][M], int tour, char pseudo1[L], char pseudo2[L]);
int begin();
int load_classique(int grille[N][M], int *tour, char pseudo1[L], char pseudo2[L]);
void affich_result(int grille[N][M], char joueur1[L], char joueur2[L], int tour);
void affich_score_classique();

void pseudo_classique(char pseudo1[L], char pseudo2[L], int party, int debut);
void enregistrement_score_classique(char joueur[L], int nb_coups);
void puissance_classique();
int fin_jeux();
