/**
*Given a non-negative number represented as an array of digits, plus one to the number.
*The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int flag = 1;
        for(auto d = digits.rbegin(); d != digits.rend(); ++d){
            *d += flag;
            if (*d >= 10) {
                *d %= 10;
                flag = 1; 
            }
            else
                flag = 0;
        }
        if (flag)
            digits.insert(digits.begin(), flag);
        
        return digits;
    }
};