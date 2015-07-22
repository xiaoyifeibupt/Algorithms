/**
*Given a binary tree, determine if it is height-balanced.

*For this problem, a height-balanced binary tree is defined as a binary tree 
*in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool checkBalance(TreeNode *root,int &dep){
        if(root == NULL){
            dep = 0;
            return true;
        }
        int leftDep, rightDep;
        
        bool leftBalance = checkBalance(root->left, leftDep);
        bool rightBalance = checkBalance(root->right, rightDep);
        
        dep = max(leftDep, rightDep) + 1;
        
        return leftBalance && rightBalance && (abs(rightDep - leftDep) <= 1);
    }
    bool isBalanced(TreeNode *root) {
        int dep;
        return checkBalance(root,dep);
    }
};
