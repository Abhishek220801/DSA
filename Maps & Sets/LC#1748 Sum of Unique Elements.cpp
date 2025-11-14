// https://leetcode.com/problems/sum-of-unique-elements/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        for(auto &x: nums){
            if(s.find(x)!=s.end()){
                ans+=x;
                s.erase(x);
            } 
        }
        for(auto &x: mp){
            if(x.second==1) ans+=x.first;
        }
        return ans;
    }
};
