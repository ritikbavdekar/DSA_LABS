#include "insertionSort.h"

void insertInOrder(creditCard* cardArray, int n, creditCard newcard){
	creditCard card = newcard;
	creditCard tempcard;
	for(int i=0;i<n;i++){
		if(card.card_no < cardArray[i].card_no || i==n-1){
			tempcard = card;
			card = cardArray[i];
			cardArray[i] = tempcard;
		}
	}
}

void insertionSort(creditCard* cardArray,int n){
	if(n==0){
		topstack = &n;
		return;
	}
	insertionSort(cardArray,n-1);
	insertInOrder(cardArray,n,cardArray[n-1]);
}
