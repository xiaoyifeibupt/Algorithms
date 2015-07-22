/**
*Given an array of integers, every element appears three times except for one. Find that single one.

*Note:
*Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitnum[32] = {0};
        int res = 0;
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < n; j++){
                bitnum[i] += (A[j] >> i) & 1;
            }
            res |= (bitnum[i] % 3) << i;
        }
        return res;
    }
};
