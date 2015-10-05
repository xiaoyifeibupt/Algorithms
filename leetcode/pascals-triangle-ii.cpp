/**
*Given an index k, return the kth row of the Pascal's triangle.
*For example, given k = 3,
*Return [1,3,3,1].
*Note:
*Could you optimize your algorithm to use only O(k) extra space?
*
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> re;
        for(int i = 0; i <= rowIndex; i++){
            int k = (int)re.size();
            for(int j = k - 1; j >= 1; j--)
                re[j] += re[j-1];
            re.push_back(1);
        }
     return re;      
    }
};