/**
*Given two strings, find the longest common subsequence (LCS).
*Example*
*For *"ABCD"* and *"EDCA"*, the *LCS* is *"A"* (or *"D"*, *"C"*), return *1*.*
*For *"ABCD"* and *"EACB"*, the *LCS* is *"AC"*, return *2*.*

*Clarification*
*What's the definition of Longest Common Subsequence?*
*
*https://en.wikipedia.org/wiki/Longest_common_subsequence_problem*
*http://baike.baidu.com/view/2020307.htm*
*
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.length() < B.length()) {
            return longestCommonSubsequence(B, A);
        }
        vector<vector<int>> table(2, vector<int>(A.length() + 1, 0));

        // if A[i - 1] != B[j - 1]:
        //     table[i][j] = max(table[i - 1][j], table[i][j - 1])
        // if A[i - 1] == B[j - 1]:
        //     table[i][j] = table[i - 1][j - 1] + 1
        for (int i = 1; i < A.length() + 1; ++i) {
            for (int j = 1; j < B.length() + 1; ++j) {
                if (A[i - 1] != B[j - 1]) {
                    table[i % 2][j] = max(table[(i - 1) % 2][j],
                                       table[i % 2][j - 1]);
                } else {
                    table[i % 2][j] = table[(i - 1) % 2][j - 1] + 1;
                }
            }
        }

        return table[A.length() % 2][B.length()];
    }
};

