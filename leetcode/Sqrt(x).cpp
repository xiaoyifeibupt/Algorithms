/*
*Implement int sqrt(int x).
*Compute and return the square root of x.
*/
/*Newton*/
class Solution {
public:
    int mySqrt(int x) {
        if (x ==0)  
            return 0;  
        double pre;  
        double cur = 1;  
        do  
        {  
            pre = cur;  
            cur = x / (2 * pre) + pre / 2.0;  
        } while (abs(cur - pre) > 0.00001);  
        return int(cur);
    }
};
