/**
*Given a positive integer, return its corresponding column title as appear in an Excel sheet.
*For example:
*    1 -&gt; A
*    2 -&gt; B
*    3 -&gt; C
*    ...
*    26 -&gt; Z
*    27 -&gt; AA
*    28 -&gt; AB 
*Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
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