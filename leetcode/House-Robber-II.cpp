/**
*Note: This is an extension of House Robber.

*After robbing those houses on that street, the thief has found himself a new place
*for his thievery so that he will not get too much attention. This time, 
*all houses at this place are arranged in a circle. That means the first 
*house is the neighbor of the last one. Meanwhile, the security system for 
*these houses remain the same as for those in the previous street.

*Given a list of non-negative integers representing the amount of money of 
*each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int robHelper(vector<int>& number,int start, int end) {
        int limit = end - start + 1;
        vector<int> dp = {number[start], max(number[start], number[start + 1])};
        
        for (int i = 2; i < limit; ++i) {
            dp.push_back(max(number[start + i] + dp[i - 2], dp[i - 1]));
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.empty() ? 0: nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        return max(robHelper(nums, 0, nums.size() - 2), robHelper(nums, 1, nums.size() - 1));
    }
};
