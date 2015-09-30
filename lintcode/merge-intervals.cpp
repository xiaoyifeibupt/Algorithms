/**
*Given a collection of intervals, merge all overlapping intervals.
*Example*
*Given intervals => merged intervals:*
*[                     [
  [1, 3],               [1, 6],
  [2, 6],      =>       [8, 10],
  [8, 10],              [15, 18]
  [15, 18]            ]
]
*

*Challenge*
*O(*n* log *n*) time and O(1) extra space.*
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
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end(), 
            [](const Interval &a, const Interval &b) {
                return a.start < b.start;
            });
        vector<Interval> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            Interval& pre = result.back();
            if (intervals[i].start <= pre.end)
                pre.end = max(pre.end, intervals[i].end);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};
