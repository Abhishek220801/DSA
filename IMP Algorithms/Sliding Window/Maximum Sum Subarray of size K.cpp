// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// #1. Brute Force 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maxSum = INT_MIN;
    
    for(int i=0; i<=n-k; i++){
        int sum = 0;
        for(int j=i; j<i+k; j++){
            sum+=arr[j];
        }
        maxSum = max(sum, maxSum);
    }
    
    cout<<"Maximum subarray sum = "<<maxSum<<endl;
    return 0;
}

// 2. Sliding Window Approach 
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int prevSum = 0, currSum = 0, maxSum = INT_MIN;
        for(int i=0; i<k; i++)
            prevSum += arr[i];
        maxSum = max(maxSum, prevSum);
        int i = 1, j = i+k-1, n = arr.size();
        while(j<n){
            currSum = prevSum+arr[j]-arr[i-1];
            maxSum = max(maxSum, currSum);
            prevSum = currSum;
            i++;
            j++;
        }
        return maxSum;
    }
};
