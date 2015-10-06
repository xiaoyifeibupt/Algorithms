/**
*Given a binary tree, find its minimum depth.
*Example*
*Given a binary tree as follow:*
*        1*
*     /     \ *
*   2       3*
*          /    \*
*        4      5  *
*The *minimum* depth is 2*
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
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr)
            return 0;
        if (root -> left != nullptr && root -> right != nullptr)
            return 1 + min(minDepth(root -> left), minDepth(root -> right));
        else
            return 1 + max(minDepth(root -> left), minDepth(root -> right));
    }
};
