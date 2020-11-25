#include<stdio.h>
#include<stdlib.h>
#include"tab2.h"

int main() {
	TABLEAU tab = newArray();
	//newArray();
	//AfficherTab(tab);
	displayElements(&tab, 0, 100);
	printf("\n 2)  ");
	/*incrementArraySize(&tab, 50);
	AfficherTab(tab*/
	printf("\n 3)  ");
	setElement(&tab, 106, 101);
	displayElements(&tab, 0, 100);
	//AfficherTab(tab);
	printf("\n 4)  ");
}
