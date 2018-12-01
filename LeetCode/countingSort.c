#include <stdio.h>
#include <stdlib.h>

void countingSort(int *num, int count, int **countArray, int *countArraySize)

//
// Given a number allocates new memory and does counting sort.
// Also sets the count array and its size.
//

{
	int index; 
	int temp = 0;
	int max = 0;
	int *ab;

	//
	// 1. identify the maximum element.
	//

	for (index = 0; index < count; index++) {
		if (num[index] > max) {
			max = num[index];
		}
	}

	//
	// 2. Allocate Count array and set values.
	//

	ab = (int *)malloc(sizeof(int)*max);

	if (ab == NULL) {
		return ;
	}

	for (index = 0; index < max; index++) {
		ab[index] = 0;
	}

	for (index = 0; index < count; index++) {
		ab[num[index]] += 1;
	}

	for (index = 1; index < max; index++) {
		ab[index] = ab[index]+ab[index-1];
	}

	*countArraySize = max;
	*countArray = ab;
	return;
}

int main() {
	int a[11] = {6,0,2,0,1,3,4,6,1,3,2};
	int count = 11;
	int *num;
	int numcount;
	int index;

	countingSort (a,count,&num,&numcount);
	for (index = 0; index < numcount; index++) {
		printf("\t%d",num[index]);
	}

	if(num != NULL) {
		free(num);
	}
}