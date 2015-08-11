/**
*Implement int sqrt(int x).
*Example*
*sqrt(3) = 1*
*sqrt(4) = 2*
*sqrt(5) = 2*
*sqrt(10) = 3*

*Challenge*
*O(log(x))*
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
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
