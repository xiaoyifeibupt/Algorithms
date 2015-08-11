/**
*Compare two strings A and B, determine whether A contains all of the characters in B. 
*Example*
*For *A = "ABCD"*, *B = "ACD"*, return *true*.*
*For *A = "ABCD"*, *B = "AABC"*, return *false*.*

*Note*
*The characters of B in A are not necessary continuous or ordered. *
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        unordered_map<char, int> count;
        for (const auto& aa : A)
            ++count[aa];
        for (const auto& bb :B) {
            --count[bb];
            if (count[bb] < 0)
                return false;
        }
        return true;
    }
};

