#include <stdio.h>

int main (void)
{
	int i=0;
    char c[] = "정답을 출력한다.";
    while(c[i]!=NULL)
    {
    	printf("%c",c[i]);
    	
    	if(c[i] == NULL) i = 0;
    	i++;
	}
    
    return 0;
}
