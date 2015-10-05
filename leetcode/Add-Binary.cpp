/**
*
*Given two binary strings, return their sum (also a binary string).
*For example,
*a = "11"
*b = "1"
*Return "100".
*
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int flag = 0;
        
        int ai = a.size() - 1;
        int bi = b.size() - 1;
        string c = "";
        while(ai >= 0 && bi >= 0){
            int sum = (a[ai--] - '0') + (b[bi--] - '0') + flag;
            flag = sum / 2;
            sum %= 2;
            c = (char)(sum + '0') + c;
        }
        
        while(ai >= 0){
            int sum = (a[ai--] - '0') + flag;
            flag = sum / 2;
            sum %= 2;
            c = (char)(sum + '0') + c;
        }
        
        while(bi >= 0){
            int sum = (b[bi--] - '0') + flag;
            flag = sum / 2;
            sum %= 2;
            c = (char)(sum + '0') + c;
        }
        
        if(flag)
            c = (char)(flag + '0') + c;
             
         return c;
    }
};