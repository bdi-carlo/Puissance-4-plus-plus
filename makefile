FICHIERS =  afficher_matrice.o init_matrice.o menu_principal.o placer_pion.o puissance_classique.o win.o

exe : ${FICHIERS}
	gcc -o exe ${FICHIERS}
menu_principal.o : menu_principal.c
	gcc -c menu_principal.c -g
afficher_matrice.o : afficher_matrice.c
	gcc -c afficher_matrice.c -g
init_matrice.o : init_matrice.c
	gcc -c init_matrice.c -g
placer_pion.o : placer_pion.c
	gcc -c placer_pion.c -g
puissance_classique.o : puissance_classique.c
	gcc -c puissance_classique.c -g
win.o : win.c
	gcc -c win.c -g
