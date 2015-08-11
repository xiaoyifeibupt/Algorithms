/**
*Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:
*Example*
*If nums = *[3,2,2,1]* and *k=2*, a valid answer is *1*.*

*Note*
*You should do really partition in array *nums* instead of just counting the numbers of integers smaller than k.*
*If all elements in *nums* are smaller than *k*, then return *nums.length*

*Challenge*
*Can you partition the array in-place and in O(n)?*
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            while (left <= right && nums[left] < k)
                left++;
            while (left <= right && nums[right] >= k)
                right--;
            if (left <= right)
                swap(nums[left++], nums[right--]);
        }
        return left;
    }
};
