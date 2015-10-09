/**
*Given a list of integers, which denote a permutation.
*Example*
*For *[1,3,2,3]*, the previous permutation is *[1,2,3,3]*
*For *[1,2,3,4]*, the previous permutation is *[4,3,2,1]*

*Note*
*The list may contains duplicate integers.*
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int k = -1, ll = 0;
        for (int  i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1])
                k = i;
        }
        if (k >= 0) {
            for (int i = k + 1; i < nums.size(); ++i)
                if (nums[i] < nums[k])
                    ll = i;
            swap(nums[k], nums[ll]);
        }
        reverse(nums.begin() + k + 1, nums.end());
        return nums;
    }
};
