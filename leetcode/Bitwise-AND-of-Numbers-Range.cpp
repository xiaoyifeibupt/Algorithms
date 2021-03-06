/**
*Given a range [m, n] where 0 &lt;= m &lt;= n &lt;= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
*For example, given the range [5, 7], you should return 4.
*Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int offset = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            offset++;
        }
        return m << offset;
    }
};