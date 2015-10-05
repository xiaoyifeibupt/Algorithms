/**
*Given a binary tree, find the maximum path sum.
*Example*
*Given the below binary tree:*
*  1
 / \
2   3
*
*return *6*.*
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        maxSum (root);
        return mps;
    }
    int maxSum(TreeNode *root) {
        if (root == nullptr)
            return 0;
        
        int _left = max(0, maxSum(root -> left));
        int _right = max(0, maxSum(root -> right));
        
        mps = max(mps, _left + root -> val + _right);
        
        return root -> val + max(_left, _right);
    }
private:
    int mps = INT_MIN;
};
