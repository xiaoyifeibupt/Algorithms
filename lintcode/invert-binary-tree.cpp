/**
*Invert a binary tree.
*Example*
*  1         1
 / \       / \
2   3  => 3   2
   /       \
  4         4
*

*Challenge*
*Do it in recursion is acceptable, can you do it without recursion?*
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        invertTree(root);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) 
            return NULL;
        
        TreeNode* leftNode = root -> left;
        TreeNode* rightNode = root -> right;
        root -> left = invertTree(rightNode);
        root -> right = invertTree(leftNode);
        
        return root;
            
    }
};
