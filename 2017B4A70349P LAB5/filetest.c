#include "measureTimeAndSpace.h"
#include "insertionSort.h"
#include "readRecord.h"

int main(int argc, char* argv[]){
	spaceForSortingTest(argv[1],argv[2]);
	timeForSortingTest(argv[1],argv[2]);
	timeForReadingTest(argv[1],argv[2]);
	

}
