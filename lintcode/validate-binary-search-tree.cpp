/**
*Given a binary tree, determine if it is a valid binary search tree (BST).
*Example*
*An example:*
*  2
 / \
1   3
   /
  4
   \
    5
*
*The above binary tree is serialized as *{2,1,3,#,#,4,#,#,5}* (in level order).*
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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (last && last != root && last->val >= root->val)
            return false;
        last = root;
        if (!isValidBST(root->right))
            return false;
        return true;
    }

private:
    TreeNode *last = nullptr;
};
