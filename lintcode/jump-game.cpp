/**
*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

*Example*
*A = *[2,3,1,1,4]*, return *true*.

*
*
A = *[3,2,1,0,4]*, return *false*.
*

*Note*
*This problem have two method which is *Greedy* and *Dynamic Programming*. *
*The time complexity of *Greedy* method is *O(n)*.*
*The time complexity of *Dynamic* Programming method is *O(n^2)*. *
*We manually set the small data set to allow you pass the test in both ways. This is just to let you learn how to use this problem in dynamic programming ways. If you finish it in dynamic programming ways, you can try greedy method to make it accept again. *
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int reach = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > reach)
                return false;
            reach = max(reach, i + A[i]);
        }
        return true;
    }
};

