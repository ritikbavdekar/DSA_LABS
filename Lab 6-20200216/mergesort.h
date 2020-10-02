typedef struct
{
	char name[10];
	float cgpa;
}Element;

Element* read(char* filename,int size);
void merge(Element Ls1[],int sz1, Element Ls2[], int sz2,Element Ls[]);
void mergeSort(int arr[],int l,int r);
