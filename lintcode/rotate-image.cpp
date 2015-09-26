/**
*You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
*Example*
*Given a matrix*
*[
    [1,2],
    [3,4]
]
*
*rotate it by 90 degrees (clockwise), return*
*[
    [3,1],
    [4,2]
]
*

*Challenge*
*Do it in-place.*
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        const int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1- j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};
