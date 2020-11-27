#include<stdio.h>
#include<stdlib.h>
#include"tab2.h"

int main() {
	TABLEAU tab = newArray();
	//newArray();
	//AfficherTab(tab);
	//displayElements(&tab, 0, 100);
	printf("\n 2)  ");
	//incrementArraySize(&tab, 50);
	displayElements(&tab, -10, 106);
	printf("\n 3)  ");
	setElement(&tab, 106, 666);
	setElement(&tab, 105, 555);
	displayElements(&tab, 90, 106);
	deleteElements(&tab, 100, 104);
	printf("\n 4)__________________________________________________________________________________________  ");
	displayElements(&tab, 70, 106);
	return EXIT_SUCCESS;
}