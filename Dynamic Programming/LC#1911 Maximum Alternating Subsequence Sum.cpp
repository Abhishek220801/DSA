// https://leetcode.com/problems/maximum-alternating-subsequence-sum

// Brute Force: Recursive O(2^n * n)
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


// Memoization -> O(n)
class Solution {
public:
    typedef long long ll;
    int n;
    ll t[100001][2];

    ll solve(vector<int>& nums, int idx, bool flag){
        if(idx >= n) return 0;
        if(t[idx][flag]!=-1) return t[idx][flag];
        ll skip = solve(nums, idx+1, flag);
        ll val = nums[idx];
        if(flag == false) val = -val;
        ll take = solve(nums, idx+1, !flag) + val;
        return t[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, true);  // 0 - even index, true : + 
    }
};


// Bottom Up 
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long>> t(n+1, vector<long>(2, 0)); // even : 0 , odd : 1

        for(int i=1; i<=n; i++){
            // Even
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]);
            // Odd
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]);
        }

        return max(t[n][0], t[n][1]);
    }
};
