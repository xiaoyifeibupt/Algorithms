/**
*Given a non-overlapping interval list which is sorted by start point.
*Example*
*Insert *[2, 5]* into *[[1,2], [5,9]]*, we get* [[1,9]]*.*
*Insert* [3, 4]* into *[[1,2], [5,9]]*, we get *[[1,2], [3,4], [5,9]]*.*
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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        int i = 0;
        vector<Interval> result;
        while (i < intervals.size() && newInterval.start > intervals[i].end)
            result.push_back(intervals[i++]);
            
        while (i < intervals.size() && newInterval.end >= intervals[i].start) {
            newInterval = {min(newInterval.start, intervals[i].start),
                max(newInterval.end, intervals[i].end)};
            ++i;
        }
        result.push_back(newInterval);
        
        result.insert(result.end(), intervals.cbegin() + i, intervals.cend());
        return result;
    }
};
