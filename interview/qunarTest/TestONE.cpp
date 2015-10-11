#include<iostream>
#include<string>
#include<vector>

using namespace std;


vector<string> split(string str,string pattern) {  
	string::size_type pos;  
	vector<string> result;  
	str += pattern;
	int size = str.size();  

	for(int i = 0; i < size; i++) {
		pos = str.find(pattern,i);
		if (pos < size) {  
			string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}  
	return result;
}

int str2num(string str) {
	int num = 0;
	for (int i = 0; i < str.length(); ++i {
		num = num * 10 + (str[i] - '0');
	}
	return num;
}

int main() {

	int N;
	cin>>N;
	string input, newStableVersion = "";
	int max_1 = 0, max_2 = 0;
	for (int i = 0; i < N; ++i) {
		cin>>input;
		vector<string> vec = split(input, ".");
		int major = str2num(vec[0]);
		int minor = str2num(vec[1]);
		if (minor % 2 == 0) {
			if (major > max_1 || (major == max_1 && minor > max_2)) {
				newStableVersion = input;
				max_1 = major;
				max_2 = minor;
			}
		}
	}
	if (max_1 != 0 && max_2 != 0)
		cout<<newStableVersion;
	else
		cout<<"no stable available";

	system("pause");
	return 0;
}