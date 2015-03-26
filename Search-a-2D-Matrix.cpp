/*
*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

*Integers in each row are sorted from left to right.
*The first integer of each row is greater than the last integer of the previous row.
*For example,

*Consider the following matrix:

  [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
  ]
*Given target = 3, return true.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitnum[32]={0};
        int res=0;
        for(int i=0; i<32; i++){
            for(int j=0; j<n; j++){
                bitnum[i]+=(A[j]>>i)&1;
            }
            res|=(bitnum[i]%3)<<i;
        }
        return res;
    }
};
