/**
*Find the contiguous subarray within an array (containing at least one number) which has the largest product.
*Example*
*For example, given the array *[2,3,-2,4]*, the contiguous subarray *[2,3]* has the largest product = *6*.*
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int global_max = INT_MIN, local_max = 1, local_min = 1;

        for (const auto& n : nums) {
            int cur_max = local_max * n;
            int cur_min = local_min * n;
            local_max = max(n, max(cur_max, cur_min));
            local_min = min(n, min(cur_max, cur_min));
            global_max = max(global_max, local_max);
        }

        return global_max;
    }
};
