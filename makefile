FICHIERS =  game.o interface.o puissance_classique.o grille.o
COMMANDE = -g -Wextra

exe : ${FICHIERS}
	gcc -o exe ${FICHIERS}
game.o : game.c
	gcc -c game.c ${COMMANDE}
interface.o : interface.c
	gcc -c interface.c ${COMMANDE}
puissance_classique.o : puissance_classique.c
	gcc -c puissance_classique.c ${COMMANDE}
grille.o : grille.c
	gcc -c grille.c ${COMMANDE}
