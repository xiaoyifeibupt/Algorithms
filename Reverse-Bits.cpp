class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t re = 0;
        for (uint32_t i = 1; i != 0; i <<= 1){
            re <<= 1;
            if (n & 1) 
                re |= 1;
            n >>= 1;
     }
    return re;
    }
};
