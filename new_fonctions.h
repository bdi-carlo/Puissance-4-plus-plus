#define N 6
#define M 7
#define L 20

//Enumeration permettant de savoir le type de la piece
typedef enum{vide,creuse,pleine,bloquante}t_type;

//Strucuture pour connaitre le type et la valeur du pion
typedef struct{int valeur_pion1; t_type type1;int valeur_pion2; t_type type2;}t_piece;

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


void init_matrice_avance(t_piece matrice[N][M]);
void afficher_matrice_avance(t_piece matrice[N][M]);
void placer_pions_avance(t_piece grille[N][M], int colonne, int ligne, int num_joueur, int type);

void puissance_avance();