// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

#include<iostream>
#include<queue>
using namespace std;

int main()
{

    int arr[] = {6,5,3,2,8,10,9};
    int k = 3;

    int n = sizeof(arr)/4;

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto x: arr){
        pq.push(x);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    for(auto x: ans){
        cout<<x<<" ";
    }


    return 0;
}

// GFG Solution:
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        int ptr = 0;
        
        for(int i =0; i<n; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                arr[ptr++] = pq.top();
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            arr[ptr++] = pq.top();
            pq.pop();
        }
    }
};
