/**
*Print numbers from 1 to the largest number with N digits by recursion.
*Example*
*Given *N = 1*, return *[1,2,3,4,5,6,7,8,9]*.*
*Given *N = 2*, return *[1,2,3,4,5,6,7,8,9,10,11,12,...,99]*.*

*Note*
*It's pretty easy to do recursion like:*
*recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
*
*however this cost a lot of recursion memory as the recursion depth maybe very large. Can you do it in another way to recursive with at most N depth?*

*Challenge*
*Do it in recursion, not for-loop.*
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> result;
        numbersByRecursionHelper(0, n, result);
        return result;
    }

    // Construct the numbers by the current digit count.
    void numbersByRecursionHelper(int depth, int n, vector<int>& result) {
        if (depth == n) {
            return;
        }

        if (depth == 0) {  // Initiate the result.
            for (size_t d = 1; d <= 9; ++d) {
                result.emplace_back(d);
            }
        } else {  // Construct the numbers by the previous result.
            const size_t count = result.size();
            for (size_t d = 1; d <= 9; ++d) {
                result.emplace_back(d * pow(10, depth));
                for (size_t i = 0; i < count; ++i) {
                    result.emplace_back(result[i] + d * pow(10, depth));
                }
            }
        }
        // Construct the numbers in the next depth.
        numbersByRecursionHelper(depth + 1, n, result);
    }
};
