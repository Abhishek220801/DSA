// https://leetcode.com/problems/fibonacci-number/

//Memoization or Top Down DP
//T O(n) S O(2n) or O(n) -> Recursive stack space + Array space 

class Solution {
public:
    int helper(vector<int>& dp, int ind){
        if(dp[ind]!=-1) return dp[ind];
        if(ind<=1) return dp[ind]=ind;
        return dp[ind] = helper(dp,ind-1)+helper(dp,ind-2);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        helper(dp,n);
        return dp[n];
    }
};

//Bottom Up DP or Iterative Way
//Time: O(n) 
//Space: O(n) no recursive stack space only array allocated memory

class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        vector<int>dp(n+1);
        dp[0]=0; dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};

//Space Optimization 

class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int seclast = 0, last = 1, ans;
        for(int i=2;i<=n;i++){
           ans = seclast + last;
           seclast = last;
           last = ans;
        }
        return ans;
    }
};
