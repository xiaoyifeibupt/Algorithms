/**
*Given a sorted array of n integers, find the starting and ending position of a given target value.
*Example*
*Given *[5, 7, 7, 8, 8, 10]* and target value *8*,
return *[3, 4]*.*

*Challenge*
*O(log *n*) time.*
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return {-1, -1};
        int left = 0, right = A.size() - 1;
        int mid;
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            if (A[mid] < target)
                left = mid + 1;
            else if (A[mid] > target)
                right = mid - 1;
            else
                break;
        }
        if (A[mid] == target) {
            int i = mid, j = mid;
            while(A[i] == target) --i;
            while(A[j] == target) ++j;
            return {i + 1, j - 1};
        }else
            return {-1, -1};
    }
};
