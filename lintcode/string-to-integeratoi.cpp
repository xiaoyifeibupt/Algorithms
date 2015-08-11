/**
*Implement function atoi to convert a string to an integer.
*Example*
*"10" => 10*
*"-1" => -1*
*"123123123123123" => 2147483647*
*"1.0" => 1*
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        if (str.empty()) return 0;
        int i = 0, sign = 1, result = 0;
        while (str[i] == ' ')
            ++i;
        
        if (str[i] == '-') {
            sign = -1;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }
        
        for (; i < str.length() && isdigit(str[i]); ++i) {
            if (result > (INT_MAX - (str[i] - '0')) / 10 ||
                ((str[i] - '0') == INT_MAX / 10 && 
                (str[i] - '0') > INT_MAX % 10)) { 
                    return sign > 0 ? INT_MAX : INT_MIN;
            }
            result *= 10;
            result += str[i] - '0';
        }
        result *= sign;
        return result;
    }
};
