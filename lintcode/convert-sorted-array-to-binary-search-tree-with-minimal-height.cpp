/**
*Given a sorted (increasing order) array, Convert it to create a binary tree with minimal height.
*Example*
*Given *[1,2,3,4,5,6,7]*, return*
*     4
   /   \
  2     6
 / \    / \
1   3  5   7
*

*Note*
*There may exist multiple valid solutions, return any of them.*
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
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return toBST(A, 0, A.size() - 1);
    }
    TreeNode *toBST(vector<int> &A, int start, int end) {
        if (start <= end) {
            int mid = start + ((end - start) >> 1);
            TreeNode *root = new TreeNode(A[mid]);
            root -> left = toBST(A, start, mid - 1);
            root -> right = toBST(A, mid + 1, end);
            return root;
        }
        return nullptr;
    }
};



