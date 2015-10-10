/**
*Say you have an array for which the ith element is the price of a given stock on day i.
*Example*
*Given an example *[4,4,6,1,1,4,2,5]*, return *6*.*

*Note*
*You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).*
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.empty()) {
            return 0;
        }

        int hold_1 = INT_MIN, hold_2 = INT_MIN;
        int release_1 = INT_MIN, release_2 = INT_MIN;

        for (const auto& p : prices) {
            hold_1 = max(hold_1, -p);
            release_1 = max(release_1, hold_1 + p);
            hold_2 = max(hold_2, release_1 - p);
            release_2 = max(release_2, hold_2 + p);
        }

        return release_2;
    }
};
