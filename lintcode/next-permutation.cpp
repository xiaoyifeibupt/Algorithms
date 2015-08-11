/**
*Given a list of integers, which denote a permutation.
*Example*
*For *[1,3,2,3]*, the next permutation is *[1,3,3,2]*
*For *[4,3,2,1]*, the next permutation is *[1,2,3,4]*

*Note*
*The list may contains duplicate integers.*
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int k = -1, ll = 0;
        for (int  i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1])
                k = i;
        }
        if (k >= 0) {
            for (int i = 0; i < nums.size(); ++i)
                if (nums[i] > nums[k])
                    ll = i;
            swap(nums[k], nums[ll]);
        }
        reverse(nums.begin() + k + 1, nums.end());
        return nums;
    }
};
