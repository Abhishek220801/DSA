// https://leetcode.com/problems/house-robber-ii/

// Top Down or Memoization
class Solution {
public:
    int t[101];
    int helper(vector<int>& nums, int i, int n){
        if(i>n) return 0;      // using n as index and both n-1 and n-2 are valid indices, so can't consider them out of bound values
        if(t[i]!=-1) return t[i];
        int steal = nums[i] + helper(nums,i+2,n);
        int skip = helper(nums,i+1,n);
        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];               // single house
        if(n==2) return max(nums[0],nums[1]);  // two houses
        memset(t, -1, sizeof(t));
        int steal_0th = helper(nums,0,n-2);    // 0th robber, can't rob last since circular
        memset(t, -1, sizeof(t));              // 1st robbed, can rob last 
        int skip_0th = helper(nums,1,n-1);
        return max(steal_0th, skip_0th);     
    }
};

// Bottom Up or Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> t(n+1, 0);
        t[0] = 0;
        
        // case 1: steal house 1, can't take last
        for(int i=1; i<=n-1; i++){
            int skip = t[i-1];
            int steal = nums[i-1] + ((i-2)>=0 ? t[i-2] : 0);
            t[i] = max(skip, steal);
        }
        int res1 = t[n-1];

        t.clear();
        t[0] = 0, t[1] = 0;

        // case 2: skip house 1, therefore can take last
        for(int i=2; i<=n; i++){
            int skip = t[i-1];
            int steal = nums[i-1] + ((i-2)>=0 ? t[i-2] : 0);
            t[i] = max(skip, steal);
        }
        int res2 = t[n];

        return max(res1, res2);
    }
};


// Space Optimization 
class Solution {
public:
    int solve(vector<int>& nums, int l, int r){
        int prevPrev = 0, prev = 0, ans;

        for(int i=l; i<=r; i++){
            int skip = prev;
            int take = nums[i]+ prevPrev;
            ans = max(skip, take);
            prevPrev = prev;
            prev = ans;
        }
        
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        int take_0th = solve(nums, 0, n-2);
        int skip_0th = solve(nums, 1, n-1);

        return max(take_0th, skip_0th);
    }
};
