/**
*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
*Example*
*For example, given the following triangle*
*[
     [*2*],
    [*3*,4],
   [6,*5*,7],
  [4,*1*,8,3]
]
*
*
*The minimum path sum from top to bottom is *11* (i.e., *2* + *3* + *5* + *1* = 11).*

*Note*
*Bonus point if you are able to do this using only *O*(*n*) extra space, where *n* is the total number of rows in the triangle.*
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if (triangle.empty()) return 0;
        vector<int> pre(triangle.front());
        for (size_t i = 1; i < triangle.size(); ++i) {
            vector<int> cur(triangle[i]);
            cur.front() += pre.front();
            for (size_t j = 1; j < cur.size() - 1; ++j)
                cur[j] += min(pre[j - 1], pre[j]);
            cur.back() += pre.back();
            pre.swap(cur);
        }
        return *min_element(pre.cbegin(), pre.cend());
    }
};

