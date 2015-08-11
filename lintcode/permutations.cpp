/**
*Given a list of numbers, return all possible permutations.
*Example*
*For nums = *[1,2,3]*, the permutations are:*
*[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*

*Challenge*
*Do it without recursion.*
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};

