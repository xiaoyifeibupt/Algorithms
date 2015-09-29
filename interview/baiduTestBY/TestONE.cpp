#include<iostream>
#include<string>
#include<vector>
using namespace std;


long long permutationIndex(string& A) {
	long long index = 1;
	// Position 1 is paired with factor 0 and so is skipped.
	int position = 2;
	long long factor = 1;
    for (int i = static_cast<int>(A.length()) - 2; i >= 0; --i) {
        int successors = 0;
        for (int j = i + 1; j < A.length(); ++j) {
            if (A[i] > A[j]) {
                ++successors;
            }
        }
        index += successors * factor;
        factor *= position;
        ++position;
    }
    return index;
}

int main() {
	vector<long long> result;
	int num;
	cin>>num;
	for (int i = 0; i < num; ++i) {
		string inStr;
		cin>>inStr;
		result.push_back(permutationIndex(inStr));
	}
	for (int i = 0; i < num; ++i) {
		cout<<result[i];
		if (i != num - 1)
			cout<<endl;
	}

	return 0;

}