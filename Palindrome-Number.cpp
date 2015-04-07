/*
*Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        int base = 1;
        while(x / base >= 10) base *= 10;
        
        while(x) {
            int left = x / base;
            int right = x % 10;
            
            if(left != right) return false;
            x -= left * base;
            base /= 100;
            x /= 10;
        }
        return true;
    }
};
