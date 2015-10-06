/**
*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.
*Example*
*Given a matrix:*
*[
  [1, 2,  3,  4],
  [5, 6,  7,  8],
  [9,10, 11, 12]
]
*
*return *[1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]*
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        result.push_back(matrix[0][0]);
        int flag = 1;
        for (int p = 1; p < m + n - 1; ++p) {
            if (flag % 2) {
                for (int j = min(p, n - 1); j >= max(0, p - m + 1); --j)
                    result.push_back(matrix[p - j][j]);
                flag++;
            } else {
                for (int i = min(p, m - 1); i >= max(0, p - n + 1); --i)
                    result.push_back(matrix[i][p - i]);
                flag++;
            }
        }
        return result;
    }
};
