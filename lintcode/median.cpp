/**
*Given a unsorted array with integers, find the median of it. 
*Example*
*Given [4, 5, 1, 2, 3], return 3*
*Given [7, 9, 4, 5], return 5*

*Challenge*
*O(n) time.*
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
//        int mid = (nums.size() % 2 == 0 ? nums.size() / 2 : nums.size() / 2 + 1);
        int mid = (nums.size() - 1) / 2;
        int L = 0,R = nums.size() - 1;
        while(L < R) {
            int left = L, right = R;
            int key = nums[left];
            
            while(left < right) {
                while(left < right && nums[right] > key) --right;
                nums[left] = nums[right];
                while(left < right && nums[left] <= key) ++left;
                nums[right] = nums[left];
            }
            nums[left] = key;
            if (left == mid) 
                return nums[mid];
            else if (left > mid) 
                R = left - 1;
            else 
                L = left + 1;
        }
        return nums[mid];
    }
};

