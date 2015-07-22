/**
*Given a binary tree, return the preorder traversal of its nodes' values.

*For example:
*Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
*return [1,2,3].

*Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> treeStack;
        TreeNode* p = root;
        
        while(p || !treeStack.empty()) {
            if(p) {
                result.push_back(p -> val);
                treeStack.push(p);
                p = p -> left;
            }
            else {
                p = treeStack.top();
                treeStack.pop();
                p = p -> right;
            }
        }
        return result;
    }
};
