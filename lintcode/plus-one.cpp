/**
*Given a non-negative number represented as an array of digits, plus one to the number.
*Example*
*Given *[1,2,3]* which represents 123, return *[1,2,4]*.*
*Given *[9,9,9]* which represents 999, return *[1,0,0,0]*.*
*/

// class Solution {
// public:
//     /**
//      * @param digits a number represented as an array of digits
//      * @return the result
//      */
//     vector<int> plusOne(vector<int>& digits) {
//         // Write your code here
//         vector<int> result;
//         int flag = 1;
//         for (int i = digits.size() - 1; i >= 0; --i) {
//             int num = digits[i] + flag;
//             flag = num / 10;
//             num %= 10;
//             result.push_back(num);
//         }
//         if (flag)
//             result.push_back(flag);
//         reverse(result.begin(), result.end());
//         return result;
//     }
// };
class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        vector<int> result(digits.begin(), digits.end());
        int flag = 1;
        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            *it += flag;
            flag  = *it / 10;
            *it %= 10;
        }
        if (flag)
            result.insert(result.begin(), flag);
        return result;
    }
};