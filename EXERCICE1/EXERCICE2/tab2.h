typedef struct Tableau {
	int* elt;
	int size;
	int eltsCount;
} TABLEAU;

TABLEAU newArray();
int incrementArraySize(TABLEAU* tab, int incrementValue);


int setElement(TABLEAU* tab, int pos, int element);

int displayElements(TABLEAU* tab, int startPos, int endPos);

int deleteElements(TABLEAU* tab, int startPos, int endPos);