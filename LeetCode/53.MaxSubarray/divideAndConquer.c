
int FindCrossMax(int *nums, int low, int mid, int high) {
    
    int index; 
    int lsum = INT_MIN;
    int rsum = INT_MIN;
    int sum = 0;
    
    for (index = mid; index > low; index--) {
        sum += nums[index];
        if (sum > lsum) {
            lsum = sum;
        }
    }
    
    sum = 0;
    for (index = mid; index < high; index++) {
        sum += nums[index];
        if (sum > rsum) {
            rsum = sum;
        }
    }
    
    return (lsum+rsum);
}

int FindMaxSubArray(int* nums, int low, int high)
{
    int lsum,rsum,csum;
    int mid;
    
    if (low == high) {
        //
        // Base case. Only 1 element.
        //
        return nums[low];
    } else {
        
        mid = (low+high)/2;
        lsum = FindMaxSubArray(nums,low,mid);
        rsum = FindMaxSubArray(nums,mid+1,high);
        csum = FindCrossMax(nums,low,mid,high);
    }
    
    if (lsum > rsum && lsum > csum) {
        return lsum;
    } else if (rsum > lsum && rsum > csum) {
        return rsum;
    }
    
    return csum;
}

int maxSubArray(int* nums, int numsSize) {
    return FindMaxSubArray(nums,0,numsSize-1);
}