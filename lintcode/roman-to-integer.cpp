/**
*Given a roman numeral, convert it to an integer.
*Example*
*IV* -> *4*
*XII* -> *12*
*XXI* -> *21*
*XCIX* -> *99*

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
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        unordered_map<char, int> numeral_map = {{'I',    1}, {'V',   5}, {'X',  10},
                                                {'L',   50}, {'C', 100}, {'D', 500},
                                                {'M', 1000}};
        int decimal = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && numeral_map[s[i]] > numeral_map[s[i - 1]]) {
                decimal += numeral_map[s[i]] - 2 * numeral_map[s[i - 1]];
            } else {
                decimal += numeral_map[s[i]];
            }
        }
        return decimal;
    }
};
