#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
*	Assumtions :
*	1. ASCII char set.
*	2. inplace sorting required.
*	3. knowing where is the char to start
*/
int main(int argc,char **argv)
{
	char a[] = "a b c    ";
	int toChange = strlen(a)-1;
	int last = strlen(a);
	//assumptions where is the last char in string
	int ptr = 4;
	printf("\nString Prev : %s",a);
	while(toChange>0){
		if(a[ptr]!=' '){
			a[toChange] = a[ptr];
			toChange-=1;
			
		}
		else {
			a[toChange] = '0';
			a[toChange-1] = '2';
			a[toChange-2] = '%';
			toChange-=3;
			
		}
		ptr--;
	}
	printf("\nString now : %s with length %d",a,strlen(a));
}
