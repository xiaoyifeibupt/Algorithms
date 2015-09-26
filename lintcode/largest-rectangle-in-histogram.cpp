/**
*Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*Example*
*Given height = *[2,1,5,6,2,3]*,*return *10*.*
*/

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int n = height.size(), result = 0;
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while ((!s.empty()) && (height[s.top()] >= height[i])) {
                int h = height[s.top()];
                s.pop();
                result = max(result, (i - 1 - (s.empty() ? (-1) : s.top())) * h);
            }
            s.push(i);
        }
        while (!s.empty()) {
            int h = height[s.top()];
            s.pop();
            result = max(result, (n - 1 - (s.empty() ? (-1) : s.top())) * h);
        }
        return result;
    }
};

