/**
*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*Example*
*For *[4, 5, 1, 2, 3]* and *target=1*, return *2*.*
*For *[4, 5, 1, 2, 3]* and *target=0*, return *-1*.*

*Challenge*
*O(logN) time*
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (A[mid] == target) 
                return mid;
            if (A[left] < A[mid]) {
                if (A[left] <= target && target < A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else if (A[left] > A[mid]) {
                if (A[mid] < target && target <= A[right]) 
                    left = mid + 1;
                else
                    right = mid - 1;
            } else
                left++;
        }
        return -1;
    }
};
