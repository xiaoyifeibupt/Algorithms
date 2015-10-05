/**
*Given a binary tree, return the inorder traversal of its nodes' values.
*For example:
*Given binary tree {1,#,2,3},
*   1
*    \
*     2
*    /
*   3
*return [1,3,2].
*Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        stack<TreeNode*> rootNode;
        TreeNode* p = root;
        while(p || !rootNode.empty()) {
            if(p) {
                rootNode.push(p);
                p = p -> left;
            }
            else {
                p = rootNode.top();
                rootNode.pop();
                result.push_back(p -> val);
                p = p -> right;
            }
        }
        
        return result;
    }
};