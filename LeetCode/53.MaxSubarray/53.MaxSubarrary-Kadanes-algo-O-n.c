/*
    Idea: Using Kadane's algorithm. 
    For each element : 
    maxEachIteration = maxEachIteration + array[index];
    
    if (maxEachIteration < 0) 
        maxEachIteration = 0; // i.e, do not take negative values. only start with a positive one.
        
    if ( maxFinal < maxEachIteration) {
        maxFinal = maxEachIteration;
    }
*/
#define max(a,b) (a>b)?a:b

int maxSubArray(int* nums, int numsSize) {
    int index;
    int maxEachIteration = 0;
    int maxFinal = INT_MIN;
    
    if(numsSize == 1) {
        return nums[0];
    }
    
    if (numsSize == 0) {
        return 0;
    }
    
    for (index = 0; index < numsSize; index++) {
        
        maxEachIteration = maxEachIteration < 0? nums[index]:max(nums[index] + maxEachIteration,nums[index]);
        maxFinal = max(maxFinal,maxEachIteration);
    }
    
    return maxFinal;
}