/**
*Find the Nth number in Fibonacci sequence.
*Example*
*Given *1*, return *0*
*Given *2*, return *1*
*Given *10*, return *34*

*Note*
*The *N*th fibonacci number won't exceed the max value of signed 32-bit integer in the test cases.*
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n == 1) return 0;
        if (n == 2) return 1;
        int a = 0, b = 1, c = 0;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

