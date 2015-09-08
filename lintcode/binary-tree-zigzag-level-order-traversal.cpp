/**
*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
*return its zigzag level order traversal as:*
*
[
  [3],
  [20,9],
  [15,7]
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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (root == nullptr) return result;
        stack<TreeNode* > levels[2];
        int current = 0, next = 1;
        
        levels[current].push(root);
        vector<int> temp;
        while (!levels[0].empty() || !levels[1].empty()) {
            TreeNode* node = levels[current].top();
            levels[current].pop();
            
            temp.push_back(node -> val);
            if (current == 0) {
                if (node -> left)
                    levels[next].push(node -> left);
                if (node -> right)
                    levels[next].push(node -> right);
            } else {
                if (node -> right)
                    levels[next].push(node -> right);
                if (node -> left)
                    levels[next].push(node -> left);
            }
            if (levels[current].empty()) {
                result.push_back(temp);
                temp.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        return result;
    }
};
