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

	if (tab->elt == NULL) {
		return -1;
	}
	else {
		tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));//On agrandi le tableau de incrementValue
		tab->size += incrementValue;//Indique la nouvelle taille du tableau
	}


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
	//tab [0] correspond à la position 1 d'après la consigne
	if (tab->elt == NULL || pos < 1) {
	return 0;//Renvoi 0 en cas d'erreur
	}
	
	if (pos < tab->size +1) {// Si la postion demandé est contenue dans le tableau
		*(tab->elt + pos-1) = element;//On met la valeur element a la postion pos
	}
	else{
		int differenceDeTaille = pos - tab->size;// On calcul la differnce de taille entre le tableau initial et le nouveau qui va contenir la position voulue
		int SizeInit = tab->size;//On enregistre la taille du tableau avant son agrandissement
		incrementArraySize(tab, differenceDeTaille);//On complète le tableau pour qu'il contiene la position souhaite
		for (int i = 0; i < differenceDeTaille-1; i++) { //On initalise la nouvelle partie du tableau avec des 0
			*(tab->elt + SizeInit + i) = 0;
		}
		*(tab->elt + tab->size - 1) = element;// on met la valeur element a la postion pos
		
}
}

int displayElements(TABLEAU* tab, int startPos, int endPos)
{     //tab [0] correspond à la position 1. Pour garder la meme logique que la fonction précédente
	if (tab->elt == NULL) {
		return(-1);// Si pas de tableau on retourne -1
	}
	
	if (endPos > tab->size) {//Si on veut afficher plus que ce qui existe on reduit endpos pour afficher le tableau jusqu'a la fin
		endPos = tab->size;
		printf("\n Certaines positions demandees n'existe pas, l'affichage s'arrete a la dernière position du tableau\n");
	}
	 if (startPos >= endPos) {//La consigne ne precisez pas la facon de traiter ce cas, j'ai donc choisi de le traiter comme ceci
		printf("\n tab[%d] positon :%d   = %d", endPos-1, endPos, *(tab->elt + endPos-1));//Si startPos>=endPos on affiche EndPos
		return(0);
	}

	if (startPos < 1) {// Si on start post negatif on met startPos à 0
		startPos = 1;
		printf("Les tableau n'ont pas de position négatives. Le tableau affiche les valeurs à partir de l'indexe 0");
	}

	for (int i = startPos; i < endPos+1; i++) {//On affiche les elements compris entre startPos et endPos

		printf("\n tab[%d] positon :%d   = %d", i-1,i, *(tab->elt + i-1));
	}
	printf("\n");

	return (0);
}

int deleteElements(TABLEAU* tab, int startPos, int endPos)
// J'ai choisi que cette fonction supprimer tout les elments de l'intervalle ferme [stardPos ; endPos]
{
	if (tab->elt == NULL) {
		return(-1);
	}
	int NbElementSuppr = 0,NewSize=0; 
	NbElementSuppr = endPos - startPos +1;// Nombre d'elts que l'on veut supprimer du tableau
	NewSize = tab->size - NbElementSuppr;
	if (NbElementSuppr > tab->size - endPos ) {
		NbElementSuppr = tab->size - endPos ;
	}
	int j=0;
	for (j; j < NbElementSuppr; j++) {
		*(tab->elt + startPos -1 + j) = *(tab->elt + endPos + j);// On met les elments placé après la zone de suppression a la place de ceux qui vont etre surpprime
	}
	//tab->size = NewSize;
	//free(tab->elt + startPos + j);

	

	return 0;
}



