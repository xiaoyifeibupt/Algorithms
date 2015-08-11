/**
*Implement an algorithm to determine if a string has all unique characters.
*Example*
*Given *"abc"*, return *true*.*
*Given *"aab"*, return *false*.*

*Challenge*
*What if you can not use additional data structures?*
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        unordered_map<char, int> cnt;
        for (const auto& c : str) {
            ++cnt[c];
            if(cnt[c] > 1)
                return false;
        }
        return true;
    }
};
