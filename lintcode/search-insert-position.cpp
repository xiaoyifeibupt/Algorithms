/**
*Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
*Example*
*[1,3,5,6]*, 5 → 2*
*[1,3,5,6]*, 2 → 1*
*[1,3,5,6]*, 7 → 4*
*[1,3,5,6]*, 0 → 0*

*Challenge*
*O(log(n)) time*
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (A[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
