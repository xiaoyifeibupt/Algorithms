/**
*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
*For example:
*Given binary tree {3,9,20,#,#,15,7},
*    3
*   / \
*  9  20
*    /  \
*   15   7
*return its zigzag level order traversal as:
*[
*  [3],
*  [20,9],
*  [15,7]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == NULL) return result;
        queue<TreeNode *> nodequ;
        nodequ.push(root);
        vector<int> tem;
        int count = 1;
        int c_tem = 0;
        int level = 0;
        while(!nodequ.empty()) {
            tem.clear();
            c_tem = 0;
            level++;
            for(int i = 0; i < count; i++) {
                TreeNode *tn = nodequ.front();
                tem.push_back(tn -> val);
                nodequ.pop();
                if(tn -> left != NULL) {
                    nodequ.push(tn -> left);
                    c_tem++;
                }
                if(tn -> right != NULL) {
                    nodequ.push(tn -> right);
                    c_tem++;
                }
            }
            count = c_tem;
            if(level & 0x1)
                result.push_back(tem);
            else {
                reverse(tem.begin(),tem.end());
                result.push_back(tem);
            }
        }
    return result;
    }
};