#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct Point2D {
	Point2D(int a, int b) {
		x = a;
		y = b;
	}
	int x;
	int y;
};

int multiply(Point2D p1, Point2D p2, Point2D p0) {  
    return((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));  
}  
  
double dis(Point2D p1,Point2D p2) {  
    return(sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));  
}  
  
  
vector<Point2D> Graham_scan(vector<Point2D> PointSet) {
	vector<Point2D> res;
    int n = PointSet.size();
	int i, j, k = 0,top = 2;  

    for(i = 1; i < n; i++)
        if ((PointSet[i].y < PointSet[k].y)
				||((PointSet[i].y == PointSet[k].y) 
				&& (PointSet[i].x < PointSet[k].x))) {
			
			k = i;
		}

    swap(PointSet[0],PointSet[k]);
 
    for (i = 1; i < n - 1; i++) {  
        k = i;  
        for (j=i+1;j<n;j++)  
            if ( (multiply(PointSet[j], PointSet[k], PointSet[0]) > 0)  
					||((multiply(PointSet[j], PointSet[k], PointSet[0]) == 0)  
                    &&(dis(PointSet[0], PointSet[j]) < dis(PointSet[0], PointSet[k]))) )  
                k = j; 
        swap(PointSet[i],PointSet[k]);
    }  
 
	res.push_back(PointSet[0]);  
    res.push_back(PointSet[1]);
    res.push_back(PointSet[2]);  

    for (i = 3; i < n; i++) {
		while(multiply(PointSet[i],res[res.size() - 1],res[res.size() - 2]) >= 0) 
			res.pop_back();  
        
        res.push_back(PointSet[i]);  
    }
	return res;
}
bool vecIn(Point2D p, vector<Point2D> poly) {
	int px = p.x, py = p.y;
	bool flag = false;
	for(int i = 0, len = poly.size(), j = len - 1; i < len; j = i, i++) {
		int sx = poly[i].x;
		int sy = poly[i].y;
		int tx = poly[j].x;
		int ty = poly[j].y;

		if((sx == px && sy == py) || (tx == px && ty == py)) {
			return false;
		}

		if((sy < py && ty >= py) || (sy >= py && ty < py)) {
			int x = sx + (py - sy) * (tx - sx) / (ty - sy);

			if(x == px) return false;

			if(x > px) flag = !flag;
		}
	}
	return flag ? true : false;
}
int solution(vector<Point2D> &A) {
    // write your code in C++11
	int count = 0;
	vector<Point2D> polygen = Graham_scan(A);
	for (const auto& a : A) {
		if (vecIn(a,polygen)) {
			count++;
		}
	}
	return count;;

}
int main() {
	vector<Point2D> ps;
	ps.push_back(Point2D(0,0));
	ps.push_back(Point2D(0,3));
	ps.push_back(Point2D(2,3));
	ps.push_back(Point2D(2,2));
	ps.push_back(Point2D(1,2));
	ps.push_back(Point2D(1,1));
	ps.push_back(Point2D(2,1));
	ps.push_back(Point2D(2,0));
	solution(ps);
	getchar();
	return 0;
}