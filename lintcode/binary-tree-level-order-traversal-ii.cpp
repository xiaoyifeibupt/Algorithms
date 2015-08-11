/**
*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
*Example*
*Given binary tree *{3,9,20,#,#,15,7}*,*
*
    3
   / \
  9  20
    /  \
   15   7
*
* *
*return its bottom-up level order traversal as:*
*
[
  [15,7],
  [9,20],
  [3]
]*
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        
        if (!root) return result;
        queue<TreeNode*> que_tree_node;
        que_tree_node.push(root);
        int levelsize = que_tree_node.size();
        vector<int> level;
        while(!que_tree_node.empty()) {
            TreeNode* node = que_tree_node.front();
            que_tree_node.pop();
            --levelsize;
            level.push_back(node -> val);
            
            if (node -> left) 
                que_tree_node.push(node -> left);
            if (node -> right) 
                que_tree_node.push(node -> right);
            
            if (levelsize == 0) {
                levelsize = que_tree_node.size();
                result.push_back(level);
                level.clear();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
