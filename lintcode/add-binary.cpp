/**
*Given two binary strings, return their sum (also a binary string).
*Example*
*a = *11*
*b = *1*
*Return *100*
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string result;
        int length = a.length() > b.length() ? a.length() : b.length();
        int flag = 0;
        for (int i = 0; i < length; ++i) {
            int a_i = i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
            int b_i = i < b.length() ? b[b.length() - 1 - i] - '0' : 0;
            int sum = a_i + b_i + flag;
            flag = sum / 2;
            sum %= 2;
            result.push_back('0' + sum);
        }
        if (flag)
            result.push_back('0' + flag);
        reverse(result.begin(), result.end());
        return result;
    }
};
