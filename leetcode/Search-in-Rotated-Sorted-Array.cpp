/**
*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

*(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

*You are given a target value to search. If found in the array return its index, otherwise return -1.

*You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0; 
        int right = nums.size() - 1;
        while(left <= right) {
            int midle = (left + right) >> 1;
            
            if(nums[midle] == target) return midle;
            
            if(nums[left] <= nums[midle]) {
                if(nums[left] <= target && target  < nums[midle]) {
                    right = midle - 1;
                }
                else
                    left = midle + 1;
            }
            else{
                if(nums[midle] < target && target <= nums[right])
                    left = midle + 1;
                else 
                    right = midle - 1;
            }
        }
        return -1;
    }
};
