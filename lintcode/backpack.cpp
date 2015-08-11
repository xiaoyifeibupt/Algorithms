/**
*Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack? 
*Example*
*If we have *4* items with size *[2, 3, 5, 7]*, the backpack size is 11, we can select *[2, 3, 5]*, so that the max size we can fill this backpack is *10*. If the backpack size is *12*. we can select *[2, 3, 7]* so that we can fulfill the backpack.*
*You function should return the max size we can fill in the given backpack.*

*Note*
*You can not divide any item into small pieces.*

*Challenge*
*O(n x m) time and O(m) memory.*
*O(n x m) memory is also acceptable if you do not know how to optimize memory.*
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<vector<bool>> table(A.size() + 1, vector<bool>(m + 1, false));
        table[0][0] = true;

        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= m; ++j) {
                table[i][j] = table[i - 1][j] || 
                                (j - A[i - 1] >= 0 && table[i - 1][j - A[i - 1]]);
            }
        }
        for (int j = m; j >= 0; j--) {
            if (table[A.size()][j]) return j;
        }
        return 0;
    }
};