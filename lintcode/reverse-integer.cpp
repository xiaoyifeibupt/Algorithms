/**
*Reverse digits of an integer. Returns 0 when the reversed integer overflows (signed 32-bit integer).
*Example*
*Given *x = 123*, return *321*
*Given *x = -123*, return *-321*
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long long result = 0;
        int temp = abs(n);
        while (temp > 0) {
            result *= 10;
            result += temp % 10;
            temp /= 10;
        }
        result = (n >= 0) ? result : -result;
        return ((result > INT_MAX || result < INT_MIN) ? 0 : result);
    }
};
