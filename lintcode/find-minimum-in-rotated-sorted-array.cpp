/**
*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*Example*
*Given *[4, 5, 6, 7, 0, 1, 2]* return *0*

*Note*
*You may assume no duplicate exists in the array.*
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int left = 0, right = num.size() - 1;
        int mid = left;
        while (num[left] >= num[right]) {
            if (right - left == 1) {
                mid = right;
                break;
            }
            mid = (left + right) >> 1;
            if (num[mid] >= num[left])
                left = mid;
            else if (num[mid] <= num[right])
                right = mid;
        }
        return num[mid];
    }
};
