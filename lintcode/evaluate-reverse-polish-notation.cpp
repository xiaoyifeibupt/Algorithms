/**
*Evaluate the value of an arithmetic expression in Reverse Polish Notation.
*Example*
*["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if (tokens.empty()) return 0;
        stack<string> sta;
        for (const auto& token : tokens) {
        if (!is_operator(token)) {
                sta.emplace(token);
            } else {
                int y = stoi(sta.top());
                sta.pop();
                int x = stoi(sta.top());
                sta.pop();
                if (token[0] == '+') {
                    x += y;
                } else if (token[0] == '-') {
                    x -= y;
                } else if (token[0] == '*') {
                    x *= y;
                } else {
                    x /= y;
                }
                sta.emplace(to_string(x));
            }
        }
        return stoi(sta.top());
    }

    bool is_operator(const string &op) {
        return op.length() == 1 && string("+-*/").find(op) != string::npos;
    }
};
