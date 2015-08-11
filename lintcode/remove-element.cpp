/**
*Given an array and a value, remove all occurrences of that value in place and return the new length.
*Example*
*Given an array *[0,4,4,0,0,2,4,4]*, *value=4*
*return *4* and front four elements of the array is *[0,0,0,2]*
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int i = 0, j = A.size();
        while (i < j) {
            if (A[i] != elem)
                i++;
            else
                swap(A[i], A[--j]);
        }
        return i;
    }
};
