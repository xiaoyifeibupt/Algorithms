/**
*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*Example*
*Given a matrix*
*[
  [1,2],
  [0,3]
],
*
*return
    [
      [0,2],
      [0,0]
    ]*

*Challenge*
*Did you use extra space?
A straight forward solution using O(*mn*) space is probably a bad idea.
A simple improvement uses O(*m* + *n*) space, but still not the best solution.
Could you devise a constant space solution?*
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        const size_t m = matrix.size();
        if (m == 0) return;
        const size_t n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    row[i] = col[j] = true;
            }
        }
        for (size_t i = 0; i < m; ++i) {
            if (row[i]) {
                fill(&matrix[i][0], &matrix[i][0] + n, 0);
            }
        }
        for (size_t j = 0; j < n; ++j) {
            if (col[j]) {
                for (size_t i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
