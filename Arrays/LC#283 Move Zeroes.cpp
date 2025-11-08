https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[j++] = nums[i];
            }
        }
        while(j<nums.size()){
            nums[j++] = 0;
        }
    }
};


// or 

var moveZeroes = function (nums) {
    let p1 = 0
    let p2 = 1
    //conditions: p1 -> 0 , p2 -> 1 : swap

    while (p2 <= nums.length - 1) {
        if (nums[p1] === 0 && nums[p2] !== 0) {
            [nums[p1], nums[p2]] = [nums[p2], nums[p1]]
            p1++
            p2++
        } else if (nums[p1] == 0 && nums[p2] == 0) {
            p2++
        } else {
            p1++
            p2++
        }
    }
};
