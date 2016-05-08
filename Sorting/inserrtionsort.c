#include <stdio.h>

void insertionSortArray(int a[]){
	int i,j,size=0;
	size = sizeof(a);
	printf("Size : %d\n",size);
	for(i=0;i<=size;i++){
		for(j=i+1;j<=size;j++){
			if(a[i]>a[j]) {
				//swap variables.
				a[i] = a[i]+a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}

		}
		printf("Value : %d\n",a[i]);
	}

}

void main(){
int a[5] = {5,3,4,2,1};
printf("This world");
insertionSortArray(a);
}
