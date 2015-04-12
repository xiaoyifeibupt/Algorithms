/**
*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

*For example:
*Given the following binary tree,
     1            <---
   /   \
  2     3         <---
   \     \
    5     4       <---
*You should return [1, 3, 4].
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (root == NULL)  
            return result;
        queue<TreeNode *> treeque;
        treeque.push(root);
        int count = 1;  
        int level = 0;  

        while(!treeque.empty()) {
            level = 0;  
            for (int i = 0; i < count; ++i) {  
                root = treeque.front();  
                treeque.pop();
                if(i == count - 1)
                    result.push_back(root->val);
                if (root->left != NULL) {
                    treeque.push(root->left);  
                    ++level;  
                }  
                if (root->right != NULL) {  
                    treeque.push(root->right);  
                    ++level;  
                }  
            }
            count = level;  
        }
    return result;
    }
};
