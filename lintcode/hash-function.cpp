/**
*In data structure Hash, hash function is used to convert a string(or any other type) into an integer smaller than hash size and bigger or equal to zero. The objective of designing a hash function is to "hash" the key as unreasonable as possible. A good hash function can avoid collision as less as possible. A widely used hash function algorithm is using a magic number 33, consider any string as a 33 based big integer like follow:
*Example*
*For key="abcd" and size=100, return 78*

*Clarification*
*For this problem, you are not necessary to design your own hash algorithm or consider any collision issue, you just need to implement the algorithm as described.*
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long long value = 0L;
        for (const auto& c : key) {
            value = value * 33L % HASH_SIZE;
            value = (value + static_cast<const long long>(c) % HASH_SIZE) % HASH_SIZE;
        }
        return static_cast<int>(value);
    }
};
