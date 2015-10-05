/**
*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*Example*
*Given 4 points: *(1,2)*, *(3,6)*, *(0,0)*, *(1,3)*.*
*The maximum number is *3*.*
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        if (points.size() < 3) return points.size();
        int result = 0;
        unordered_map<double, int> slope_count;
        for (int i = 0; i < points.size()-1; i++) {
            slope_count.clear();
            int samePointNum = 0; // 与i 重合的点
            int point_max = 1; // 和i 共线的最大点数
            for (int j = i + 1; j < points.size(); j++) {
                double slope; // 斜率
                if (points[i].x == points[j].x) {
                    slope = std::numeric_limits<double>::infinity();
                    if (points[i].y == points[j].y) {
                        ++ samePointNum;
                        continue;
                    }
                } else {
                    slope = 1.0 * (points[i].y - points[j].y) /
                    (points[i].x - points[j].x);
                }
                int count = 0;
                if (slope_count.find(slope) != slope_count.end())
                    count = ++slope_count[slope];
                else {
                    count = 2;
                    slope_count[slope] = 2;
                }
                if (point_max < count) 
                    point_max = count;
            }
            result = max(result, point_max + samePointNum);
        }
        return result;
    }
};
