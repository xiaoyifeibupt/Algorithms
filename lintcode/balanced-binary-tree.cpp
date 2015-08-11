/**
*Given a binary tree, determine if it is height-balanced.
*Example*
*Given binary tree A=*{3,9,20,#,#,15,7}*, B=*{3,#,20,15,7}*
*
A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
*
*The binary tree A is a height-balanced binary tree, but B is not.*
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        int depth = 0;
        return isBalancedTree(root, &depth);
    }
    bool isBalancedTree(TreeNode* root, int* pDepth) {
        if (root == nullptr) {
            *pDepth = 0;
            return true;
        }
        int left, right;
        if (isBalancedTree(root -> left, &left) 
            && isBalancedTree(root -> right, &right)) {
                int diff = left - right;
                if (diff <= 1 && diff >= -1) {
                    *pDepth = 1 + (left > right ? left : right);
                    return true;
                }
        }
        return false;
    }
};
