/*
 *最长递增子序列
 *{1,2,6,1,8,4,9}返回{1,2,6,8,9};
 *
 *教训：返回值为const引用,没看清楚，返回的局部变量的引用
 *
*/

#include<iostream>
#include<vector>

using namespace std;


const vector<int>& findSeq_1(const vector<int>& input) {		
	int n = input.size(), i, j, k, max;		
	vector<int> liss(n, 1);
	vector<int> pre;
	for (int ii = 0; ii < n; ++ii)
		pre.push_back(ii);
	for (i = 1, max = 1, k = 0; i < n; ++i) {
		for (j = 0; j < i; ++j) {
			if (input[j] < input[i] && liss[j] + 1 > liss[i]) {
				liss[i] = liss[j] + 1;
				pre[i] = j;
				if (max < liss[i]) {
					max = liss[i];
					k = i;
				}
			}
		}
	}
	vector<int> *result = new vector<int>(max, 0);
	i = max - 1;
	while (pre[k] != k) {
		(*result)[i--] = input[k];
		k = pre[k];
	}
	(*result)[i] = input[k];
	return *result;
}


void insert(vector<int>& LIS, int target) {
    int left = 0, right = LIS.size() - 1;
    auto comp = [](int x, int target) { return x <= target; };

	// Find the largest index "left" which satisfies LIS[left] <= target
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (!comp(LIS[mid], target)) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

    // If not found, append the target.
	if (left == LIS.size()) {
		LIS.emplace_back(target);
	} else {
		LIS[left] = target;
	}
}

const vector<int>& findSeq_2(vector<int> nums) {
	vector<int> *LIS = new vector<int>();

	for (auto& i : nums) {
		insert(*LIS, i);
	}

    return *LIS;
}
int main() {

	int aa[] = {1,2,6,3,8,4,9};
	vector<int> input(aa,aa + 7);
	vector<int> result_1 = findSeq_1(input);
	vector<int> result_2 = findSeq_2(input);
	system("pause");
	return 0;
}
