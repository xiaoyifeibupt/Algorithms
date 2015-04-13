/**
*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

*For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
*the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*More practice:
*If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0],b = 0;
        for(int i = 0; i < n; i++) {
            if(b > 0)
                b+=A[i];
            else
                b = A[i];
            if(sum < b)
                sum = b;
        }
    return sum;
    }
};
