/*
*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

*For example:
*Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
*return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

class Solution {
public:
    bool hps(TreeNode *root, int sum,int cursum){
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return cursum + root->val == sum;
        return (hps(root->left,sum,cursum + root->val) || hps(root->right,sum,cursum + root->val));
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        return hps(root,sum,0);
    }
};
