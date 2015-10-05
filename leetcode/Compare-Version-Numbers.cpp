/**
*Compare two version numbers version1 and version2.
*If version1 &gt; version2 return 1, if version1 &lt; version2 return -1, otherwise return 0.
*You may assume that the version strings are non-empty and contain only digits and the . character.
*The . character does not represent a decimal point and is used to separate number sequences.
*For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
*Here is an example of version numbers ordering:
*0.1 &lt; 1.1 &lt; 1.2 &lt; 13.37
*Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int re1 = 0,re2 = 0;
        int i = 0,j = 0;
        while(version1.length() != i || version2.length() != j){
            re1 = 0;
            while(i != version1.length()){
                if(version1[i] == '.'){
                    ++i;
                    break;
                }
                re1 = re1 * 10 + (version1[i] - '0');
                ++i;
            }
            
            re2 = 0;
            while(j != version2.length()){
                if(version2[j] == '.'){
                    ++j;
                    break;
                }
                re2 = re2 * 10 + (version2[j] - '0');
                ++j;
            }
            
            if(re1 > re2)
                return 1;
            else if(re1 < re2)
                return -1;
        }
        return 0;
    }
};