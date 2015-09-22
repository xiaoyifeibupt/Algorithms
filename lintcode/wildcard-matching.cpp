/**
*Implement wildcard pattern matching with support for '?' and '*'.
*Example*
*isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int p_pos = 0, s_pos = 0;
        int last_p_pos = -1, last_s_pos = -1;
        const int s_len = strlen(s), p_len = strlen(p);
        while (s_pos < s_len) {
            if (p_pos < p_len && (p[p_pos] == s[s_pos] || p[p_pos] == '?')) {
                ++s_pos;
                ++p_pos;
            } else if (p_pos < p_len && p[p_pos] == '*') {
                ++p_pos;
                last_s_pos = s_pos;
                last_p_pos = p_pos;
            } else if (last_p_pos != -1) {
                ++last_s_pos;
                s_pos = last_s_pos;
                p_pos = last_p_pos;
            } else
                return false;
        }
        while (p_pos < p_len && p[p_pos] == '*')
            ++p_pos;
        return p_pos == p_len;
    }
};
