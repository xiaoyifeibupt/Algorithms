/**
最大子矩阵
Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 65536/65536 K (Java/Others)
Problem Description:
求一个矩阵中最大的2*2矩阵(元素和最大)的和。
如:
1 2 0 3 4
2 3 4 5 1
1 1 5 3 0
中最大的是:
4 5
5 3
和为17
输入
m*n的矩阵
输出
该m*n矩阵的最大2*2子矩阵(元素和最大)的和
*/


#include<iostream>
#include<vector>
#include <string>
using namespace std;

int get_max_Matrix(vector<vector<int> > &a) {  
	
	int row = a.size();
	int col = a[0].size();
	int maxsum = 0, result_i, result_j, sum, last_vsum = 0;	 
	last_vsum = a[0][0] + a[1][0];
	for(int i = 0; i < row - 1; i++) {  
		for(int j=1; j < col; j++) {  
			sum = last_vsum ;
			last_vsum = a[i][j] + a[i + 1][j];
			sum += last_vsum;
			if(maxsum < sum) {  
				maxsum = sum;  
				result_i = i;  
				result_j = j-1;  
			}  
		}  
	}
	return maxsum;
}  

vector<string> split(string str,string pattern) {  
	string::size_type pos;  
	vector<string> result;  
	str += pattern;//扩展字符串以方便操作  
	int size = str.size();  
  
	for(int i = 0; i < size; i++) {
		pos = str.find(pattern,i);  
		if(pos < size) {
			string s = str.substr(i, pos - i);
			result.push_back(s);  
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}
int main() {
	vector<vector<int> > matrix;
	vector<int> temp;
	string line;
	getline(cin, line);
	vector<string> row = split(line, ";");
	for (int i = 0; i < row.size(); ++i) {
		vector<string> element = split(row[i], " ");
		vector<int> temp;
		for (int j = 0; j < element.size(); ++j) {
			temp.push_back(stoi(element[j]));
		}
		matrix.push_back(temp);
	}
	cout<<get_max_Matrix(matrix);
	system("pause");
	return 0;
}