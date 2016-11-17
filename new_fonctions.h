#define N 6
#define M 7
#define L 20

int menu();
void fin_jeux();

void init_matrice(int grille[N][M]);
void afficher_matrice(int grille[N][M]);
int placer_pions(int grille[N][M], int colonne, int num_joueur);
int gagne(int grille[N][M]);
int choix_ligne(int matrice[N][M], int colonne);
void pseudo_classique(char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L]);
void enregistrement_score_classique(char joueur[L], int nb_coups);
void puissance_classique();

