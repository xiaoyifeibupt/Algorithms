/**
 *


*/


#include<iostream>
#include<vector>

using namespace std;

int maxPathSum(vector<vector<int> > &grid) {
	int m = grid.size();
	if(m == 0) return 0;
	int n = grid[0].size();
	vector<vector<int> > dp(m,vector<int>(n));
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i == 0){
				if(j == 0)
					dp[i][j] = grid[i][j];
				else
					dp[i][j] = dp[i][j - 1] + grid[i][j];
			}else if(j == 0)
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			else
				dp[i][j] = max(dp[i - 1][j] + grid[i][j],dp[i][j - 1] + grid[i][j]);
		}
	}
return dp[m - 1][n - 1];
}

int main() {

	vector<vector<int> > gridtemp;

	for (int i = 0; i < 6; ++i) {
		vector<int> temp;
		for (int j = 0; j < 6; ++j) {
			int input;
			cin>>input;
			temp.push_back(input);
		}
		gridtemp.push_back(temp);
	}
	cout<<maxPathSum(gridtemp);
	system("pause");

	return 0;

}