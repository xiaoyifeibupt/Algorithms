/**
*Given an array of integers, every element appears twice except for one. Find that single one.
*Note:
*Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        if(A == NULL || n == 0)
            return 0;
        int res = A[0];
        for(int j = 1; j < n; j++){
            res = res^A[j];
        }
        
        return res;
    }
};