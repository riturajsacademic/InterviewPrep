#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	char *str1;
	char *str2;
	int i=0,temp=0;

	str1 = argv[1];
	str2 = argv[2];

	//check if string length is an issue.
	if(strlen(str1)!=strlen(str2)){
		printf("\nError");
	}
	while(i<strlen(str1)){
		temp +=str1[i]-'a';
		printf("\n%d",temp);
		temp -=str2[i]-'a';
		printf("\t%d",temp);
		i++;
	}
	if(temp==0){
		printf("\nSuccess");
	}
	else{
		printf("\nError, Not Equal");
	}
}
