/**
*Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.
*Example*
*Given *[1, 1, 1, 1, 2, 2, 2]*, return *1*

*Challenge*
*O(*n*) time and O(*1*) extra space*
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int ans = nums[0], cnt = 1;
        for (const auto& i : nums) {
            if (i == ans) {
                ++cnt;
            }
            else {
                --cnt;
                if (cnt == 0) {
                    ans = i;
                    cnt = 1;
                }
            }
        }
        return ans;
    }
};

