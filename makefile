OBJET =  game.o interface.o puissance_classique.o grille.o interface_avance.o puissance_avance.o grille_avance.o IA.o
COMMANDE = -g -Wextra
BIN = ./bin/
SRC = ./src/
INCLUDE1 = ./include/classique.h
INCLUDE2 = ./include/avance.h

#compile tout les fichiers et crée un executable
all : ${OBJET}
	gcc -o Puissance_4++.exe ${OBJET}

#compilation de toutes les dépendances
game.o : ${SRC}game.c ${INCLUDE1} ${INCLUDE2}
	gcc -c ${SRC}game.c ${COMMANDE}
	

interface.o : ${SRC}interface.c ${INCLUDE1}
	gcc -c ${SRC}interface.c ${COMMANDE}

puissance_classique.o : ${SRC}puissance_classique.c ${INCLUDE1}
	gcc -c ${SRC}puissance_classique.c ${COMMANDE}

grille.o : ${SRC}grille.c
	gcc -c ${SRC}grille.c ${COMMANDE}

IA.o : ${SRC}IA.c
	gcc -c ${SRC}IA.c ${COMMANDE}
	
interface_avance.o : ${SRC}interface_avance.c ${INCLUDE1} ${INCLUDE2}
	gcc -c ${SRC}interface_avance.c ${COMMANDE}

grille_avance.o : ${SRC}grille_avance.c ${INCLUDE1} ${INCLUDE2}
	gcc -c ${SRC}grille_avance.c ${COMMANDE}

puissance_avance.o : ${SRC}puissance_avance.c ${INCLUDE1} ${INCLUDE2}
	gcc -c ${SRC}puissance_avance.c ${COMMANDE}

	
#suppression des fichiers temporaires
clean_o :
	rm -rf *.o
clean_exe :
	rm -rf *.exe
clean_txt :
	rm -rf *.txt
clean_~ :
	rm -rf *~

#suppression de tous les fichiers sauf les fichiers sources
mrproper : clean_o clean_exe clean_txt clean_~
