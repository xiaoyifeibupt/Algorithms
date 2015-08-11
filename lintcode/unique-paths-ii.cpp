/**
*Follow up for "Unique Paths":
*Example*
*For example,*
*
*There is one obstacle in the middle of a 3x3 grid as illustrated below.*
*[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
*
*The total number of unique paths is *2*.*

*Note*
*m* and *n* will be at most 100.*
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        vector<int> paths(obstacleGrid[0].size(),0);  
        paths[0] = obstacleGrid[0][0] == 0 ? 1 : 0;  
        for (int i = 0; i < obstacleGrid.size(); ++i)  
            for (int j = 0; j < obstacleGrid[0].size(); ++j)  
                if (obstacleGrid[i][j] == 1)  
                    paths[j] = 0;  
                else if (j - 1 >= 0)  
                    paths[j] += paths[j - 1];  
       return paths[obstacleGrid[0].size() - 1];
    }
};
