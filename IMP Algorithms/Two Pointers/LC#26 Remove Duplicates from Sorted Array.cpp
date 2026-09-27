// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while(j < n) {
            if(nums[j] != nums[j-1]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};
