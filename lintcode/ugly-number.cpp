/**
*Ugly number is a number that only have factors 3, 5 and 7. 
*Example*
*If *K=4*, return *9*.*

*Challenge*
*O(*K* log *K*) or O(*K*) time.*
*/

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        if (k <= 0) return 0;
        vector<long long> result(k + 1, 0);
        result[0] = 1;
        int three = 0, five = 0, seven = 0;
        int next = 1;
        while (next <= k) {
            long long next_ugly = min(min(result[three] * 3, result[five] * 5),
                                        result[seven] * 7);
            result[next] = next_ugly;
            while (result[three] * 3 <= result[next]) ++three;
            while (result[five] * 5 <= result[next]) ++five;
            while (result[seven] * 7 <= result[next]) ++seven;
            ++next;
        }
        return result[next - 1];
    }
};
