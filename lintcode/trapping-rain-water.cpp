/**
*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
*Example*
*Given *[0,1,0,2,1,0,1,3,2,1,2,1]*, return *6*.*

*Challenge*
*O(n) time and O(1) memory*
*O(n) time and O(n) memory is also acceptable.*
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        const size_t n = heights.size();
        stack<pair<int, int> > sta;
        int water = 0;
        for (size_t i = 0; i < n; ++i) {
            int height = 0;
            while (!sta.empty()) {
                int y = sta.top().first;
                int x = sta.top().second;
                water += (min(y, heights[i]) - height) * (i - x - 1);
                height = y;
                if (heights[i] < y)
                    break;
                else
                    sta.pop();
            }
            sta.push(make_pair(heights[i], i));
        }
        return water;
    }
};