/**
*Say you have an array for which the ith element is the price of a given stock on day i.
*Example*
*Given an example* *[2,1,2,0,1]*, return 2*
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int sum = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                sum = sum + prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};
