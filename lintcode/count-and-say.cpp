/**
*The count-and-say sequence is the sequence of integers beginning as follows:
*Example*
*Given n = *5*, return *"111221"*.*

*Note*
*The sequence of integers will be represented as a string.*
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string str("1");
        while (--n) {
            str = getNext(str);
        }
        return str;
    }
    string getNext(const string& str) {
        stringstream ss;
        for (int i = 0; i < str.length(); ++i) {
            int count = 1;
            while (i < str.length() - 1 && str[i] == str[i + 1]) {
                ++i;
                ++count;
            }
            ss<<count<<str[i];
        }
        return ss.str();
    }
};
