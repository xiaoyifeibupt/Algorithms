/**
*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
*For example:
*Given binary tree {3,9,20,#,#,15,7},
*    3
*   / \
*  9  20
*    /  \
*   15   7
*return its bottom-up level order traversal as:
*[
*  [15,7],
*  [9,20],
*  [3]
*]
*confused what &quot;{1,#,2,3}&quot; means? &gt; read more on how binary tree is serialized on OJ.
*OJ's Binary Tree Serialization:
*The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
*Here's an example:
*   1
*  / \
* 2   3
*    /
*   4
*    \
*     5
*The above binary tree is serialized as &quot;{1,2,3,#,#,4,#,#,5}&quot;. 
*
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector< vector<int> > result;  
        if (root == NULL)  
            return result;
        queue<TreeNode *> treeque;
        treeque.push(root);
        int count = 1;  
        int level = 0;  
        vector<int> tem(0);
        while(!treeque.empty()) {
            tem.clear();  
            level = 0;  
            for (int i = 0; i < count; ++i) {  
                root = treeque.front();  
                treeque.pop();  
                tem.push_back(root->val);  
                if (root->left != NULL) {
                    treeque.push(root->left);  
                    ++level;  
                }  
                if (root->right != NULL) {  
                    treeque.push(root->right);  
                    ++level;  
                }  
            }  
            count = level;  
            result.push_back(tem);  
        }
        reverse(result.begin(),result.end());
    return result;
    }
};