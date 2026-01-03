#include<bits/stdc++.h>
using namespace std;

bool canPartition(int nums[], int n){
    int x = 0; 
    vector<int> pre(n);
    pre[0] = nums[0];
    int y = pre[n-1];
    if(y%2!=0) return false;
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] + nums[i];
    }
    while(x<n){
        if(2*pre[x]==y) return true;
    }
    return false;
}

int main() {
    
    int nums[] = {9,1,8,6,5,2};
    int n = sizeof(nums)/sizeof(nums[0]);
    
    if(canPartition(nums, n)) cout<<"Array can be partitioned";
    else cout<<"Array cannot be partitioned";
    
    // 2pre[x] = pre[n-1];

    return 0;
}
