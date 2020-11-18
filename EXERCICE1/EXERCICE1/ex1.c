#include<stdio.h>
#include<stdlib.h>
#include"tab.h"
#define size 10

int main() {
	int myTab1[size];
	printf("%d\n",initTab(myTab1, size));
	afficheTab(myTab1, size, 2);
	return EXIT_SUCCESS;
}
