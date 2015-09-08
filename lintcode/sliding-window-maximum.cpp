/**
*Given an array of n integer with duplicate number, and a moving window(size k), move the window at each iteration from the start of the array, find the maximum number inside the window at each moving. 
*Example*
*For array *[1, 2, 7, 7, 8]*,  moving window size *k = 3*. return *[7, 7, 8]*
*At first the window is at the start of the array like this *
*[|1, 2, 7| ,7, 8]* , return the maximum *7*;*
*then the window move one step forward.*
*[1, |2, 7 ,7|, 8]*, return the maximum *7*;*
*then the window move one step forward again.*
*[1, 2, |7, 7, 8|]*, return the maximum *8*;*

*Challenge*
*o(n) time and O(k) memory*
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        deque<int> que;
        vector<int> max_nums;
        for (int i = 0; i < k; ++i) {
            while (!que.empty() && nums[i] >= nums[que.back()])
                que.pop_back();
            que.emplace_back(i);
        }
        for (int i = k; i < nums.size(); ++i) {
            max_nums.emplace_back(nums[que.front()]);
            while (!que.empty() && nums[i] >= nums[que.back()])
                que.pop_back();
            while (!que.empty() && que.front() <= i - k)
                que.pop_front();
            que.emplace_back(i);
        }
        if (!que.empty())
            max_nums.emplace_back(nums[que.front()]);
        return max_nums;
    }
};

