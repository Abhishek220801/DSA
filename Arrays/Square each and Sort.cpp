// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// TC: O(nlogn) due to sorting
void squareSort(vector<int> &arr){
    for(auto &x: arr){
        x*=x;
    }
    sort(arr.begin(),arr.end());
}
