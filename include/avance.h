#define N 6
#define M 7
#define L 7

/**
*\file avance.h
*\brief Prototypes des fonctions du puissance 4 avance utilisées
*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/

void init_matrice_avance(t_piece matrice[N][M]);
void afficher_matrice_avance(t_piece matrice[N][M]);
int choix_ligne_avance(t_piece matrice[N][M], int colonne);
void placer_pions_avance(t_piece matrice[N][M], int colonne, int ligne, int num_joueur, int type);
int gagne_avance(t_piece grille[N][M]);
void affich_result_avance(t_piece grille[N][M], int win, int tour, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L]);
int grille_pleine(t_piece matrice[N][M]);
int fin_jeux_avance();
int nb_joueur();
void pseudo_avance(char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs);
void puissance_avance();
void afficher_regles();
void save_quit_avance(t_piece matrice[N][M], int tour, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs, int nb_block1, int nb_block2, int nb_block3, int nb_block4);
int load_avance(t_piece matrice[N][M], int *tour, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int *nb_joueurs, int *nb_block1,  int *nb_block2, int *nb_block3, int *nb_block4);
void enregistrement_score_avance(char joueur[L], int nb_coups);

int player1(t_piece grille[N][M], int *nb_block1, int pions, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs, int tour, int nb_block2, int nb_block3, int nb_block4);
void player2(t_piece grille[N][M], int *nb_block2, int pions, char pseudo1[L]);
void player3(t_piece grille[N][M], int *nb_block3, int pions, char pseudo1[L]);
void player4(t_piece grille[N][M], int *nb_block4, int pions, char pseudo1[L]);
void affich_score_avance();
