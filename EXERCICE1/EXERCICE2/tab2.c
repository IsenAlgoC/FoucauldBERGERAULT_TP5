#include<stdlib.h>
#include"tab2.h"
#include<stdio.h>
#define TAILLEINITIAL 100



TABLEAU newArray()
{
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIAL * sizeof(int)); // On attribue au tableau la mémoire nécessaire a son stockage
	tab.size = TAILLEINITIAL;//initialisation de size
	tab.eltsCount = 0;//initialisation de elts.count
	if (tab.elt != NULL && tab.size > 0) {//On test si le tableau s'est correctement créé
		for (int i = 0; i < tab.size; i++) {
			*(tab.elt + i) = 0;// Initialisation du tableau avec de 0
		}
		return(tab);
	}
	else {
		tab.elt = NULL; // Si l'allocation a echoué on renvoi un tableau avec elt = null
		return(tab);
		}
	}

int incrementArraySize(TABLEAU* tab, int incrementValue)
{
	//int* tabTransit = NULL;
	//tabTransit = (int*)realloc(tab->elt, tab->size + incrementValue * sizeof(int));
	//tab->elt = tabTransit;
	tab->elt = (int*)realloc(tab->elt, tab->size + incrementValue * sizeof(int));
	tab->size += incrementValue;

	return (tab->size);
}

int AfficherTab(TABLEAU tab)
{
	for (int i = 0; i < tab.size; i++) {
		
		printf("\n tab[%d] = %d",i, *(tab.elt + i));
	}

	return(1);
}

int setElement(TABLEAU* tab, int pos, int element) {
	
	if (tab->elt == NULL || pos < 1) {
	return 0;//Renvoi 0 en cas d'erreur
	}
	
	if (pos < tab->size +1) {
		*(tab->elt + pos-1) = element;
	}
	else{
		int differenceDeTaille = pos - tab->size;
		printf("1erpassage");
		incrementArraySize(tab, differenceDeTaille);
		for (int i = 0; i < differenceDeTaille; i++) {
			*(tab->elt + tab->size + i) = 1;
			printf("passage");

		}
		
}
}

int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if (tab->elt == NULL || startPos<0) {
		return(-1);
	}
	
	else if (endPos > tab->size) {
		endPos = tab->size;
		printf("\n positions demandé n'existe pas, l'affichage s'arrette avec la dernière position du tableau\n");
		return(-1);
	}

	for (int i = startPos; i < endPos; i++) {

		printf("\n tab[%d] = %d", i, *(tab->elt + i));
	}

	return (0);
}


