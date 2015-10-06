/**
*Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.
*Example*
*Given *[-1, -2, -3, 4, 5, 6]*, after re-range, it will be *[-1, 5, -2, 4, -3, 6]* or any other reasonable answer.*

*Note*
*You are not necessary to keep the original order of positive integers or negative integers.*

*Challenge*
*Do it in-place and without extra memory.*
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int n = A.size(), countPositive = 0;
        bool next = false;
        for (const auto& a : A)
            countPositive += a > 0 ? 1 : 0;
        if (2 * countPositive > n) 
            next = true;
        int pos = 0, neg = 0, i = 0;
        while (pos < n && neg < n) {
            while (pos < n && A[pos] < 0)
                ++pos;
            while (neg < n && A[neg] > 0)
                ++neg;
            if (next && A[i] < 0)
                swap(A[i], A[pos]);
            if (!next && A[i] > 0)
                swap(A[i], A[neg]);
            if (i == pos)
                ++pos;
            if (i == neg)
                ++neg;
            next = !next;
            ++i;
        }
    }
};
