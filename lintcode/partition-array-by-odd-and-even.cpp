/**
*Partition an integers array into odd number first and even number second.
*Example*
*Given *[1, 2, 3, 4]*, return *[1, 3, 2, 4]*

*Challenge*
*Do it in-place.*
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while(left <= right && nums[left] % 2 == 1)
                left++;
            while(left <= right && nums[right] % 2 == 0)
                right--;
            if (left < right)
                swap(nums[left++], nums[right--]);
        }
    }
};
