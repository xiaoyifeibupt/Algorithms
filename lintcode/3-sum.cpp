/**
*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
*Example*
*For example, given array S = *{-1 0 1 2 -1 -4}*, A solution set is:*
*(-1, 0, 1)
(-1, -1, 2)
*

*Note*
*Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)*
*The solution set must not contain duplicate triplets.*
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
        for (int i = 0; i != nums.size();i++) {  
            if(i > 0 && nums[i] == nums[i-1])  
                continue;  
            int j, k;  
            j = i + 1;  
            k = nums.size() - 1;  
            while (j < k) {  
                if (j > i + 1 && nums[j] == nums[j-1]) {   
                    j++;  
                    continue;  
                }  
                if (k < nums.size()-1 && nums[k] == nums[k+1]) {  
                    k--;  
                    continue;  
                }  
                int sum = nums[i] + nums[j] + nums[k];  
                if (sum > 0){  
                    k--;  
                } else if (sum < 0){  
                    j++;  
                } else {  
                    vector<int> tmp;  
                    tmp.push_back(nums[i]);  
                    tmp.push_back(nums[j]);  
                    tmp.push_back(nums[k]);  
                    result.push_back(tmp);  
                    j++;  
                }  
            }  
        }  
        return result;  
    }
};

