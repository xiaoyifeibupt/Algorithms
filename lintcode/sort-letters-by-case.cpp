/**
*Given a string which contains only letters. Sort it by lower case first and upper case second.
*Example*
*For &quot;*abAcD*&quot;, a reasonable answer is &quot;*acbAD*&quot;*

*Note*
*It's *not necessary* to keep the original order of lower-case letters and upper case letters.*

*Challenge*
*Do it in one-pass and in-place.*
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int i = 0, j = letters.length() - 1;
        while (i < j) {
            while (i <= j && islower(letters[i]))
                ++i;
            while (i <= j && isupper(letters[j]))
                --j;
            if (i < j)
                swap(letters[i++], letters[j--]);
        }
    }
};

