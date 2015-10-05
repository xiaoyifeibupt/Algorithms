/**
*
*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
*For example, given the array [&#8722;2,1,&#8722;3,4,&#8722;1,2,1,&#8722;5,4],
*the contiguous subarray [4,&#8722;1,2,1] has the largest sum = 6.
*click to show more practice.
*More practice:
*If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*
*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0];
        int minSum = min(0,sum);
        int answer = A[0];
        for(int i = 1; i < n; i++) {
            sum += A[i];
            answer = max(answer,sum - minSum);
            minSum = min(minSum,sum);
        }
    return answer;
    }
};