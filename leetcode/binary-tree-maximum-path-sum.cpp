/**
*
*Given a binary tree, find the maximum path sum.
*For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
*For example:
*Given the below binary tree,
*       1
*      / \
*     2   3
*Return 6.
*
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return maxSum;
    }
    int getMax(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int _left = max(0, getMax(root -> left));
        int _right = max(0, getMax(root -> right));
        
        maxSum = max(maxSum, _left + root -> val + _right);
        
        return root -> val + max(_left, _right);
    }
private:
    int maxSum = INT_MIN;
};