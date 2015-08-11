/**
*Find K-th largest element in an array.
*Example*
*In array *[9,3,2,4,8]*, the 3rd largest element is *4*.*
*In array *[1,2,3,4,5]*, the 1st largest element is *5*, 2nd largest element is *4*, 3rd largest element is *3* and etc.*

*Note*
*You can swap elements in the array*

*Challenge*
*O(n) time, O(1) extra memory.*
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int L = 0,R = nums.size() - 1;
        while(L < R) {
            int left = L, right = R;
            int key = nums[left];
            
            while(left < right) {
                while(left < right && nums[right] < key) --right;
                nums[left] = nums[right];
                while(left < right && nums[left] >= key) ++left;
                nums[right] = nums[left];
            }
            nums[left] = key;
            if (left == k - 1) 
                return nums[k - 1];
            else if (left > k - 1) 
                R = left - 1;
            else 
                L = left + 1;
        }
        return nums[k - 1];
    }
};
