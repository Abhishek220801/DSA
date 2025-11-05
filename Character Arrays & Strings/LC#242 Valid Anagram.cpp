https://leetcode.com/problems/valid-anagram/

// by sorting both
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};

//using un_map -> since duplicates can exist
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<int,int> mp;
        for(auto &x: s){
            mp[x]++;
        }
        for(auto &y: t){
            if(mp.find(y)==mp.end()) return false;
            mp[y]--;
            if(mp[y]==0) mp.erase(y);
        }
        if(mp.size()>0) return false;
        return true;
    }
};
