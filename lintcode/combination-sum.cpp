/**
*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
*Example*
*given candidate set *2,3,6,7* and target *7*, *A solution set is: *[7]* *[2, 2, 3]* *

*Note*
*All numbers (including target) will be positive integers.*Elements in a combination (*a*1*, *a*2*, … , *a*k*) must be in non-descending order. (ie, *a*1* ≤ *a*2* ≤ … ≤ *a*k*).*The solution set must not contain duplicate combinations.*
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSumHelper(candidates, target, 0, v, ans);
        return ans;
    }

private:
    void combinationSumHelper(vector<int>& num, int gap, int begin,
                              vector<int>& v,vector<vector<int>> &ans) {
        if (gap == 0) {
            ans.emplace_back(v);
            return;
        }

        for (size_t i = begin; i < num.size() && num[i] <= gap; ++i) {
            v.emplace_back(num[i]);
            combinationSumHelper(num, gap - num[i], i, v, ans);
            v.pop_back();
        }
    }
};
