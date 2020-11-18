#include<stdlib.h>
#include"tab.h"
#include<stdio.h>
#define TAILLEAJOUT 50

int initTab(int* tab, int size) {
	if (tab == NULL || size < 0) {
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		*(tab + i) = 0;
	}
	return size;

}

int afficheTab(int* tab, int size, int nbElts)
{
	if (tab == NULL || size < 0 || size<nbElts) {
		return -1;
	}
	for (int i = 0; i < nbElts; i++) {
		printf("%d ", *(tab + i));
	}
	printf("\n");

	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	realloc(tab,TAILLEAJOUT);
	*(tab + *nbElts) = element;
	nbElts += 1;
	return nbElts;

}
