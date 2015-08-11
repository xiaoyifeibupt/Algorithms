/**
*Given two array of integers(the first array is array A, the second array is array B), now we are going to find a element in array A which is A[i], and another element in array B which is B[j], so that the difference between A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference. 
*Example*
*For example, given array A = *[3,6,7,4]*, B = *[2,8,9,3]*,  return *0*

*Challenge*
*O(*n* log *n*) time*
*/

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int i = 0;
        int j = 0;
        int min_diff = INT_MAX;

        while (i < A.size() && j < B.size()) {
            min_diff = min(min_diff, abs(A[i] - B[j]));
            A[i] < B[j] ? ++i : ++j;
        }

        return min_diff;
    }
};

