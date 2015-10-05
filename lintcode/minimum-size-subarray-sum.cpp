/**
*Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return -1 instead.
*Example*
*Given the array *[2,3,1,2,4,3]* and s = *7*, the subarray *[4,3]* has the minimal length under the problem constraint.*

*Challenge*
*If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).*
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int start = - 1, sum = 0, minsize = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                minsize = min(minsize, i - start);
                sum -= nums[++start];
            }
        }
        if (minsize == INT_MAX)
            return -1;
        else
            return minsize;
    }
};
