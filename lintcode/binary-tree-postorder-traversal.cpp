/**
*Given a binary tree, return the postorder traversal of its nodes' values.
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
*return *[3,2,1]*.*

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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> sta;
        while (1) {
            if (root) {
                sta.push(root);
                sta.push(root -> right);
                root = root -> left;
            }
            else if (!root) {
                root = sta.top();
                sta.pop();
                if(!root) {
                    root = sta.top();
                    sta.pop();
                    result.push_back(root -> val);
                    if(sta.empty()) break;
                    root = sta.top();
                    sta.pop();
                }
                sta.push(nullptr);
            }
        }
        return result;
    }
};
