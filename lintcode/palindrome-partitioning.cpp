/**
* Given a string s, partition s such that every substring of the partition is a palindrome.Return all possible palindrome partitioning of s.
*Example*
*given *s* = *"aab"*,*Return*
*  [
    ["aa","b"],
    ["a","a","b"]
  ]*
*/

// class Solution {
// public:
//     /**
//      * @param s: A string
//      * @return: A list of lists of string
//      */
//     vector<vector<string>> partition(string s) {
//         // write your code here
//         const int n = s.size();
//         vector<vector<bool>> p(n, vector<bool>(n, false));
//         for (int i = n - 1; i >= 0; --i)
//             for (int j = i; j < n; ++j)
//                 p[i][j] = (s[i] == s[j]) && (j - i < 2 || p[i + 1][j - 1]);
        
//         vector<vector<string> > sub_palins[n]; // sub palindromes of s[0,i]
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = i; j < n; ++j)
//                 if (p[i][j]) {
//                     const string palindrome = s.substr(i, j - i + 1);
//                     if (j + 1 < n) {
//                         for (auto v : sub_palins[j + 1]) {
//                             v.insert(v.begin(), palindrome);
//                             sub_palins[i].push_back(v);
//                         }
//                     } else {
//                         sub_palins[i].push_back(vector<string> { palindrome });
//                     }
//                 }
//         }
//         return sub_palins[0];
//     }
// };

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path; // 一个partition 方案
        DFS(s, path, result, 0);
        return result;
    }
        // 搜索必须以s[start] 开头的partition 方案
    void DFS(string &s, vector<string>& path,
        vector<vector<string>> &result, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) { // 从i 位置砍一刀
                path.push_back(s.substr(start, i - start + 1));
                DFS(s, path, result, i + 1); // 继续往下砍
                path.pop_back(); // 撤销上上行
            }
        }
    }
    
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};