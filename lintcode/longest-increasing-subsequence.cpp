/**
*Given a sequence of integers, find the longest increasing subsequence (LIS).
*Example*
*For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3*
*For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4*

*Challenge*
*Time complexity O(n^2) or O(nlogn)*

*Clarification*
*What's the definition of longest increasing subsequence?*
*    * The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.  *
*    * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem*
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        vector<int> lis;
        for (const auto& num : nums)
            insert(lis, num);
        return lis.size();
    }
    void insert(vector<int>& lis, int target) {
        int left = 0, right = lis.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (lis[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (left == lis.size())
            lis.push_back(target);
        else
            lis[left] = target;
    }
};

