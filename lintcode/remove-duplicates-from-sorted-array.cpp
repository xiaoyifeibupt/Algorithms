/**
*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
*Example*
*Given input array *A = [1,1,2]*,*
*Your function should return *length = 2*, and A is now *[1,2]*.*
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0, right = 1;
        while (right < nums.size()) {
            if (nums[left] != nums[right]) {
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }
        return left + 1;
    }
};
