/**
*Given an array of strings, return all groups of strings that are anagrams.
*Example*
*Given *["lint", "intl", "inlt", "code"]*, return *["lint", "inlt", "intl"]*.*
*Given *["ab", "ba", "cd", "dc", "e"]*, return *["ab", "ba", "cd", "dc"]*.*

*Note*
*All inputs will be in *lower-case*
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, int> table;
        for (auto str : strs) {
            sort(str.begin(), str.end());
            ++table[str];
        }
        vector<string> anag;
        for (auto str : strs) {
            string tem(str);
            sort(tem.begin(), tem.end());
            if (table[tem] > 1)
                anag.push_back(str);
        }
        return anag;
    }
};

