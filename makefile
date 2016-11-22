FICHIERS =  game.o interface.o puissance_classique.o grille.o interface_avance.o puissance_avance.o grille_avance.o
COMMANDE = -g -Wextra

#compile tout les fichiers et crée un executable
all : ${FICHIERS}
	gcc -o exe ${FICHIERS}

#compilation de toutes les dépendances
game.o : game.c new_fonctions.h
	gcc -c game.c ${COMMANDE}
interface.o : interface.c
	gcc -c interface.c ${COMMANDE}
puissance_classique.o : puissance_classique.c
	gcc -c puissance_classique.c ${COMMANDE}
grille.o : grille.c
	gcc -c grille.c ${COMMANDE}

interface_avance.o : interface_avance.c
	gcc -c interface_avance.c ${COMMANDE}
grille_avance.o : grille_avance.c
	gcc -c grille_avance.c ${COMMANDE}
puissance_avance.o : puissance_avance.c
	gcc -c puissance_avance.c ${COMMANDE}
	
#suppression des fichiers temporaires
clean_o :
	rm -rf *.o
clean_exe :
	rm -rf *.exe
clean_txt :
	rm -rf *.txt
