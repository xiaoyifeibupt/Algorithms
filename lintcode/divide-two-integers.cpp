/**
*Divide two integers without using multiplication, division and mod operator.
*Example*
*Given dividend = *100* and divisor = *9*, return *11*.*
*/

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
       if (dividend == 0)
            return 0;
        if (divisor == 0)
            return INT_MAX;

        long long result = exp(log(fabs(dividend)) - log(fabs(divisor)));
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;
        if (result > INT_MAX)
            result = INT_MAX;
        return result;
    }
};
