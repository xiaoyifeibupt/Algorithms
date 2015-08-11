/**
*You are climbing a stair case. It takes n steps to reach to the top.
*Example*
*Given an example n=3 , 1+1+1=2+1=1+2=3*
*return 3*
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n <= 2)
            return n;
        else{
            int a = 1,b = 2,c = 0;
            for(int i = 0;i < n - 2;i++){
                c = a + b;
                a = b;
                b = c;
            }
            return b;
        }
    }
};

