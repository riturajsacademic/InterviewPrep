/*
Idea: 2 XOR 2 = 0.
As every element is repeated 2 times except the unique one. 

Also, X XOR 0 = X (Here, X can be any number.)

*/

int singleNumber(int* nums, int numsSize) {
    
    int index;
    int result = 0;
    
    if(numsSize == 1) {
        return nums[0];
    }
    
    for(index = 0; index < numsSize; index++) {
        result ^= nums[index];
    }
    
    return result;
}