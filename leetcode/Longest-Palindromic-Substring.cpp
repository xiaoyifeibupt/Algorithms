/**
*Given a string S, find the longest palindromic substring in S. 
*You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int longestBegin = 0;
        int maxLen = 1;
        bool table[1000][1000] = {false};
        //base1
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        //base2
        for (int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                longestBegin = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i + 1][j - 1]) {
                    table[i][j] = true;
                    longestBegin = i;
                    maxLen = len;
                }
            }
        }
    return s.substr(longestBegin, maxLen);
    }
};

class Solution2 {
public:
    //从中间向两边展开
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
            string p1 = expandAroundCenter(s, i, i); //长度为奇数的候选回文字符串
            if (p1.length() > longest.length())
                longest = p1;
 
            string p2 = expandAroundCenter(s, i, i+1);//长度为偶数的候选回文字符串
            if (p2.length() > longest.length())
                longest = p2;
        }
    return longest;
    }
};

