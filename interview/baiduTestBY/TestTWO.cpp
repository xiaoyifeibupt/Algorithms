#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

int kSum(vector<int> A, int k, int target) {
    const int n = A.size();
    vector<vector<vector<int>>> table(n+1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
    for (int i = 1; i <= n; ++i) {
        if (A[i - 1] <= target) {
            for (int j = i; j <= n; ++j) {
                table[j][1][A[i - 1]] = 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, k); j > 1; --j) {
            for (int p = 1; p <= target; ++p) {
                table[i][j][p] = table[i - 1][j][p];
                if (p - A[i - 1] >= 0) {
                    table[i][j][p] += table[i - 1][j - 1][p - A[i - 1]];
                }
            }
        }
    }

    return table[n][k][target];
}

unsigned long combination(int n, int k) {
    unsigned long count = 1;
    for (int i = 1; i <= k; ++i, --n) {
        count = count * n / i;
    }
    return count;
}
int main() {
	int n, a, b, x;
	cin>>n>>a>>b>>x;

	vector<int> num;
	for (int i = a; i<= b; ++i) {
		num.push_back(i);
	}
	int aa = kSum(num, n, x);

	unsigned long bb = combination(b - a + 1, n);
	cout<<setiosflags(ios::fixed)<<setprecision(4)<<(double)aa/(double)bb<<endl;
	return 0;
}