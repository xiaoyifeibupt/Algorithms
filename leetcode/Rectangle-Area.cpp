/**
*Find the total area covered by two rectilinear rectangles in a 2D plane.
*Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
*Assume that the total area is never beyond the maximum possible value of int.
*Credits:Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);  
        if (A >= G || B >= H || C <= E || D <= F) {  
            return area;  
        }  
  
        int top = min(D, H);  
        int bottom = max(B, F);  
        int left = max(A, E);  
        int right = min(C, G);  
  
        return area - (top - bottom) * (right - left);
    }
};