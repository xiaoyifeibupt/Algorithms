/**
*The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.
*Example*
*Given *start=0, end=3*. The segment tree will be:*
*               [0,  3]
             /        \
      [0,  1]           [2, 3]
      /     \           /     \
   [0, 0]  [1, 1]     [2, 2]  [3, 3]
*
*Given *start=1, end=6*. The segment tree will be:*
*               [1,  6]
             /        \
      [1,  3]           [4,  6]
      /     \           /     \
   [1, 2]  [3,3]     [4, 5]   [6,6]
   /    \           /     \
[1,1]   [2,2]     [4,4]   [5,5]
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
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end) return nullptr;
        
        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        if (start == end) 
            return root;
        root -> left = build(start, (start + end) / 2);
        root -> right = build((start + end) / 2 + 1, end);
        return root;
    }
};
