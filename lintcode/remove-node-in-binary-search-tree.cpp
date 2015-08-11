/**
*Given a root of Binary Search Tree with unique value for each node.  Remove the node with given value. If there is no such a node with given value in the binary search tree, do nothing. You should keep the tree still a binary search tree after removal.
*Example*
*Given binary search tree:*
*          5*
*       /    \*
*    3          6*
* /    \*
*2       4*
*Remove 3, you can either return:*
*          5*
*       /    \*
*    2          6*
*      \*
*         4*
*or :*
*          5*
*       /    \*
*    4          6*
* /   *
*2*
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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if (root == NULL) return NULL;
        if (value < root -> val)
            root -> left = removeNode(root -> left, value);
        else if (value > root -> val)
            root -> right = removeNode(root -> right, value);
        else {
            if (root -> left == NULL)
                return root -> right;
            else if (root -> right == NULL)
                return root -> left;
            TreeNode *node = root;
            root = findMin(node->right);
            root->right = deleteMin(node->right);
            root->left = node->left;
        }
        return root;
    }
    TreeNode* findMin(TreeNode* node) {
        while (node != NULL && node -> left != NULL)
            node = node -> left;
        return node;
    }
    TreeNode* deleteMin(TreeNode* node) {
        if (node -> left == NULL) return node -> right;
        TreeNode* root = node;
        TreeNode* parent;
        while (node != NULL && node -> left != NULL) {
            parent = node;
            node = node -> left;
        }
        parent -> left = node -> right;
        return root;
    }
};
