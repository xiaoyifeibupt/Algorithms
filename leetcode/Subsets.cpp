/*
*Given a set of distinct integers, nums, return all possible subsets.

*Note:
*Elements in a subset must be in non-descending order.
*The solution set must not contain duplicate subsets.
*For example,
*If nums = [1,2,3], a solution is:

  [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
  ]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int loop = 1 << nums.size();
        vector<vector<int> >result;
        for(int i = 0; i < loop; ++i) {
            vector<int> temp;
            int j = i;
            int index = 0;
            while(j) {
                if(j & 1)
                    temp.push_back(nums[index]);
                index++;
                j = j >>1;
            }
            sort(temp.begin(),temp.end());
            result.push_back(temp);
        }
        return result;
    }
};
