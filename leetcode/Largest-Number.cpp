/*
*Given a list of non negative integers, arrange them such that they form the largest number.

*For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

*Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    static bool cmp(const string &s1, const string &s2){
        return (s1 + s2) > (s2 + s1);
    }
    string largestNumber(vector<int> &num) {
        vector<string> str_num;
        
        for (int i = 0; i < num.size(); ++i) 
            str_num.push_back(to_string(num[i]));
            
        sort(str_num.begin(), str_num.end(), cmp);
        
        string result = "";
        int zero = 0;
        for(int j = 0; j < str_num.size(); ++j) {
            if(str_num[j] == "0")
                zero++;
            result += str_num[j];
        }
        if(zero == str_num.size())
            return "0";
        else
        return result;
    }
};
