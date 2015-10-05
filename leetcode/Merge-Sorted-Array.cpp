/**
*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*Note:
*You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int length = m + n - 1;
        int ai = m - 1;
        int bi = n - 1;
        while(ai >= 0 && bi >= 0){
            if(nums1[ai] > nums2[bi])
                nums1[length--] = nums1[ai--];
            else
                nums1[length--] = nums2[bi--];
        }
        
        while(ai >= 0)
            nums1[length--] = nums1[ai--];
            
        while(bi >= 0)
            nums1[length--] = nums2[bi--];
    }
};