#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	char *str1;
	
	char *c;
	char a;
	str1 = argv[1];
	int i=0;
	printf("\n String is : %s\n",str1);
	
	c = argv[1];
	

	a=*c;
	//
	//	Print it bit by bit.
	//
	i=0;
	while(i<8){
		
		printf("%c",((a&(1<<i))?'1':'0'));
		++i;
	}

}
