/**
*Given an array of integers, find two numbers such that they add up to a specific target number.
*Example*
*numbers=*[2, 7, 11, 15]*, target=*9*
*return *[1, 2]*

*Note*
*You may assume that each input would have exactly one solution*

*Challenge*
*Either of the following solutions are acceptable:*
*
*O(n) Space, O(nlogn) Time*
*O(n) Space, O(n) Time*
*
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(target - nums[i]) != hash.end()) {
                return {hash[target - nums[i]] + 1, i + 1};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};

