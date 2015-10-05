/**
*
*Find the contiguous subarray within an array (containing at least one number) which has the largest product.
*For example, given the array [2,3,-2,4],
*the contiguous subarray [2,3] has the largest product = 6.
*
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        int *maxA = new int[n];
        int *minA = new int[n];
        
        maxA[0] = minA[0] = A[0];
        int value = maxA[0];
        
        for(int i = 1 ; i < n ; ++i) {  
            maxA[i] = max(max(A[i],maxA[i-1]*A[i]),minA[i-1]*A[i]);  
            minA[i] = min(min(A[i],maxA[i-1]*A[i]),minA[i-1]*A[i]);  
            value=max(value,maxA[i]);  
        }
        delete [] maxA;
        delete [] minA;
    return value;  
    }
};