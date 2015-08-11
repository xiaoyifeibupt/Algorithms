/**
*Write an algorithm which computes the number of trailing zeros in n factorial.
*Example*
*11! = 39916800*, so the out should be 2*

*Challenge*
*O(log N) time*
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long count = 0;
        while (n) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

