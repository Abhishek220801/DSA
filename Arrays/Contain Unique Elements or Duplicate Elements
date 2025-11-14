#include <iostream>
#include <unordered_map>
using namespace std;

bool checkUnique(int arr[], int n){
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){      // can use for each in case of vectors but not raw array bc they decay to pointer when passed to functions 
        mp[arr[i]]++;
    }
    for(auto &x: mp){
        if(x.second>1) return false;
    }
    return true;
}

int main() {
    int arr[] = {3,7,9,1,5,8,10,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bool unique = checkUnique(arr, n);
    
    if(unique) cout<<"All elements in array are unique";
    else cout<<"Array contains duplicate elements";

    return 0;
}
