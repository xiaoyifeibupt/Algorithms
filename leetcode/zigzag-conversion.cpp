/**
*
*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
*P   A   H   N
*A P L S I I G
*Y   I   R
*And then read line by line: "PAHNAPLSIIGYIR"
*Write the code that will take a string and make this conversion given a number of rows:
*string convert(string text, int nRows);
*convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*
*/
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1 || s.length() == 0)  
           return s;  
  
        string res = "";  
        int len = s.length();  
        for (int i = 0; i < len && i < nRows; ++i) {  
            int indx = i;  
            res += s[indx];  
  
            for (int k = 1; indx < len; ++k) {
                if (i == 0 || i == nRows - 1)
                    indx += 2 * nRows - 2;
                else {  
                    if (k & 0x1)
                        indx += 2 * (nRows - 1 - i);  
                    else 
                        indx += 2 * i;  
                }
                if (indx < len) {  
                    res += s[indx];  
                }     
            }  
        }  
        return res;  
    }
};