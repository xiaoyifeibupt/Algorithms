/**
*Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
*Example*
*Consider the following matrix:*
*[*
*    [1, 3, 5, 7],*
*    [2, 4, 7, 8],*
*    [3, 5, 9, 10]*
*]*
*Given target = *3*, return *2*.*

*Challenge*
*O(m+n) time and O(1) extra space*
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int count = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) return count;
        int row = 0; int column = matrix[0].size() - 1;
        while(row < matrix.size() && column >= 0) {
            if (matrix[row][column] > target)
                column--;
            else if (matrix[row][column] < target)
                row++;
            else {
                count++;
                row++;
            }
        }
        return count;
    }
};

