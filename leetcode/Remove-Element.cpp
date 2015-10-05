/**
*Given an array and a value, remove all instances of that value in place and return the new length.
*The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size();
        while (i < j) {
            if (nums[i] == val)
                swap(nums[i], nums[--j]);
            else
                ++i;
        }
        return i;
    }
};