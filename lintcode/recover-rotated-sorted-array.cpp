/**
*Given a rotated sorted array, recover it to sorted array in-place.
*Example*
*[4, 5, 1, 2, 3]* -> *[1, 2, 3, 4, 5]*

*Challenge*
*In-place, O(*1*) extra space and O(*n*) time.*

*Clarification*
*What is rotated array?*
*
*For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]*
*
*/

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
         int i = findMinPoint(nums);
        reverse(nums.begin(), nums.begin() + i);
        reverse(nums.begin() + i, nums.end());
        reverse(nums.begin(), nums.end());
    }


    int findMinPoint(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;

        // Find min left s.t. num[left] > num[left + 1].
        while (left < right && num[left] >= num[right]) {
            int mid = left + (right - left) / 2;
            if (num[mid] < num[left]) {
                right = mid;
            } else if (num[mid] > num[left]) {
                left = mid + 1;
            } else {
                ++left;
            }
        }

        return left;
    }
};
