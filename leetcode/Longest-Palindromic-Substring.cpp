/**
*Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    //ä»ä¸­é´åä¸¤è¾¹å±å¼
    string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2;
        int n = s.length();
        while (l >= 0 && r <= n-1 && s[l] == s[r]) {
            l--;
            r++;
        }
    return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        string longest = s.substr(0, 1);  // a single char itself is a palindrome
        for (int i = 0; i < n-1; i++) {
            string p1 = expandAroundCenter(s, i, i); //é¿åº¦ä¸ºå¥æ°çåéåæå­ç¬¦ä¸²
            if (p1.length() > longest.length())
                longest = p1;
 
            string p2 = expandAroundCenter(s, i, i+1);//é¿åº¦ä¸ºå¶æ°çåéåæå­ç¬¦ä¸²
            if (p2.length() > longest.length())
                longest = p2;
        }
    return longest;
    }
};