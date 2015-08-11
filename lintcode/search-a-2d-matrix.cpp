/**
*Write an efficient algorithm that searches for a value in an m x n matrix.
*Example*
*Consider the following matrix:*
*[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
*
*Given *target = 3*, return *true*.*

*Challenge*
*O(log(n) + log(m)) time*
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (matrix[mid / n][mid % n] > target)
                right = mid - 1;
            else if (matrix[mid / n][mid % n] < target)
                left = mid + 1;
            else
                return true;
        }
        return false;
    }
};

