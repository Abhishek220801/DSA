// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0, i = 0, j = 0;
        int len = 0, maxLen = INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else {   // nums[j] == 0
                if(flips<k){
                    flips++;
                    j++;
                }
                else{  // flips == k
                    len = j-i;
                    maxLen = max(len, maxLen);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
            len = j-i;
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};
