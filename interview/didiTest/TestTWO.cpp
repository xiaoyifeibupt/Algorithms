/*
*求最长和为0的字数组
*/

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

vector<vector<int> > subarraySum(vector<int> nums){
	int sum = 0;
	vector<vector<int> > result;
	vector<int> ret;
	map<int, int> map;
	map[0] = -1;  
	for(int i=0; i < nums.size();i++) {
	   sum += nums[i];
		 
	   if(map.find(sum) != map.end()){
		   ret.push_back(map[sum] + 1);
		   ret.push_back(i);  
		   result.push_back(ret);
		   ret.clear();
	   }	
	   map[sum] = i;
	}	
	return result;
}

vector<string> split(string str,string pattern) {  
	string::size_type pos;  
	vector<string> result;  
	str += pattern;
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

	string line;
	getline(cin, line);
	vector<string> numStr = split(line, " ");
	vector<int> num;
	for (int i = 0; i < numStr.size(); ++i) {
		num.push_back(atoi(numStr[i].c_str()));
	}
	vector<vector<int> > result = subarraySum(num);
	int max = 0, max_index = 0;
	for (int i = 0; i < result.size(); ++i) {
		int m = result[i][1] - result[i][0];
		if (m > max) {
			max = m;
			max_index = i;
		}
	}
	for (int ii = result[max_index][0]; ii <= result[max_index][1]; ++ii) {
		cout<<num[ii];
		if (ii != result[max_index][1])
			cout<<" ";
	}
	system("pause");
	return 0;
}