/**
*Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
*Example*
*Given *[1,2,2,3,4,4,5,3]* return *1* and *5*

*Challenge*
*O(n) time, O(1) extra space.*
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        if (A.size() == 0) return {0,0};
        int allOR = 0;
        for (int a : A)
            allOR ^= a;
        int indexBit = allOR & ~(allOR - 1);
        
        int x = 0;
        for (int a : A) {
            if (a & indexBit)
                x ^= a;
        }
        return {x,allOR ^ x};
    }
};
