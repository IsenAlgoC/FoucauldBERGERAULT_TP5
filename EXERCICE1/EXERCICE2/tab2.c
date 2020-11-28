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
	
	if (startPos < 1) {// Si on start post negatif on met startPos à 0
		startPos = 1;
		printf("\n Certaines positions demandees n'existent pas. L'affichichage du tableau commence a la position 1 ");
	}
	if (endPos > tab->size) {//Si on veut afficher plus que ce qui existe on reduit endpos pour afficher le tableau jusqu'a la fin
		endPos = tab->size;
		printf("\n Certaines positions demandees n'existent pas. L'affichage du tableau s'arrete a la derniere position du tableau\n");
	}
	 if (startPos >= endPos) { // Dans le cas ou startPos est superieur a EndPos on intervertit les valeurs de starPos et endPos
		 int transit;
		 transit = startPos;
		 startPos = endPos;
		 endPos = transit;
	}



	for (int i = startPos; i < endPos+1; i++) {//On affiche les elements compris entre startPos et endPos

		printf("\n tab[%d] positon :%d   = %d", i-1,i, *(tab->elt + i-1));
	}
	printf("\n");

	return (0);
}

int deleteElements(TABLEAU* tab, int startPos, int endPos)
// J'ai choisi que cette fonction supprimer tout les elments de l'intervalle ferme [stardPos ; endPos]
//tab [0] correspond à la position 1. Pour garder la meme logique que la fonction précédente
{
	if (tab->elt == NULL) {
		return(-1);
	}
	//dans le cas ou endPos est superieur à la taille du tableau on supprimer tout le tableau de starPos à la fin
	if (endPos > tab->size) {
		endPos = tab->size;
	}
	// dans le cas ou startPos est inferieur à 1 on suuprime tous le tableau de 1 à endPos
	if (startPos < 1) {
		startPos = 1;
	}
	// Dans le cas ou startPos est superieur a EndPos on intervertit les valeurs de starPos et endPos
	if (startPos > endPos) {
		int transit;
		transit = startPos;
		startPos = endPos;
		endPos = transit;
	}
	int NbElementSuppr = 0,NewSize=0; 
	NbElementSuppr = endPos - startPos +1;// Nombre d'elts que l'on veut supprimer du tableau
	NewSize = tab->size - NbElementSuppr;
	if (NbElementSuppr > tab->size - endPos ) {
		NbElementSuppr = tab->size - endPos ;
	}
	int j=0;
	for (j; j < NbElementSuppr; j++) {
		*(tab->elt + startPos -1 + j) = *(tab->elt + endPos + j);// On met les elements placé après la zone de suppression a la place de ceux qui vont etre surpprime
	}
	tab->size = NewSize;

	if (tab->size == 0) {// Cas ou l'on supprime tous le tableau
		free(tab->elt);
		return 0;
	}
	//Libération des adresses mémoires en trop en allouants le tableau avec sa nouvelle taille a une autre adresse
	tab->elt = (int*)realloc(tab->elt, tab->size * sizeof(int));
	

	return 0;
}



