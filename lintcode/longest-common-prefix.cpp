/**
*Given k strings, find the longest common prefix (LCP).
*Example*
*For strings *"ABCD"*, *"ABEF"* and *"ACEF"*, the LCP is *"A"*
*For strings *"ABCDEFG"*, *"ABCEFG"* and *"ABCEFA"*, the LCP is *"ABC"*
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.size() == 0) return "";
        auto prefix_len = strs[0].length();
        for (const auto& str : strs) {
            auto i = 0;
            for (; i < str.length() && i < prefix_len && str[i] == strs[0][i]; ++i);
            if (i < prefix_len) {
                prefix_len = i;
            }
        }

        return strs[0].substr(0, prefix_len);
    }
};

