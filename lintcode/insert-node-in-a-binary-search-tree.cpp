/**
*Given a binary search tree  and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.
*Example*
*Given binary search tree as follow, after Insert node 6, the tree should be:*
*  2             2
 / \           / \
1   4   -->   1   4
   /             / \ 
  3             3   6
*

*Challenge*
*Can you do it without recursion?*
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (root == nullptr) {
            return node;
        }
        TreeNode* curr = root;
        while (true) {
            if (node->val < curr->val) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    curr->left = node;
                    break;
                }
            } else if (node->val > curr->val) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    curr->right = node;
                    break;
                }
            } else {
                curr->val = node->val;
                break;
            }
        }
        return root;
    }
};
