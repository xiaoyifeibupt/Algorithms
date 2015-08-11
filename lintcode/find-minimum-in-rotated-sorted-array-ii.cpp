/**
*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*Example*
*Given [4,4,5,6,7,0,1,2] return 0*
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int left = 0, right = num.size() - 1;
        while (left < right && num[left] >= num[right]) {
            int mid = left + ((right - left)  >> 1);
            if (num[mid] < num[left])
                right = mid;
            else if (num[mid] > num[left])
                left = mid + 1;
            else
                ++left;
        }
        return num[left];
    }
};
