/**
*Given a binary tree, return the inorder traversal of its nodes' values.
*Example*
*Given binary tree *{1,#,2,3}*,*
*
   1
    \
     2
    /
   3
*
* *
*return *[1,3,2]*.*

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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        stack<TreeNode*> sta;
        while (root || !sta.empty()) {
            if(root) {
                sta.push(root);
                
                root = root -> left;
            }
            else {
                root = sta.top();
                sta.pop();
                result.push_back(root -> val);
                root = root -> right;
            }
        }
        return result;
    }
};
