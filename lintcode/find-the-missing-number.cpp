/**
*Given an array contains N numbers of 0 .. N, find which number doesn't exist in the array.
*Example*
*Given *N* = *3* and the array *[0, 1, 3]*, return *2*.*

*Challenge*
*Do it in-place with O(1) extra memory and O(n) time.*
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int missing_num = 0;
        // xor all nums <= N.
        for (int num = 0; num <= nums.size(); ++num) {
            missing_num ^= num;
        }
        // Delete num in nums.
        for (const auto& num : nums) {
            missing_num ^= num;
        }
        // The remaining num would be missing num.
        return missing_num;
    }
};
