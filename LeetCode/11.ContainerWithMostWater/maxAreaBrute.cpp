#define min(a,b) (a<b)?a:b

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,j,max,a,b;
        int temp;
        i = 0;
        j = 0;
        max = 0;
        
        for (i=0; i < height.size(); i++) {
            for (j = i+1; j <= height.size();j++) {
                a = j-i;
                b = min(height[i],height[j]);
                temp = a*b;
                if (temp > max) {
                    max = temp;
                }
            }
        }
        return max;
    }

};