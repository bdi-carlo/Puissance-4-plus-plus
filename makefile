FICHIERS =  game.o interface_4_joueurs.o puissance_classique_4_joueurs_bis.o grille_4joueurs.o
COMMANDE = -g -Wextra
PUISSANCE = puissance_classique_4_joueurs_bis.c
INTERFACE = interface_4_joueurs.c

exe : ${FICHIERS}
	gcc -o exe ${FICHIERS}
game.o : game.c
	gcc -c game.c ${COMMANDE}
interface_4_joueurs.o : ${INTERFACE}
	gcc -c ${INTERFACE} ${COMMANDE}
puissance_classique_4_joueurs_bis.o : ${PUISSANCE}
	gcc -c ${PUISSANCE} ${COMMANDE}
grille_4joueurs.o : grille_4joueurs.c
	gcc -c grille_4joueurs.c ${COMMANDE}
