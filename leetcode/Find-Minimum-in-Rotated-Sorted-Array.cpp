/**
*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

*Find the minimum element.

*You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0;
        int right = nums.size() - 1;
        int mid = left;
        while(nums[left] >= nums[right]) {
            if(right - left == 1) {
                mid = right;
                break;
            }
            mid = left + ((right - left)>>1);
            if(nums[left] == nums[right] && nums[mid] == nums[left]) 
                return MinInOrder(nums,left,right);
            if(nums[mid] >= nums[left])
                left = mid;
            else if(nums[mid] <= nums[right])
                right = mid;
        }
    return nums[mid];
    }
    int MinInOrder(vector<int>&nums,int left,int right) {
        int result = nums[left];
        for(int i = 0; i <= right; i++) {
            if(result > nums[i])
                result = nums[i];
        }
    return result;
    }
};
