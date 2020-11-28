#include<stdio.h>
#include<stdlib.h>
#include"tab2.h"

int main() {
	// déclartaion du tableau et initialisation de ses valeurs à 0
	TABLEAU tab = newArray();
	displayElements(&tab, 0, 100);
	printf("\nTest de setElement et IncrementArraySize. On affiche le nouveau tableau de la position 90 à 106\n");
	setElement(&tab, 106, 666);// On rajoute la valeur 666 dans la 106 case. Test par la meme occasion la fonction increment
	displayElements(&tab, 90, 106);
	deleteElements(&tab, 100, 104);// On supprimer les cases 100 à 104
	printf("\nTest de la suppression des cases 100 à 104 du tableau\n");
	displayElements(&tab, -1, 106); // test de la fonction display si startPos et endPos sont en dehors du tableau
	return EXIT_SUCCESS;
}