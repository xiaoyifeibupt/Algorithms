/*
*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

*For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        if(n < 1)
            return "";
        else{
            string re = "";
            while(n){
                n = n - 1;
                char c = n%26 + 'A';
                re += c;
                n /= 26;
            }
            reverse(re.begin(), re.end());
            return re;
        }
    }
};
