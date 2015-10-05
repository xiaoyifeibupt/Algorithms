/**
*Given a binary tree, return the postorder traversal of its nodes' values.
*For example:
*Given binary tree {1,#,2,3},
*   1
*    \
*     2
*    /
*   3
*return [3,2,1].
*Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        const TreeNode *p, *q;
        stack<const TreeNode* > sta;
        p = root;
        do {
            while (p) {
                sta.push(p);
                p = p -> left;
            }
            q = nullptr;
            while (!sta.empty()) {
                p = sta.top();
                sta.pop();
                if (p -> right == q) {
                    result.push_back(p -> val);
                    q = p;
                } else {
                    sta.push(p);
                    p = p -> right;
                    break;
                }
            }
        } while(!sta.empty());
        return result;
    }
};