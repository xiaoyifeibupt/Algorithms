/**
*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

*For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
*the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*More practice:
*If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution1 {
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

class Solution2 {
public:
    int maxSubArray(int A[], int n) {
        int answer = A[0];
        int endhere = A[0];
        for(int i = 1; i < n; i++) {
            endhere = max(endhere + A[i],A[i]);
            answer = max(answer,endhere);
        }
    return answer;
    }
};

class Solution3 {
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
