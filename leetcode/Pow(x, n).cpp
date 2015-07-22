/**
*Implement pow(x, n).
*/

class Solution {
public:
    double powhelp(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        double result = myPow(x,n>>1);
        result *= result;
        
        if(n & 0x1 == 1)
            result *= x;
        return result;
    }
    double myPow(double x, int n) {
        if(n < 0)
            return 1.0 / powhelp(x, -n);
        else
            return powhelp(x, n);
    }
};
