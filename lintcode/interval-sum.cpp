/**
*Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the sum number between index start and end in the given array, return the result list.
*Example*
*For array *[1,2,7,8,5]*, and queries *[(0,4),(1,2),(2,4)]*, return *[23,9,20]*

*Note*
*We suggest you finish problem *Segment Tree Build*, *Segment Tree Query* and *Segment Tree Modify* first.*

*Challenge*
*O(logN) time for each query*
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class SegmentTreeSumNode {
public:
    int start, end;
    long long sum;
    SegmentTreeSumNode *left, *right;
    SegmentTreeSumNode(int start, int end, long long sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> result;
        SegmentTreeSumNode *root = build(A, 0, A.size() - 1);
        for (const auto& q : queries)
            result.push_back(query(root, q.start, q.end));
        return result;
    }
    
    SegmentTreeSumNode* build(vector<int> &A, int start, int end) {
        if (start > end)
            return nullptr;
        SegmentTreeSumNode* root = new SegmentTreeSumNode(start, end, 0);
        if (start == end) {
            root -> sum = A[start];
            return root;
        }
        
        root -> left = build(A, start, (start + end) / 2);
        root -> right = build(A, (start + end) / 2 + 1, end);
        
        long long left_sum = root -> left == nullptr ? 0 : root -> left -> sum;
        long long right_sum = root -> right == nullptr ? 0 : root -> right -> sum;
        
        root -> sum = left_sum + right_sum;
        return root;
    }
    
    long long query(SegmentTreeSumNode *root, int start, int end) {
        if (root == nullptr || root -> end < start || root -> start > end)
            return 0;
        if (root -> start >= start && root -> end <= end)
            return root -> sum;
        
        long long left = query(root->left, start, end);
        long long right = query(root->right, start, end);
        
        return left + right;
    }
};
