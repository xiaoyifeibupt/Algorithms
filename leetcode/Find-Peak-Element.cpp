/**
*A peak element is an element that is greater than its neighbors.

*Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

*The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

*You may imagine that num[-1] = num[n] = -∞.

*For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

*Note:
*Your solution should be in logarithmic complexity.
*/
class Solution1 {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); ++i)
            if(num[i] < num[i - 1])
                return i - 1;
                
        return num.size() - 1;
    }
};

class Solution2 {
public:
    int findPeakElement(const vector<int> &num) {
        int left = 0, right = num.size() - 1;
        while(left <= right) {
            if(left == right)
                return left;
            int mid = (left + right) >> 1;
            if(num[mid] < num[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
    }
};
