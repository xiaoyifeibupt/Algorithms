/**
*Given a string, find the length of the longest substring without repeating characters. 
*Example*
*For example, the longest substring without repeating letters for *"abcabcbb"* is *"abc"*, which the length is *3*. *
*For *"bbbbb"* the longest substring is *"b"*, with the length of *1*.*

*Challenge*
*O(n) time*
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int lsrc[256];
        memset(lsrc, -1, sizeof(lsrc));
        
        int index = -1,max = 0;
        for(int i = 0; i < s.length(); i++) {
            if(lsrc[s[i]] > index)
                index = lsrc[s[i]];
            if(i - index > max)
                max = i -index;
            lsrc[s[i]] = i;
        }
        return max;
    }
};
