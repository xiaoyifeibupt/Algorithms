/**
*
*There are N children standing in a line. Each child is assigned a rating value. 
*You are giving candies to these children subjected to the following requirements:
*Each child must have at least one candy.
*Children with a higher rating get more candies than their neighbors.
*What is the minimum candies you must give?
*
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> result(n, 1);
        for (int i = 0; i < n; ++i)
            if (ratings[i] > ratings[i - 1])
                result[i] = result[i - 1] + 1;
        for (int i = n - 1; i >= 1; --i)
            if (ratings[i - 1] > ratings[i] && result[i - 1] <= result[i])
                result[i - 1] = result[i] + 1;
        return accumulate(result.cbegin(), result.cend(), 0);
    }
};