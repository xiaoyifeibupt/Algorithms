/**
*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

*Example*
*Given array A = *[2,3,1,1,4]*
*
*
The minimum number of jumps to reach the last index is *2*. (Jump *1* step from index 0 to 1, then *3* steps to the last index.)
*
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int ret = 0, curr = 0, last = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > curr)
                return -1;
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i + A[i]);
        }
        return ret;
    }
};
