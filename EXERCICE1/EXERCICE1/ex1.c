#include<stdio.h>
#include<stdlib.h>
#include"tab.h"
#define size 10
#define TAB2SIZE 100

#define TAILLEINITIALE 100 
#define TAILLEAJOUT 50

int main() {
	// PARTIE 1 ------------------------------------------------------------------------------------------------------
	// intialiser mytab1 et l'afficher
	printf("myTab1 ");
	int myTab1[size];
	//printf("%d\n",initTab(myTab1, size));
	initTab(myTab1, size);
	afficheTab(myTab1, size, 10);


	// Initialiser mytab2 
	printf("\nmyTab2 ");
	int *myTab2 = (int*)malloc(TAB2SIZE);
	if (myTab2 != NULL) {
		initTab(myTab2, 20);
	}
	else {
		printf("memoire insuffisante");
		return(-1);
	}
	// remplir le tableau de 1 à 20 et l'afficher 
	for (int i = 0; i < 20; i++)
	{
		*(myTab2 + i) = 1 + i;
	}
	afficheTab(myTab2, 20, 20);

	//Destruction du tableau
	free(myTab2);
	
	// PARTIE 2 -----------------------------------------------------------------------------------------------------------



	return EXIT_SUCCESS;
}
