/**
*The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.
*Example*
*Given n = *5*:*
*isBadVersion(3) -> false
isBadVersion(5) -> true
isBadVersion(4) -> true
*
*Here we are 100% sure that the 4th version is the first bad version.*

*Note*
*Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is *VersionControl.isBadVersion(v)*

*Challenge*
*You should call *isBadVersion* as few as possible. *
*/

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int left = 1, right = n - 1;
        VersionControl vc;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (vc.isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

