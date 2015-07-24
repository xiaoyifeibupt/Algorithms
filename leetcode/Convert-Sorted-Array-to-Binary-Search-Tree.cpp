/**
*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left > right)
            return NULL;
        int mid = (left + right) >> 1;
        TreeNode* leftNode = helper(nums, left, mid - 1);
        TreeNode* rightNode = helper(nums, mid + 1, right);
        
        TreeNode* parNode = new TreeNode(nums[mid]);
        parNode -> left = leftNode;
        parNode -> right = rightNode;
        
        return parNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }
};