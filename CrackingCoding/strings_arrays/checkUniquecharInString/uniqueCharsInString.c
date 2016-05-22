#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
int i,temp,final,temp2;
char *c;

printf("Argc:%d ",argc);
printf("String is: %s",argv[0]);
c = argv[1];
final = temp = i = 0;
printf("\ntemp\tchar\ttemp2\tfinal/Success");
	
	while(i<strlen(c)){
		temp = c[i] - 'a';
		printf("\n%d\t",temp);
		temp2 =(final&(1<<temp)); 
		printf("%c\t",c[i]);
		printf("%d\t",temp2);
		if(temp2>0)
		{
			printf("\nString was bad!!");
			break;
		}
		else
		{
			i++;
			final = final|(1<<temp);	
			printf("%d\t",final);
		
		}
	
	}
	if(temp2==0){
		printf("\nSuccess");
	}
}
