#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#ifndef creditCard_H
#define creditCard_H

typedef struct {	
	char firstName[20];
	char lastName[20];
	char expiryDate[8];
	char bankCode[6];
	int card_no;
} creditCard;

#endif