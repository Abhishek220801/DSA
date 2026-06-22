// https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while(left <= right) {
            if(abs(nums[left]) > abs(nums[right])) {
                ans[idx] = nums[left] * nums[left];
                left++;
            } else {
                ans[idx] = nums[right] * nums[right];
                right--;
            }

            idx--;
        }

        return ans;
    }
};
