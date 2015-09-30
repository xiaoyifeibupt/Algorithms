/**
*Numbers keep coming, return the median of numbers at every time a new number added.
*Example*
*For numbers coming list: *[1, 2, 3, 4, 5]*, return *[1, 1, 2, 2, 3]*.*
*For numbers coming list: *[4, 5, 1, 3, 2, 6, 0]*, return *[4, 4, 4, 3, 3, 3, 3]*.*
*For numbers coming list: *[2, 20, 100]*, return *[2, 2, 20]*.*

*Challenge*
*Total run time in O(*nlogn*).*

*Clarification*
*What's the definition of Median?
- Median is the number that in the middle of a sorted array. If there are n numbers in a sorted array A, the median is *A[(n - 1) / 2]*. For example, if *A=[1,2,3]*, median is *2*. If *A=[1,19]*, median is *1*.*
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        // min_heap stores the larger half seen so far.
        priority_queue<int, vector<int>, greater<int>> min_heap;
        // max_heap stores the smaller half seen so far.
        priority_queue<int, vector<int>, less<int>> max_heap;

        vector<int> ans;
        int x;
        for (auto& x : nums) {
            if (max_heap.empty() || x > max_heap.top()) {
                min_heap.emplace(x);
                if (min_heap.size() > max_heap.size() + 1) {
                    max_heap.emplace(min_heap.top());
                    min_heap.pop();
                }
            }
            else {
                max_heap.emplace(x);
                if (max_heap.size() > min_heap.size()) {
                    min_heap.emplace(max_heap.top());
                    max_heap.pop();
                }
            }

            ans.emplace_back(min_heap.size() == max_heap.size() ?
                             max_heap.top() : min_heap.top());
        }

        return ans;
    }
};

