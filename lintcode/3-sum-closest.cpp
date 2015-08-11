/**
*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. 
*Example*
*For example, given array *S = {-1 2 1 -4}*, and *target = 1*. The sum that is closest to the target is *2*. *(-1 + 2 + 1 = 2)*.*

*Note*
*You may assume that each input would have exactly one solution.*

*Challenge*
*O(n^2) time, O(1) extra space*
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int ans = INT_MAX;
        int min_diff = INT_MAX;

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicated.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {  // Time: O(n) for each i.
                const auto sum = nums[i] + nums[j] + nums[k];

                if (sum > target) {  // Should decrease sum.
                    --k;
                } else if (sum < target) {  // Should increase sum.
                    ++j;
                } else {
                    return target;
                }

                if (abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    ans = sum;
                }
            }
        }

        return ans;
    }
};

