#include<iostream>
#include<string>
#include<map>
using namespace std;

class mycomp {
public:
	bool operator()(const string &k1, const string &k2) const {
		if (k1.length() < k2.length())
			return true;
		else if(k1.length() == k2.length()) {
			if (k1 < k2)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};


int main() {
	int num_1, num_2, num_3;
	cin>>num_1;
	map<string, int, mycomp> unmap_1, unmap_2, unmap_3;
	for (int i = 0; i < num_1; ++i) {
		string str;
		cin>>str;
		++unmap_1[str];
	}
	cin>>num_2;
	for (int i = 0; i < num_2; ++i) {
		string str;
		cin>>str;
		if (unmap_1.count(str) == 1)
			++unmap_2[str];
	}
	cin>>num_3;
	for (int i = 0; i < num_3; ++i) {
		string str;
		cin>>str;
		if (unmap_2.count(str) == 1)
			++unmap_3[str];
	}
	int count = 0;
	for (map<string, int, mycomp>::iterator iter = unmap_3.begin(); iter != unmap_3.end(); ++iter) {
		cout<<iter->first;
		count++;
		if (count != unmap_3.size())
			cout<<" ";
	}
	return 0;
}