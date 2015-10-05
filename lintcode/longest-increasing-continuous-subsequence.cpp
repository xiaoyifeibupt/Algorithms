/**
*Give you an integer array (index from 0 to n-1, where n is the size of this array)，find the longest increasing continuous subsequence in this array. (The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)
*Example*
*For *[5, 4, 2, 1, 3]*, the LICS  is *[5, 4, 2, 1]*, return *4*.*
*For *[5, 1, 2, 3, 4]*, the LICS  is *[1, 2, 3, 4]*, return *4*.*

*Note*
*O(n) time and O(1) extra space. *
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int max_inc = 0, max_dec = 0;
        int cur_inc = 0, cur_dec = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i == 0 || (i > 0 && A[i] == A[i - 1])) {
                max_inc = max(max_inc, ++cur_inc);
                max_dec = max(max_dec, ++cur_dec);
            } else if (i > 0 && A[i] > A[i - 1]) {
                max_inc = max(max_inc, ++cur_inc);
                cur_dec = 1;
            } else if (i > 0 && A[i] < A[i - 1]) {
                cur_inc = 1;
                max_dec = max(max_dec, ++cur_dec);
            }
        }
        return max(max_inc, max_dec);
    }
};