/**
*Write a method to replace all spaces in a string with %20. The string is given in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.
*Example*
*Given *"Mr John Smith"*, length = *13*.*
*The string after replacement should be *"Mr%20John%20Smith"*.*

*Note*
*If you are using Java or Python，please use characters array instead of string.*

*Challenge*
*Do it in-place.*
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if (length == 0) return 0;
        int nelen = length;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ')
                nelen += 2;
        }
        int j = nelen;
        int i = length - 1;
        string[j--] = '\0';
        while (i >= 0) {
            if (string[i] == ' ') {
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
            }
            else
                string[j--] = string[i];
            --i;
        }
        return nelen;
    }
};
