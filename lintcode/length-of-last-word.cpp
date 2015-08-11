/**
*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
*Example*
*Given s = *"Hello World"*, return *5*.*

*Note*
*A word is defined as a character sequence consists of non-space characters only.*
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int len = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (len > 0)
                    break;
            } else
                ++len;
        }
        return len;
    }
};
