/**
*Given a string S and a string T, count the number of distinct subsequences of T in S.
*Example*
*Given S = *"rabbbit"*, T = *"rabbit"*, return *3*.*

*Challenge*
*Do it in O(n*2*) time and O(n) memory. *
*O(n*2*) memory is also acceptable if you do not know how to optimize memory.*
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
         vector<vector<int>> ways(S.length() + 1, vector<int>(T.length() + 1, 0));
        // ways[i][j] means number of distinct subsequence of S[0, i] with T[0, j]
        ways[0][0] = 1;
        for (int i = 0; i < S.length(); ++i) {
            ways[i + 1][0] = ways[i][0];
            for (int j = 0; j < T.length(); ++j) {
                ways[i + 1][j + 1] = S[i] == T[j]?
                                          ways[i][j + 1] + ways[i][j] :
                                          ways[i][j + 1];

            }
        }
        return ways[S.length()][T.length()];
    }
};

