/**
*Count the number of k's between 0 and n. k can be 0 - 9.
*Example*
*if n=12, k=1 in *[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]*, we have *FIVE *1's *(1, 10, 11, 12)*
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            int num = i;
            while (num > 0) {
                if (num % 10 == k) {
                    ++cnt;
                }
                num /= 10;
            }
        }
        return cnt;
    }
};
