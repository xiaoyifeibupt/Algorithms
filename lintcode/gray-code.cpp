/**
*The gray code is a binary numeral system where two successive values differ in only one bit.
*Example*
*Given *n = 2*, return *[0,1,3,2]*. Its gray code sequence is:*
*00 - 0
01 - 1
11 - 3
10 - 2
*

*Note*
*For a given *n*, a gray code sequence is not uniquely defined.*
*[0,2,3,1]* is also a valid gray code sequence according to the above definition.*

*Challenge*
*O(2*n*) time.*
*/

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        /**
        vector<int> result = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = result.size() - 1; j >= 0; --j) {
                result.emplace_back(1 << i | result[j]);
            }
        }
        return result;
        */
        vector<int> result;
        for (int i = 0; i < 1 << n; ++i) {
            result.emplace_back(i >> 1 ^ i);
        }
        return result;
    }
};
