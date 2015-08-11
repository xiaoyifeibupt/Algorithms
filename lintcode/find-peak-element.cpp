/**
*There is an integer array which has the following features:
*Example*
*Given *[1, 2, 1, 3, 4, 5, 7, 6]*
*Return index *1* (which is number 2) or *6* (which is number 7)*

*Note*
*The array may contains multiple peeks, find any of them.*

*Challenge*
*Time complexity O(logN)*
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if ((mid == 0 || A[mid - 1] <= A[mid]) &&
                (mid == A.size() - 1 || A[mid] >= A[mid + 1])) {
                return mid;
            }else if (mid > 0 && A[mid - 1] > A[mid]) {
                right = mid - 1;
            }
            // Else: A[mid - 1] <= A[mid] < A[mid + 1]
            else {
                left = mid + 1;
            }
        }
    }
};

