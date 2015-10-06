/**
*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
*Example*
*Given *[1, 0, 1, 2]*, return *[0, 1, 1, 2]*.*

*Note*
*You are not suppose to use the library's sort function for this problem. *

*Challenge*
*A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.*
*Could you come up with an one-pass algorithm using only constant space?*
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int begin = 0, cur = 0, end = nums.size() - 1;
        while (cur <= end) {
            if (nums[cur] == 0) {
                swap(nums[begin],nums[cur]);
                ++begin;
                ++cur;
            } else if (nums[cur] == 1) {
                ++cur;
            } else {
                swap(nums[cur], nums[end]);
                --end;
            }
        }
    }
};
