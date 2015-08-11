/**
*Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.
*Example*
*Given *[-3, 1, 2, -3, 4]*, return *[0, 2]* or *[1, 3]*.*

*Note*
*There is at least one subarray that it's sum equals to zero.*
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int, int> table;
        table[0] = -1;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (!table.emplace(sum, i).second) {  // Already exists.
                return {table[sum] + 1, i};
            }
        }
        return {};
    }
};
