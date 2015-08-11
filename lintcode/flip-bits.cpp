/**
*Determine the number of bits required to flip if you want to convert integer n to integer m.
*Example*
*Given *n* = *31* (11111), *m* = *14* (01110), return *2*.*

*Note*
*Both *n* and *m* are 32-bit integers.*
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int num = 0;
        for (int c = a ^ b; c != 0; c &= c - 1) {
            ++num;
        }
        return num;
    }
};
