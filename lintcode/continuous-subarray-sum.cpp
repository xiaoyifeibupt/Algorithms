/**
*Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)
*Example*
*Give *[-3, 1, 3, -3, 4]*, return *[1,4]*.*
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        if (A.empty()) return {-1, -1};
        int sum = A[0];
        int maxSum = sum;
        vector<int> max_i_j{0, 0};
        for (int i = 0, j = 1; j < A.size(); ++j) {
            if (sum < 0) {
                i = j;
                sum = 0;
            }
            sum += A[j];
            if (sum > maxSum) {
                maxSum = sum;
                max_i_j[0] = i, max_i_j[1] = j;
            }
        }
        return max_i_j;
    }
};
