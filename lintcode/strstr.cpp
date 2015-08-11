/**
*strstr (a.k.a find sub string), is a useful function in string operation. Your task is to implement this function. 
*Example*
*If source = *"source"* and target = *"target"*, return *-1*.*
*If source = *"abcdabcdefg"* and target = *"bcd"*, return *1*.*

*Challenge*
*O(n*2*) is acceptable. Can you implement an O(n) algorithm? (hint: *KMP*)*

*Clarification*
*Do I need to implement KMP Algorithm in a real interview?*
*
*Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.*
*
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source != nullptr && target != nullptr) {
            int slen = strlen(source);
            int tlen = strlen(target);
            if (tlen == 0) return 0;
            int i = 0, j = 0;
            while (i <= slen - tlen) {
                if (source[i] == target[j]) {
                    i++;
                    j++;
                } else {
                    i = i - j + 1;
                    j = 0;
                }
                if (j == tlen) return i - j;
            }
        }
        return -1;
    }
};

