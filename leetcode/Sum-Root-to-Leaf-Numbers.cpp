/*
*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

*An example is the root-to-leaf path 1->2->3 which represents the number 123.

*Find the total sum of all root-to-leaf numbers.

*For example,

    1
   / \
  2   3
*The root-to-leaf path 1->2 represents the number 12.
*The root-to-leaf path 1->3 represents the number 13.

*Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        result = 0;
        sumnum(root,0);
        return result;
    }
    void sumnum(TreeNode* root, int sum) {
        if(root -> left == NULL && root -> right == NULL)
            result += sum * 10 + root -> val;
        if(root -> left)
            sumnum(root -> left, sum * 10 + root -> val);
        if(root -> right)
            sumnum(root -> right, sum * 10 + root -> val);
    }
private:
    int result;
};
