/**
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        vector<int> num = numbers;
        sort(num.begin(),num.end());
        
        int i = 0,j = num.size() - 1;
        while(i < j) {
            if(num[i] + num[j] < target)
                i++;
            else if(num[i] + num[j] > target)
                j--;
            else {
                for(int index = 0;index < numbers.size(); index++) {
                    if(numbers[index] == num[i])
                        result.push_back(index + 1);
                    else if(numbers[index] == num[j])
                        result.push_back(index + 1);
                }
                return result;
            }
        }
        result.push_back(-1);
        result.push_back(-1);
        return result; 
    }
};
