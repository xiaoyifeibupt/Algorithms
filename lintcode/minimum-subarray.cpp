/**
*Given an array of integers, find the subarray with smallest sum.
*Example*
*For *[1, -1, -2, 1*], return *-3*

*Note*
*The subarray should contain at least one integer.*
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int minSum = INT_MAX, sum = 0;
        for (auto& num : nums) {
            sum += num;
            minSum = min(sum, minSum);
            if (sum > 0)
                sum = 0;
        }
        return minSum;
    }
};

