/**
*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

  P   A   H   N
  A P L S I I G
  Y   I   R
*And then read line by line: "PAHNAPLSIIGYIR"
*Write the code that will take a string and make this conversion given a number of rows:

*string convert(string text, int nRows);
*convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;
        string res[nRows];
        int i = 0, j, gap = nRows-2;
        while(i < s.size()){
            for(j = 0; i < s.size() && j < nRows; ++j) res[j] += s[i++];
            for(j = gap; i < s.size() && j > 0; --j) res[j] += s[i++];
        }
        string str = "";
        for(i = 0; i < nRows; ++i)
            str += res[i];
    return str;
    }
};
