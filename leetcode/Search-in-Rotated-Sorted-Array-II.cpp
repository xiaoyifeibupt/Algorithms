/**
*Follow up for "Search in Rotated Sorted Array":
*What if duplicates are allowed?

*Would this affect the run-time complexity? How and why?

*Write a function to determine if a given target is in the array.
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int left = 0; 
        int right = nums.size() - 1;
        while(left <= right) {
            int midle = (left + right) >> 1;
            
            if(nums[midle] == target) return true;
            
            if(nums[left] < nums[midle]) {
                if(nums[left] <= target && target  <= nums[midle]) {
                    right = midle - 1;
                }
                else
                    left = midle + 1;
            }
            else if(nums[left] > nums[midle]){
                if(target >= nums[left] || target <= nums[midle])
                    right = midle - 1;
                else 
                    left = midle + 1;
            }
            else
                left++;
        }
        return false;
    }
};
