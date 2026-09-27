// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = n = nums.size();
        if(n == 1 || (n == 2 && nums[0] == nums[1])) return 1;
        if(n == 2 && nums[0] != nums[1]) return 2;
        int i = 0, j = 1;
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
