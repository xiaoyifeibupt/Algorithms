/**
*Given string A representative a positive integer which has N digits, remove any k digits of the number, the remaining digits are arranged according to the original order to become a new positive integer.
*Example*
*Given an integer A = *"178542"*, k = *4*
*return a string *"12"*
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        int len = A.length();
        if (len <= k) return "0";
        stack<char> s;
        for (int i = 0; i < len; ++i) {
            while (k > 0 && !s.empty() && s.top() > A[i]) {
                s.pop();
                --k;
            }
            s.emplace(A[i]);
        }
        while (k > 0) {
            s.pop();
            --k;
        }
        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        // Strip all leading '0'
        auto i = 0;
        for (; i < ans.length() && ans[i] == '0'; ++i);
        ans = ans.substr(i);

        // Handle boundary case
        if (ans.length() == 0) {
            return "0";
        }

        return ans;
    }
};

