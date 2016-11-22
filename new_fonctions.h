#define N 6
#define M 7
#define L 20

int menu();

void init_matrice(int matrice[N][M]);
void afficher_matrice(int matrice[N][M]);
int choix_ligne(int matrice[N][M], int colonne);
void placer_pions(int matrice[N][M], int colonne, int ligne, int num_joueur);
int gagne(int grille[N][M]);
void affich_result(int grille[N][M], char joueur1[L], char joueur2[L], int tour);

void pseudo_classique(char pseudo1[L], char pseudo2[L]);
void enregistrement_score_classique(char joueur[L], int nb_coups);
void puissance_classique();
int fin_jeux();

void puissance_avance();
void afficher_matrice_avance(int matrice[N][M]);
int fin_jeux_avance();
int nb_joueur();
void pseudo_avance(char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs);
int gagne_avance(int grille[N][M]);
void placer_pions_avance(int grille[N][M], int colonne, int num_joueur);
void afficher_matrice_avance(int matrice[N][M]);
void save_score_avance(char joueur[L], int nb_coups);
void affich_result_avance(int grille[N][M], char joueur1[L], char joueur2[L], char joueur3[L], char joueur4[L], int tour);
