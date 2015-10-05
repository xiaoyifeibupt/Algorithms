/**
*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
*Note: 
*You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*Follow up:
*What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*  Try to utilize the property of a BST.
*  What if you could modify the BST node's structure?
*  The optimal runtime complexity is O(height of BST).
*Credits:Special thanks to @ts for adding this problem and creating all test cases.
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        TreeNode *cur = root;
        int rank = 0;
        while (!s.empty() || cur) {
            if (cur) {
                s.emplace(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                if (++rank == k) {
                    return cur->val;
                }
                cur = cur->right;
            }
        }

        return INT_MIN;
    }
};