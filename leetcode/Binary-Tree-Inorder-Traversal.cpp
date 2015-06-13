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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        stack<TreeNode*> rootNode;
        TreeNode* p = root;
        while(p || !rootNode.empty()) {
            if(p) {
                rootNode.push(p);
                p = p -> left;
            }
            else {
                p = rootNode.top();
                rootNode.pop();
                result.push_back(p -> val);
                p = p -> right;
            }
        }
        
        return result;
    }
};
