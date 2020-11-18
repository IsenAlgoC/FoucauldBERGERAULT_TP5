#include<stdlib.h>
#include"tab2.h"
#include<stdio.h>
#define TAILLEINITIAL 100

typedef struct Tableau {
	int* elt;
	int size;
	int eltsCount;
} TABLEAU;

TABLEAU newArray()
{
	TABLEAU tab;
	tab.elt = TAILLEINITIAL;
	tab.size = TAILLEINITIAL;
	tab.eltsCount = TAILLEINITIAL;
	for (int i = 0; i < TAILLEINITIAL; i++) {

	}
}
