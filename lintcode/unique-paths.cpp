/**
*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
*Example*
*1,1*1,2*1,3*1,4*1,5*1,6*1,7*2,1*3,1*3,7*
*
*Above is a 3 x 7 grid. How many possible unique paths are there?
*

*Note*
*m* and *n* will be at most 100.*
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<int> paths(n, 1);
        for (int i = 1; i < m; i++)  
         for (int j = 1; j < n; j++)    
            paths[j] += paths[j - 1];  
       return paths[n - 1];
    }
};

