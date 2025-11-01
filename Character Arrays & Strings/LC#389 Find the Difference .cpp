// Approach 2 - using ASCII and difference 
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum_s = 0, sum_t = 0;
        for(int i=0; i<s.length(); i++){
            sum_s += (int)s[i];
        }
        for(int i=0; i<t.length(); i++){
            sum_t += (int)t[i];
        }
        return (char)(sum_t - sum_s);
    }
};
