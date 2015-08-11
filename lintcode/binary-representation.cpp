/**
*Given a (decimal - e.g. 3.72) number that is passed in as a string, return the binary representation that is passed in as a string. If the fractional part of the number can not be represented accurately in binary with at most 32 characters, return ERROR.
*Example*
*For n = *"3.72"*, return *"ERROR"*.*
*For n = *"3.5"*, return *"11.1"*.*
*/

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        int int_part = stoi(n.substr(0, n.find('.')));
        double dec_part = stod(n.substr(n.find('.')));
        string int_str = "";
        string dec_str = "";

        if (int_part == 0) {
            int_str.push_back('0');
        }

        while (int_part > 0) {
            int c = int_part % 2;
            int_str.push_back('0' + c);
            int_part = int_part >> 1;
        }
        reverse(int_str.begin(), int_str.end());

        while (dec_part > 0.0) {
            if (dec_str.length() > 32) {
                return "ERROR";
            }
            double remain = dec_part * 2;
            if (remain >= 1.0) {
                dec_str.push_back('1');
                dec_part = remain - 1.0;
            }
            else {
                dec_str.push_back('0');
                dec_part = remain;
            }
        }
        return dec_str.length() > 0? int_str + "." + dec_str : int_str;
    }
};

