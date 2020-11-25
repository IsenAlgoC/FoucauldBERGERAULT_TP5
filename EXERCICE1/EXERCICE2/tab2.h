typedef struct Tableau {
	int* elt;
	int size;
	int eltsCount;
} TABLEAU;

TABLEAU newArray();
int incrementArraySize(TABLEAU* tab, int incrementValue);

int AfficherTab(TABLEAU tab);

int setElement(TABLEAU* tab, int pos, int element);

int displayElements(TABLEAU* tab, int startPos, int endPos);
