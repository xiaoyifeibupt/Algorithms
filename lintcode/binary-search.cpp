/**
*For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.
*Example*
*If the array is *[1, 2, 3, 3, 4, 5, 10]*, for given target *3*, return *2*.*

*Challenge*
*If the count of numbers is bigger than 2^32, can your code work properly?*
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int left = 0, right = array.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (array[mid] < target)
                left = mid + 1;
            else if (array[mid] > target)
                right = mid - 1;
            else {
                int i = mid;
                while (array[i] == target) --i;
                return i + 1;
            }
        }
        return -1;
    }
};
