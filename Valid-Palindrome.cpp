/*
*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

*For example,
    "A man, a plan, a canal: Panama" is a palindrome.
    "race a car" is not a palindrome.

*Note:
*Have you consider that the string might be empty? This is a good question to ask during an interview.

*For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int le = 0;
        int ri = s.size() - 1;
        while(le < ri){
            while(!isalnum(s[le])){
                ++le;
                if(le >= ri)
                    break;
            }
            
            while(!isalnum(s[ri])){
                --ri;
                if(le >= ri)
                    break;
            }
            
            if(le >= ri)
                    break;
            s[le] = tolower(s[le]);
            s[ri] = tolower(s[ri]);
            if(s[le] != s[ri])
                return false;
            ++le;
            --ri;
            
        }
    return true;
    }
};
