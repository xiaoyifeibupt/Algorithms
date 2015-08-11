/**
*There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
*Example*
*Given *4* gas stations with *gas[i]=[1,1,3,1]*, and the *cost[i]=[2,2,1,1]*. The starting gas station's index is *2*.*

*Note*
*The solution is guaranteed to be unique.*

*Challenge*
*O(n) time and O(1) extra space*
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int cur_sum = 0, total_sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            cur_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (cur_sum < 0) {
                cur_sum = 0;
                start = i + 1;
            }
        }
        if (total_sum >= 0) 
            return start;
        else
            return -1;
    }
};
