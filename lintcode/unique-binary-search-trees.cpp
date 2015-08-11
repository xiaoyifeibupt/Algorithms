/**
*Given n, how many structurally unique BSTs (binary search trees) that store values 1...n?
*Example*
*Given n = 3, there are a total of 5 unique BST's.*
*1           3    3       2      1
 \         /    /       / \      \
  3      2     1       1   3      2
 /      /       \                  \
2     1          2                  3
*
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> num(n + 1, 0);
        num[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                num[i] += num[j] * num[i - 1 - j];
            }
        }
        return num[n];
    }
};
