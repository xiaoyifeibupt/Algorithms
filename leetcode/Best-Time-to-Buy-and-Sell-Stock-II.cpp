/**
*Say you have an array for which the ith element is the price of a given stock on day i.
*Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.size() < 2)
            return 0;
        for(int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i + 1] - prices[i] > 0)
                result = result + prices[i + 1] - prices[i];
        }
        return result;
    }
};