// https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n+1, 0);
        vector<int> suf(n+1, 0);
        for(int i=1; i<=n; i++){
            if(customers[i-1] == 'N'){
                pre[i] = 1 + pre[i-1];
            }
            else pre[i] = pre[i-1];
        }
        for(int i=n-1; i>=0; i--){
            if(customers[i] == 'Y'){
                suf[i] = 1 + suf[i+1];
            }
            else suf[i] = suf[i+1];
        }
        for(int i=0; i<=n; i++){
            pre[i] += suf[i];
        }
        auto it = min_element(pre.begin(),pre.end());
        int index = distance(pre.begin(), it);
        return index;
    }
};
