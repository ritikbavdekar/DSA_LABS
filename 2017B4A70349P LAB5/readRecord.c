#include "readRecord.h"

creditCard* readCard(creditCard* cardArray,char* filename,int* finalsize)
{
	int size=10;
	cardArray=(creditCard*)malloc(sizeof(creditCard)*size);
	FILE* f =fopen(filename,"r");

	if(f==NULL)
	{
		printf("FILE Doesn't exist");
		exit(0);
	}
	creditCard newcard;
	int i=0;
	while(!feof(f)){
		fscanf(f,"\"%d,%[^,],%[^,],%[^,],%[^\"]\"\n",&(newcard.card_no),newcard.bankCode,newcard.expiryDate,newcard.firstName,newcard.lastName);
		cardArray[i++]=newcard;
		if(i==size){
			size*=2;
			cardArray = realloc(cardArray,sizeof(creditCard)*size);
		}
	}
	fclose(f);
	*finalsize = i;
	return cardArray;
}