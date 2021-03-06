/**
*Given an array of size n, find the majority element. The majority element is the element that appears more than &lfloor; n/2 &rfloor; times.
*You may assume that the array is non-empty and the majority element always exist in the array.
*Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int nTimes = 0;
        int candidate = 0;
        for(int i = 0; i < num.size(); i ++)
        {
            if(nTimes == 0)
            {
                candidate = num[i];
                nTimes = 1;
            }
            else
            {
                if(candidate == num[i])
                    nTimes ++;
                else
                    nTimes --;
            }
        }
        return candidate;
    }
};