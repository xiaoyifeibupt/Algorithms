/**
*Given an integer, convert it to a roman numeral.
*Example*
*4* -> *IV*
*12* -> *XII*
*21* -> *XXI*
*99* -> *XCIX*
*more examples at: *http://literacy.kent.edu/Minigrants/Cinci/romanchart.htm*

*Clarification*
*What is *Roman Numeral*?*
*
*https://en.wikipedia.org/wiki/Roman_numerals*
*https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97*
*http://baike.baidu.com/view/42061.htm*
*
*/

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        map<int, string, greater<int>> numeral_map = 
                {{1,    "I"}, {4,   "IV"}, {5,   "V"}, {9,   "IX"},
                {10,   "X"}, {40,  "XL"}, {50,  "L"}, {90,  "XC"},
                {100,  "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
                {1000, "M"}};
        string result;
        while (n > 0) {
            for (const auto& kvp : numeral_map){
                while (n / kvp.first > 0) {
                    n -= kvp.first;
                    result.append(kvp.second);
                }
            }
        }        
        return result;
    }
};
