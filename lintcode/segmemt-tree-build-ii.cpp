/**
*The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.
*Example*
*Given *[3,2,1,4]*. The segment tree will be:*
*                 [0,  3] (max = 4)
                  /            \
        [0,  1] (max = 3)     [2, 3]  (max = 4)
        /        \               /             \
[0, 0](max = 3)  [1, 1](max = 2)[2, 2](max = 1) [3, 3] (max = 4)
*

*Clarification*
*Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:*
*
*which of these intervals contain a given point*
*which of these points are in a given interval*
*
*See wiki:
*Segment Tree*
*Interval Tree*
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return buildhelp(A, 0, A.size() - 1);
    }
    SegmentTreeNode* buildhelp(vector<int>& A, int start, int end) {
        if (start > end) return nullptr;
        
        SegmentTreeNode *root = new SegmentTreeNode(start, end, INT_MAX);
        if (start == end) {
            root -> max = A[start];
            return root;
        }
        
        root -> left = buildhelp(A, start, (start + end) / 2);
        root -> right = buildhelp(A, (start + end) / 2 + 1, end);
        
        int left_max = root -> left == nullptr ? INT_MAX : root -> left -> max;
        int right_max = root -> right == nullptr ? INT_MAX : root -> right -> max;
        
        root -> max = max(left_max, right_max);
        return root;
    }
};
