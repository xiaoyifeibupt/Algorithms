/**
*Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
*Example*
*
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (A[mid] == target)
                return true;
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
        return false;
    }
};
