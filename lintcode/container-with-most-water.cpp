/**
*Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*Example*
*Given *[1,3,2]*, the max area of the container is *2*.*

*Note*
*You may not slant the container.*
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int i = 0, j = heights.size() - 1, max_area = 0;
        while (i < j) {
            max_area = max(max_area, min(heights[i], heights[j]) * (j - i));
            if (heights[i] > heights[j])
                --j;
            else if (heights[i] < heights[j])
                ++i;
            else {
                ++i;
                --j;
            }
        }
        return max_area;
    }
};
