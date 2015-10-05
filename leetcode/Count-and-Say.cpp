/**
*The count-and-say sequence is the sequence of integers beginning as follows:
*1, 11, 21, 1211, 111221, ...
*1 is read off as "one 1" or 11.
*11 is read off as "two 1s" or 21.
*21 is read off as "one 2, then one 1" or 1211.
*Given an integer n, generate the nth sequence.
*Note: The sequence of integers will be represented as a string.
*
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n < 1)
            return "";
        string result = "1";
        int i = 1;
        while(i < n) {
            result = forOneStr(result);
            i++;
        }
    return result;
    }
    string forOneStr(string str) {
        char tem = str[0];
        int count = 1;
        string nextStr = "";
        for(int i = 1; i < str.size(); ++i) {
            if(str[i] == tem) {
                count++;
                continue;
            }
            char xx[10];
            sprintf(xx, "%d%d", count, tem - '0');
            string tem1(xx);
            nextStr += tem1;
            tem = str[i];
            count = 1;
        }
        char xx[10];
        sprintf(xx, "%d%d", count, tem - '0');
        string tem1(xx);
        nextStr += tem1;
        return nextStr;
    }
};