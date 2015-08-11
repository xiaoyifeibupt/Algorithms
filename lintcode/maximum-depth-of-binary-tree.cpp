/**
*Given a binary tree, find its maximum depth.
*Example*
*Given a binary tree as follow:*
*  1
 / \ 
2   3
   / \
  4   5
*
*The maximum depth is *3*.*
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
    int maxDepth(TreeNode *root) {
        // write your code here
        if(root == nullptr) return 0;
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        return (left > right) ? (left + 1) : (right + 1);
    }
};
