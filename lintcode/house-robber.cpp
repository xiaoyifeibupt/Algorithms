/**
*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
*Example*
*Given *[3, 8, 4]*, return *8*.*

*Challenge*
*O(n) time and O(1) memory.*
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if (A.size() <= 1)
            return A.empty() ? 0: A[0];
        vector<long long> dp = {A[0], max(A[0], A[1])};
        for (int i = 2; i < A.size(); ++i) {
            dp.push_back(max(A[i] + dp[i - 2], dp[i - 1]));
        }
        
        return dp.back();
    }
};
