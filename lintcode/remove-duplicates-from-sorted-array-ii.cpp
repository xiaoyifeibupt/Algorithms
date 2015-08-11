/**
*Follow up for "Remove Duplicates":What if duplicates are allowed at most twice?
*Example*
*
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }

        const int k = 2; // At most k duplicated.

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] != nums[right] ||
                (left - k + 1 < 0 || nums[left] != nums[left - k + 1])) {
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }

        return left + 1;
    }
};
