/**
*Given a permutation which contains no repeated number, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.
*Example*
*Given [1,2,4], return 1.*
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long index = 1;
        int position = 2;
        long long fac = 1;
        for (int i = A.size() - 2; i >=0; --i) {
            int an = 0;
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j])
                    ++an;
            }
            index += an * fac;
            fac *= position;
            ++position;
        }
        return index;
    }
};
