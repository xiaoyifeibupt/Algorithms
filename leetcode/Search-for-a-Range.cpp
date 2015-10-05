/**
*Given a sorted array of integers, find the starting and ending position of a given target value.
*Your algorithm's runtime complexity must be in the order of O(log n).
*If the target is not found in the array, return [-1, -1].
*For example,
*Given [5, 7, 7, 8, 8, 10] and target value 8,
*return [3, 4].
*
*/
class Solution {
public:

    int binsearch(int A[],int n,int tar){
        int left = 0;
        int right = n - 1;
        while(left <= right){
            int mid = (left + right)>>1;
            if(A[mid] > tar)
                right = mid - 1;
            else if(A[mid] < tar)
                left = mid + 1;
            else
                return mid;
        }
    return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
       
        vector<int> result;
        int index = binsearch(A,n,target);
        if(index == -1){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else{
            int ls = index;
            while(ls>0 && A[index] == A[ls-1]) ls--;
            int rs = index;
            while(rs<n-1 && A[index] == A[rs+1]) rs++;
            result.clear();
            result.push_back(ls);
            result.push_back(rs);
        }
        return result;

    }
};