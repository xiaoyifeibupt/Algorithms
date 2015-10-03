/**
*Given a string s, cut s into some substrings such that every substring is a palindrome.
*Example*
*For example, given *s = "aab"*,*
*Return 1 since the palindrome partitioning *["aa","b"]* could be produced using 1 cut.*
*/

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        vector<vector<bool>> is_palindrome(s.size(), vector<bool>(s.size(), false));
        vector<int> T(s.size() + 1);
        iota(T.rbegin(), T.rend(), -1);
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i < 2 || is_palindrome[i + 1][j - 1])) {
                    is_palindrome[i][j] = true;
                    T[i] = min(T[i], 1 + T[j + 1]);
                }
            }
        }
        return T[0];
    }
};


