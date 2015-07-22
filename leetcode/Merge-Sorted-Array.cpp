/**
*Given two sorted integer arrays A and B, merge B into A as one sorted array.

*Note:
*You may assume that A has enough space (size that is greater or equal to m + n) 
*to hold additional elements from B. The number of elements initialized in A 
*and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int length = m + n - 1;
        int ai = m - 1;
        int bi = n - 1;
        while(ai >= 0 && bi >= 0){
            if(A[ai] > B[bi])
                A[length--] = A[ai--];
            else
                A[length--] = B[bi--];
        }
        
        while(ai >= 0)
            A[length--] = A[ai--];
            
        while(bi >= 0)
            A[length--] = B[bi--];
    }
};
