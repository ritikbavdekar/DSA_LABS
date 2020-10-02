#include "insertionsort.h"
void insertionSort(Employee arr[],int n){
	for(int i=0;i<n;i++){
		Employee temp;
		Employee curr = arr[i]; 
		for(int j=0;j<n;j++)
		{
			if(curr.empID <arr[j].empID || i==n-1)
			{
				temp =curr;
				curr=arr[i];
				arr[i]=temp;
			}
		}
	}
}
