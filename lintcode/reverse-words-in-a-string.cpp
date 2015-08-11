/**
*Given an input string, reverse the string word by word.
*Example*
*

*Clarification*
*
*What constitutes a word?*
    A sequence of non-space characters constitutes a word.*
*Could the input string contain leading or trailing spaces?*
    Yes. However, your reversed string should not contain leading or trailing spaces.*
*How about multiple spaces between two words?*
    Reduce them to a single space in the reversed string.*
*
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        vector<string> vec;
        int len = s.length();
        if (len == 0)
            return "";
        int i = 0;
        int j = len - 1;
        while (i != len && s[i] == ' ')
            i++;
        while (j != -1 && s[j] == ' ')
            j--;
        int k = i;
        while ( i <= j) {
            k = i;
            while(s[i] !=' ' && i <= j)
                i++;
            vec.push_back(s.substr(k, i - k));
            while(s[i] == ' ' && i <= j)
                i++;
        }
        if (vec.empty()){
            return "";
        }
        reverse(vec.begin(), vec.begin() + vec.size());
        string m = vec[0];
        for (int i = 1; i < vec.size(); i++) {
            m += " ";
            m += vec[i];
        }
        return m;
    }
};
