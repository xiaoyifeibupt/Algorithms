#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;

void nextPermutation(string &str) {
    int k = -1, ll = 0;
    for (int  i = 0; i < str.length() - 1; ++i) {
        if (str[i] < str[i + 1])
            k = i;
    }
    if (k >= 0) {
        for (int i = k + 1; i < str.size(); ++i)
            if (str[i] > str[k])
                ll = i;
        swap(str[k], str[ll]);
    }
    reverse(str.begin() + (k + 1), str.end());
}
int solution(int N) {
	string str = to_string(N);	
	sort(str.begin(), str.end());
	string next(str);
	int count = 0;
	do {
		if (*next.begin() != '0')
			count++;
		nextPermutation(next);
	} while(next != str);	
	return count;
}
int main() {
	int x = solution(120);
	
	system("pause");
	return 0;
}