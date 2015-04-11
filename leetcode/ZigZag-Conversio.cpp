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

class Solution1 {
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

/**
 * 0        8         16
 * 1      7 9       1517
 * 2    6   10    14  18
 * 3  5     11  13    19
 * 4        12        20    
 * 第0行和最后一行中，前一个下标的值和后一个下标的值相差 2 * nRows - 2
 * 中间行中，前一个下标的值和后一个下标的值需要根据这个下标是该行中的奇数列还是偶数列来计算
 * 奇数列2 * (nRows - 1 - i)，偶数列2 * i。
 * /
class Solution2 {
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
