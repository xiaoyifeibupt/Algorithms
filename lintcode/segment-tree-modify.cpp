/**
*For a Maximum Segment Tree, which each node has an extra value max to store the maximum value in this node's interval.
*Example*
*For segment tree:*
*                      [1, 4, max=3]
                    /                \
        [1, 2, max=2]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]
*
*if call *modify(root, 2, 4)*, we can get:*
*                      [1, 4, max=4]
                    /                \
        [1, 2, max=4]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=4], [3, 3, max=0], [4, 4, max=3]
*
*or* call *modify(root, 4, 0)*, we can get:*
*                      [1, 4, max=2]
                    /                \
        [1, 2, max=2]                [3, 4, max=0]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=0]
*

*Note*
*We suggest you finish problem *Segment Tree Build* and *Segment Tree Query* first.*

*Challenge*
*Do it in *O(h)* time, h is the height of the segment tree.*
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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root == nullptr || root->start > index || root->end < index) {
            return;
        }

        if (root->start == index && root->end == index) {
            root->max = value;
            return;
        }

        modify(root->left, index, value);
        modify(root->right, index, value);

        int left_max = root->left != nullptr? root->left->max : INT_MIN;
        int right_max = root->right != nullptr? root->right->max : INT_MIN;

        root->max = max(left_max, right_max);
    }
};
