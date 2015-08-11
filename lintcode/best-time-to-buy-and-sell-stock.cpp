/**
*Say you have an array for which the ith element is the price of a given stock on day i.
*Example*
*Given an example* [3,2,3,1,2]*, return 1*
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size() < 2) return 0;
        int low = prices[0];
        int result = 0;
        for (int i : prices) {
            if (i < low)
                low = i;
            else if (i - low > result)
                result = i - low;
        }
        return result;
    }
};

