/**
*Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
*Example*
*Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.*
*1,2,3* → *1,3,2*
*3,2,1* → *1,2,3*
*1,1,5* → *1,5,1*

*Challenge*
*The replacement must be in-place, do not allocate extra memory.*
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
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
    }
};
