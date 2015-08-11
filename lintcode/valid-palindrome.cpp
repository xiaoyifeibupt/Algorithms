/**
*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*Example*
*"A man, a plan, a canal: Panama"* is a palindrome.*
*"race a car"* is not a palindrome.*

*Note*
*Have you consider that the string might be empty? This is a good question to ask during an interview.*
*For the purpose of this problem, we define empty string as valid palindrome.*

*Challenge*
*O(n) time without extra memory.*
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while(i < j && !isalnum(s[i]))
                ++i;
            while(i < j && !isalnum(s[j]))
                --j;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
