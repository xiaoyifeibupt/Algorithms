/**
*Cosine similarity is a measure of similarity between two vectors of an inner product space that measures the cosine of the angle between them. The cosine of 0° is 1, and it is less than 1 for any other angle.
*Example*
*Given A = *[1, 2, 3]*, B = *[2, 3 ,4]*.*
*Return *0.9926*.*
*Given A = *[0]*, B = *[0]*.*
*Return *2.0000*
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        if (A.size() != B.size()) return 2.0000;
        int AB = 0, AA = 0, BB = 0;
        for (int i = 0; i < A.size(); ++i) {
            AB += A[i] * B[i];
            AA += A[i] * A[i];
            BB += B[i] * B[i];
        }
        if (AA == 0 || BB == 0) return 2.0000;
        else {
            double ab = AB, aa = sqrt(AA), bb = sqrt(BB);
            return ab / (aa * bb);
        }
    }
};

