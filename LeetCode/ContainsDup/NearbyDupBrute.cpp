class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int i,j,jmax;
        bool flag = false;
        
        if (nums.size() == 1) {
            return false;
        }
        
        for (i = 0;i<nums.size();i++) {
            jmax = (i+k>nums.size()-1) ? nums.size()-1:i+k;
            for (j = i+1; j <= jmax;j++) {
                if (abs((long)nums[i] - nums[j]) <= t && abs((long)j-i) <= k) {
                    flag = true;
                    break;
                }
            }
        }
        
        return flag;
    }
};