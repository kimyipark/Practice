#include <stdio.h>

int yy;
int mm;
int dd;

int main (void){
	scanf("%d.%d.%d",&yy,&mm,&dd);
	
	printf("%04d.%02d.%02d",yy,mm,dd);
	
	return 0;
}

