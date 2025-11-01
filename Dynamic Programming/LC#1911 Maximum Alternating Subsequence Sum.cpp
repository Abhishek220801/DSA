// https://leetcode.com/problems/maximum-alternating-subsequence-sum

// Brute Force: Recursive
class Solution {
public:
    typedef long long ll;
    int n;

    ll solve(vector<int>& nums, int idx, bool flag){
        if(idx >= n) return 0;
        ll skip = solve(nums, idx+1, flag);
        ll val = nums[idx];
        if(flag == false) val = -val;
        ll take = solve(nums, idx+1, !flag) + val;
        return max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        return solve(nums, 0, true);  // 0 - even index, true : + 
    }
};
