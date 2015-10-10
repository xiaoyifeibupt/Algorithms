/**
*Given an integer array with no duplicates. A max tree building on this array is defined as follow:
*Example*
*Given *[2, 5, 6, 0, 3, 1]*, the max tree constructed by this array is:*
*    6
   / \
  5   3
 /   / \
2   0   1
*

*Challenge*
*O(n) time and memory.*
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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     * 单调堆栈,堆栈里存放的树，只有左子树，没有有子树，且根节点最大。
     *（1）如果新来一个数，比堆栈顶的树根的数小，则把这个数作为一个单独的节点压入堆栈。
     *（2）否则，不断从堆栈里弹出树，新弹出的树以旧弹出的树为右子树，连接起来，
     * 直到目前堆栈顶的树根的数大于新来的数。然后，弹出的那些数，已经形成了一个新的树，
     * 这个树作为新节点的左子树，把这个新压入堆栈。

     * 这样的堆栈是单调的，越靠近堆栈顶的数越小。
     * 最后还要按照（2）的方法，把所有树弹出来，每个旧树作为新树的右子树。
     */
     
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        if (A.empty()) 
            return nullptr;
        stack<TreeNode*> sta;
        sta.push(new TreeNode(A[0]));
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] <= sta.top() -> val)
                sta.push(new TreeNode(A[i]));
            else {
                TreeNode* p = sta.top();
                sta.pop();
                while (!sta.empty() && A[i] > sta.top() -> val) {
                    sta.top() -> right = p;
                    p = sta.top();
                    sta.pop();
                }
                
                TreeNode* node = new TreeNode(A[i]);
                node -> left = p;
                sta.push(node);
            }
        }
        TreeNode* root = sta.top();
        sta.pop();
        while (!sta.empty()) {
            sta.top() -> right = root;
            root = sta.top();
            sta.pop();
        }
        return root;
    }
};
