// https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int prevLoss = 0, k = minutes, n = customers.size();
        for(int i=0; i<k; i++){
            if(grumpy[i]==1) prevLoss += customers[i];
        }
        int maxLoss = prevLoss;
        int maxIdx = 0;
        int i = 1, j = k;
        while(j<n){
            int currLoss = prevLoss;
            if(grumpy[j]==1) currLoss+=customers[j];
            if(grumpy[i-1]==1) currLoss-=customers[i-1]; 
            if(maxLoss < currLoss){
                maxLoss = currLoss;
                maxIdx = i;
            }
            prevLoss = currLoss;
            i++;
            j++;
        }
        // filling 0s in the grumpy array window 
        for(int i=maxIdx; i<maxIdx+k; i++){
            grumpy[i] = 0;
        }
        // sum of satisfaction
        int maxS = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i]==0) maxS += customers[i];
        }
        return maxS;
    }
};
