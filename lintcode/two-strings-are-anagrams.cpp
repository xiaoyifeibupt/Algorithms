/**
*Write a method anagram(s,t) to decide if two strings are anagrams or not.
*Example*
*Given *s="abcd"*, *t="dcab"*, return *true*.*

*Challenge*
*O(n) time, O(1) extra space*
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> count;
        for (const auto& ss : s)
            ++count[tolower(ss)];
        for (const auto& tt :t) {
            --count[tolower(tt)];
            if (count[tolower(tt)] < 0)
                return false;
        }
        return true;
    }
};
