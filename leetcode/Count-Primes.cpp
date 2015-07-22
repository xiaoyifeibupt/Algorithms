/**
*Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<int> vec(n,true);
        for(int i = 2; i * i < n; i++) {
            if(vec[i]) {
                for(int j = i; i * j < n; j++)
                    vec[j * i] = false;
            }
        }
        int result = 0;
        for(int i = 2; i < n; i++)
            if(vec[i]) result++;
        return result;
    }
};
