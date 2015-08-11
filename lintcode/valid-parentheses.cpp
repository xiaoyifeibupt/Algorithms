/**
*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*Example*
*The brackets must close in the correct order, *"()"* and *"()[]{}"* are all valid but *"(]"* and *"([)]"* are not.*
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> sta;
        for (const char c : s) {
            if (c == ')' || c == ']' || c == '}') {
                if (sta.empty())
                    return false;
                else {
                    char a = sta.top();
                    sta.pop();
                    if ((a == '(' && c != ')') ||
                        (a == '[' && c != ']') ||
                        (a == '{' && c != '}'))
                        return false;
                }
            } 
            else
                sta.push(c);
        }
        return sta.empty();
    }
};
