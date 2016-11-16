#define N 6
#define M 7
#define L 20

int menu();
void fin_jeux();

void init_matrice(int matrice[N][M]);
void afficher_matrice(int matrice[N][M]);
void placer_pions(int matrice[N][M], int colonne, int num_joueur);
int gagne(int grille[N][M]);

void pseudo_classique(char pseudo1[L], char pseudo2[L]);
void enregistrement_score_classique(char joueur[L], int nb_coups);
void puissance_classique();

