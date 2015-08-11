/**
*Given an integers array A.
*Example*
*For A = *[1, 2, 3]*, return *[6, 3, 2]*.*
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> result(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        long long right = 1;
        for (int j = nums.size() - 1; j >= 0; --j) {
            result[j] *= right;
            right *= nums[j];
        }
        return result;
    }
};
