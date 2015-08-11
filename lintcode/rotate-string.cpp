/**
*Given a string and an offset, rotate string by offset. (rotate from left to right)
*Example*
*Given *"abcdefg"*.*
*offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
*

*Challenge*
*Rotate in-place with O(1) extra memory.*
*/

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        if (!A.empty()) {
            offset %= A.length();
            reverse(A.begin(), A.begin() + A.length() - offset);
            reverse(A.begin() + A.length() - offset, A.end());
            reverse(A.begin(), A.end());
        }
        return A;
    }
    
};
