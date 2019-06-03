#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

void Quicksort(int A[],int start,int end){
	
	int index;
	
	if(start<end){
		index = Partition(A,start,end);
		Quicksort(A,start,index-1);
		Quicksort(A,index+1,end);
	}
}

Partition(int A[],int start, int end){
	
	srand(time(NULL));
	
	int randNum = start+ (rand()%(end-start+1));
	int temp;
	
	temp = A[randNum];
	A[randNum] = A[end];
	A[end] = temp;
	//랜덤한 요소와 A[end] 요소를 스왑한다.
	
	int pivot = A[end];
	int rose = start;
	int i;
	
	for(i=start;i<end;i++){
		//값의 비교가 이뤄진다.
		if(A[i]<=pivot){
			
			temp = A[rose];
			A[rose] = A[i];
			A[i] = temp;
			rose++;
		} 
	}  
	
	temp = A[rose];
	A[rose] = A[end];
	A[end] = temp;
	
	return rose;
}
int main(void){
	int A[MAX] = {70,20,30,50,80,10,100,60,40,90};
	int i = 0;
	
	printf("\nbefore sorting\n");
	
	for(i=0;i<MAX;i++){
		printf("%d ",A[i]);
	}
	
	Quicksort(A,0,MAX-1);
	printf("\nafter sorting\n");
	
	for(i=0;i<MAX;i++){
		printf("%d ",A[i]);
	}
	
}

