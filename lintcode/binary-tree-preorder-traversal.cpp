/**
*Given a binary tree, return the preorder traversal of its nodes' values.
*Example*
*Given binary tree *{1,#,2,3}*:*
*1
 \
  2
 /
3
*
*return *[1,2,3]*.*

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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        stack<TreeNode*> sta;
        while (root || !sta.empty()) {
            if(root) {
                sta.push(root);
                result.push_back(root -> val);
                root = root -> left;
            }
            else {
                root = sta.top();
                sta.pop();
                root = root -> right;
            }
        }
        return result;
    }
};

