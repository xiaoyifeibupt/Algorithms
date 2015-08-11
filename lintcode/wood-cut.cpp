/**
*Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.
*Example*
*For *L=[232, 124, 456]*, *k=7*, return *114*.*

*Note*
*You couldn't cut wood into float length.*

*Challenge*
*O(n log Len), where Len is the longest length of the wood.*
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        const int n = L.size();
        if (n == 0) {
            return 0;
        }

        int left = 1, right = *max_element(L.cbegin(), L.cend());
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find the smallest x,  s.t. pieceCount(x) < k <= pieceCound(x - 1)
            if (pieceCount(L, mid) < k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // The max length is x - 1
        return left - 1;
    }

    int pieceCount(vector<int>& L, int x) {
        int cnt = 0;
        for (const auto& len : L) {
            cnt += len / x;
        }
        return cnt;
    }
};
