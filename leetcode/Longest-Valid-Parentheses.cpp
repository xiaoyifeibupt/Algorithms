/**
*Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
*For &quot;(()&quot;, the longest valid parentheses substring is &quot;()&quot;, which has length = 2.
*Another example is &quot;)()())&quot;, where the longest valid parentheses substring is &quot;()()&quot;, which has length = 4.
*
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;  
        sta.push(-1);  
        int ans = 0;  
        for(int i = 0;i < s.size();i++) {  
            if(s[i] == '(')
                sta.push(i);
            else {  
                if(sta.size() > 1) {  
                    sta.pop();  
                    int tmp = sta.top();  
                    ans = max(ans,i - tmp);  
                }  
                else {  
                    sta.pop();  
                    sta.push(i);
                }  
            }  
        }  
        return ans;  
    }
};