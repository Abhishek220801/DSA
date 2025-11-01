// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int n;

    int solve(vector<int>& nums, int i, int p){
        if(i>=n) return 0;
        
        int take = 0;
        if(p==-1 || nums[i]>nums[p])
            take = 1 + solve(nums, i+1, i);
        
        int skip = solve(nums, i+1, p);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        return solve(nums, 0, -1);
    }
};
