/**
*Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.
*Example*
*Given *[1,1,2,3,3,3,2,2,4,1]* return *4*

*Challenge*
*One-pass, constant extra space.*
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < A.size(); i++) {
            twos |= ones & A[i];
            ones ^= A[i];// 异或3次 和 异或 1次的结果是一样的
            //对于ones 和 twos 把出现了3次的位置设置为0 （取反之后1的位置为0）
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};
