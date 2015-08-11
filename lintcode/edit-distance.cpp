/**
*Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
*Example*
*Given word1 = *"mart"* and word2 = *"karma"*, return *3*.*
*/

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        const size_t m = word1.size();
        const size_t n = word2.size();

        if (m < n) {
            return minDistance(word2, word1);
        }

        vector<vector<int>> steps(m + 1, vector<int>(n + 1, 0));

        for (int j = 0; j < n + 1; ++j) {
            steps[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i) {
            steps[i][0] = i;
            for (int j = 1; j < n + 1; ++j) {
                steps[i][j] = word1[i - 1] == word2[j - 1] ?
                steps[i - 1][j - 1] :
                1 + min(steps[i - 1][j - 1],
                        min(steps[i - 1][j], steps[i][j - 1]));
            }
        }

        return steps[m][n];
    }
};

