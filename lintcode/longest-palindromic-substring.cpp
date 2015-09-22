/**
*Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*Example*
*Given the string = *"abcdzdcab"*, return *"cdzdc"*.*

*Challenge*
*O(n*2*) time is acceptable. Can you do it in O(n) time.*
*/

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    /*
    string expendAroundCenter(string& s, int x, int y) {
        int left = x, right = y;
        while (left >= 0 && right <= s.length() - 1 && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string& s) {
        // Write your code here
        int n = s.length();
        if (n == 0) return "";
        string longest = s.substr(0, 1);
        for (int i = 0; i < n - 1; ++i) {
            string p1 = expendAroundCenter(s, i, i);
            if (p1.length() > longest.length())
                longest = p1;
            string p2 = expendAroundCenter(s, i, i + 1);
            if (p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
    */
    string longestPalindrome(string& s) {
        bool check[1001][1001] = {false};
        for(int i=0; i<s.size(); i++){
            check[i][i] = true;
        }
        int res_low=0, res_high=0;
        for(int step=1; step<s.size(); step++){
            for(int i=0; i<s.size()-step; i++){
                int j = i + step;
                if (s[i] == s[j] && (i+1==j || check[i+1][j-1] == true)){
                    check[i][j] = true;
                    if (j-i+1 > res_high-res_low+1){
                        res_low = i;
                        res_high = j;
                    }
                } 
            }
        }
        return s.substr(res_low, res_high - res_low + 1);
    }
};
