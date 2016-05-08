#include <stdio.h>

int partition(int a[],int l,int h){
	int index,i,temp;
	int pivot = a[h-1];
	i=l;
	for(index=l;index<h-1;index++){
		if(a[index]<pivot){
			//swap a[index] and a[i]
			//a[index] +=a[i];
			//a[i] = a[index]-a[i];
			//a[index] = a[index]-a[i];
			temp = a[index];
			a[index] = a[i];
			a[i] = temp;
			i+=1;
		}
	}

	//swap i and pivot.
	temp = a[h-1];
	a[h-1] = a[i];
	a[i] = temp;
	return i;
}


void quickSortArray(int a[],int low,int high){
	if(low<high){
	int index = partition(a,low,high);
	printf("\nAt index %d Value: %d",index,a[index]);
	quickSortArray(a,low,index);
	quickSortArray(a,index+1,high);
	}
}

int main(){
int a[5] = {2,5,4,1,3};
int size = 0,i;
size = sizeof(a)/sizeof(int);
quickSortArray(a,0,size);

for(i=0;i<5;i++){
	printf("\n%d size: %d  %d  %d",a[i],size,sizeof(a),sizeof(int));
}

return 0;
}
