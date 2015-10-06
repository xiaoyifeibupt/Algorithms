/**
*Given n and k, return the k-th permutation sequence.
*Example*
*For *n = 3*, all permutations are listed as follows:*
*"123"
"132"
"213"
"231"
"312"
"321"
*
*If *k = 4*, the fourth permutation is *"231"*

*Note*
*n* will be between 1 and 9 inclusive.*

*Challenge*
*O(n*k) in time complexity is easy, can you do it in O(n^2) or less?*
*/

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
       vector<int> nums;
       long long fac = 1;
       for (int i = 1; i <= n; ++i) {
           nums.push_back(i);
           fac *= i;
       }
       stringstream result;
       while (n > 0) {
           fac /= n;
           int index = (k - 1) / fac;
           result<<nums[index];
           nums.erase(nums.begin() + index);
           k = (k - 1) % fac + 1;
           --n;
       }
       return result.str();
    }   
};
