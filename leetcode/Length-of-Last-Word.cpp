/**
*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
*If the last word does not exist, return 0.
*Note: A word is defined as a character sequence consists of non-space characters only.
*For example, 
*Given s = &quot;Hello World&quot;,
*return 5.
*
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s == NULL)
            return 0;
        int x = 0;
        while(*s != '\0'){
            if(*s != ' ')  
            {  
                int curLen = 0;  
                while(*s != '\0' && *s != ' ') s++, curLen++;  
                x = curLen;  
            }  
            else s++; 
        }
    return x;
    }
};