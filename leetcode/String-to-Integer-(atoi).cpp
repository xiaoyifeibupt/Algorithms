/**
*Implement atoi to convert a string to an integer.

*Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

*Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

*Update (2015-02-10):
*The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

*spoilers alert... click to show requirements for atoi.

*Requirements for atoi:
*The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

*The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

*If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

*If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
public:
    int atoi(string str) {
        static const int MAX = (int)((unsigned)~0 >> 1);
        static const int MIN = -(int)((unsigned)~0 >> 1) - 1;
        static const int MAX_DIV = (int)((unsigned)~0 >> 1) / 10;
        static const int MIN_DIV = (int)((((unsigned)~0 >> 1) + 1) / 10);
        static const int MAX_R = (int)((unsigned)~0 >> 1) % 10;
        static const int MIN_R = (int)((((unsigned)~0 >> 1) + 1) % 10);
        int result = 0;
        int sign = 1;
        int c;
        
        int i = 0;
        while (isspace(str[i]) && i < str.size())
            ++i;
        if (str[i] == '+' || str[i] == '-') {    
            if (str[i] == '-')
                sign = -1;
            ++i;
        }
        while (isdigit(str[i]) && i < str.size()) {
            c = str[i] - '0';
            if (sign > 0 && (result > MAX_DIV || (result == MAX_DIV && c >= MAX_R))) {
                result = MAX;
                break;
            }
            else if (sign < 0 && (result > MIN_DIV || (result == MIN_DIV && c >= MIN_R))) {
                result = MIN;
                break;
            } 
            result = result * 10 + c;
            ++i;
        }
        return sign > 0 ? result : -result;
    }
};
