// prefix sum calculation array creation 
vector<int> prefixSum(n);

// prefix sum calculation 
prefixSum[0] = arr[0];
for(int i=1; i<=n; i++){
    prefixSum[i] = prefixSum[i-1]+arr[i];
}

// printing
for(auto &x: prefixSum){
    cout<<x<<" ";
}
    
