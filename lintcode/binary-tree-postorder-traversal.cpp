/**
*Given a binary tree, return the postorder traversal of its nodes' values.
*Example*
*Given binary tree *{1,#,2,3}*,*
*
   1
    \
     2
    /
   3
*
* *
*return *[3,2,1]*.*

*Challenge*
*Can you do it without recursion?*
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        /* p，正在访问的结点，q，刚刚访问过的结点*/
        const TreeNode *p, *q;
        stack<const TreeNode*> sta;
        p = root;
        do {
            while (p != nullptr) {/* 往左下走*/
                sta.push(p);
                p = p -> left;
            }
            q = nullptr;
            while (!sta.empty()) {
                p = sta.top();
                sta.pop();
                /* 右孩子不存在或已被访问，访问之*/
                if (p -> right == q) {
                    result.push_back(p -> val);
                    q = p;/* 保存刚访问过的结点*/
                } else {
                    /* 当前结点不能访问，需第二次进栈*/
                    sta.push(p);
                    p = p -> right;/* 先处理右子树*/
                    break;
                }
            }
        } while (!sta.empty());
        return result;
    }
};
